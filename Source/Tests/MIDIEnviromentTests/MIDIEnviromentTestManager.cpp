/*
  ==============================================================================

    MIDIEnviromentTestManager.cpp
    Created: 31 May 2020 5:38:40pm
    Author:  Taras A. Palczynski III

  ==============================================================================
*/

#include "MIDIEnviromentTestManager.h"

#include "NoteAndVelocityTest.h"

void MIDIEnviromentTestManager::updateLoop(MidiBuffer& midiMessages, int numberOfSamples, double processorSampleRate)
{
    MidiMessage m;
    int time;
    {
        const ScopedLock scopedLock (queuesLock);
        
        // If no listeners are in the currently running listener tests, add the top test from queue there
        if (currentlyRunningListenerTests.size() == 0 && listenerTestQueue.size() != 0)
        {
            MIDIEnviromentTestType front = listenerTestQueue.front();
            currentlyRunningListenerTests.push_back(front);
            currentlyRunningListenerTestsSet.insert(front);
            
            listenerTestSet.erase(front);
            listenerTestQueue.pop();
        }
        
        // Iterate over all currently running listener tests and run
        for (auto it = currentlyRunningListenerTests.begin(); it != currentlyRunningListenerTests.end(); ++it)
        {
            bool updateQueue = false;
            MIDIEnviromentTestType type = *it;
            MIDIEnviromentTestID id;
            id.testType = type;
            id.operationType = MIDIEnviromentTestOperationType::LISTENER;
            
            {
                const ScopedLock scopedLock (entryMapLock);
                
                // Setup the test
                if (testEntryMap[id].status == Status::IN_QUEUE)
                {
                    testEntryMap[id].status = Status::RUNNING;
                    testEntryMap[id].lastValidMessageTime = currentListenTime;
                    
                    testEntryMap[id].changeBroadcaster.sendChangeMessage();
                }
                
                for (const MidiMessageMetadata metadata : midiMessages)
                {
                    m = metadata.getMessage();
                    time = metadata.samplePosition;
                    
                    // Run update block
                    // Check to see if this message is a message part of the test.
                    // The timeout is what determines if we should consider the absense of these messages a fail.
                    if (testEntryMap[id].theTest.verifyMessageAndRemoveIfPartOfTest(m))
                    {
                        testEntryMap[id].lastValidMessageTime = currentListenTime;
                        
                        testEntryMap[id].progress = testEntryMap[id].theTest.getPercentOfMessagesLeft();
                        
                        testEntryMap[id].changeBroadcaster.sendChangeMessage();
                    }
                }
                
                // If the current timeout time is equal or greater to the intended timeout time, consider the test to have failed (Timeout).
                if (currentListenTime - testEntryMap[id].lastValidMessageTime >= timeoutInSeconds)
                {
                    testEntryMap[id].status = Status::TIMEOUT;
                    
                    // Update view with new status
                    // Tell all subscribers that this young lad is a changed man.
                    testEntryMap[id].changeBroadcaster.sendChangeMessage();
                    
                    updateQueue = true;
                }
                    
                // No more messages to listen for.  Report success, and go to next test.
                if (testEntryMap[id].progress == 1.0)
                {
                    testEntryMap[id].status = Status::DONE;
                    
                    // Update view with new status
                    // Tell all subscribers that this young lad is a changed man.
                    testEntryMap[id].changeBroadcaster.sendChangeMessage();
                    
                    updateQueue = true;
                }
            }
                
            if (updateQueue)
            {
                currentlyRunningListenerTestsSet.erase(*it);
                it = currentlyRunningListenerTests.erase(it);
                
                if (listenerTestQueue.size() > 0)
                {
                    MIDIEnviromentTestType nextTest = listenerTestQueue.front();
                    listenerTestSet.erase(nextTest);
                    listenerTestQueue.pop();
                    
                    auto indexOfExisting = currentlyRunningListenerTestsSet.find(nextTest);
                    
                    // Allow next intended test to be put in currently running if the test is not already running.
                    // Not doing this could result in duplicates due to the doppelganger system.
                    if (indexOfExisting == listenerTestSet.end())
                    {
                        currentlyRunningListenerTests.push_back(nextTest);
                        currentlyRunningListenerTestsSet.insert(nextTest);
                    }
                }
            }
        }
    }
    
    currentListenTime += numberOfSamples / processorSampleRate;
    
    // Clear all input for clean slate for broadcasting
    midiMessages.clear();
    
    {
        const ScopedLock queuesScopedLock (queuesLock);
        
        if (broadcasterTestQueue.size() > 0)
        {
            MIDIEnviromentTestType type = broadcasterTestQueue.front();
            MIDIEnviromentTestID id;
            id.testType = type;
            id.operationType = MIDIEnviromentTestOperationType::BROADCASTER;
            
            const ScopedLock scopedLock (entryMapLock);
            
            // Front test was just added to the queue.  Add dopple ganger if applicable.
            if (testEntryMap[id].status == Status::IN_QUEUE && testEntryMap[id].hasListenerDoppelganger)
            {
                // Add if the listener type is not already currently running
                auto indexOfExisting = currentlyRunningListenerTestsSet.find(id.testType);
                
                if (indexOfExisting == listenerTestSet.end())
                {
                    currentlyRunningListenerTests.push_back(id.testType);
                    currentlyRunningListenerTestsSet.insert(id.testType);
                }
            }
            
            // Run test update block, which updates the entry map's progress
            testEntryMap[id].progress = testEntryMap[id].theTest.updateLoop(midiMessages, numberOfSamples, processorSampleRate, testEntryMap[id].status);
            
            // If the status of the entry is any sort of failure, set the error message and update the view
        //    if (testEntryMap[id].status > Status::DONE)
            
            // Update the view with these new changes
            testEntryMap[id].changeBroadcaster.sendChangeMessage();
            
            if (testEntryMap[id].status == Status::DONE)
            {
                // Remove test from test set and move on to the new test.
                broadcasterTestSet.erase(id.testType);
                broadcasterTestQueue.pop();
            }
        }
    }
}

bool MIDIEnviromentTestManager::isThereTestsAvaliable()
{
    bool noTestsAvaliable = (broadcasterTestQueue.size() == 0) && (listenerTestQueue.size() == 0) && (currentlyRunningListenerTests.size() == 0);
    return !noTestsAvaliable;
}

void MIDIEnviromentTestManager::addSubscriberToTestChange(MIDIEnviromentTestID testID, ChangeListener *subscriber)
{
    const ScopedLock myScopedLock (entryMapLock);
    testEntryMap[testID].changeBroadcaster.addChangeListener(subscriber);
}

int MIDIEnviromentTestManager::addTestToQueue(MIDIEnviromentTestID testID)
{
    switch (testID.operationType)
    {
        case BROADCASTER:
            return addBroadcastingTestToQueue(testID);
            break;
        case LISTENER:
            return addListeningTestToQueue(testID);
            break;
        default:
            return 1;
            break;
    }
}

int MIDIEnviromentTestManager::addBroadcastingTestToQueueWithListenerDoppelganger(MIDIEnviromentTestID testID)
{
    int ret = 0;
    
    ret = addBroadcastingTestToQueue(testID);
    if (ret > 0)
        return ret;
    
    ret = addListeningTestToQueue(testID);
    if (ret > 0)
        return ret;
    
    {
        const ScopedLock scopedLock (entryMapLock);
        
        MIDIEnviromentTestID tempTestID = testID;
        tempTestID.operationType = MIDIEnviromentTestOperationType::BROADCASTER;
        testEntryMap[tempTestID].hasListenerDoppelganger = true;
    }
    
    return 0;
}

int MIDIEnviromentTestManager::addBroadcastingTestToQueue(MIDIEnviromentTestID testID)
{
    const ScopedLock queueLock (queuesLock);
    
    testID.operationType = MIDIEnviromentTestOperationType::BROADCASTER;
    
    auto indexOfExisting = broadcasterTestSet.find(testID.testType);
    
    // Already exists
    if (indexOfExisting != broadcasterTestSet.end()) {
        return 1;
    } else { // Does not exist
        broadcasterTestQueue.push(testID.testType);
        broadcasterTestSet.insert(testID.testType);
        initatlizeTestEntry(testID);
        return 0;
    }
}

int MIDIEnviromentTestManager::addListeningTestToQueue(MIDIEnviromentTestID testID)
{
    const ScopedLock queueLock (queuesLock);
    
    testID.operationType = MIDIEnviromentTestOperationType::LISTENER;
    
    auto indexOfExisting = listenerTestSet.find(testID.testType);
    auto indexOfExisting2 = currentlyRunningListenerTestsSet.find(testID.testType);
    
    // Already exists
    if (indexOfExisting != listenerTestSet.end() || indexOfExisting2 != currentlyRunningListenerTestsSet.end()) {
        return 1;
    } else { // Does not exist
        listenerTestQueue.push(testID.testType);
        listenerTestSet.insert(testID.testType);
        initatlizeTestEntry(testID);
        return 0;
    }
}

void MIDIEnviromentTestManager::initatlizeTestEntry(MIDIEnviromentTestID testID)
{
    const ScopedLock scopedLock (entryMapLock);
    
    MIDIEnviromentTest newTest;
    switch(testID.testType)
    {
        case NOTE_AND_VELOCITY:
            newTest = NoteAndVelocityTest(testID.midiChannel);
            break;
        default:
            newTest = MIDIEnviromentTest();
            break;
    }
    newTest.initalizeTest();
    testEntryMap[testID].theTest = newTest;
    
    testEntryMap[testID].status = Status::IN_QUEUE;
    testEntryMap[testID].progress = 0.0;
    testEntryMap[testID].hasListenerDoppelganger = false;
    
    // Update view that test has been updated
    testEntryMap[testID].changeBroadcaster.sendChangeMessage();
}

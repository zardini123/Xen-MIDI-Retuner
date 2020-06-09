/*
  ==============================================================================

    MIDIEnviromentTest.cpp
    Created: 29 May 2020 5:47:08pm
    Author:  Taras A. Palczynski III

  ==============================================================================
*/

#include "MIDIEnviromentTest.h"

MIDIEnviromentTest::MIDIEnviromentTest()
{
    initalUniqueMessageCount = -1;
    currentTimeInSeconds = 0.0;
    
    initalized = false;
}

void MIDIEnviromentTest::initalizeTest()
{
    allUniqueMessages.clear();
    setupMessageSequenceAndUniqueMessages();
    
    initalUniqueMessageCount = allUniqueMessages.size();
    
    messageSequenceToPlay.updateMatchedPairs();
    messageSequenceToPlay.sort();
    
    currentTimeInSeconds = 0.0;
    
    initalized = true;
}

double MIDIEnviromentTest::updateLoop(MidiBuffer& midiMessages, int numberOfSamples, double processorSampleRate, Status &currentStatus)
{
    double timeOfBufferEnd = currentTimeInSeconds + (numberOfSamples / processorSampleRate);
    for (auto i = 0; i < messageSequenceToPlay.getNumEvents(); i++)
    {
        MidiMessageSequence::MidiEventHolder *event = messageSequenceToPlay.getEventPointer(i);

        if (event->message.getTimeStamp() >= currentTimeInSeconds && event->message.getTimeStamp() < timeOfBufferEnd)
        {
            auto samplePosition = roundToInt((event->message.getTimeStamp() - currentTimeInSeconds) * processorSampleRate);
            midiMessages.addEvent(event->message, samplePosition);
        }
    }
    
    currentTimeInSeconds = timeOfBufferEnd;
    
    currentStatus = (currentTimeInSeconds > messageSequenceToPlay.getEndTime())? Status::DONE : Status::RUNNING;
    
    return jmap(messageSequenceToPlay.getEndTime() - currentTimeInSeconds, messageSequenceToPlay.getEndTime(), 0.0, 0.0, 1.0);
}

bool MIDIEnviromentTest::verifyMessageAndRemoveIfPartOfTest(MidiMessage &message)
{
    return allUniqueMessages.erase(message) >= 1;
}

double MIDIEnviromentTest::getPercentOfMessagesLeft()
{
    return jmap((double)initalUniqueMessageCount - allUniqueMessages.size(), 0.0, (double)initalUniqueMessageCount, 0.0, 1.0);
}

bool MIDIEnviromentTest::verifyMessageIsPartOfTest(MidiMessage &message)
{
    auto elementFound = allUniqueMessages.find(message);
    // If equal to .end(), cannot be found
    return elementFound != allUniqueMessages.end();
}

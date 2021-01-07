/*
  ==============================================================================

    MIDIEnviromentTestManager.h
    Created: 31 May 2020 5:38:40pm
    Author:  Taras A. Palczynski III

  ==============================================================================
*/

#pragma once

#include <unordered_map>
#include <queue>
#include <list>

#include <JuceHeader.h>
#include "MIDIEnviromentTest.h"
#include "../../ProcessorStructures.h"

struct MIDIEnviromentTestEntry
{
    MIDIEnviromentTestID entryID;
    
    MIDIEnviromentTest theTest;
    /// Only used by Broadcaster type.  Used for starting listener when test starts.
    bool hasListenerDoppelganger = false;
    
    ChangeBroadcaster changeBroadcaster;
    
    double progress {0.0};
    Status status { Status::IN_QUEUE };
    juce::String errorIfFailed;
    
    /// Only used by Listener type.  Used for determining how long its been since last valid message for timeout.
    double lastValidMessageTime {0.0};
};

struct MIDIEnviromentTestActionButtonMaps
{
    Button *theButton;
    MIDIEnviromentTestID entryID;
};

class MIDIEnviromentTestManager
{
private:
    std::queue<MIDIEnviromentTestType> broadcasterTestQueue;
    std::unordered_set<MIDIEnviromentTestType> broadcasterTestSet;
    
    // TODO: Bundle lists and unordered_sets together as they will be used in the processor soon
    std::list<MIDIEnviromentTestType> currentlyRunningListenerTests;
    std::unordered_set<MIDIEnviromentTestType> currentlyRunningListenerTestsSet;
    std::queue<MIDIEnviromentTestType> listenerTestQueue;
    std::unordered_set<MIDIEnviromentTestType> listenerTestSet;
    
    double timeoutInSeconds {2.0};
    double currentListenTime {0.0};
public:
    CriticalSection entryMapLock;
    std::unordered_map<MIDIEnviromentTestID, MIDIEnviromentTestEntry, MIDIEnviromentTestID, MIDIEnviromentTestID> testEntryMap;
    
    CriticalSection queuesLock;
    
    bool isThereTestsAvaliable();
    
    void updateLoop(MidiBuffer& midiMessages, int numberOfSamples, double processorSampleRate);
    
    void addSubscriberToTestChange(MIDIEnviromentTestID testID, ChangeListener *subscriber);
    
    int addTestToQueue(MIDIEnviromentTestID testID);
    
    int addBroadcastingTestToQueueWithListenerDoppelganger(MIDIEnviromentTestID testID);
    int addBroadcastingTestToQueue(MIDIEnviromentTestID testID);
    int addListeningTestToQueue(MIDIEnviromentTestID testID);
    
    void initatlizeTestEntry(MIDIEnviromentTestID testID);
};

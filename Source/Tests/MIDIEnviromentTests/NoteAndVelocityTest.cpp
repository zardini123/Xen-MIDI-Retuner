/*
  ==============================================================================

    NoteAndVelocityTest.cpp
    Created: 29 May 2020 1:25:51pm
    Author:  Taras A. Palczynski III

  ==============================================================================
*/

#include "NoteAndVelocityTest.h"

NoteAndVelocityTest::NoteAndVelocityTest(int channel)
{
    MIDIEnviromentTest::channel = channel;
}

void MIDIEnviromentTest::setupMessageSequenceAndUniqueMessages()
{
    // Note on/off: 3 bytes (24 bits)
    // MIDI bitrate: 31250 bits per second
    // 24/31250 = 0.000768 seconds per message
    double secondsPerNote = 0.000768;
//    double secondsPerNote = 0.1;
    double currentTime = 0.0;
    
    for (int i = 0; i < 128; i++)
    {
        MidiMessage ms = MidiMessage::noteOn(channel, i, (juce::uint8)jmax(i, 1));
        ms.setTimeStamp(currentTime);
        
        auto insertReturn = allUniqueMessages.insert(ms);
        messageSequenceToPlay.addEvent(*insertReturn.first);
        
        currentTime += secondsPerNote;
        
        ms = MidiMessage::noteOff(channel, i);
        ms.setTimeStamp(currentTime);
        
        insertReturn = allUniqueMessages.insert(ms);
        messageSequenceToPlay.addEvent(*insertReturn.first);
        
        currentTime += secondsPerNote;
    }
}

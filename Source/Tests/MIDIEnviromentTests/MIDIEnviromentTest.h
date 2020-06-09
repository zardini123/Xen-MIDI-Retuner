/*
  ==============================================================================

    MIDIEnviromentTest.h
    Created: 29 May 2020 1:10:52pm
    Author:  Taras A. Palczynski III

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "../../ProcessorStructures.h"
#include <unordered_set>

struct MidiMessageHash {
    size_t operator()(const MidiMessage& message) const {
        std::hash<uint8_t> hasher;
        size_t seed = 0;
        // Not a constant pointer, but a pointer to a constant
        const juce::uint8 *rawDataPointer = message.getRawData();
        
        for (int i = 0; i < message.getRawDataSize(); i++) {
            seed ^= hasher(*rawDataPointer) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            
            // Pointer is of type uint8_t, therefore incrementing moves pointer by 8 bits.
            rawDataPointer++;
        }
        return seed;
    }
};

struct MidiMessageEqual {
    bool operator()(const MidiMessage &lhs, const MidiMessage &rhs) const {
        // Dont bother checking byte for byte if the amount of bytes are different
        if (lhs.getRawDataSize() != rhs.getRawDataSize())
            return false;
        
        const juce::uint8 *rawDataPointerLHS = lhs.getRawData();
        const juce::uint8 *rawDataPointerRHS = rhs.getRawData();
        
        // Number of bytes are identical at this point
        for (int i = 0; i < lhs.getRawDataSize(); i++)
        {
            if (*rawDataPointerLHS != *rawDataPointerRHS)
                return false;
                
            rawDataPointerLHS++;
            rawDataPointerRHS++;
        }
        
        return true;
    }
};

class MIDIEnviromentTest
{
protected:
    MidiMessageSequence messageSequenceToPlay;
    bool initalized;
    
    int channel;
    
    double currentTimeInSeconds;
public:
    unsigned long initalUniqueMessageCount;
    
    MIDIEnviromentTest();
    
    std::unordered_set<MidiMessage, MidiMessageHash, MidiMessageEqual> allUniqueMessages;
    
    /// Run all needed functions and logic to get the test ready for the updateLoop.
    /// Cannot run this function from the constructor of MIDIEnviromentTest as in runtime, the derived class implementation will not be known at that time.
    virtual void initalizeTest();
    
    /// Derived classes will implement this function to create the sequence of midi messages for the test.
    virtual void setupMessageSequenceAndUniqueMessages();
    
    /// The update loop to be called by the invoker.
    /// Returns the current progress of update loop.  Range [0,1].  1 = complete.
    /// @param midiMessages The buffer to put the midi messages into.
    /// @param numberOfSamples The number of samples per audio block.  Needed for understanding time in regards to the MidiSequence.
    /// @param processorSampleRate The audio sample rate of the processor.  Needed for setting MIDI message timestamps properly.
    /// @param currentStatus If the loop returns a TestStatus of FAILED, this Result will contain the reason for failure.
    virtual double updateLoop(MidiBuffer& midiMessages, int numberOfSamples, double processorSampleRate, Status &currentStatus);
    
    virtual bool verifyMessageAndRemoveIfPartOfTest(MidiMessage &message);
    
    double getPercentOfMessagesLeft();
    
    /// Checks if message is used in the test.  This function is used by the test listeners to determine if messages are getting through or not.
    /// @param message The message to check if exists in test.
    virtual bool verifyMessageIsPartOfTest(MidiMessage &message);
};

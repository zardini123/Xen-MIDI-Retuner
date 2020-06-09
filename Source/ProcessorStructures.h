/*
  ==============================================================================

    ProcessorStructures.h
    Created: 22 May 2020 12:11:28pm
    Author:  Taras A. Palczynski III

  ==============================================================================
*/

#pragma once

const int MAX_MIDI_CHANNELS = 16;
const int CENTER_PITCHWHEEL = 8192;

enum MIDIEnviromentTestType
{
    NULL_TEST = 0,
    NOTE_AND_VELOCITY,
    SYS_EX
};

enum MIDIEnviromentTestOperationType
{
    NULL_TYPE = 0,
    LISTENER,
    BROADCASTER
};

struct MIDIEnviromentTestID
{
public:
    MIDIEnviromentTestType testType;
    MIDIEnviromentTestOperationType operationType;
    int midiChannel {1};
    
    size_t operator()(const MIDIEnviromentTestID& id) const {
        std::hash<int> hasher;
        size_t seed = 0;
        seed ^= hasher(id.testType) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        seed ^= hasher(id.operationType) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        
        // Dont have hash be effected by midiChannel if the test is midi channel independent
        int finalMidiChannel = isMidiChannelIndependentTest()? 0 : id.midiChannel;
        seed ^= hasher(finalMidiChannel) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        
        return seed;
    }
    
    bool operator()(const MIDIEnviromentTestID &lhs, const MIDIEnviromentTestID &rhs) const {
        return (lhs.testType == rhs.testType) && (lhs.operationType == rhs.operationType);
    }
    
    bool isMidiChannelIndependentTest() const
    {
        switch (testType)
        {
            case SYS_EX:
                return true;
                break;
            default:
                return false;
                break;
        }
    }
};

enum Status
{
    IN_QUEUE = -2,
    RUNNING = -1,
    DONE = 0,
    FAILED = 1,
    TIMEOUT = 2
};

enum SingleChannelNotePrioritzation
{
    NOTE = 0,
    VELOCITY,
    RANDOM
};

enum SingleChannelNotePrioritzationModifier
{
    MOST_RECENT = 0,
    FIRST,
    HIGHEST_NOTE,
    LOWEST_NOTE
};

enum InterpolationDimension
{
    CENTS = 0,
    FREQUENCY
};

struct Note
{
    int midiNote;
    uint8 velocity;
    
    bool turnOffFlag = false;
};

struct Channel
{
    uint16 pitchwheel = CENTER_PITCHWHEEL; // Default to pitchbend wheel at center
    const Note *priorityNote;
    
    float scaleConvertedPriorityNote;
    std::vector<Note> notes;
};

struct OutputChannel
{
    int initalMidiNote;
    int initalJump;
    
    int noteOffset;
    int currentMidiNoteNumber;
};

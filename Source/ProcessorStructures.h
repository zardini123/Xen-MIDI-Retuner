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

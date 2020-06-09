/*
  ==============================================================================

    ProcessorData.h
    Created: 21 May 2020 10:01:21pm
    Author:  Taras A. Palczynski III

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#include "ProcessorStructures.h"
#include "AnaMark-Tuning-Library/SCL_Import.h"
#include "Components/TransitionCurve.h"
#include "Tests/MIDIEnviromentTests/MIDIEnviromentTestManager.h"

struct ProcessorData
{
    ProcessorData() {}    // Constructor? (the {} brackets) are needed here.

    ~ProcessorData()
    {
        // this ensures that no dangling pointers are left when the
        // singleton is deleted.
        clearSingletonInstance();
    }

    JUCE_DECLARE_SINGLETON (ProcessorData, false)

    MIDIEnviromentTestManager midiEnviromentTestManager;

    Channel input[MAX_MIDI_CHANNELS];
    CriticalSection inputLock;

    OutputChannel output[MAX_MIDI_CHANNELS];
    std::vector<Note> outputNotes[MAX_MIDI_CHANNELS];

    TUN::CSingleScale scale;

    AudioParameterInt *in_pitch_bend_range;
    AudioParameterInt *out_pitch_bend_range;

    AudioParameterChoice *singleChannelNotePriority;
    AudioParameterChoice *singleChannelNotePriorityModifier;

    InterpolationDimension interploationDimension = CENTS;

    TransitionCurve transitionCurve;
};

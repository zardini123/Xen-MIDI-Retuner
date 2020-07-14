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
    ProcessorData(AudioProcessor &processorForApvts);
    
    AudioProcessorValueTreeState apvts;
    UndoManager undoManager;
    
    MIDIEnviromentTestManager midiEnviromentTestManager;

    Channel input[MAX_MIDI_CHANNELS];
    CriticalSection inputLock;

    OutputChannel output[MAX_MIDI_CHANNELS];
    std::vector<Note> outputNotes[MAX_MIDI_CHANNELS];

    TUN::CSingleScale scale;

    InterpolationDimension interploationDimension = CENTS;

    TransitionCurve transitionCurve;
};
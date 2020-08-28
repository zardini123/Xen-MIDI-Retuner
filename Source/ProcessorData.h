/*
  ==============================================================================

    ProcessorData.h
    Created: 21 May 2020 10:01:21pm
    Author:  Taras A. Palczynski III

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#include "ProcessorStructures.h"
#include "AnaMark-Tuning-Library/SCL_Import.h"
#include "Components/TransitionCurve.h"
#include "Tests/MIDIEnviromentTests/MIDIEnviromentTestManager.h"

struct ProcessorData
{
    ProcessorData(AudioProcessor &processorForApvts);

    AudioProcessorValueTreeState apvts;
    UndoManager undoManager;

    TransitionCurve transitionCurve;

    Channel input[MAX_MIDI_CHANNELS];
    CriticalSection inputLock;

    OutputChannel output[MAX_MIDI_CHANNELS];

    TUN::CSingleScale scale;
    ChangeBroadcaster scaleChangedBroadcaster;

    MIDIEnviromentTestManager midiEnviromentTestManager;

    std::unique_ptr<FileLogger> logger;
};

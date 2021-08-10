/*
  ==============================================================================

    ProcessorData.h
    Created: 21 May 2020 10:01:21pm
    Author:  Taras A. Palczynski III

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#include "../lib/AnaMark-Tuning-Library/src/DynamicScaleFormats/MTS-ESP-Client.hpp"
#include "../lib/AnaMark-Tuning-Library/src/Scale.hpp"
#include "Components/TransitionCurve.h"
#include "ProcessorStructures.h"
#include "Tests/MIDIEnviromentTests/MIDIEnviromentTestManager.h"

struct ProcessorData {
    ProcessorData(AudioProcessor &processorForApvts);

    AudioProcessorValueTreeState apvts;
    UndoManager undoManager;

    TransitionCurve transitionCurve;

    InputChannel input[MAX_MIDI_CHANNELS];
    CriticalSection inputLock;

    OutputChannel output[MAX_MIDI_CHANNELS];

    AnaMark::Scale scale;
    AnaMark::MTSESPClient *mtsESPClient;
    ChangeBroadcaster scaleChangedBroadcaster;

    MIDIEnviromentTestManager midiEnviromentTestManager;

    std::unique_ptr<FileLogger> logger;
};

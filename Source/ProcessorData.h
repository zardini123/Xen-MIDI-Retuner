/*
  ==============================================================================

    ProcessorData.h
    Created: 21 May 2020 10:01:21pm
    Author:  Taras A. Palczynski III

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <array>

#include "../lib/AnaMark-Tuning-Library/src/DynamicScaleFormats/MTS-ESP-Client.hpp"
#include "../lib/AnaMark-Tuning-Library/src/Scale.hpp"

#include "Components/TransitionCurve.h"
#include "ProcessorStructures.h"
#include "ScaleChangeBroadcaster.h"

const int MAX_MIDI_CHANNELS = 16;
const int CENTER_PITCHWHEEL = 8192;

struct Note {
  int midiNote;
  uint8 velocity;

  bool turnOffFlag = false;
};

struct ProcessorData {
  struct InputChannel {
    std::vector<Note> notes;

    uint16 pitchwheel = CENTER_PITCHWHEEL; // Default to pitchbend wheel at center
    const Note *noteToTune = nullptr;

    float continuousTunedNote;
  };

  struct OutputChannel {
    std::vector<Note> notes;

    int centerOfOutputPitchbendRangeStatic;
    int noteToTuneToContinuousTunedNoteDifference;

    int offsetOutputPitchbendRange;
    int outputMidiNoteForTunedNote;
  };

  ProcessorData(AudioProcessor &processorForApvts);

  AudioProcessorValueTreeState apvts;
  UndoManager undoManager;

  TransitionCurve transitionCurve;

  InputChannel input[MAX_MIDI_CHANNELS];
  CriticalSection inputLock;

  OutputChannel output[MAX_MIDI_CHANNELS];

  AnaMark::Scale scale;
  ScaleChangeBroadcaster scaleChangeBroadcaster;

  // Map midi note to scale note
  std::array<int, AnaMark::Scale::tunableRangeSize> midiNoteToScaleNoteMapping;

  AnaMark::MTSESPClient *mtsESPClient = nullptr;
  ChangeBroadcaster scaleChangedBroadcaster;

  std::unique_ptr<FileLogger> logger;
};

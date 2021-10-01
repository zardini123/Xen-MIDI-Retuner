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
#include <map>
#include <set>

#include "../lib/AnaMark-Tuning-Library/src/DynamicScaleFormats/MTS-ESP-Client.hpp"
#include "../lib/AnaMark-Tuning-Library/src/Scale.hpp"

#include "Components/TransitionCurve.h"
#include "ProcessorStructures.h"
#include "ScaleChangeBroadcaster.h"
#include "Utilities.h"

const int MAX_MIDI_CHANNELS = 16;
const int CENTER_PITCHWHEEL = 8192;

struct Note {
  int midiNote;
  uint8 velocity;

  bool turnOffFlag = false;
};

class ScaleNoteMapping : public AnaMark::ChangeAttacher,
                         public juce::ChangeBroadcaster,
                         public juce::AudioProcessorValueTreeState::Listener {
public:
  enum NoteMappingType {
    NO_MAPPING = 0,
    PRIMARY_MAPPING = 1,
    SECONDARY_MAPPING = 2,
  };

  ScaleNoteMapping(AnaMark::Scale &scaleToBindTo) : scaleReference{scaleToBindTo} {
    this->midiNoteToScaleNoteMapping.fill(-1);
    this->secondaryMapping.fill(-1);
  }

  NoteMappingType getMidiNoteMapping(int midiNote, int &scaleNoteOut) {
    assert(midiNote >= 0 && midiNote <= this->midiNoteToScaleNoteMapping.size());

    if (this->midiNoteToScaleNoteMapping[midiNote] != -1) {
      scaleNoteOut = this->midiNoteToScaleNoteMapping[midiNote];
      return PRIMARY_MAPPING;
    }

    if (this->secondaryMapping[midiNote] != -1) {
      scaleNoteOut = this->secondaryMapping[midiNote];
      return SECONDARY_MAPPING;
    }

    return NO_MAPPING;
  }

  void RecieveChangeFromProvider(const AnaMark::ChangeProvider *const changeOrigin,
                                 const AnaMark::ChangeProvider *const notifier,
                                 int scaleNote, double newFrequency) {
    assert(scaleNote >= AnaMark::Scale::firstTunableScaleNote &&
           scaleNote < AnaMark::Scale::afterLastTunableScaleNote);
    updateMapping(lastLegacyMappingOption);
  }

  void RecieveChangeFromProvider(const AnaMark::ChangeProvider *const changeOrigin,
                                 const AnaMark::ChangeProvider *const notifier,
                                 std::vector<int> &scaleNotes,
                                 std::vector<double> &newFrequencies) {
    assert(false);
  }

  void parameterChanged(const String &parameterID, float newValue) {
    if (parameterID == "legacy_mapping") {
      lastLegacyMappingOption = static_cast<bool>(newValue);
      updateMapping(lastLegacyMappingOption);
    }
  }

private:
  // Outputs the midi note to map to given a certain frequency
  int mappingFunction(double scaleFrequency) {
    double continuousMidiNote = freqHZToContinuousMidiNote(scaleFrequency);
    return static_cast<int>(std::round(continuousMidiNote));
  }

  void updateMapping(bool legacyMapping) {
    this->midiNoteToScaleNoteMapping.fill(-1);
    this->secondaryMapping.fill(-1);

    if (legacyMapping) {
      for (auto scaleNote = AnaMark::Scale::firstTunableScaleNote;
           scaleNote < AnaMark::Scale::afterLastTunableScaleNote;
           ++scaleNote) {
        this->midiNoteToScaleNoteMapping[scaleNote] = scaleNote;
      }
    } else {
      for (auto scaleNote = AnaMark::Scale::firstTunableScaleNote;
           scaleNote < AnaMark::Scale::afterLastTunableScaleNote;
           ++scaleNote) {
        // this->logger->logMessage(std::to_string(scaleNote));

        double scaleFrequency = this->scaleReference.FrequencyForMIDINote(scaleNote);
        double continuousMidiNote = freqHZToContinuousMidiNote(scaleFrequency);

        // Round to the closest midi note
        // @TODO: Provide user ability to round either up or down if half-way inbetween
        // two midi notes (to some tolerance)
        int closestMidiNote = static_cast<int>(std::round(continuousMidiNote));

        // @TODO: Handle frequencies that snap to notes outside inbound range.
        // This can only be done once out-of-bound support is provided by AnaMark.
        if (closestMidiNote < AnaMark::Scale::firstTunableScaleNote ||
            closestMidiNote >= AnaMark::Scale::afterLastTunableScaleNote) {
          continue;
        }

        double distance = std::abs(continuousMidiNote - closestMidiNote);

        // Check if the mapping for midi note to scale note is already taken
        if (this->midiNoteToScaleNoteMapping[closestMidiNote] == -1) {
          // this->logger->logMessage("Set: " + std::to_string(closestMidiNote));
          this->midiNoteToScaleNoteMapping[closestMidiNote] = scaleNote;
        } else {
          // If it is, check old "distance" from frequency to midi note to see if this new
          // mapping would result in a shorter distance

          // this->logger->logMessage("Conflict " + std::to_string(closestMidiNote));

          int mappedScaleNote = this->midiNoteToScaleNoteMapping[closestMidiNote];
          double mappedScaleNoteFreq =
              this->scaleReference.FrequencyForMIDINote(mappedScaleNote);
          double mappedContinuousMidiNote =
              freqHZToContinuousMidiNote(mappedScaleNoteFreq);

          double mappedDistance = std::abs(mappedContinuousMidiNote - closestMidiNote);

          if (distance < mappedDistance) {
            // this->logger->logMessage("Conflict set " +
            // std::to_string(closestMidiNote));
            this->midiNoteToScaleNoteMapping[closestMidiNote] = scaleNote;
          }
          // Else keep the scale note that was previously mapped
        }
      }

      // Secondary mapping
      for (auto midiNote = AnaMark::Scale::firstTunableScaleNote;
           midiNote < AnaMark::Scale::afterLastTunableScaleNote;
           ++midiNote) {
        if (this->midiNoteToScaleNoteMapping[midiNote] == -1) {
          // Scan left and right for the first and closest scale frequency
          int left = midiNote;
          int right = midiNote;
          int midiNoteResult = -1;
          while (left >= 0 && right < 128) {
            int leftMapping = this->midiNoteToScaleNoteMapping[left];
            int rightMapping = this->midiNoteToScaleNoteMapping[right];
            if (leftMapping != -1 && rightMapping != -1) {
              double leftCont = freqHZToContinuousMidiNote(
                  this->scaleReference.FrequencyForMIDINote(leftMapping));
              double rightCont = freqHZToContinuousMidiNote(
                  this->scaleReference.FrequencyForMIDINote(rightMapping));

              if (midiNote - leftCont < rightCont - midiNote) {
                midiNoteResult = left;
              } else {
                midiNoteResult = right;
              }
              break;
            } else if (leftMapping != -1) {
              midiNoteResult = left;
              break;
            } else if (rightMapping != -1) {
              midiNoteResult = right;
              break;
            }

            --left;
            ++right;
          }

          // this->logger->logMessage("mapping: at " + std::to_string(midiNote) + ", " +
          // std::to_string(midiNoteResult) + "-> " +
          // std::to_string(this->secondaryMapping[midiNoteResult]));
          this->secondaryMapping[midiNote] =
              (midiNoteResult >= 0 && midiNoteResult < 128)
                  ? this->midiNoteToScaleNoteMapping[midiNoteResult]
                  : -1;
        }
      }
    }

    // Broadcast mapping change
    this->sendChangeMessage();
  }

  AnaMark::Scale &scaleReference;

  // @FIXME: Will not be updated on plugin first initalize to whatever value it was when
  // saved
  bool lastLegacyMappingOption = false;

  std::array<int, AnaMark::Scale::tunableRangeSize> midiNoteToScaleNoteMapping;
  std::array<int, AnaMark::Scale::tunableRangeSize> secondaryMapping;
};

class ProcessorData {
public:
  struct InputChannel {
    std::vector<Note> notes;

    uint16 pitchwheel = CENTER_PITCHWHEEL; // Default to pitchbend wheel at center
    const Note *noteToTune = nullptr;

    float continuousTunedNote;
  };

  struct OutputChannel {
    std::vector<Note> notes;

    int scaleNote;

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
  std::unordered_set<int> playingMidiNotes;
  ReadWriteLock inputLock;

  OutputChannel output[MAX_MIDI_CHANNELS];

  AnaMark::Scale scale;
  ScaleNoteMapping scaleNoteMapping;
  ScaleChangeBroadcaster scaleChangeBroadcaster;

  AnaMark::MTSESPClient *mtsESPClient = nullptr;
  ChangeBroadcaster scaleChangedBroadcaster;

  std::unique_ptr<FileLogger> logger;
};

/*
  ==============================================================================

    ScaleChangeBroadcaster.h
    Created: 22 Aug 2021 9:33:25pm
    Author:  Taras A. Palczynski III

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#include "../lib/AnaMark-Tuning-Library/src/AttacherProvider.hpp"

class ScaleChangeBroadcaster : public AnaMark::ChangeAttacher,
                               public juce::ChangeBroadcaster {
public:
  void RecieveChangeFromProvider(const AnaMark::ChangeProvider *const changeOrigin,
                                 const AnaMark::ChangeProvider *const notifier,
                                 int scaleNote, double newFrequency) {
    this->sendChangeMessage();
  }

  void RecieveChangeFromProvider(const AnaMark::ChangeProvider *const changeOrigin,
                                 const AnaMark::ChangeProvider *const notifier,
                                 std::vector<int> &scaleNotes,
                                 std::vector<double> &newFrequencies) {
    this->sendChangeMessage();
  }
};

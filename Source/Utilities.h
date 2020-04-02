/*
  ==============================================================================

    Utilities.h
    Created: 26 Mar 2020 2:05:34pm
    Author:  Taras A. Palczynski III

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

float pitchwheelPosToSemitones(const uint16 pitchwheelPos, const float pitchbendRange);

float noteAndSemitonesToFreqHz(int noteNum, float semitones);
void freqHZToNoteAndSemitones(double frequency, int &noteNum, double &semitones);

int random(int min, int max);

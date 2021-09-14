/*
  ==============================================================================

    Utilities.h
    Created: 26 Mar 2020 2:05:34pm
    Author:  Taras A. Palczynski III

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

float pitchwheelPosToSemitones(const uint16 pitchwheelPos, const float pitchbendRange);

// @FIXME: Why is return value a float, whereas some arguments are double?  All should be
// double for maximum resolution.
float noteAndSemitonesToFreqHz(int noteNum, float semitones);
float continuousNoteToFreqHz(float continuousNote);
void freqHZToNoteAndSemitones(double frequency, int &noteNum, double &semitones);
float freqHZToContinuousMidiNote(double frequency);

int random(int min, int max);

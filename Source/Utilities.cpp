/*
  ==============================================================================

    Utilities.cpp
    Created: 26 Mar 2020 2:05:34pm
    Author:  Taras A. Palczynski III

  ==============================================================================
*/

#include "Utilities.h"

float pitchwheelPosToSemitones(const uint16 pitchwheelPos, const float pitchbendRange)
{
    // jmap requires the same type for all variables, therefore everything needs to be floats
    return pitchwheelPos > 8192? juce::jmap((float)pitchwheelPos, 8192.0f, 16383.0f, 0.0f, pitchbendRange) : juce::jmap((float)pitchwheelPos, 0.0f, 8192.0f, -pitchbendRange, 0.0f);
}

float noteAndSemitonesToFreqHz(int noteNum, float semitones)
{
    return std::pow(2, ((noteNum + semitones) - 69) / 12.0f) * 440;
}

float continuousNoteToFreqHz(float continuousNote)
{
    return std::pow(2, ((continuousNote) - 69) / 12.0f) * 440;
}

void freqHZToNoteAndSemitones(double frequency, int &noteNum, double &semitones)
{
    // Convert frequency to the midi note number with decimal result kept
    double exactNoteNum = 12 * std::log2(frequency / 440) + 69;

    // Get nearest integer midi note number
    int closestNoteNum = std::round(exactNoteNum);

    noteNum = closestNoteNum;
    semitones = exactNoteNum - closestNoteNum;
}

float freqHZToContinuousMidiNote(double frequency)
{
    int noteNum;
    double semitones;
    freqHZToNoteAndSemitones(frequency, noteNum, semitones);
    
    return noteNum + semitones;
}

int random(int min, int max) //range : [min, max)
{
   static bool first = true;
   if (first)
   {
      std::srand( std::time(NULL) ); //seeding for the first time only!
      first = false;
   }
   return min + std::rand() % (( max + 1 ) - min);
}

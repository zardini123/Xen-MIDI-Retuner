/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.5

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>

//// Forward declare class as cyclic dependency results in "undeclared identifier" errors
//// https://www.eventhelix.com/RealtimeMantra/HeaderFileIncludePatterns.htm
class NoteAndFrequencyOverlay;
class ScaleFrequenciesOverlay;
class KeyboardVisualControlsOverlay;

#include "../../ComponentWithReferenceToData.h"
//[/Headers]

#include "ScaleFrequenciesOverlay.h"
#include "NoteAndFrequencyOverlay.h"
#include "KeyboardVisualControlsOverlay.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class KeyboardVisual  : public ComponentWithReferenceToData
{
public:
    //==============================================================================
    KeyboardVisual (ProcessorData *dataReference);
    ~KeyboardVisual() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setKeyboardSettings(int firstMidiNote, int lastMidiNote);
    void setKeyboardDimensions(int width, int height);

    int getFirstMidiNote();
    int getLastMidiNote();

    double ConvertDiscreteMidiNoteToPercentWidth(int discreteMidiNote);
    double ConvertDiscreteMidiNoteToPercentWidth(int discreteMidiNote, int& keyDistanceIndex);

    double ConvertContinuousMidiNoteToPercentWidth(double continousMidiNote);

    double ConvertPixelsToContinuousMidiNote(int xPositionInPixels);
    double ConvertPercentWidthToContinuousMidiNote(double percentWidth);

    // Painting methods for keyboard-related drawing
    void drawMarkerAtDiscreteMidiNote(int midiNote, juce::Colour baseColor, juce::Graphics& graphics);
    void drawMarkerAtContinuousMidiNote(double continousMidiNote, juce::Colour baseColor, juce::Graphics& graphics);
    void drawMarkerAtFrequencyHz(double frequencyHz, juce::Colour baseColor, juce::Graphics& graphics);

    void drawLargerMarkerAtDiscreteMidiNote(int midiNote, juce::Colour baseColor, juce::Graphics& graphics);
    void drawLargerMarkerAtContinuousMidiNote(double continousMidiNote, juce::Colour baseColor, juce::Graphics& graphics);

    static const Colour inRangeWhiteKeyColour;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void mouseMove (const juce::MouseEvent& e) override;
    void mouseDrag (const juce::MouseEvent& e) override;
    void mouseWheelMove (const juce::MouseEvent& e, const juce::MouseWheelDetails& wheel) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    void setEqualSpacingValues();

    // Keyboard settings
    int entireWidth;
    int entireHeight;

    int firstMidiNote;
    int lastMidiNote;

    // Keyboard cached values
    double keyDistances[13];

    int firstMidiNoteAsKeyInTwelveKeyRange;
    int startOctave;
    double entireDistance;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<ScaleFrequenciesOverlay> scaleFrequenciesOverlay;
    std::unique_ptr<NoteAndFrequencyOverlay> noteAndFreqOverlay;
    std::unique_ptr<KeyboardVisualControlsOverlay> controlsOverlay;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KeyboardVisual)
};

//[EndFile] You can add extra defines here...
//[/EndFile]


/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.1

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
//class NoteAndFrequencyOverlay;

#include "../ComponentWithReferenceToData.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class KeyboardVisual  : public ComponentWithReferenceToData,
                        public juce::Slider::Listener
{
public:
    //==============================================================================
    KeyboardVisual (ProcessorData *dataReference);
    ~KeyboardVisual() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setKeyboardSettings(int firstMidiNote, int lastMidiNote, int width, int height);

    int getFirstMidiNote();
    int getLastMidiNote();

    double ConvertDiscreteMidiNoteToPercentWidth(int discreteMidiNote);
    double ConvertDiscreteMidiNoteToPercentWidth(int discreteMidiNote, int& keyDistanceIndex);

    double ConvertContinuousMidiNoteToPercentWidth(double continousMidiNote);

//    double ConvertPixelsToContinuousMidiNote(int xPosition);
//    double ConvertPercentWidthToContinuousMidiNote(double percentWidth);
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;
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
    std::unique_ptr<juce::Slider> highest;
    std::unique_ptr<juce::Slider> lowest;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KeyboardVisual)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.8

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>

class KeyboardVisual;

#include "KeyboardVisual.h"
#include "../../ProcessorData.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class KeyboardVisualControlsOverlay  : public ComponentWithReferenceToData,
                                       public juce::AudioProcessorValueTreeState::Listener,
                                       public juce::Button::Listener
{
public:
    //==============================================================================
    KeyboardVisualControlsOverlay (ProcessorData *dataReference, KeyboardVisual *keyboardVis);
    ~KeyboardVisualControlsOverlay() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void parameterChanged (const String &parameterID, float newValue) override;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    KeyboardVisual *keyboard;

    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> viewStartingMidiNoteAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> viewEndingMidiNoteAttachment;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Slider> viewStartingMidiNote;
    std::unique_ptr<juce::Slider> viewEndingMidiNote;
    std::unique_ptr<juce::Viewport> visualOptionsViewport;
    std::unique_ptr<juce::ToggleButton> showVisualOptionsToggle;
    std::unique_ptr<juce::TextButton> viewZoomIn;
    std::unique_ptr<juce::TextButton> viewZoomOut;
    std::unique_ptr<juce::TextButton> viewShiftRight;
    std::unique_ptr<juce::TextButton> viewShiftLeft;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KeyboardVisualControlsOverlay)
};

//[EndFile] You can add extra defines here...
//[/EndFile]


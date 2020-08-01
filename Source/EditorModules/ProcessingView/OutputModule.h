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

#include "../../ComponentWithReferenceToData.h"
//[/Headers]

#include "../../Components/MIDIChannelStatusAndToggle.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class OutputModule  : public ComponentWithReferenceToData,
                      public juce::Slider::Listener,
                      public juce::ComboBox::Listener,
                      public juce::Button::Listener
{
public:
    //==============================================================================
    OutputModule (ProcessorData *dataReference);
    ~OutputModule() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> outputPitchbendAttachment;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Slider> out_pitch_bend_range;
    std::unique_ptr<juce::Label> label;
    std::unique_ptr<juce::Label> section_title;
    std::unique_ptr<juce::Label> juce__label;
    std::unique_ptr<juce::Slider> juce__slider;
    std::unique_ptr<juce::Label> label2;
    std::unique_ptr<juce::ComboBox> singleChannelPriorityModifier2;
    std::unique_ptr<juce::Label> juce__label2;
    std::unique_ptr<juce::Label> juce__label3;
    std::unique_ptr<MIDIChannelStatusAndToggle> juce__component;
    std::unique_ptr<juce::ToggleButton> juce__toggleButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OutputModule)
};

//[EndFile] You can add extra defines here...
//[/EndFile]


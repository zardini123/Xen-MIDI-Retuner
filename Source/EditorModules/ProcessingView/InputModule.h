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

#include "../../ComponentWithReferenceToData.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class InputModule  : public ComponentWithReferenceToData,
                     public juce::ComboBox::Listener
{
public:
    //==============================================================================
    InputModule (ProcessorData *dataReference);
    ~InputModule() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> inputPitchbendAttachment;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Slider> keyboard_pitch_bend_range;
    std::unique_ptr<juce::Label> label3;
    std::unique_ptr<juce::Label> section_title;
    std::unique_ptr<juce::ComboBox> keyboard_channel;
    std::unique_ptr<juce::Label> label5;
    std::unique_ptr<juce::Label> label6;
    std::unique_ptr<juce::ComboBox> keyboard_channel2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (InputModule)
};

//[EndFile] You can add extra defines here...
//[/EndFile]


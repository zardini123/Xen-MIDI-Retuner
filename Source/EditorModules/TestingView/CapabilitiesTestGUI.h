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
//[/Headers]

#include "MIDIChannelToolbar.h"
#include "ActionButtonAndStatus.h"
#include "ActionButtonAndStatus.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class CapabilitiesTestGUI  : public ComponentWithReferenceToData,
                             public juce::Button::Listener,
                             public juce::Slider::Listener
{
public:
    //==============================================================================
    CapabilitiesTestGUI (ProcessorData *dataReference);
    ~CapabilitiesTestGUI() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Label> section_title;
    std::unique_ptr<juce::TextButton> run_all_tests_for_all_channels;
    std::unique_ptr<juce::Label> listening_header;
    std::unique_ptr<juce::Label> broadcasting_header;
    std::unique_ptr<juce::Label> label6;
    std::unique_ptr<juce::Label> label8;
    std::unique_ptr<juce::TextButton> start_all_test_listeners;
    std::unique_ptr<juce::TextButton> stop_all_test_listeners;
    std::unique_ptr<juce::Slider> timeout_slider;
    std::unique_ptr<juce::Label> timeout_slider_label;
    std::unique_ptr<juce::Label> label2;
    std::unique_ptr<juce::Label> label4;
    std::unique_ptr<juce::Viewport> viewport;
    std::unique_ptr<juce::Label> label;
    std::unique_ptr<MIDIChannelToolbar> component;
    std::unique_ptr<juce::TextButton> run_all_tests;
    std::unique_ptr<ActionButtonAndStatus> component2;
    std::unique_ptr<ActionButtonAndStatus> component3;
    std::unique_ptr<juce::TextButton> textButton3;
    std::unique_ptr<juce::TextButton> textButton4;
    std::unique_ptr<juce::TextButton> textButton5;
    std::unique_ptr<juce::TextButton> start_test_listeners_for_all_channels;
    std::unique_ptr<juce::TextButton> stop_test_listeners_for_all_channels;
    std::unique_ptr<juce::ToggleButton> autostart_all_listeners;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CapabilitiesTestGUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]


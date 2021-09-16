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
class OutputModule  : public ComponentWithReferenceToData,
                      public juce::AudioProcessorValueTreeState::Listener,
                      public juce::ComboBox::Listener,
                      public juce::Button::Listener
{
public:
    //==============================================================================
    OutputModule (ProcessorData *dataReference);
    ~OutputModule() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void parameterChanged (const String &parameterID, float newValue) override;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> outputPitchbendAttachment;

    std::unique_ptr<AudioProcessorValueTreeState::ComboBoxAttachment> tunedNotePerKeyboardChannelAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::ComboBoxAttachment> tunedNotePerKeyboardChannelModifierAttachment;

    std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> sendOutUntunedNotesAttachment;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Slider> synthPitchBendRange;
    std::unique_ptr<juce::Label> label;
    std::unique_ptr<juce::Label> section_title;
    std::unique_ptr<juce::ComboBox> synth_channel;
    std::unique_ptr<juce::Label> label2;
    std::unique_ptr<juce::ToggleButton> sendOutUntunedNotes;
    std::unique_ptr<juce::Label> juce__label;
    std::unique_ptr<juce::Label> label4;
    std::unique_ptr<juce::ComboBox> tunedNotePerKeyboardChannel;
    std::unique_ptr<juce::Label> label3;
    std::unique_ptr<juce::ComboBox> tunedNotePerKeyboardChannelModifier;
    std::unique_ptr<juce::ComboBox> synth_midi_type;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OutputModule)
};

//[EndFile] You can add extra defines here...
//[/EndFile]


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
class KeyboardVisualOptions  : public ComponentWithReferenceToData,
                               public juce::Button::Listener,
                               public juce::ComboBox::Listener
{
public:
    //==============================================================================
    KeyboardVisualOptions (ProcessorData *dataReference);
    ~KeyboardVisualOptions() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    std::unique_ptr<AudioProcessorValueTreeState::ComboBoxAttachment> midiChannelAttachment;

    std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> enableInputMIDINotesAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> enableChannelPriorityNoteAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> enableScaleAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> enablePriorityNoteSnappedToScaleAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> enableOutputMIDIPriorityNoteAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> enableOutputPitchbendRangeAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> enableInputPitchbendRangeAttachment;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::ToggleButton> enableInputMIDINotes;
    std::unique_ptr<juce::Label> midiChannelLabel;
    std::unique_ptr<juce::ComboBox> midiChannel;
    std::unique_ptr<juce::ToggleButton> enableChannelPriorityNote;
    std::unique_ptr<juce::ToggleButton> enableScale;
    std::unique_ptr<juce::ToggleButton> enablePriorityNoteSnappedToScale;
    std::unique_ptr<juce::ToggleButton> enableOutputMIDIPriorityNote;
    std::unique_ptr<juce::ToggleButton> enableOutputPitchbendRange;
    std::unique_ptr<juce::ToggleButton> enableInputPitchbendRange;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KeyboardVisualOptions)
};

//[EndFile] You can add extra defines here...
//[/EndFile]


/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.5

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PluginGUI  : public Component,
                   public Button::Listener,
                   public Slider::Listener
{
public:
    //==============================================================================
    PluginGUI ();
    ~PluginGUI();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    XenMidiRetunerAudioProcessor *processor;
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<GroupComponent> groupComponent2;
    std::unique_ptr<GroupComponent> groupComponent;
    std::unique_ptr<TextButton> scala_button;
    std::unique_ptr<Label> scala_file_label;
    std::unique_ptr<TextButton> kbm_button;
    std::unique_ptr<Label> kbm_file_label;
    std::unique_ptr<TextButton> tun_button;
    std::unique_ptr<Label> tun_file_label;
    std::unique_ptr<TextButton> apply_tun_file;
    std::unique_ptr<TextButton> apply_scala_files;
    std::unique_ptr<Slider> out_pitch_bend_range;
    std::unique_ptr<Label> label;
    std::unique_ptr<TextButton> textButton;
    std::unique_ptr<Label> label2;
    std::unique_ptr<TextEditor> textEditor;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginGUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]


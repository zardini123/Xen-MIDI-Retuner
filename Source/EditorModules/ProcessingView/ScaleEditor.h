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

#include "../../ComponentWithReferenceToData.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ScaleEditor  : public ComponentWithReferenceToData,
                     public ChangeListener,
                     public juce::Button::Listener
{
public:
    //==============================================================================
    ScaleEditor (ProcessorData *dataReference);
    ~ScaleEditor() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void changeListenerCallback (ChangeBroadcaster *source) override;
    void setScaleLabel();
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Label> label;
    std::unique_ptr<juce::TextButton> importTunFile;
    std::unique_ptr<juce::TextButton> resetScaleButton;
    std::unique_ptr<juce::HyperlinkButton> hyperlinkButton;
    std::unique_ptr<juce::Label> scale_name_label;
    std::unique_ptr<juce::Label> juce__label;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScaleEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]


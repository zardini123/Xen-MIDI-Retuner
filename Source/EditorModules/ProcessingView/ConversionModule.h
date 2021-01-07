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

#include "../../Components/TransitionCurveGUI.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ConversionModule  : public ComponentWithReferenceToData,
                          public juce::AudioProcessorValueTreeState::Listener
{
public:
    //==============================================================================
    ConversionModule (ProcessorData *dataReference);
    ~ConversionModule() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void parameterChanged (const String &parameterID, float newValue) override;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> curveTransitionAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> curveMidpointAttachment;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Label> sectionTitle;
    std::unique_ptr<TransitionCurveGUI> transitionCurveGUI;
    std::unique_ptr<juce::Slider> transitionSlider;
    std::unique_ptr<juce::Label> transitionLabel;
    std::unique_ptr<juce::Slider> midpointSlider;
    std::unique_ptr<juce::Label> midpointLabel;
    std::unique_ptr<juce::Label> snappingCurveLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ConversionModule)
};

//[EndFile] You can add extra defines here...
//[/EndFile]


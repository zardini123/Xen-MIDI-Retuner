/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.7

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
//[/Headers]

#include "Components/TransitionCurve.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ConversionModule  : public Component,
                          public Slider::Listener
{
public:
    //==============================================================================
    ConversionModule ();
    ~ConversionModule() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    TransitionCurve *getTransitionCurve();
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Label> section_title;
    std::unique_ptr<Component> transitionCurve;
    std::unique_ptr<Slider> slider;
    std::unique_ptr<Label> label;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ConversionModule)
};

//[EndFile] You can add extra defines here...
//[/EndFile]


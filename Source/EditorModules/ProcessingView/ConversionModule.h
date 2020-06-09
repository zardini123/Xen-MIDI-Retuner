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

#include "../../ProcessorData.h"
//[/Headers]

#include "../../Components/TransitionCurveGUI.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ConversionModule  : public Component,
                          public Slider::Listener,
                          public ComboBox::Listener
{
public:
    //==============================================================================
    ConversionModule ();
    ~ConversionModule() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Label> label;
    std::unique_ptr<Label> section_title;
    std::unique_ptr<TransitionCurveGUI> transitionCurveGUI;
    std::unique_ptr<Slider> transitionSlider;
    std::unique_ptr<Label> label2;
    std::unique_ptr<Slider> midpointSlider;
    std::unique_ptr<Label> label3;
    std::unique_ptr<Label> label5;
    std::unique_ptr<ComboBox> interploationDimension;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ConversionModule)
};

//[EndFile] You can add extra defines here...
//[/EndFile]


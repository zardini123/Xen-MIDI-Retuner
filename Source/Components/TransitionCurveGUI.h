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
#include <map>

#include "TransitionCurve.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TransitionCurveGUI  : public Component
{
public:
    //==============================================================================
    TransitionCurveGUI (TransitionCurve *transitionCurve);
    ~TransitionCurveGUI() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    int getHorizontalMargin();
    int getVerticalMargin();
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Point<float> convertPercentsToPixels(Point<float> percentsPoint);
    TransitionCurve *curve = nullptr;

    int horizontalMargin = 10;
    int verticalMargin = 10;

    Path internalPath;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TransitionCurveGUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]


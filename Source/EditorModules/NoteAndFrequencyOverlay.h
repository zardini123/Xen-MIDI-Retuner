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

//// Forward declare class as cyclic dependency results in "undeclared identifier" errors
//// https://www.eventhelix.com/RealtimeMantra/HeaderFileIncludePatterns.htm
//class KeyboardVisual;

#include "KeyboardVisual.h"
#include "../ProcessorData.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class NoteAndFrequencyOverlay  : public Component,
                                 private Timer
{
public:
    //==============================================================================
    NoteAndFrequencyOverlay (KeyboardVisual *keyboardVis);
    ~NoteAndFrequencyOverlay() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    const int UPDATE_RATE = 60;

    KeyboardVisual *keyboard;

    double time;

    void timerCallback() override;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NoteAndFrequencyOverlay)
};

//[EndFile] You can add extra defines here...
//[/EndFile]


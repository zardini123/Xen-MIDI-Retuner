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

class KeyboardVisual;

#include "KeyboardVisual.h"
#include "../../ProcessorData.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ScaleFrequenciesOverlay  : public ComponentWithReferenceToData,
                                 public juce::ChangeListener,
                                 private Timer
{
public:
    //==============================================================================
    ScaleFrequenciesOverlay (ProcessorData *dataReference, KeyboardVisual *keyboardVis);
    ~ScaleFrequenciesOverlay() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    virtual void changeListenerCallback (ChangeBroadcaster *source) override;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    KeyboardVisual *keyboard;

    void timerCallback() override;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScaleFrequenciesOverlay)
};

//[EndFile] You can add extra defines here...
//[/EndFile]


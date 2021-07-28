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

#include "../ComponentWithReferenceToData.h"
//[/Headers]

#include "ProcessingView/InputModule.h"
#include "ProcessingView/ScaleEditor.h"
#include "ProcessingView/ConversionModule.h"
#include "ProcessingView/OutputModule.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ProcessingView  : public ComponentWithReferenceToData
{
public:
    //==============================================================================
    ProcessingView (ProcessorData *dataReference);
    ~ProcessingView() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<InputModule> component;
    std::unique_ptr<ScaleEditor> component2;
    std::unique_ptr<ConversionModule> conversionModule;
    std::unique_ptr<OutputModule> component3;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ProcessingView)
};

//[EndFile] You can add extra defines here...
//[/EndFile]


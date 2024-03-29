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
#include "ComponentWithReferenceToData.h"
#include "PluginProcessor.h"
//[/Headers]

#include "EditorModules/KeyboardVisual/KeyboardVisual.h"
#include "EditorModules/KeyboardVisual/ScaleFrequenciesOverlay.h"
#include "EditorModules/ProcessingView.h"
#include "EditorModules/KeyboardVisual/KeyboardVisualControlsOverlay.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PluginGUI  : public ComponentWithReferenceToData
{
public:
    //==============================================================================
    PluginGUI (ProcessorData *dataReference);
    ~PluginGUI() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    TooltipWindow tooltipWindow;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<KeyboardVisual> keyboardVisual;
    std::unique_ptr<ScaleFrequenciesOverlay> scaleFrequenciesOverlay;
    std::unique_ptr<ProcessingView> processingView;
    std::unique_ptr<KeyboardVisualControlsOverlay> controlsOverlay;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginGUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]


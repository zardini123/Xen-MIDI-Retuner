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
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//[/Headers]

#include "EditorModules/KeyboardVisual.h"
#include "EditorModules/ScaleFrequenciesOverlay.h"
#include "EditorModules/NoteAndFrequencyOverlay.h"
#include "EditorModules/InputModule.h"
#include "EditorModules/ScaleEditor.h"
#include "EditorModules/ConversionModule.h"
#include "EditorModules/OutputModule.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PluginGUI  : public Component
{
public:
    //==============================================================================
    PluginGUI (XenMidiRetunerAudioProcessor *processorA);
    ~PluginGUI() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    XenMidiRetunerAudioProcessor *processor;
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<KeyboardVisual> keyboardVisual;
    std::unique_ptr<ScaleFrequenciesOverlay> scaleFrequenciesOverlay;
    std::unique_ptr<NoteAndFrequencyOverlay> noteAndFreqOverlay;
    std::unique_ptr<InputModule> component;
    std::unique_ptr<ScaleEditor> component2;
    std::unique_ptr<ConversionModule> conversionModule;
    std::unique_ptr<OutputModule> component3;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginGUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]


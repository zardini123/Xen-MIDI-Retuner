/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
#include "../../ProcessorStructures.h"
#include "../../ProcessorData.h"
#include "../../ComponentWithReferenceToData.h"

//// Forward declare class as cyclic dependency results in "undeclared identifier" errors
//// https://www.eventhelix.com/RealtimeMantra/HeaderFileIncludePatterns.htm
//class ActionButtonAndStatusTracker;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ActionButtonAndStatus  : public ComponentWithReferenceToData,
                               public ChangeListener,
                               public juce::Button::Listener
{
public:
    //==============================================================================
    ActionButtonAndStatus (ProcessorData *dataReference);
    ~ActionButtonAndStatus() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    ActionButtonAndStatus(ProcessorData *dataReference, MIDIEnviromentTestType testType, MIDIEnviromentTestOperationType operationType);

    void changeListenerCallback(ChangeBroadcaster *source) override;

    void attachListenerToActionButton(Button::Listener *theListener);

    void setActionName(std::string action);
    void setStatus(Status status, double percentage);
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    double progress;
    MIDIEnviromentTestID testID;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::TextButton> actionButton;
    std::unique_ptr<ProgressBar> statusBar;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ActionButtonAndStatus)
};

//[EndFile] You can add extra defines here...
//[/EndFile]


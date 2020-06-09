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
#include "../../ProcessorStructures.h"
#include "../../ProcessorData.h"

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
class ActionButtonAndStatus  : public Component,
                               public ChangeListener,
                               public Button::Listener
{
public:
    //==============================================================================
    ActionButtonAndStatus ();
    ~ActionButtonAndStatus() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    ActionButtonAndStatus(MIDIEnviromentTestType testType, MIDIEnviromentTestOperationType operationType);

    void changeListenerCallback(ChangeBroadcaster *source) override;

    void attachListenerToActionButton(Button::Listener *theListener);

    void setActionName(std::string action);
    void setStatus(Status status, double percentage);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    double progress;
    MIDIEnviromentTestID testID;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<TextButton> actionButton;
    std::unique_ptr<ProgressBar> statusBar;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ActionButtonAndStatus)
};

//[EndFile] You can add extra defines here...
//[/EndFile]


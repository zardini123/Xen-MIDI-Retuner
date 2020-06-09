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
#include "../../Utilities.h"
//[/Headers]

#include "ActionButtonAndStatus.h"
#include "ActionButtonAndStatus.h"
#include "ActionButtonAndStatus.h"
#include "ActionButtonAndStatus.h"
#include "ActionButtonAndStatus.h"
#include "ActionButtonAndStatus.h"
#include "ActionButtonAndStatus.h"
#include "ActionButtonAndStatus.h"
#include "ActionButtonAndStatus.h"
#include "ActionButtonAndStatus.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TestList  : public Component
{
public:
    //==============================================================================
    TestList ();
    ~TestList() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<ActionButtonAndStatus> note_velocity_broadcaster_action;
    std::unique_ptr<ActionButtonAndStatus> pitch_bend_broadcaster_action;
    std::unique_ptr<ActionButtonAndStatus> channel_aftertouch_broadcaster_action;
    std::unique_ptr<ActionButtonAndStatus> control_change_broadcaster_action;
    std::unique_ptr<ActionButtonAndStatus> poly_aftertouch_broadcaster_action;
    std::unique_ptr<ActionButtonAndStatus> note_velocity_listener_action;
    std::unique_ptr<ActionButtonAndStatus> pitch_bend_listener_action;
    std::unique_ptr<ActionButtonAndStatus> channel_aftertouch_listener_action;
    std::unique_ptr<ActionButtonAndStatus> control_change_listener_action;
    std::unique_ptr<ActionButtonAndStatus> poly_aftertouch_listener_action;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TestList)
};

//[EndFile] You can add extra defines here...
//[/EndFile]


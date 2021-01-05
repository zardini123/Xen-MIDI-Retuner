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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "TestList.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TestList::TestList (ProcessorData *dataReference)
    : ComponentWithReferenceToData (dataReference)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    note_velocity_broadcaster_action.reset (new ActionButtonAndStatus (data, NOTE_AND_VELOCITY, BROADCASTER));
    addAndMakeVisible (note_velocity_broadcaster_action.get());
    pitch_bend_broadcaster_action.reset (new ActionButtonAndStatus (data));
    addAndMakeVisible (pitch_bend_broadcaster_action.get());
    channel_aftertouch_broadcaster_action.reset (new ActionButtonAndStatus (data));
    addAndMakeVisible (channel_aftertouch_broadcaster_action.get());
    control_change_broadcaster_action.reset (new ActionButtonAndStatus (data));
    addAndMakeVisible (control_change_broadcaster_action.get());
    poly_aftertouch_broadcaster_action.reset (new ActionButtonAndStatus (data));
    addAndMakeVisible (poly_aftertouch_broadcaster_action.get());
    note_velocity_listener_action.reset (new ActionButtonAndStatus (data, NOTE_AND_VELOCITY, LISTENER));
    addAndMakeVisible (note_velocity_listener_action.get());
    pitch_bend_listener_action.reset (new ActionButtonAndStatus (data));
    addAndMakeVisible (pitch_bend_listener_action.get());
    channel_aftertouch_listener_action.reset (new ActionButtonAndStatus (data));
    addAndMakeVisible (channel_aftertouch_listener_action.get());
    control_change_listener_action.reset (new ActionButtonAndStatus (data));
    addAndMakeVisible (control_change_listener_action.get());
    poly_aftertouch_listener_action.reset (new ActionButtonAndStatus (data));
    addAndMakeVisible (poly_aftertouch_listener_action.get());

    //[UserPreSize]
    //[/UserPreSize]

    setSize (200, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

TestList::~TestList()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    note_velocity_broadcaster_action = nullptr;
    pitch_bend_broadcaster_action = nullptr;
    channel_aftertouch_broadcaster_action = nullptr;
    control_change_broadcaster_action = nullptr;
    poly_aftertouch_broadcaster_action = nullptr;
    note_velocity_listener_action = nullptr;
    pitch_bend_listener_action = nullptr;
    channel_aftertouch_listener_action = nullptr;
    control_change_listener_action = nullptr;
    poly_aftertouch_listener_action = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TestList::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TestList::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    note_velocity_broadcaster_action->setBounds (proportionOfWidth (0.5000f), 1, proportionOfWidth (0.5000f), 24);
    pitch_bend_broadcaster_action->setBounds (proportionOfWidth (0.5000f), 24, proportionOfWidth (0.5000f), 24);
    channel_aftertouch_broadcaster_action->setBounds (proportionOfWidth (0.5000f), 48, proportionOfWidth (0.5000f), 24);
    control_change_broadcaster_action->setBounds (proportionOfWidth (0.5000f), 72, proportionOfWidth (0.5000f), 24);
    poly_aftertouch_broadcaster_action->setBounds (proportionOfWidth (0.5000f), 96, proportionOfWidth (0.5000f), 24);
    note_velocity_listener_action->setBounds (proportionOfWidth (0.0000f), 0, proportionOfWidth (0.5000f), 24);
    pitch_bend_listener_action->setBounds (proportionOfWidth (0.0000f), 24, proportionOfWidth (0.5000f), 24);
    channel_aftertouch_listener_action->setBounds (proportionOfWidth (0.0000f), 48, proportionOfWidth (0.5000f), 24);
    control_change_listener_action->setBounds (proportionOfWidth (0.0000f), 72, proportionOfWidth (0.5000f), 24);
    poly_aftertouch_listener_action->setBounds (proportionOfWidth (0.0000f), 96, proportionOfWidth (0.5000f), 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TestList" componentName=""
                 parentClasses="public ComponentWithReferenceToData" constructorParams="ProcessorData *dataReference"
                 variableInitialisers="ComponentWithReferenceToData (dataReference)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="200" initialHeight="400">
  <BACKGROUND backgroundColour="ff00c1"/>
  <JUCERCOMP name="" id="8ab3a91cf9f16b4c" memberName="note_velocity_broadcaster_action"
             virtualName="" explicitFocusOrder="0" pos="50% 1 50% 24" sourceFile="ActionButtonAndStatus.cpp"
             constructorParams="data, NOTE_AND_VELOCITY, BROADCASTER"/>
  <JUCERCOMP name="" id="cdd446f78c157c7" memberName="pitch_bend_broadcaster_action"
             virtualName="" explicitFocusOrder="0" pos="50% 24 50% 24" sourceFile="ActionButtonAndStatus.cpp"
             constructorParams="data"/>
  <JUCERCOMP name="" id="64e7b5de6dc3428d" memberName="channel_aftertouch_broadcaster_action"
             virtualName="" explicitFocusOrder="0" pos="50% 48 50% 24" sourceFile="ActionButtonAndStatus.cpp"
             constructorParams="data"/>
  <JUCERCOMP name="" id="ae6ef277b4290cd" memberName="control_change_broadcaster_action"
             virtualName="" explicitFocusOrder="0" pos="50% 72 50% 24" sourceFile="ActionButtonAndStatus.cpp"
             constructorParams="data"/>
  <JUCERCOMP name="" id="daf629722121eaab" memberName="poly_aftertouch_broadcaster_action"
             virtualName="" explicitFocusOrder="0" pos="50% 96 50% 24" sourceFile="ActionButtonAndStatus.cpp"
             constructorParams="data"/>
  <JUCERCOMP name="" id="3ecb3114d4853cf3" memberName="note_velocity_listener_action"
             virtualName="" explicitFocusOrder="0" pos="0% 0 50% 24" sourceFile="ActionButtonAndStatus.cpp"
             constructorParams="data, NOTE_AND_VELOCITY, LISTENER"/>
  <JUCERCOMP name="" id="3baf8ad16a706496" memberName="pitch_bend_listener_action"
             virtualName="" explicitFocusOrder="0" pos="0% 24 50% 24" sourceFile="ActionButtonAndStatus.cpp"
             constructorParams="data"/>
  <JUCERCOMP name="" id="7720dded8ca7f090" memberName="channel_aftertouch_listener_action"
             virtualName="" explicitFocusOrder="0" pos="0% 48 50% 24" sourceFile="ActionButtonAndStatus.cpp"
             constructorParams="data"/>
  <JUCERCOMP name="" id="bcfe5cfc33f9aa79" memberName="control_change_listener_action"
             virtualName="" explicitFocusOrder="0" pos="0% 72 50% 24" sourceFile="ActionButtonAndStatus.cpp"
             constructorParams="data"/>
  <JUCERCOMP name="" id="cfffcb61eaa046" memberName="poly_aftertouch_listener_action"
             virtualName="" explicitFocusOrder="0" pos="0% 96 50% 24" sourceFile="ActionButtonAndStatus.cpp"
             constructorParams="data"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


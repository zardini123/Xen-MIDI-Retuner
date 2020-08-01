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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "MIDIChannelStatusAndToggle.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MIDIChannelStatusAndToggle::MIDIChannelStatusAndToggle ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    channel1.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (channel1.get());
    channel1->setButtonText (TRANS("1"));
    channel1->addListener (this);

    allMidiChannels.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (allMidiChannels.get());
    allMidiChannels->setButtonText (TRANS("All"));
    allMidiChannels->addListener (this);

    noMidiChannels.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (noMidiChannels.get());
    noMidiChannels->setButtonText (TRANS("None"));
    noMidiChannels->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MIDIChannelStatusAndToggle::~MIDIChannelStatusAndToggle()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    channel1 = nullptr;
    allMidiChannels = nullptr;
    noMidiChannels = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MIDIChannelStatusAndToggle::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        int x = -4, y = 52, width = proportionOfWidth (1.0000f), height = 1;
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 4, y = 60, width = 16, height = 16;
        juce::Colour fillColour = juce::Colour (0xfffff400);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MIDIChannelStatusAndToggle::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    channel1->setBounds (0, 56, proportionOfWidth (1.0000f), 24);
    allMidiChannels->setBounds (0, 0, proportionOfWidth (1.0000f), 24);
    noMidiChannels->setBounds (0, 24, proportionOfWidth (1.0000f), 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MIDIChannelStatusAndToggle::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == channel1.get())
    {
        //[UserButtonCode_channel1] -- add your button handler code here..
        //[/UserButtonCode_channel1]
    }
    else if (buttonThatWasClicked == allMidiChannels.get())
    {
        //[UserButtonCode_allMidiChannels] -- add your button handler code here..
        //[/UserButtonCode_allMidiChannels]
    }
    else if (buttonThatWasClicked == noMidiChannels.get())
    {
        //[UserButtonCode_noMidiChannels] -- add your button handler code here..
        //[/UserButtonCode_noMidiChannels]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MIDIChannelStatusAndToggle"
                 componentName="" parentClasses="public juce::Component" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="323e44">
    <RECT pos="-4 52 100% 1" fill="solid: ffffffff" hasStroke="0"/>
    <RECT pos="4 60 16 16" fill="solid: fffff400" hasStroke="0"/>
  </BACKGROUND>
  <TOGGLEBUTTON name="new toggle button" id="376d0814ad9a71a7" memberName="channel1"
                virtualName="" explicitFocusOrder="0" pos="0 56 100% 24" buttonText="1"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="new button" id="6a187000ddb03320" memberName="allMidiChannels"
              virtualName="" explicitFocusOrder="0" pos="0 0 100% 24" buttonText="All"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="1f30330a68bcba9f" memberName="noMidiChannels"
              virtualName="" explicitFocusOrder="0" pos="0 24 100% 24" buttonText="None"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


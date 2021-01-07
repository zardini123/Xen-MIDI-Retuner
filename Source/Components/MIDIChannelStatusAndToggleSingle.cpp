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

#include "MIDIChannelStatusAndToggleSingle.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MIDIChannelStatusAndToggleSingle::MIDIChannelStatusAndToggleSingle ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    juce__toggleButton.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (juce__toggleButton.get());
    juce__toggleButton->setButtonText (TRANS("<ch>"));
    juce__toggleButton->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 24);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MIDIChannelStatusAndToggleSingle::~MIDIChannelStatusAndToggleSingle()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    juce__toggleButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MIDIChannelStatusAndToggleSingle::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        float x = 4.0f, y = 4.0f, width = 16.0f, height = 16.0f;
        juce::Colour fillColour = juce::Colour (0xfff9ff00);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 6.500f);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MIDIChannelStatusAndToggleSingle::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    juce__toggleButton->setBounds (0, 0, proportionOfWidth (1.0000f), 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MIDIChannelStatusAndToggleSingle::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == juce__toggleButton.get())
    {
        //[UserButtonCode_juce__toggleButton] -- add your button handler code here..
        //[/UserButtonCode_juce__toggleButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void MIDIChannelStatusAndToggleSingle::setCannel(int channel)
{
    juce__toggleButton->setButtonText (TRANS(std::to_string(channel)));
    midiChannel = channel;
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MIDIChannelStatusAndToggleSingle"
                 componentName="" parentClasses="public juce::Component" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="600" initialHeight="24">
  <BACKGROUND backgroundColour="323e44">
    <ROUNDRECT pos="4 4 16 16" cornerSize="6.5" fill="solid: fff9ff00" hasStroke="0"/>
  </BACKGROUND>
  <TOGGLEBUTTON name="new toggle button" id="235ccfc4ecc06ea6" memberName="juce__toggleButton"
                virtualName="" explicitFocusOrder="0" pos="0 0 100% 24" buttonText="&lt;ch&gt;"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


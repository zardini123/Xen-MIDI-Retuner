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

#include "MIDIChannelToolbar.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MIDIChannelToolbar::MIDIChannelToolbar ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    for (int i = 0; i < MIDI_CHANNELS; i++)
    {
        buttons[i].reset (new TextButton ("new button"));
        addAndMakeVisible (buttons[i].get());
        buttons[i]->setButtonText (TRANS(std::to_string(i + 1)));
        buttons[i]->addListener (this);

        buttons[i]->setColour (TextButton::buttonColourId, Colour (0xff3c3c3c));
    }
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    setSelectedChannel(1);
    //[/Constructor]
}

MIDIChannelToolbar::~MIDIChannelToolbar()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MIDIChannelToolbar::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MIDIChannelToolbar::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    float width = 1 / (float)MIDI_CHANNELS;
    for (int i = 0; i < MIDI_CHANNELS; i++)
    {
        buttons[i]->setBounds (proportionOfWidth (i / (float)MIDI_CHANNELS), 0, proportionOfWidth (width), proportionOfHeight (1.0000f));
    }
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void MIDIChannelToolbar::buttonClicked (Button* buttonThatWasClicked)
{
    int buttonIndex = 0;
    for (int i = 0; i < MIDI_CHANNELS; i++)
    {
        if (buttonThatWasClicked == buttons[i].get())
        {
            buttonIndex = i;
        }
    }

    setSelectedChannel(buttonIndex + 1);
}


/// Sets selected midi channel in GUI.
/// @param channel Channels range from 1 to 16
void MIDIChannelToolbar::setSelectedChannel(int channel)
{
    for (int i = 0; i < MIDI_CHANNELS; i++)
    {
        if (i == (channel - 1))
        {
            // Selected
            buttons[i]->setColour (TextButton::buttonColourId, Colour (0xffababab));
        } else
        {
            // Unselected
            buttons[i]->setColour (TextButton::buttonColourId, Colour (0xff3c3c3c));
        }
    }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MIDIChannelToolbar" componentName=""
                 parentClasses="public Component, public Button::Listener" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff00db"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


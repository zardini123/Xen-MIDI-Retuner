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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "KeyboardVisual.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
double keyDistances[13];

void SetEqualSpacingValues()
{
    for (int i = 0; i < 13; i++)
    {
        bool previousNoteWhite = !MidiMessage::isMidiNoteBlack(i + 59);
        bool noteWhite = !MidiMessage::isMidiNoteBlack(i + 60);
        bool doubleWhite = previousNoteWhite && noteWhite;
        
        int lastIndex = i - 1;
        keyDistances[i] = ((i == 0)? 0 : (doubleWhite? 1.0 : 0.5)) + ((lastIndex >= 0)? keyDistances[lastIndex] : 0);
    }
    for (int i = 0; i < 13; i++) {
        keyDistances[i] /= keyDistances[11];
    }
}
//[/MiscUserDefs]

//==============================================================================
KeyboardVisual::KeyboardVisual ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    SetEqualSpacingValues();
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

KeyboardVisual::~KeyboardVisual()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void KeyboardVisual::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xffff0892));

    {
        int x = 4, y = 4, width = 36, height = 36;
        Colour fillColour = Colour (0xffa5302a);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 652, y = 4, width = 36, height = 36;
        Colour fillColour = Colour (0xffa5302a);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    //[UserPaint] Add your own custom painting code here..
    int keyWidth = 20,
        entireWidth = keyWidth * 12;
    for (int i = 0; i < 13; i++)
    {
        int x = keyDistances[i] * entireWidth, y = 0, height = 36;
        Colour fillColour = Colour (MidiMessage::isMidiNoteBlack(i + 60)? 0xff000000 : 0xffffffff);
        g.setColour (fillColour);
        g.fillRect (x, y, keyWidth, height);
    }
    //[/UserPaint]
}

void KeyboardVisual::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

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

<JUCER_COMPONENT documentType="Component" className="KeyboardVisual" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffff0892">
    <RECT pos="4 4 36 36" fill="solid: ffa5302a" hasStroke="0"/>
    <RECT pos="652 4 36 36" fill="solid: ffa5302a" hasStroke="0"/>
  </BACKGROUND>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


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
#include "../Utilities.h"
//[/Headers]

#include "ScaleFrequenciesOverlay.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ScaleFrequenciesOverlay::ScaleFrequenciesOverlay (KeyboardVisual *keyboardVis)
{
    //[Constructor_pre] You can add your own custom stuff here..
    keyboard = keyboardVis;
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ScaleFrequenciesOverlay::~ScaleFrequenciesOverlay()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ScaleFrequenciesOverlay::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    ProcessorData* processorData = ProcessorData::getInstance();

    int y = 0, width = 1, height = 100;
    for (auto it = processorData->scale.GetNoteFrequenciesHz().begin(); it != processorData->scale.GetNoteFrequenciesHz().end(); ++it) {
        int note;
        double semitones;
        freqHZToNoteAndSemitones((*it), note, semitones);
        float midiNote = note + semitones;

        double x = keyboard->ConvertContinuousMidiNoteToPercentWidth(midiNote) * proportionOfWidth(1.0f);
        Colour fillColour = Colour (0xffdc143c);
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ScaleFrequenciesOverlay::resized()
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

<JUCER_COMPONENT documentType="Component" className="ScaleFrequenciesOverlay"
                 componentName="" parentClasses="public Component" constructorParams="KeyboardVisual *keyboardVis"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="dc143c"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


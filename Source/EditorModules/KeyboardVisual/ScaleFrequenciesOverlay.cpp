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
#include "../../Utilities.h"
//[/Headers]

#include "ScaleFrequenciesOverlay.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ScaleFrequenciesOverlay::ScaleFrequenciesOverlay (ProcessorData *dataReference, KeyboardVisual *keyboardVis)
    : ComponentWithReferenceToData (dataReference)
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
void ScaleFrequenciesOverlay::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    Colour baseColour = Colour (0x4fe82950);
    if (data->apvts.getParameterAsValue("keyboard_visuals-enable_scale").getValue()) {
        // @TODO: Create a iterator for scale to iterate over midi note, scale note (non-mapped), and frequency order
        for (auto i = AnaMark::Scale::firstTunableScaleNote; i < AnaMark::Scale::afterLastTunableScaleNote; ++i) {
            double frequency = data->scale.FrequencyForMIDINote(i);
            keyboard->drawMarkerAtFrequencyHz(frequency, baseColour, g);
        }
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
                 componentName="" parentClasses="public ComponentWithReferenceToData"
                 constructorParams="ProcessorData *dataReference, KeyboardVisual *keyboardVis"
                 variableInitialisers="ComponentWithReferenceToData (dataReference)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="dc143c"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


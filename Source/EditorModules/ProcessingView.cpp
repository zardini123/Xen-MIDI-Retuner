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

#include "ProcessingView.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ProcessingView::ProcessingView (ProcessorData *dataReference)
    : ComponentWithReferenceToData (dataReference)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    component.reset (new InputModule (data));
    addAndMakeVisible (component.get());
    component2.reset (new ScaleEditor (data));
    addAndMakeVisible (component2.get());
    conversionModule.reset (new ConversionModule (data));
    addAndMakeVisible (conversionModule.get());
    component3.reset (new OutputModule (data));
    addAndMakeVisible (component3.get());

    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ProcessingView::~ProcessingView()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    component = nullptr;
    component2 = nullptr;
    conversionModule = nullptr;
    component3 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ProcessingView::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        int x = proportionOfWidth (0.2500f), y = 0, width = 1, height = proportionOfHeight (1.0000f);
        juce::Colour fillColour = juce::Colour (0xffb6b6b6);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = proportionOfWidth (0.7500f), y = 1, width = 1, height = proportionOfHeight (1.0000f);
        juce::Colour fillColour = juce::Colour (0xffb6b6b6);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = proportionOfWidth (0.5000f), y = 0, width = 1, height = proportionOfHeight (1.0000f);
        juce::Colour fillColour = juce::Colour (0xffb6b6b6);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ProcessingView::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    component->setBounds (0, 0, proportionOfWidth (0.2504f), proportionOfHeight (1.0000f));
    component2->setBounds (proportionOfWidth (0.2504f), 0, proportionOfWidth (0.2504f), proportionOfHeight (1.0000f));
    conversionModule->setBounds (proportionOfWidth (0.5008f), 0, proportionOfWidth (0.2504f), proportionOfHeight (1.0000f));
    component3->setBounds (proportionOfWidth (0.7496f), 0, proportionOfWidth (0.2504f), proportionOfHeight (1.0000f));
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

<JUCER_COMPONENT documentType="Component" className="ProcessingView" componentName=""
                 parentClasses="public ComponentWithReferenceToData" constructorParams="ProcessorData *dataReference"
                 variableInitialisers="ComponentWithReferenceToData (dataReference)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="323e44">
    <RECT pos="25% 0 1 100%" fill="solid: ffb6b6b6" hasStroke="0"/>
    <RECT pos="75% 1 1 100%" fill="solid: ffb6b6b6" hasStroke="0"/>
    <RECT pos="50% 0 1 100%" fill="solid: ffb6b6b6" hasStroke="0"/>
  </BACKGROUND>
  <JUCERCOMP name="" id="718dd2c51df8bc00" memberName="component" virtualName=""
             explicitFocusOrder="0" pos="0 0 25.039% 100%" sourceFile="ProcessingView/InputModule.cpp"
             constructorParams="data"/>
  <JUCERCOMP name="" id="362421b4abac7430" memberName="component2" virtualName=""
             explicitFocusOrder="0" pos="25.039% 0 25.039% 100%" sourceFile="ProcessingView/ScaleEditor.cpp"
             constructorParams="data"/>
  <JUCERCOMP name="" id="3e17f48e254318d" memberName="conversionModule" virtualName=""
             explicitFocusOrder="0" pos="50.077% 0 25.039% 100%" sourceFile="ProcessingView/ConversionModule.cpp"
             constructorParams="data"/>
  <JUCERCOMP name="" id="da4dccb613aa70d0" memberName="component3" virtualName=""
             explicitFocusOrder="0" pos="74.961% 0 25.039% 100%" sourceFile="ProcessingView/OutputModule.cpp"
             constructorParams="data"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


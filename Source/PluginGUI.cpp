/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.8

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginGUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PluginGUI::PluginGUI (ProcessorData *dataReference)
    : ComponentWithReferenceToData (dataReference)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    keyboardVisual.reset (new KeyboardVisual (data));
    addAndMakeVisible (keyboardVisual.get());
    scaleFrequenciesOverlay.reset (new ScaleFrequenciesOverlay (this->data, keyboardVisual.get()));
    addAndMakeVisible (scaleFrequenciesOverlay.get());
    processingView.reset (new ProcessingView (data));
    addAndMakeVisible (processingView.get());
    controlsOverlay.reset (new KeyboardVisualControlsOverlay (this->data, keyboardVisual.get()));
    addAndMakeVisible (controlsOverlay.get());

    //[UserPreSize]
    // Force the overlays and their children to not accept mouse events, and therefore let KeyboardVisual deal with the events
    scaleFrequenciesOverlay->setInterceptsMouseClicks(false, false);

    // Dont allow clicks on the control overlay, but allow it in the child components of the overlay
    controlsOverlay->setInterceptsMouseClicks(false, true);

    // Notify visual change to other overlays
    keyboardVisual->addChangeListener(scaleFrequenciesOverlay.get());
    //[/UserPreSize]

    setSize (1300, 450);


    //[Constructor] You can add your own custom stuff here..
//    juce__label->setText(data->logger->getLogFile().getFullPathName(), dontSendNotification);
    //[/Constructor]
}

PluginGUI::~PluginGUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    keyboardVisual = nullptr;
    scaleFrequenciesOverlay = nullptr;
    processingView = nullptr;
    controlsOverlay = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PluginGUI::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PluginGUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    keyboardVisual->setBounds (0, getHeight() - proportionOfHeight (0.2000f), proportionOfWidth (1.0000f), proportionOfHeight (0.2000f));
    scaleFrequenciesOverlay->setBounds (0 + 0, proportionOfHeight (0.7000f), juce::roundToInt (proportionOfWidth (1.0000f) * 1.0000f), juce::roundToInt (proportionOfHeight (0.2000f) * 0.6000f));
    processingView->setBounds (0, 0, proportionOfWidth (1.0000f), proportionOfHeight (0.7000f));
    controlsOverlay->setBounds (0, getHeight() - 106 - proportionOfHeight (0.0644f), proportionOfWidth (1.0000f), proportionOfHeight (0.0644f));
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

<JUCER_COMPONENT documentType="Component" className="PluginGUI" componentName=""
                 parentClasses="public ComponentWithReferenceToData" constructorParams="ProcessorData *dataReference"
                 variableInitialisers="ComponentWithReferenceToData (dataReference)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="1300" initialHeight="450">
  <BACKGROUND backgroundColour="ff323e44"/>
  <JUCERCOMP name="" id="9a893a36dc7e0c36" memberName="keyboardVisual" virtualName=""
             explicitFocusOrder="0" pos="0 0Rr 100% 20%" sourceFile="EditorModules/KeyboardVisual/KeyboardVisual.cpp"
             constructorParams="data"/>
  <JUCERCOMP name="" id="31178f5ce0e8830f" memberName="scaleFrequenciesOverlay"
             virtualName="" explicitFocusOrder="0" pos="0 70% 100% 60%" posRelativeX="9a893a36dc7e0c36"
             posRelativeW="9a893a36dc7e0c36" posRelativeH="9a893a36dc7e0c36"
             sourceFile="EditorModules/KeyboardVisual/ScaleFrequenciesOverlay.cpp"
             constructorParams="this-&gt;data, keyboardVisual.get()"/>
  <JUCERCOMP name="" id="28aad21504a460c5" memberName="processingView" virtualName=""
             explicitFocusOrder="0" pos="0 0 100% 70%" sourceFile="EditorModules/ProcessingView.cpp"
             constructorParams="data"/>
  <JUCERCOMP name="" id="21258a0fb7996dd" memberName="controlsOverlay" virtualName=""
             explicitFocusOrder="0" pos="0 106Rr 100% 6.444%" sourceFile="EditorModules/KeyboardVisual/KeyboardVisualControlsOverlay.cpp"
             constructorParams="this-&gt;data, keyboardVisual.get()"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


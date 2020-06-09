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

#include "PluginGUI.h"
#include "EditorModules/ProcessingView.h"
#include "EditorModules/TestingView.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PluginGUI::PluginGUI ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    keyboardVisual.reset (new KeyboardVisual());
    addAndMakeVisible (keyboardVisual.get());
    scaleFrequenciesOverlay.reset (new ScaleFrequenciesOverlay (keyboardVisual.get()));
    addAndMakeVisible (scaleFrequenciesOverlay.get());
    noteAndFreqOverlay.reset (new NoteAndFrequencyOverlay (keyboardVisual.get()));
    addAndMakeVisible (noteAndFreqOverlay.get());
    tabbedComponent.reset (new TabbedComponent (TabbedButtonBar::TabsAtTop));
    addAndMakeVisible (tabbedComponent.get());
    tabbedComponent->setTabBarDepth (26);
    tabbedComponent->addTab (TRANS("Processing"), Colour (0x00d3d3d3), new ProcessingView(), true);
    tabbedComponent->addTab (TRANS("Testing"), Colour (0x00d3d3d3), new TestingView(), true);
    tabbedComponent->setCurrentTabIndex (0);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (1000, 450);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PluginGUI::~PluginGUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    keyboardVisual = nullptr;
    scaleFrequenciesOverlay = nullptr;
    noteAndFreqOverlay = nullptr;
    tabbedComponent = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PluginGUI::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PluginGUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    keyboardVisual->setBounds (0, getHeight() - proportionOfHeight (0.2000f), proportionOfWidth (1.0000f), proportionOfHeight (0.2000f));
    scaleFrequenciesOverlay->setBounds (0 + 0, (getHeight() - proportionOfHeight (0.2000f)) + proportionOfHeight (0.2000f) - (roundToInt (proportionOfHeight (0.2000f) * 0.6000f)), roundToInt (proportionOfWidth (1.0000f) * 1.0000f), roundToInt (proportionOfHeight (0.2000f) * 0.6000f));
    noteAndFreqOverlay->setBounds (0 + 0, (getHeight() - proportionOfHeight (0.2000f)) + proportionOfHeight (0.2000f) - (roundToInt (proportionOfHeight (0.2000f) * 0.6000f)), roundToInt (proportionOfWidth (1.0000f) * 1.0000f), roundToInt (proportionOfHeight (0.2000f) * 0.6000f));
    tabbedComponent->setBounds (0, 0, proportionOfWidth (1.0000f), proportionOfHeight (0.8000f));
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
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="1000" initialHeight="450">
  <BACKGROUND backgroundColour="ff323e44"/>
  <JUCERCOMP name="" id="9a893a36dc7e0c36" memberName="keyboardVisual" virtualName=""
             explicitFocusOrder="0" pos="0 0Rr 100% 20%" sourceFile="EditorModules/KeyboardVisual.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="31178f5ce0e8830f" memberName="scaleFrequenciesOverlay"
             virtualName="" explicitFocusOrder="0" pos="0 0Rr 100% 60%" posRelativeX="9a893a36dc7e0c36"
             posRelativeY="9a893a36dc7e0c36" posRelativeW="9a893a36dc7e0c36"
             posRelativeH="9a893a36dc7e0c36" sourceFile="EditorModules/ScaleFrequenciesOverlay.cpp"
             constructorParams="keyboardVisual.get()"/>
  <JUCERCOMP name="" id="d4b4c1a2077d41bb" memberName="noteAndFreqOverlay"
             virtualName="" explicitFocusOrder="0" pos="0 0Rr 100% 60%" posRelativeX="9a893a36dc7e0c36"
             posRelativeY="9a893a36dc7e0c36" posRelativeW="9a893a36dc7e0c36"
             posRelativeH="9a893a36dc7e0c36" sourceFile="EditorModules/NoteAndFrequencyOverlay.cpp"
             constructorParams="keyboardVisual.get()"/>
  <TABBEDCOMPONENT name="new tabbed component" id="c25fcd1f05344720" memberName="tabbedComponent"
                   virtualName="" explicitFocusOrder="0" pos="0 0 100% 80%" orientation="top"
                   tabBarDepth="26" initialTab="0">
    <TAB name="Processing" colour="d3d3d3" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="EditorModules/ProcessingView.cpp"/>
    <TAB name="Testing" colour="d3d3d3" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="EditorModules/TestingView.cpp"/>
  </TABBEDCOMPONENT>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


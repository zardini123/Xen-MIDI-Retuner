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

#include "PluginGUI.h"
#include "EditorModules/ProcessingView.h"
#include "EditorModules/TestingView.h"
#include "EditorModules/SettingsView.h"


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
    tabbedComponent.reset (new juce::TabbedComponent (juce::TabbedButtonBar::TabsAtTop));
    addAndMakeVisible (tabbedComponent.get());
    tabbedComponent->setTabBarDepth (26);
    tabbedComponent->addTab (TRANS("Processing"), juce::Colour (0x00d3d3d3), new ProcessingView (data), true);
    tabbedComponent->addTab (TRANS("Testing"), juce::Colour (0x00d3d3d3), new TestingView (data), true);
    tabbedComponent->addTab (TRANS("Settings"), juce::Colour (0x00d3d3d3), new SettingsView(), true);
    tabbedComponent->setCurrentTabIndex (0);


    //[UserPreSize]
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
    tabbedComponent = nullptr;


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
                 parentClasses="public ComponentWithReferenceToData" constructorParams="ProcessorData *dataReference"
                 variableInitialisers="ComponentWithReferenceToData (dataReference)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="1300" initialHeight="450">
  <BACKGROUND backgroundColour="ff323e44"/>
  <JUCERCOMP name="" id="9a893a36dc7e0c36" memberName="keyboardVisual" virtualName=""
             explicitFocusOrder="0" pos="0 0Rr 100% 20%" sourceFile="EditorModules/KeyboardVisual/KeyboardVisual.cpp"
             constructorParams="data"/>
  <TABBEDCOMPONENT name="new tabbed component" id="c25fcd1f05344720" memberName="tabbedComponent"
                   virtualName="" explicitFocusOrder="0" pos="0 0 100% 80%" orientation="top"
                   tabBarDepth="26" initialTab="0">
    <TAB name="Processing" colour="d3d3d3" useJucerComp="1" contentClassName=""
         constructorParams="data" jucerComponentFile="EditorModules/ProcessingView.cpp"/>
    <TAB name="Testing" colour="d3d3d3" useJucerComp="1" contentClassName=""
         constructorParams="data" jucerComponentFile="EditorModules/TestingView.cpp"/>
    <TAB name="Settings" colour="d3d3d3" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="EditorModules/SettingsView.cpp"/>
  </TABBEDCOMPONENT>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


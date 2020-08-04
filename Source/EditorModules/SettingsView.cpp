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

#include "SettingsView.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
SettingsView::SettingsView ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    juce__label.reset (new juce::Label ("new label",
                                        TRANS("Xen MIDI Retuner created by Taras Palczynski III")));
    addAndMakeVisible (juce__label.get());
    juce__label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label->setJustificationType (juce::Justification::centredRight);
    juce__label->setEditable (false, false, false);
    juce__label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label2.reset (new juce::Label ("new label",
                                         TRANS("Licensed under GNU General Public License v3.0\n")));
    addAndMakeVisible (juce__label2.get());
    juce__label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label2->setJustificationType (juce::Justification::centredRight);
    juce__label2->setEditable (false, false, false);
    juce__label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    version_string.reset (new juce::Label ("new label",
                                           TRANS("v<version>")));
    addAndMakeVisible (version_string.get());
    version_string->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    version_string->setJustificationType (juce::Justification::centredRight);
    version_string->setEditable (false, false, false);
    version_string->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    version_string->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__hyperlinkButton.reset (new juce::HyperlinkButton (TRANS("GitHub Page"),
                                                            URL ("https://github.com/zardini123/Xen-MIDI-Retuner")));
    addAndMakeVisible (juce__hyperlinkButton.get());
    juce__hyperlinkButton->setTooltip (TRANS("https://github.com/zardini123/Xen-MIDI-Retuner"));
    juce__hyperlinkButton->setButtonText (TRANS("GitHub Page"));


    //[UserPreSize]
    version_string->setText("v" + std::string(ProjectInfo::versionString), dontSendNotification);
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

SettingsView::~SettingsView()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    juce__label = nullptr;
    juce__label2 = nullptr;
    version_string = nullptr;
    juce__hyperlinkButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SettingsView::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void SettingsView::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    juce__label->setBounds (getWidth() - 8 - 312, getHeight() - 40 - 24, 312, 24);
    juce__label2->setBounds (getWidth() - 8 - 310, getHeight() - 20 - 24, 310, 24);
    version_string->setBounds (getWidth() - 8 - 150, getHeight() - 60 - 24, 150, 24);
    juce__hyperlinkButton->setBounds (getWidth() - 8 - 294, getHeight() - 24, 294, 24);
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

<JUCER_COMPONENT documentType="Component" className="SettingsView" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="323e44"/>
  <LABEL name="new label" id="c63985a8ba7396d" memberName="juce__label"
         virtualName="" explicitFocusOrder="0" pos="8Rr 40Rr 312 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Xen MIDI Retuner created by Taras Palczynski III"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="34"/>
  <LABEL name="new label" id="d9787ac2c1a2ce0a" memberName="juce__label2"
         virtualName="" explicitFocusOrder="0" pos="8Rr 20Rr 310 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Licensed under GNU General Public License v3.0&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="34"/>
  <LABEL name="new label" id="bb3721bcdef4d8ba" memberName="version_string"
         virtualName="" explicitFocusOrder="0" pos="8Rr 60Rr 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="v&lt;version&gt;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="34"/>
  <HYPERLINKBUTTON name="new hyperlink" id="e1d097dfac65fe01" memberName="juce__hyperlinkButton"
                   virtualName="" explicitFocusOrder="0" pos="8Rr 0Rr 294 24" tooltip="https://github.com/zardini123/Xen-MIDI-Retuner"
                   buttonText="GitHub Page" connectedEdges="0" needsCallback="0"
                   radioGroupId="0" url="https://github.com/zardini123/Xen-MIDI-Retuner"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


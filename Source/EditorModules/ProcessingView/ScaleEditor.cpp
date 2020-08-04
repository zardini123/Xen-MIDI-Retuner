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

#include "ScaleEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ScaleEditor::ScaleEditor (ProcessorData *dataReference)
    : ComponentWithReferenceToData (dataReference)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    label.reset (new juce::Label ("new label",
                                  TRANS("Scale\n")));
    addAndMakeVisible (label.get());
    label->setFont (juce::Font (22.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    label->setJustificationType (juce::Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    importTunFile.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (importTunFile.get());
    importTunFile->setButtonText (TRANS("Load .tun File"));
    importTunFile->addListener (this);

    importTunFile->setBounds (8, 32, 150, 24);

    resetScaleButton.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (resetScaleButton.get());
    resetScaleButton->setButtonText (TRANS("Reset"));
    resetScaleButton->addListener (this);

    resetScaleButton->setBounds (8, 64, 150, 24);

    hyperlinkButton.reset (new juce::HyperlinkButton (TRANS("Sevish Workshop"),
                                                      URL ("https://sevish.com/scaleworkshop/")));
    addAndMakeVisible (hyperlinkButton.get());
    hyperlinkButton->setTooltip (TRANS("https://sevish.com/scaleworkshop/"));
    hyperlinkButton->setButtonText (TRANS("Sevish Workshop"));

    hyperlinkButton->setBounds (8, 96, 150, 24);

    scale_name_label.reset (new juce::Label ("new label",
                                             TRANS("No Scale Loaded")));
    addAndMakeVisible (scale_name_label.get());
    scale_name_label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    scale_name_label->setJustificationType (juce::Justification::centredLeft);
    scale_name_label->setEditable (false, false, false);
    scale_name_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    scale_name_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    data->scaleChangedBroadcaster.addChangeListener(this);
    setScaleLabel();
    //[/Constructor]
}

ScaleEditor::~ScaleEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label = nullptr;
    importTunFile = nullptr;
    resetScaleButton = nullptr;
    hyperlinkButton = nullptr;
    scale_name_label = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ScaleEditor::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ScaleEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    label->setBounds (0, 0, proportionOfWidth (1.0000f), 24);
    scale_name_label->setBounds (8, 128, getWidth() - 16, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ScaleEditor::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == importTunFile.get())
    {
        //[UserButtonCode_importTunFile] -- add your button handler code here..
        FileChooser myChooser ("Please select the AnaMark Tuning file you want to load...",
                           File::getSpecialLocation (File::userHomeDirectory),
                           "*.tun");

        if (myChooser.browseForFileToOpen())
        {
            File theFile (myChooser.getResult());

            data->scale.Read(theFile.getFullPathName().toStdString().c_str());
            data->scaleChangedBroadcaster.sendChangeMessage();
        }
        //[/UserButtonCode_importTunFile]
    }
    else if (buttonThatWasClicked == resetScaleButton.get())
    {
        //[UserButtonCode_resetScaleButton] -- add your button handler code here..
        data->scale.Reset();
        data->scaleChangedBroadcaster.sendChangeMessage();
        //[/UserButtonCode_resetScaleButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ScaleEditor::changeListenerCallback (ChangeBroadcaster *source)
{
    setScaleLabel();
}

void ScaleEditor::setScaleLabel()
{
    std::string scaleName = data->scale.m_strName;
    if (scaleName == "")
        scaleName = "No Scale Loaded";

    scale_name_label->setText(scaleName, dontSendNotification);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ScaleEditor" componentName=""
                 parentClasses="public ComponentWithReferenceToData, public ChangeListener"
                 constructorParams="ProcessorData *dataReference" variableInitialisers="ComponentWithReferenceToData (dataReference)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="323e44"/>
  <LABEL name="new label" id="235c5745dedfe1ad" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="0 0 100% 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Scale&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="22.0"
         kerning="0.0" bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
  <TEXTBUTTON name="new button" id="d2712430b72f9c65" memberName="importTunFile"
              virtualName="" explicitFocusOrder="0" pos="8 32 150 24" buttonText="Load .tun File"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="2e643fc79257c780" memberName="resetScaleButton"
              virtualName="" explicitFocusOrder="0" pos="8 64 150 24" buttonText="Reset"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <HYPERLINKBUTTON name="new hyperlink" id="6e1339fc3a50cbf" memberName="hyperlinkButton"
                   virtualName="" explicitFocusOrder="0" pos="8 96 150 24" tooltip="https://sevish.com/scaleworkshop/"
                   buttonText="Sevish Workshop" connectedEdges="0" needsCallback="0"
                   radioGroupId="0" url="https://sevish.com/scaleworkshop/"/>
  <LABEL name="new label" id="7989d8e0cabb16c8" memberName="scale_name_label"
         virtualName="" explicitFocusOrder="0" pos="8 128 16M 24" edTextCol="ff000000"
         edBkgCol="0" labelText="No Scale Loaded" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


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

#include "ScaleEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ScaleEditor::ScaleEditor (ProcessorData *dataReference)
    : ComponentWithReferenceToData (dataReference)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    heading.reset (new juce::Label ("new label",
                                    TRANS("Scale\n")));
    addAndMakeVisible (heading.get());
    heading->setFont (juce::Font (22.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    heading->setJustificationType (juce::Justification::centred);
    heading->setEditable (false, false, false);
    heading->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    heading->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    mtsESPClientLabel.reset (new juce::Label ("new label",
                                              TRANS("MTS-ESP Client")));
    addAndMakeVisible (mtsESPClientLabel.get());
    mtsESPClientLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    mtsESPClientLabel->setJustificationType (juce::Justification::centred);
    mtsESPClientLabel->setEditable (false, false, false);
    mtsESPClientLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    mtsESPClientLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    mtsESPClientToggle.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (mtsESPClientToggle.get());
    mtsESPClientToggle->setButtonText (TRANS("Enable"));
    mtsESPClientToggle->addListener (this);

    mtsESPClientToggle->setBounds (0, 56, 150, 24);

    mtsESPClientStatus.reset (new juce::Label ("new label",
                                               TRANS("Off")));
    addAndMakeVisible (mtsESPClientStatus.get());
    mtsESPClientStatus->setFont (juce::Font (15.00f, juce::Font::italic));
    mtsESPClientStatus->setJustificationType (juce::Justification::centred);
    mtsESPClientStatus->setEditable (false, false, false);
    mtsESPClientStatus->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    mtsESPClientStatus->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    data->scaleChangedBroadcaster.addChangeListener(this);
    //[/Constructor]
}

ScaleEditor::~ScaleEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    heading = nullptr;
    mtsESPClientLabel = nullptr;
    mtsESPClientToggle = nullptr;
    mtsESPClientStatus = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ScaleEditor::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        int x = (getWidth() / 2) - (108 / 2), y = 24, width = 108, height = 2;
        juce::Colour fillColour = juce::Colour (0xffe82950);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ScaleEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    heading->setBounds (0, 0, proportionOfWidth (1.0000f), 24);
    mtsESPClientLabel->setBounds (proportionOfWidth (0.0000f), 32, 150, 24);
    mtsESPClientStatus->setBounds (proportionOfWidth (0.0000f), 80, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ScaleEditor::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == mtsESPClientToggle.get())
    {
        //[UserButtonCode_mtsESPClientToggle] -- add your button handler code here..
        bool toggleState = mtsESPClientToggle->getToggleStateValue().getValue();
        if (toggleState) {
            // Connect MTS ESP Client
            data->mtsESPClient = new AnaMark::MTSESPClient();
            data->scale.AttachToStateProvider(&data->mtsESPClient->SingleChannel());
        } else {
            // Disconnect
            data->scale.DetachFromStateProvider();
            delete data->mtsESPClient;
        }
        //[/UserButtonCode_mtsESPClientToggle]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ScaleEditor::changeListenerCallback (ChangeBroadcaster *source)
{
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
  <BACKGROUND backgroundColour="323e44">
    <RECT pos="0Cc 24 108 2" fill="solid: ffe82950" hasStroke="0"/>
  </BACKGROUND>
  <LABEL name="new label" id="235c5745dedfe1ad" memberName="heading" virtualName=""
         explicitFocusOrder="0" pos="0 0 100% 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Scale&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="22.0"
         kerning="0.0" bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
  <LABEL name="new label" id="2cc7f93d9d946829" memberName="mtsESPClientLabel"
         virtualName="" explicitFocusOrder="0" pos="0% 32 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="MTS-ESP Client" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <TOGGLEBUTTON name="new toggle button" id="ab0ca0663d9c6545" memberName="mtsESPClientToggle"
                virtualName="" explicitFocusOrder="0" pos="0 56 150 24" buttonText="Enable"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="28b3506bf05ebba8" memberName="mtsESPClientStatus"
         virtualName="" explicitFocusOrder="0" pos="0% 80 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Off" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="1" justification="36" typefaceStyle="Italic"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


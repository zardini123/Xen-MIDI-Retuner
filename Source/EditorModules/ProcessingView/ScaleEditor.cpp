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

    mtsESPComboBoxLabel.reset (new juce::Label ("new label",
                                                TRANS("Enable MTS-ESP tuning\n")));
    addAndMakeVisible (mtsESPComboBoxLabel.get());
    mtsESPComboBoxLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    mtsESPComboBoxLabel->setJustificationType (juce::Justification::centred);
    mtsESPComboBoxLabel->setEditable (false, false, false);
    mtsESPComboBoxLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    mtsESPComboBoxLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    mtsESPStatusLabel.reset (new juce::Label ("new label",
                                              TRANS("Status: Off")));
    addAndMakeVisible (mtsESPStatusLabel.get());
    mtsESPStatusLabel->setFont (juce::Font (15.00f, juce::Font::italic));
    mtsESPStatusLabel->setJustificationType (juce::Justification::centred);
    mtsESPStatusLabel->setEditable (false, false, false);
    mtsESPStatusLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    mtsESPStatusLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    enableMtsEsp.reset (new juce::ComboBox ("new combo box"));
    addAndMakeVisible (enableMtsEsp.get());
    enableMtsEsp->setEditableText (false);
    enableMtsEsp->setJustificationType (juce::Justification::centredLeft);
    enableMtsEsp->setTextWhenNothingSelected (juce::String());
    enableMtsEsp->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    enableMtsEsp->addListener (this);

    enableMtsEsp->setBounds (8, 48, 150, 24);

    legacyMapping.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (legacyMapping.get());
    legacyMapping->setButtonText (TRANS("Map MIDI Notes Directly To Scale Notes"));
    legacyMapping->addListener (this);

    legacyMapping->setBounds (192, 48, 216, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    enableMtsEsp->addItemList(data->apvts.getParameter("enable_mts_esp")->getAllValueStrings(), 1);
    enableMtsEspAttachment.reset(new AudioProcessorValueTreeState::ComboBoxAttachment(data->apvts, "enable_mts_esp", *enableMtsEsp.get()));

    legacyMappingAttachment.reset(new AudioProcessorValueTreeState::ButtonAttachment(data->apvts, "legacy_mapping", *legacyMapping.get()));

    data->scaleChangedBroadcaster.addChangeListener(this);
    data->apvts.addParameterListener("enable_mts_esp", this);

    startTimerHz(5);
    //[/Constructor]
}

ScaleEditor::~ScaleEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    heading = nullptr;
    mtsESPComboBoxLabel = nullptr;
    mtsESPStatusLabel = nullptr;
    enableMtsEsp = nullptr;
    legacyMapping = nullptr;


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
    mtsESPComboBoxLabel->setBounds (proportionOfWidth (0.0000f), 24, 168, 24);
    mtsESPStatusLabel->setBounds (proportionOfWidth (0.0000f), 80, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ScaleEditor::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == enableMtsEsp.get())
    {
        //[UserComboBoxCode_enableMtsEsp] -- add your combo box handling code here..
        //[/UserComboBoxCode_enableMtsEsp]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void ScaleEditor::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == legacyMapping.get())
    {
        //[UserButtonCode_legacyMapping] -- add your button handler code here..
        // data->updateMidiNoteMapping();
        //[/UserButtonCode_legacyMapping]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
// here...
void ScaleEditor::changeListenerCallback(ChangeBroadcaster *source) {}

void ScaleEditor::parameterChanged(const String &parameterID, float newValue) {
  if (parameterID == "enable_mts_esp") {
    // @TODO: JUCE documentation states using this method in a parameterChanged method can
    // result in non-consistent updates.  Is this really the case?  What replacement can I
    // use?
    int mtsEspState = (int)*data->apvts.getRawParameterValue(parameterID);
    // data->logger->logMessage("enable_mts_esp: " + std::to_string(mtsEspState));
    // @FIXME:  For some reason parameterChanged is called twice per change.  No idea why.
    // Causes huge issues with spawning two MTS-ESP clients, along with attaching them.
    // Figure out why its being called twice.
    if (mtsEspState == 1) { // Enable client
      if (data->mtsESPClient == nullptr && !data->scale.IsAttachedToAStateProvider()) {
        data->mtsESPClient = new AnaMark::MTSESPClient();
        data->scale.AttachToStateProvider(&data->mtsESPClient->SingleChannel());
      }
    } else if (mtsEspState == 0) { // Disable client
      if (data->scale.IsAttachedToAStateProvider()) {
        data->scale.DetachFromStateProvider();
      }
      delete data->mtsESPClient;
      data->mtsESPClient = nullptr;
    }
  }
}

void ScaleEditor::timerCallback() {
  std::string status = "Status: ";

  if (data->mtsESPClient == nullptr) {
    status += "Off";
  } else {
    if (data->mtsESPClient->ConnectedToAMTSESPMaster()) {
      status += "Connected";
    } else {
      status += "Not Connected";
    }
  }

  mtsESPStatusLabel->setText(status, dontSendNotification);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ScaleEditor" componentName=""
                 parentClasses="public ComponentWithReferenceToData, public ChangeListener, public juce::AudioProcessorValueTreeState::Listener, public juce::Timer"
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
  <LABEL name="new label" id="2cc7f93d9d946829" memberName="mtsESPComboBoxLabel"
         virtualName="" explicitFocusOrder="0" pos="0% 24 168 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Enable MTS-ESP tuning&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="28b3506bf05ebba8" memberName="mtsESPStatusLabel"
         virtualName="" explicitFocusOrder="0" pos="0% 80 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Status: Off" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="1" justification="36"
         typefaceStyle="Italic"/>
  <COMBOBOX name="new combo box" id="7ad45a71932a9cc1" memberName="enableMtsEsp"
            virtualName="" explicitFocusOrder="0" pos="8 48 150 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TOGGLEBUTTON name="new toggle button" id="e003d17db4cb3ace" memberName="legacyMapping"
                virtualName="" explicitFocusOrder="0" pos="192 48 216 24" buttonText="Map MIDI Notes Directly To Scale Notes"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


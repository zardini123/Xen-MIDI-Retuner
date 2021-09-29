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

#include "InputModule.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
InputModule::InputModule (ProcessorData *dataReference)
    : ComponentWithReferenceToData (dataReference)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    keyboardPitchBendRange.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (keyboardPitchBendRange.get());
    keyboardPitchBendRange->setRange (1, 96, 1);
    keyboardPitchBendRange->setSliderStyle (juce::Slider::IncDecButtons);
    keyboardPitchBendRange->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);

    keyboardPitchBendRange->setBounds (8, 70, 150, 24);

    label3.reset (new juce::Label ("new label",
                                   TRANS("Pitch Bend Wheel (semitones)")));
    addAndMakeVisible (label3.get());
    label3->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (juce::Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label3->setBounds (8, 38, 128, 32);

    section_title.reset (new juce::Label ("section_title",
                                          TRANS("From Keyboard\n")));
    addAndMakeVisible (section_title.get());
    section_title->setFont (juce::Font (22.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    section_title->setJustificationType (juce::Justification::centredTop);
    section_title->setEditable (false, false, false);
    section_title->setColour (juce::Label::textColourId, juce::Colours::white);
    section_title->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    section_title->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    keyboardChannel.reset (new juce::ComboBox ("new combo box"));
    addAndMakeVisible (keyboardChannel.get());
    keyboardChannel->setEditableText (false);
    keyboardChannel->setJustificationType (juce::Justification::centredLeft);
    keyboardChannel->setTextWhenNothingSelected (juce::String());
    keyboardChannel->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    keyboardChannel->addListener (this);

    keyboardChannel->setBounds (752, 126, 150, 24);

    keyboardChannelLabel.reset (new juce::Label ("new label",
                                                 TRANS("Keyboard Channel")));
    addAndMakeVisible (keyboardChannelLabel.get());
    keyboardChannelLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    keyboardChannelLabel->setJustificationType (juce::Justification::centredLeft);
    keyboardChannelLabel->setEditable (false, false, false);
    keyboardChannelLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    keyboardChannelLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    keyboardChannelLabel->setBounds (752, 102, 150, 24);

    keyboardMidiTypeLabel.reset (new juce::Label ("new label",
                                                  TRANS("Keyboard sends out:")));
    addAndMakeVisible (keyboardMidiTypeLabel.get());
    keyboardMidiTypeLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    keyboardMidiTypeLabel->setJustificationType (juce::Justification::centredLeft);
    keyboardMidiTypeLabel->setEditable (false, false, false);
    keyboardMidiTypeLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    keyboardMidiTypeLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    keyboardMidiTypeLabel->setBounds (592, 102, 150, 24);

    keyboardMidiType.reset (new juce::ComboBox ("new combo box"));
    addAndMakeVisible (keyboardMidiType.get());
    keyboardMidiType->setEditableText (false);
    keyboardMidiType->setJustificationType (juce::Justification::centredLeft);
    keyboardMidiType->setTextWhenNothingSelected (juce::String());
    keyboardMidiType->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    keyboardMidiType->addListener (this);

    keyboardMidiType->setBounds (592, 126, 150, 24);

    juce__label2.reset (new juce::Label ("new label",
                                         TRANS("To be finished in a future release:")));
    addAndMakeVisible (juce__label2.get());
    juce__label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label2->setJustificationType (juce::Justification::centredLeft);
    juce__label2->setEditable (false, false, false);
    juce__label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label2->setBounds (592, 80, 280, 16);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
//    keyboard_pitch_bend_range->setValue(ProcessorData::getInstance()->keyboard_pitch_bend_range->get());

    inputPitchbendAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(data->apvts, "keyboard_pitch_bend_range", *keyboardPitchBendRange.get()));

    keyboardMidiType->addItemList(data->apvts.getParameter("keyboard_midi_type")->getAllValueStrings(), 1);
    keyboardChannel->addItemList(data->apvts.getParameter("keyboard_channel")->getAllValueStrings(), 1);

    keyboardMidiTypeAttachment.reset(new AudioProcessorValueTreeState::ComboBoxAttachment(data->apvts, "keyboard_midi_type", *keyboardMidiType.get()));
    keyboardChannelAttachment.reset(new AudioProcessorValueTreeState::ComboBoxAttachment(data->apvts, "keyboard_channel", *keyboardChannel.get()));

    data->apvts.addParameterListener("keyboard_midi_type", this);

    setKeyboardChannelSelectEnabled();
    //[/Constructor]
}

InputModule::~InputModule()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    keyboardPitchBendRange = nullptr;
    label3 = nullptr;
    section_title = nullptr;
    keyboardChannel = nullptr;
    keyboardChannelLabel = nullptr;
    keyboardMidiTypeLabel = nullptr;
    keyboardMidiType = nullptr;
    juce__label2 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void InputModule::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        int x = (getWidth() / 2) + 3 - (108 / 2), y = 24, width = 108, height = 2;
        juce::Colour fillColour = juce::Colour (0xffedfa00);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void InputModule::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    section_title->setBounds (0, 0, proportionOfWidth (1.0000f), 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void InputModule::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == keyboardChannel.get())
    {
        //[UserComboBoxCode_keyboardChannel] -- add your combo box handling code here..
        //[/UserComboBoxCode_keyboardChannel]
    }
    else if (comboBoxThatHasChanged == keyboardMidiType.get())
    {
        //[UserComboBoxCode_keyboardMidiType] -- add your combo box handling code here..
        //[/UserComboBoxCode_keyboardMidiType]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void InputModule::parameterChanged(const String &parameterID, float newValue)
{
    if (parameterID == "keyboard_midi_type")
    {
        setKeyboardChannelSelectEnabled();
    }
}

void InputModule::setKeyboardChannelSelectEnabled() {
  int midiTypeIndex = (int)*data->apvts.getRawParameterValue("keyboard_midi_type");
  bool enableChannelSelect = midiTypeIndex == 0;

  keyboardChannel->setEnabled(enableChannelSelect);
  keyboardChannelLabel->setEnabled(enableChannelSelect);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="InputModule" componentName=""
                 parentClasses="public ComponentWithReferenceToData, public juce::AudioProcessorValueTreeState::Listener"
                 constructorParams="ProcessorData *dataReference" variableInitialisers="ComponentWithReferenceToData (dataReference)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="323e44">
    <RECT pos="3Cc 24 108 2" fill="solid: ffedfa00" hasStroke="0"/>
  </BACKGROUND>
  <SLIDER name="new slider" id="b64c5755e8e89a8b" memberName="keyboardPitchBendRange"
          virtualName="" explicitFocusOrder="0" pos="8 70 150 24" min="1.0"
          max="96.0" int="1.0" style="IncDecButtons" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <LABEL name="new label" id="12ca6725baa12ffb" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="8 38 128 32" edTextCol="ff000000"
         edBkgCol="0" labelText="Pitch Bend Wheel (semitones)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="section_title" id="a42bffd032a0d19b" memberName="section_title"
         virtualName="" explicitFocusOrder="0" pos="0 0 100% 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="From Keyboard&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="22.0" kerning="0.0" bold="1"
         italic="0" justification="12" typefaceStyle="Bold"/>
  <COMBOBOX name="new combo box" id="961218bc77cb0156" memberName="keyboardChannel"
            virtualName="" explicitFocusOrder="0" pos="752 126 150 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="3d96623b8260204" memberName="keyboardChannelLabel"
         virtualName="" explicitFocusOrder="0" pos="752 102 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Keyboard Channel" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="aed837dbad1d3c0" memberName="keyboardMidiTypeLabel"
         virtualName="" explicitFocusOrder="0" pos="592 102 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Keyboard sends out:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="f2e57f2dcc3ce93e" memberName="keyboardMidiType"
            virtualName="" explicitFocusOrder="0" pos="592 126 150 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="baf8283d48e73c0f" memberName="juce__label2"
         virtualName="" explicitFocusOrder="0" pos="592 80 280 16" edTextCol="ff000000"
         edBkgCol="0" labelText="To be finished in a future release:"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


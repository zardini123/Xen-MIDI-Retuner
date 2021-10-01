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

#include "OutputModule.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
OutputModule::OutputModule (ProcessorData *dataReference)
    : ComponentWithReferenceToData (dataReference)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    synthPitchBendRange.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (synthPitchBendRange.get());
    synthPitchBendRange->setTooltip (TRANS("Output Pitch Bend should be set to the Input Pitch Bend Range of your instrument that you are sending the MIDI to.\n"
    "\n"
    "Should be equal to or greater than this plugin\'s Input pitch bend if note retrigger is unwanted."));
    synthPitchBendRange->setRange (1, 96, 1);
    synthPitchBendRange->setSliderStyle (juce::Slider::IncDecButtons);
    synthPitchBendRange->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);

    synthPitchBendRange->setBounds (8, 70, 150, 24);

    label.reset (new juce::Label ("new label",
                                  TRANS("Synth Pitch Bend (semitones)\n")));
    addAndMakeVisible (label.get());
    label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (juce::Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label->setBounds (8, 38, 150, 24);

    section_title.reset (new juce::Label ("section_title",
                                          TRANS("To Synth\n")));
    addAndMakeVisible (section_title.get());
    section_title->setFont (juce::Font (22.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    section_title->setJustificationType (juce::Justification::centredTop);
    section_title->setEditable (false, false, false);
    section_title->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    section_title->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    synth_channel.reset (new juce::ComboBox ("new combo box"));
    addAndMakeVisible (synth_channel.get());
    synth_channel->setEditableText (false);
    synth_channel->setJustificationType (juce::Justification::centredLeft);
    synth_channel->setTextWhenNothingSelected (juce::String());
    synth_channel->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    synth_channel->addListener (this);

    synth_channel->setBounds (712, 126, 150, 24);

    label2.reset (new juce::Label ("new label",
                                   TRANS("Synth Channel")));
    addAndMakeVisible (label2.get());
    label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (juce::Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label2->setBounds (712, 102, 150, 24);

    sendOutUntunedNotes.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (sendOutUntunedNotes.get());
    sendOutUntunedNotes->setButtonText (TRANS("Send out un-tuned notes"));
    sendOutUntunedNotes->addListener (this);

    sendOutUntunedNotes->setBounds (168, 144, 216, 24);

    juce__label.reset (new juce::Label ("new label",
                                        TRANS("Synth uses:")));
    addAndMakeVisible (juce__label.get());
    juce__label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label->setJustificationType (juce::Justification::centredLeft);
    juce__label->setEditable (false, false, false);
    juce__label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label->setBounds (552, 102, 150, 24);

    label4.reset (new juce::Label ("new label",
                                   TRANS("Modifier")));
    addAndMakeVisible (label4.get());
    label4->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (juce::Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label4->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label4->setBounds (8, 198, 144, 24);

    tunedNotePerKeyboardChannel.reset (new juce::ComboBox ("new combo box"));
    addAndMakeVisible (tunedNotePerKeyboardChannel.get());
    tunedNotePerKeyboardChannel->setTooltip (TRANS("Choose the note to tune for each keyboard MIDI channel."));
    tunedNotePerKeyboardChannel->setEditableText (false);
    tunedNotePerKeyboardChannel->setJustificationType (juce::Justification::centredLeft);
    tunedNotePerKeyboardChannel->setTextWhenNothingSelected (juce::String());
    tunedNotePerKeyboardChannel->setTextWhenNoChoicesAvailable (juce::String());
    tunedNotePerKeyboardChannel->addListener (this);

    tunedNotePerKeyboardChannel->setBounds (8, 174, 144, 24);

    label3.reset (new juce::Label ("new label",
                                   TRANS("Note to Tune Per Synth Channel")));
    addAndMakeVisible (label3.get());
    label3->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (juce::Justification::centredTop);
    label3->setEditable (false, false, false);
    label3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label3->setBounds (8, 142, 144, 32);

    tunedNotePerKeyboardChannelModifier.reset (new juce::ComboBox ("new combo box"));
    addAndMakeVisible (tunedNotePerKeyboardChannelModifier.get());
    tunedNotePerKeyboardChannelModifier->setTooltip (TRANS("Some Multi-note Prioritization options have a sub-option.  This sub-option modifies how the priority note is chosen."));
    tunedNotePerKeyboardChannelModifier->setEditableText (false);
    tunedNotePerKeyboardChannelModifier->setJustificationType (juce::Justification::centredLeft);
    tunedNotePerKeyboardChannelModifier->setTextWhenNothingSelected (juce::String());
    tunedNotePerKeyboardChannelModifier->setTextWhenNoChoicesAvailable (juce::String());
    tunedNotePerKeyboardChannelModifier->addListener (this);

    tunedNotePerKeyboardChannelModifier->setBounds (8, 222, 144, 24);

    synth_midi_type.reset (new juce::ComboBox ("new combo box"));
    addAndMakeVisible (synth_midi_type.get());
    synth_midi_type->setEditableText (false);
    synth_midi_type->setJustificationType (juce::Justification::centredLeft);
    synth_midi_type->setTextWhenNothingSelected (juce::String());
    synth_midi_type->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    synth_midi_type->addListener (this);

    synth_midi_type->setBounds (552, 126, 150, 24);

    synthIsAlreadyTuned.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (synthIsAlreadyTuned.get());
    synthIsAlreadyTuned->setButtonText (TRANS("Synth is already tuned"));
    synthIsAlreadyTuned->addListener (this);

    synthIsAlreadyTuned->setBounds (8, 104, 216, 24);

    juce__label2.reset (new juce::Label ("new label",
                                         TRANS("To be finished in a future release:")));
    addAndMakeVisible (juce__label2.get());
    juce__label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label2->setJustificationType (juce::Justification::centredLeft);
    juce__label2->setEditable (false, false, false);
    juce__label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label2->setBounds (552, 72, 280, 16);

    internalPath1.startNewSubPath (0.0f, 136.0f);
    internalPath1.lineTo (160.0f, 136.0f);
    internalPath1.lineTo (160.0f, 256.0f);
    internalPath1.lineTo (0.0f, 256.0f);
    internalPath1.closeSubPath();


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    outputPitchbendAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(data->apvts, "synth_pitch_bend_range", *synthPitchBendRange.get()));

    tunedNotePerKeyboardChannel->addItemList(data->apvts.getParameter("tuned_note_per_keyboard_channel")->getAllValueStrings(), 1);
    tunedNotePerKeyboardChannelModifier->addItemList(data->apvts.getParameter("tuned_note_per_keyboard_channel_modifier")->getAllValueStrings(), 1);

    tunedNotePerKeyboardChannelAttachment.reset(new AudioProcessorValueTreeState::ComboBoxAttachment(data->apvts, "tuned_note_per_keyboard_channel", *tunedNotePerKeyboardChannel.get()));
    tunedNotePerKeyboardChannelModifierAttachment.reset(new AudioProcessorValueTreeState::ComboBoxAttachment(data->apvts, "tuned_note_per_keyboard_channel_modifier", *tunedNotePerKeyboardChannelModifier.get()));

    sendOutUntunedNotesAttachment.reset(new AudioProcessorValueTreeState::ButtonAttachment(data->apvts, "send_out_untuned_notes", *sendOutUntunedNotes.get()));
    synthIsAlreadyTunedAttachment.reset(new AudioProcessorValueTreeState::ButtonAttachment(data->apvts, "synth_is_already_tuned", *synthIsAlreadyTuned.get()));

    data->apvts.addParameterListener("tuned_note_per_keyboard_channel", this);
    //[/Constructor]
}

OutputModule::~OutputModule()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    synthPitchBendRange = nullptr;
    label = nullptr;
    section_title = nullptr;
    synth_channel = nullptr;
    label2 = nullptr;
    sendOutUntunedNotes = nullptr;
    juce__label = nullptr;
    label4 = nullptr;
    tunedNotePerKeyboardChannel = nullptr;
    label3 = nullptr;
    tunedNotePerKeyboardChannelModifier = nullptr;
    synth_midi_type = nullptr;
    synthIsAlreadyTuned = nullptr;
    juce__label2 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    outputPitchbendAttachment = nullptr;
    //[/Destructor]
}

//==============================================================================
void OutputModule::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        float x = 0, y = 0;
        juce::Colour fillColour = juce::Colour (0x23ff0059);
        juce::Colour strokeColour = juce::Colour (0x39ff0059);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillPath (internalPath1, juce::AffineTransform::translation(x, y));
        g.setColour (strokeColour);
        g.strokePath (internalPath1, juce::PathStrokeType (2.600f), juce::AffineTransform::translation(x, y));
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void OutputModule::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    section_title->setBounds (0, 0, proportionOfWidth (1.0000f), 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void OutputModule::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == synth_channel.get())
    {
        //[UserComboBoxCode_synth_channel] -- add your combo box handling code here..
        //[/UserComboBoxCode_synth_channel]
    }
    else if (comboBoxThatHasChanged == tunedNotePerKeyboardChannel.get())
    {
        //[UserComboBoxCode_tunedNotePerKeyboardChannel] -- add your combo box handling code here..
        //[/UserComboBoxCode_tunedNotePerKeyboardChannel]
    }
    else if (comboBoxThatHasChanged == tunedNotePerKeyboardChannelModifier.get())
    {
        //[UserComboBoxCode_tunedNotePerKeyboardChannelModifier] -- add your combo box handling code here..
        //[/UserComboBoxCode_tunedNotePerKeyboardChannelModifier]
    }
    else if (comboBoxThatHasChanged == synth_midi_type.get())
    {
        //[UserComboBoxCode_synth_midi_type] -- add your combo box handling code here..
        //[/UserComboBoxCode_synth_midi_type]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void OutputModule::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == sendOutUntunedNotes.get())
    {
        //[UserButtonCode_sendOutUntunedNotes] -- add your button handler code here..
        //[/UserButtonCode_sendOutUntunedNotes]
    }
    else if (buttonThatWasClicked == synthIsAlreadyTuned.get())
    {
        //[UserButtonCode_synthIsAlreadyTuned] -- add your button handler code here..
        //[/UserButtonCode_synthIsAlreadyTuned]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void OutputModule::parameterChanged(const String &parameterID, float newValue)
{
    if (parameterID == "tuned_note_per_keyboard_channel")
    {
        SingleChannelNotePrioritzation prioritySwitch = (SingleChannelNotePrioritzation)(int)*data->apvts.getRawParameterValue(parameterID);
        tunedNotePerKeyboardChannelModifier->setEnabled(prioritySwitch == SingleChannelNotePrioritzation::NOTE_PITCH || prioritySwitch == SingleChannelNotePrioritzation::VELOCITY);
    }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="OutputModule" componentName=""
                 parentClasses="public ComponentWithReferenceToData, public juce::AudioProcessorValueTreeState::Listener"
                 constructorParams="ProcessorData *dataReference" variableInitialisers="ComponentWithReferenceToData (dataReference)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="323e44">
    <PATH pos="0 0 100 100" fill="solid: 23ff0059" hasStroke="1" stroke="2.6, mitered, butt"
          strokeColour="solid: 39ff0059" nonZeroWinding="1">s 0 136 l 160 136 l 160 256 l 0 256 x</PATH>
  </BACKGROUND>
  <SLIDER name="new slider" id="e3a72a963cc8c6fa" memberName="synthPitchBendRange"
          virtualName="" explicitFocusOrder="0" pos="8 70 150 24" tooltip="Output Pitch Bend should be set to the Input Pitch Bend Range of your instrument that you are sending the MIDI to.&#10;&#10;Should be equal to or greater than this plugin's Input pitch bend if note retrigger is unwanted."
          min="1.0" max="96.0" int="1.0" style="IncDecButtons" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <LABEL name="new label" id="1ac3af9fe857753" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="8 38 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Synth Pitch Bend (semitones)&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="section_title" id="a42bffd032a0d19b" memberName="section_title"
         virtualName="" explicitFocusOrder="0" pos="0 0 100% 24" edTextCol="ff000000"
         edBkgCol="0" labelText="To Synth&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="22.0" kerning="0.0" bold="1" italic="0" justification="12"
         typefaceStyle="Bold"/>
  <COMBOBOX name="new combo box" id="52e6b258fa592461" memberName="synth_channel"
            virtualName="" explicitFocusOrder="0" pos="712 126 150 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="16ac18ff7fa6ed12" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="712 102 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Synth Channel" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="new toggle button" id="313f41e3b63cb912" memberName="sendOutUntunedNotes"
                virtualName="" explicitFocusOrder="0" pos="168 144 216 24" buttonText="Send out un-tuned notes"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="ad39ec0fd97d0a34" memberName="juce__label"
         virtualName="" explicitFocusOrder="0" pos="552 102 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Synth uses:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="d861762387e1dd26" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="8 198 144 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Modifier" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="34c558f948bf284a" memberName="tunedNotePerKeyboardChannel"
            virtualName="" explicitFocusOrder="0" pos="8 174 144 24" tooltip="Choose the note to tune for each keyboard MIDI channel."
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems=""/>
  <LABEL name="new label" id="1112cb5e9cdc4f37" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="8 142 144 32" edTextCol="ff000000"
         edBkgCol="0" labelText="Note to Tune Per Synth Channel" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="12"/>
  <COMBOBOX name="new combo box" id="2ebd7ab8a0c8a16" memberName="tunedNotePerKeyboardChannelModifier"
            virtualName="" explicitFocusOrder="0" pos="8 222 144 24" tooltip="Some Multi-note Prioritization options have a sub-option.  This sub-option modifies how the priority note is chosen."
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems=""/>
  <COMBOBOX name="new combo box" id="fcf5fe1ca5cfefa" memberName="synth_midi_type"
            virtualName="" explicitFocusOrder="0" pos="552 126 150 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TOGGLEBUTTON name="new toggle button" id="5e5d10c3bcf65b6f" memberName="synthIsAlreadyTuned"
                virtualName="" explicitFocusOrder="0" pos="8 104 216 24" buttonText="Synth is already tuned"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="baf8283d48e73c0f" memberName="juce__label2"
         virtualName="" explicitFocusOrder="0" pos="552 72 280 16" edTextCol="ff000000"
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


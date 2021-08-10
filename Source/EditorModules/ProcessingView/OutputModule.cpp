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

    synth_pitch_bend_range.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (synth_pitch_bend_range.get());
    synth_pitch_bend_range->setTooltip (TRANS("Output Pitch Bend should be set to the Input Pitch Bend Range of your instrument that you are sending the MIDI to.\n"
    "\n"
    "Output should be equal to or greater than this plugin\'s Input pitch bend if note retrigger is unwanted."));
    synth_pitch_bend_range->setRange (1, 96, 1);
    synth_pitch_bend_range->setSliderStyle (juce::Slider::IncDecButtons);
    synth_pitch_bend_range->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);

    synth_pitch_bend_range->setBounds (8, 64, 150, 24);

    label.reset (new juce::Label ("new label",
                                  TRANS("Synth Pitch Bend (semitones)\n")));
    addAndMakeVisible (label.get());
    label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (juce::Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label->setBounds (8, 32, 150, 24);

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

    synth_channel->setBounds (168, 112, 150, 24);

    label2.reset (new juce::Label ("new label",
                                   TRANS("Synth Channel")));
    addAndMakeVisible (label2.get());
    label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (juce::Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label2->setBounds (168, 88, 150, 24);

    juce__toggleButton3.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (juce__toggleButton3.get());
    juce__toggleButton3->setButtonText (TRANS("Send un-tuned notes"));
    juce__toggleButton3->addListener (this);

    juce__toggleButton3->setBounds (8, 256, 216, 24);

    juce__label.reset (new juce::Label ("new label",
                                        TRANS("Synth uses:")));
    addAndMakeVisible (juce__label.get());
    juce__label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label->setJustificationType (juce::Justification::centredLeft);
    juce__label->setEditable (false, false, false);
    juce__label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label->setBounds (8, 88, 150, 24);

    label4.reset (new juce::Label ("new label",
                                   TRANS("Modifier")));
    addAndMakeVisible (label4.get());
    label4->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (juce::Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label4->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label4->setBounds (8, 200, 144, 24);

    tunedNotePerKeyboardChannel.reset (new juce::ComboBox ("new combo box"));
    addAndMakeVisible (tunedNotePerKeyboardChannel.get());
    tunedNotePerKeyboardChannel->setTooltip (TRANS("Choose the note to tune for each keyboard MIDI channel."));
    tunedNotePerKeyboardChannel->setEditableText (false);
    tunedNotePerKeyboardChannel->setJustificationType (juce::Justification::centredLeft);
    tunedNotePerKeyboardChannel->setTextWhenNothingSelected (juce::String());
    tunedNotePerKeyboardChannel->setTextWhenNoChoicesAvailable (juce::String());
    tunedNotePerKeyboardChannel->addListener (this);

    tunedNotePerKeyboardChannel->setBounds (8, 176, 144, 24);

    label3.reset (new juce::Label ("new label",
                                   TRANS("Note to Tune Per Keyboard Channel")));
    addAndMakeVisible (label3.get());
    label3->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (juce::Justification::centredTop);
    label3->setEditable (false, false, false);
    label3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label3->setBounds (8, 144, 144, 32);

    tunedNotePerKeyboardChannelModifier.reset (new juce::ComboBox ("new combo box"));
    addAndMakeVisible (tunedNotePerKeyboardChannelModifier.get());
    tunedNotePerKeyboardChannelModifier->setTooltip (TRANS("Some Multi-note Prioritization options have a sub-option.  This sub-option modifies how the priority note is chosen."));
    tunedNotePerKeyboardChannelModifier->setEditableText (false);
    tunedNotePerKeyboardChannelModifier->setJustificationType (juce::Justification::centredLeft);
    tunedNotePerKeyboardChannelModifier->setTextWhenNothingSelected (juce::String());
    tunedNotePerKeyboardChannelModifier->setTextWhenNoChoicesAvailable (juce::String());
    tunedNotePerKeyboardChannelModifier->addListener (this);

    tunedNotePerKeyboardChannelModifier->setBounds (8, 224, 144, 24);

    synth_midi_type.reset (new juce::ComboBox ("new combo box"));
    addAndMakeVisible (synth_midi_type.get());
    synth_midi_type->setEditableText (false);
    synth_midi_type->setJustificationType (juce::Justification::centredLeft);
    synth_midi_type->setTextWhenNothingSelected (juce::String());
    synth_midi_type->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    synth_midi_type->addListener (this);

    synth_midi_type->setBounds (8, 112, 150, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    outputPitchbendAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(data->apvts, "synth_pitch_bend_range", *synth_pitch_bend_range.get()));

    tunedNotePerKeyboardChannel->addItemList(data->apvts.getParameter("tuned_note_per_keyboard_channel")->getAllValueStrings(), 1);
    tunedNotePerKeyboardChannelModifier->addItemList(data->apvts.getParameter("tuned_note_per_keyboard_channel_modifier")->getAllValueStrings(), 1);

    tunedNotePerKeyboardChannelAttachment.reset(new AudioProcessorValueTreeState::ComboBoxAttachment(data->apvts, "tuned_note_per_keyboard_channel", *tunedNotePerKeyboardChannel.get()));
    tunedNotePerKeyboardChannelModifierAttachment.reset(new AudioProcessorValueTreeState::ComboBoxAttachment(data->apvts, "tuned_note_per_keyboard_channel_modifier", *tunedNotePerKeyboardChannelModifier.get()));


    data->apvts.addParameterListener("tuned_note_per_keyboard_channel", this);
    //[/Constructor]
}

OutputModule::~OutputModule()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    synth_pitch_bend_range = nullptr;
    label = nullptr;
    section_title = nullptr;
    synth_channel = nullptr;
    label2 = nullptr;
    juce__toggleButton3 = nullptr;
    juce__label = nullptr;
    label4 = nullptr;
    tunedNotePerKeyboardChannel = nullptr;
    label3 = nullptr;
    tunedNotePerKeyboardChannelModifier = nullptr;
    synth_midi_type = nullptr;


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
        int x = (getWidth() / 2) - (108 / 2), y = 24, width = 108, height = 2;
        juce::Colour fillColour = juce::Colour (0xffffae00);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
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

    if (buttonThatWasClicked == juce__toggleButton3.get())
    {
        //[UserButtonCode_juce__toggleButton3] -- add your button handler code here..
        //[/UserButtonCode_juce__toggleButton3]
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
    <RECT pos="0Cc 24 108 2" fill="solid: ffffae00" hasStroke="0"/>
  </BACKGROUND>
  <SLIDER name="new slider" id="e3a72a963cc8c6fa" memberName="synth_pitch_bend_range"
          virtualName="" explicitFocusOrder="0" pos="8 64 150 24" tooltip="Output Pitch Bend should be set to the Input Pitch Bend Range of your instrument that you are sending the MIDI to.&#10;&#10;Output should be equal to or greater than this plugin's Input pitch bend if note retrigger is unwanted."
          min="1.0" max="96.0" int="1.0" style="IncDecButtons" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <LABEL name="new label" id="1ac3af9fe857753" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="8 32 150 24" edTextCol="ff000000"
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
            virtualName="" explicitFocusOrder="0" pos="168 112 150 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="16ac18ff7fa6ed12" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="168 88 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Synth Channel" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="new toggle button" id="313f41e3b63cb912" memberName="juce__toggleButton3"
                virtualName="" explicitFocusOrder="0" pos="8 256 216 24" buttonText="Send un-tuned notes"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="ad39ec0fd97d0a34" memberName="juce__label"
         virtualName="" explicitFocusOrder="0" pos="8 88 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Synth uses:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="d861762387e1dd26" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="8 200 144 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Modifier" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="34c558f948bf284a" memberName="tunedNotePerKeyboardChannel"
            virtualName="" explicitFocusOrder="0" pos="8 176 144 24" tooltip="Choose the note to tune for each keyboard MIDI channel."
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems=""/>
  <LABEL name="new label" id="1112cb5e9cdc4f37" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="8 144 144 32" edTextCol="ff000000"
         edBkgCol="0" labelText="Note to Tune Per Keyboard Channel" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="12"/>
  <COMBOBOX name="new combo box" id="2ebd7ab8a0c8a16" memberName="tunedNotePerKeyboardChannelModifier"
            virtualName="" explicitFocusOrder="0" pos="8 224 144 24" tooltip="Some Multi-note Prioritization options have a sub-option.  This sub-option modifies how the priority note is chosen."
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems=""/>
  <COMBOBOX name="new combo box" id="fcf5fe1ca5cfefa" memberName="synth_midi_type"
            virtualName="" explicitFocusOrder="0" pos="8 112 150 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


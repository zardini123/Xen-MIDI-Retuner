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

    label4.reset (new juce::Label ("new label",
                                   TRANS("Modifier")));
    addAndMakeVisible (label4.get());
    label4->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (juce::Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label4->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label4->setBounds (8, 208, 144, 24);

    in_pitch_bend_range.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (in_pitch_bend_range.get());
    in_pitch_bend_range->setRange (1, 96, 1);
    in_pitch_bend_range->setSliderStyle (juce::Slider::IncDecButtons);
    in_pitch_bend_range->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);

    in_pitch_bend_range->setBounds (8, 64, 150, 24);

    label3.reset (new juce::Label ("new label",
                                   TRANS("Input Pitch Bend Range (semitones)\n")));
    addAndMakeVisible (label3.get());
    label3->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (juce::Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label3->setBounds (8, 32, 150, 24);

    section_title.reset (new juce::Label ("section_title",
                                          TRANS("Input")));
    addAndMakeVisible (section_title.get());
    section_title->setFont (juce::Font (22.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    section_title->setJustificationType (juce::Justification::centredTop);
    section_title->setEditable (false, false, false);
    section_title->setColour (juce::Label::textColourId, juce::Colours::white);
    section_title->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    section_title->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    singleChannelPriorityMode.reset (new juce::ComboBox ("new combo box"));
    addAndMakeVisible (singleChannelPriorityMode.get());
    singleChannelPriorityMode->setTooltip (TRANS("When playing multiple notes into one MIDI channel, only one note (a priority note) can be sent through the Conversion step.  This is due to the single channel pitchbend limitations of MIDI.\n"
    "\n"
    "Multi-note Prioritization is ignored when playing one note in a channel."));
    singleChannelPriorityMode->setEditableText (false);
    singleChannelPriorityMode->setJustificationType (juce::Justification::centredLeft);
    singleChannelPriorityMode->setTextWhenNothingSelected (juce::String());
    singleChannelPriorityMode->setTextWhenNoChoicesAvailable (juce::String());
    singleChannelPriorityMode->addListener (this);

    singleChannelPriorityMode->setBounds (8, 184, 144, 24);

    label2.reset (new juce::Label ("new label",
                                   TRANS("Note Prioritization")));
    addAndMakeVisible (label2.get());
    label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (juce::Justification::centredTop);
    label2->setEditable (false, false, false);
    label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label2->setBounds (8, 160, 144, 16);

    singleChannelPriorityModifier.reset (new juce::ComboBox ("new combo box"));
    addAndMakeVisible (singleChannelPriorityModifier.get());
    singleChannelPriorityModifier->setTooltip (TRANS("Some Multi-note Prioritization options have a sub-option.  This sub-option modifies how the priority note is chosen."));
    singleChannelPriorityModifier->setEditableText (false);
    singleChannelPriorityModifier->setJustificationType (juce::Justification::centredLeft);
    singleChannelPriorityModifier->setTextWhenNothingSelected (juce::String());
    singleChannelPriorityModifier->setTextWhenNoChoicesAvailable (juce::String());
    singleChannelPriorityModifier->addListener (this);

    singleChannelPriorityModifier->setBounds (8, 232, 144, 24);

    updatePriorityNoteOff.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (updatePriorityNoteOff.get());
    updatePriorityNoteOff->setButtonText (TRANS("Update Priority Note in event of Note Off"));
    updatePriorityNoteOff->addListener (this);
    updatePriorityNoteOff->setToggleState (true, juce::dontSendNotification);

    updatePriorityNoteOff->setBounds (160, 184, 150, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
//    in_pitch_bend_range->setValue(ProcessorData::getInstance()->in_pitch_bend_range->get());

    inputPitchbendAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(data->apvts, "in_pitch_bend_range", *in_pitch_bend_range.get()));

    singleChannelPriorityMode->addItemList(data->apvts.getParameter("single_channel_note_priority")->getAllValueStrings(), 1);
    singleChannelPriorityModifier->addItemList(data->apvts.getParameter("single_channel_note_priority_modifier")->getAllValueStrings(), 1);

    singleChannelNotePriorityAttachment.reset(new AudioProcessorValueTreeState::ComboBoxAttachment(data->apvts, "single_channel_note_priority", *singleChannelPriorityMode.get()));
    singleChannelPriorityModifierAttachment.reset(new AudioProcessorValueTreeState::ComboBoxAttachment(data->apvts, "single_channel_note_priority_modifier", *singleChannelPriorityModifier.get()));

    updateNotePriorityNoteOff.reset(new AudioProcessorValueTreeState::ButtonAttachment(data->apvts, "update_note_priority_note_off", *updatePriorityNoteOff.get()));


    data->apvts.addParameterListener("single_channel_note_priority", this);
    //[/Constructor]
}

InputModule::~InputModule()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label4 = nullptr;
    in_pitch_bend_range = nullptr;
    label3 = nullptr;
    section_title = nullptr;
    singleChannelPriorityMode = nullptr;
    label2 = nullptr;
    singleChannelPriorityModifier = nullptr;
    updatePriorityNoteOff = nullptr;


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

    {
        int x = 10, y = 177, width = 140, height = 2;
        juce::Colour fillColour = juce::Colour (0xff00ffb2);
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

    if (comboBoxThatHasChanged == singleChannelPriorityMode.get())
    {
        //[UserComboBoxCode_singleChannelPriorityMode] -- add your combo box handling code here..
//        *(ProcessorData::getInstance()->singleChannelNotePriority) = singleChannelPriorityMode->getSelectedItemIndex();
        //[/UserComboBoxCode_singleChannelPriorityMode]
    }
    else if (comboBoxThatHasChanged == singleChannelPriorityModifier.get())
    {
        //[UserComboBoxCode_singleChannelPriorityModifier] -- add your combo box handling code here..
//        *(ProcessorData::getInstance()->singleChannelNotePriorityModifier) = singleChannelPriorityModifier->getSelectedItemIndex();
        //[/UserComboBoxCode_singleChannelPriorityModifier]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void InputModule::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == updatePriorityNoteOff.get())
    {
        //[UserButtonCode_updatePriorityNoteOff] -- add your button handler code here..
        //[/UserButtonCode_updatePriorityNoteOff]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void InputModule::parameterChanged(const String &parameterID, float newValue)
{
    if (parameterID == "single_channel_note_priority")
    {
        SingleChannelNotePrioritzation prioritySwitch = (SingleChannelNotePrioritzation)(int)*data->apvts.getRawParameterValue(parameterID);
        singleChannelPriorityModifier->setEnabled(prioritySwitch == SingleChannelNotePrioritzation::NOTE_PITCH || prioritySwitch == SingleChannelNotePrioritzation::VELOCITY);
    }
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
    <RECT pos="10 177 140 2" fill="solid: ff00ffb2" hasStroke="0"/>
  </BACKGROUND>
  <LABEL name="new label" id="d861762387e1dd26" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="8 208 144 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Modifier" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="b64c5755e8e89a8b" memberName="in_pitch_bend_range"
          virtualName="" explicitFocusOrder="0" pos="8 64 150 24" min="1.0"
          max="96.0" int="1.0" style="IncDecButtons" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <LABEL name="new label" id="12ca6725baa12ffb" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="8 32 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Input Pitch Bend Range (semitones)&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <LABEL name="section_title" id="a42bffd032a0d19b" memberName="section_title"
         virtualName="" explicitFocusOrder="0" pos="0 0 100% 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Input" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="22.0" kerning="0.0" bold="1" italic="0" justification="12"
         typefaceStyle="Bold"/>
  <COMBOBOX name="new combo box" id="34c558f948bf284a" memberName="singleChannelPriorityMode"
            virtualName="" explicitFocusOrder="0" pos="8 184 144 24" tooltip="When playing multiple notes into one MIDI channel, only one note (a priority note) can be sent through the Conversion step.  This is due to the single channel pitchbend limitations of MIDI.&#10;&#10;Multi-note Prioritization is ignored when playing one note in a channel."
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems=""/>
  <LABEL name="new label" id="1112cb5e9cdc4f37" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="8 160 144 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Note Prioritization" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="12"/>
  <COMBOBOX name="new combo box" id="2ebd7ab8a0c8a16" memberName="singleChannelPriorityModifier"
            virtualName="" explicitFocusOrder="0" pos="8 232 144 24" tooltip="Some Multi-note Prioritization options have a sub-option.  This sub-option modifies how the priority note is chosen."
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems=""/>
  <TOGGLEBUTTON name="new toggle button" id="f453fc3ab42c5c6" memberName="updatePriorityNoteOff"
                virtualName="" explicitFocusOrder="0" pos="160 184 150 24" buttonText="Update Priority Note in event of Note Off"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


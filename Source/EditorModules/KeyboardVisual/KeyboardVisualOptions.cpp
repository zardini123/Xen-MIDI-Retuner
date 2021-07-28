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

#include "KeyboardVisualOptions.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
KeyboardVisualOptions::KeyboardVisualOptions (ProcessorData *dataReference)
    : ComponentWithReferenceToData (dataReference)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    enableInputMIDINotes.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (enableInputMIDINotes.get());
    enableInputMIDINotes->setButtonText (TRANS("Input MIDI Notes"));
    enableInputMIDINotes->addListener (this);

    midiChannelLabel.reset (new juce::Label ("new label",
                                             TRANS("Midi Channel:")));
    addAndMakeVisible (midiChannelLabel.get());
    midiChannelLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    midiChannelLabel->setJustificationType (juce::Justification::centredLeft);
    midiChannelLabel->setEditable (false, false, false);
    midiChannelLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    midiChannelLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    midiChannel.reset (new juce::ComboBox ("new combo box"));
    addAndMakeVisible (midiChannel.get());
    midiChannel->setEditableText (false);
    midiChannel->setJustificationType (juce::Justification::centredLeft);
    midiChannel->setTextWhenNothingSelected (TRANS("All"));
    midiChannel->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    midiChannel->addListener (this);

    enableChannelPriorityNote.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (enableChannelPriorityNote.get());
    enableChannelPriorityNote->setButtonText (TRANS("Channel Priority Note"));
    enableChannelPriorityNote->addListener (this);

    enableScale.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (enableScale.get());
    enableScale->setButtonText (TRANS("Scale"));
    enableScale->addListener (this);

    enablePriorityNoteSnappedToScale.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (enablePriorityNoteSnappedToScale.get());
    enablePriorityNoteSnappedToScale->setButtonText (TRANS("Priority Note Snapped to Scale"));
    enablePriorityNoteSnappedToScale->addListener (this);

    enableOutputMIDIPriorityNote.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (enableOutputMIDIPriorityNote.get());
    enableOutputMIDIPriorityNote->setButtonText (TRANS("Output MIDI for Priority Note"));
    enableOutputMIDIPriorityNote->addListener (this);

    enableOutputPitchbendRange.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (enableOutputPitchbendRange.get());
    enableOutputPitchbendRange->setButtonText (TRANS("Output Pitchbend Range"));
    enableOutputPitchbendRange->addListener (this);

    enableInputPitchbendRange.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (enableInputPitchbendRange.get());
    enableInputPitchbendRange->setButtonText (TRANS("Input Pitchbend Range"));
    enableInputPitchbendRange->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (200, 210);


    //[Constructor] You can add your own custom stuff here..
    midiChannel->addItemList(data->apvts.getParameter("keyboard_visuals-midi_channel")->getAllValueStrings(), 1);
    midiChannelAttachment.reset(new AudioProcessorValueTreeState::ComboBoxAttachment(data->apvts, "keyboard_visuals-midi_channel", *midiChannel.get()));

    enableInputMIDINotesAttachment.reset(new AudioProcessorValueTreeState::ButtonAttachment(data->apvts, "keyboard_visuals-enable_input_MIDI_notes", *enableInputMIDINotes.get()));
    enableChannelPriorityNoteAttachment.reset(new AudioProcessorValueTreeState::ButtonAttachment(data->apvts, "keyboard_visuals-enable_channel_priority_note", *enableChannelPriorityNote.get()));
    enableScaleAttachment.reset(new AudioProcessorValueTreeState::ButtonAttachment(data->apvts, "keyboard_visuals-enable_scale", *enableScale.get()));
    enablePriorityNoteSnappedToScaleAttachment.reset(new AudioProcessorValueTreeState::ButtonAttachment(data->apvts, "keyboard_visuals-enable_priority_note_snapped_to_scale", *enablePriorityNoteSnappedToScale.get()));
    enableOutputMIDIPriorityNoteAttachment.reset(new AudioProcessorValueTreeState::ButtonAttachment(data->apvts, "keyboard_visuals-enable_output_MIDI_priority_note", *enableOutputMIDIPriorityNote.get()));
    enableOutputPitchbendRangeAttachment.reset(new AudioProcessorValueTreeState::ButtonAttachment(data->apvts, "keyboard_visuals-enable_output_pitchbend_range", *enableOutputPitchbendRange.get()));
    enableInputPitchbendRangeAttachment.reset(new AudioProcessorValueTreeState::ButtonAttachment(data->apvts, "keyboard_visuals-enable_input_pitchbend_range", *enableInputPitchbendRange.get()));
    //[/Constructor]
}

KeyboardVisualOptions::~KeyboardVisualOptions()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    enableInputMIDINotes = nullptr;
    midiChannelLabel = nullptr;
    midiChannel = nullptr;
    enableChannelPriorityNote = nullptr;
    enableScale = nullptr;
    enablePriorityNoteSnappedToScale = nullptr;
    enableOutputMIDIPriorityNote = nullptr;
    enableOutputPitchbendRange = nullptr;
    enableInputPitchbendRange = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void KeyboardVisualOptions::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xad494848));

    {
        float x = 4.0f, y = 36.0f, width = 16.0f, height = 16.0f;
        juce::Colour fillColour = juce::Colour (0xffedfa00);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 6.500f);
    }

    {
        int x = 0, y = 28, width = proportionOfWidth (1.0000f), height = 1;
        juce::Colour fillColour = juce::Colour (0xffb6b6b6);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        float x = 4.0f, y = 60.0f, width = 16.0f, height = 16.0f;
        juce::Colour fillColour = juce::Colour (0xff00ffb2);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 6.500f);
    }

    {
        float x = 4.0f, y = 108.0f, width = 16.0f, height = 16.0f;
        juce::Colour fillColour = juce::Colour (0xffe82950);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 6.500f);
    }

    {
        float x = 4.0f, y = 132.0f, width = 16.0f, height = 16.0f;
        juce::Colour fillColour = juce::Colour (0xfffb00ff);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 6.500f);
    }

    {
        float x = 4.0f, y = 156.0f, width = 16.0f, height = 16.0f;
        juce::Colour fillColour = juce::Colour (0xffffae00);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 6.500f);
    }

    {
        float x = 28.0f, y = 84.0f, width = 16.0f, height = 16.0f;
        juce::Colour fillColour = juce::Colour (0xff00ffb2);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 6.500f);
    }

    {
        float x = 28.0f, y = 180.0f, width = 16.0f, height = 16.0f;
        juce::Colour fillColour = juce::Colour (0xffffae00);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 6.500f);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void KeyboardVisualOptions::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    enableInputMIDINotes->setBounds (0, 32, getWidth() - 10, 24);
    midiChannelLabel->setBounds (0, 0, proportionOfWidth (0.5000f), 24);
    midiChannel->setBounds (proportionOfWidth (0.5000f), 0, proportionOfWidth (0.4800f), 24);
    enableChannelPriorityNote->setBounds (0, 56, getWidth() - 10, 24);
    enableScale->setBounds (0, 104, getWidth() - 10, 24);
    enablePriorityNoteSnappedToScale->setBounds (0, 128, getWidth() - 10, 24);
    enableOutputMIDIPriorityNote->setBounds (0, 152, getWidth() - 10, 24);
    enableOutputPitchbendRange->setBounds (24, 176, getWidth() - 34, 24);
    enableInputPitchbendRange->setBounds (24, 80, getWidth() - 34, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void KeyboardVisualOptions::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == enableInputMIDINotes.get())
    {
        //[UserButtonCode_enableInputMIDINotes] -- add your button handler code here..
        //[/UserButtonCode_enableInputMIDINotes]
    }
    else if (buttonThatWasClicked == enableChannelPriorityNote.get())
    {
        //[UserButtonCode_enableChannelPriorityNote] -- add your button handler code here..
        //[/UserButtonCode_enableChannelPriorityNote]
    }
    else if (buttonThatWasClicked == enableScale.get())
    {
        //[UserButtonCode_enableScale] -- add your button handler code here..
        //[/UserButtonCode_enableScale]
    }
    else if (buttonThatWasClicked == enablePriorityNoteSnappedToScale.get())
    {
        //[UserButtonCode_enablePriorityNoteSnappedToScale] -- add your button handler code here..
        //[/UserButtonCode_enablePriorityNoteSnappedToScale]
    }
    else if (buttonThatWasClicked == enableOutputMIDIPriorityNote.get())
    {
        //[UserButtonCode_enableOutputMIDIPriorityNote] -- add your button handler code here..
        //[/UserButtonCode_enableOutputMIDIPriorityNote]
    }
    else if (buttonThatWasClicked == enableOutputPitchbendRange.get())
    {
        //[UserButtonCode_enableOutputPitchbendRange] -- add your button handler code here..
        //[/UserButtonCode_enableOutputPitchbendRange]
    }
    else if (buttonThatWasClicked == enableInputPitchbendRange.get())
    {
        //[UserButtonCode_enableInputPitchbendRange] -- add your button handler code here..
        //[/UserButtonCode_enableInputPitchbendRange]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void KeyboardVisualOptions::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == midiChannel.get())
    {
        //[UserComboBoxCode_midiChannel] -- add your combo box handling code here..
        //[/UserComboBoxCode_midiChannel]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="KeyboardVisualOptions" componentName=""
                 parentClasses="public ComponentWithReferenceToData" constructorParams="ProcessorData *dataReference"
                 variableInitialisers="ComponentWithReferenceToData (dataReference)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="200" initialHeight="210">
  <BACKGROUND backgroundColour="ad494848">
    <ROUNDRECT pos="4 36 16 16" cornerSize="6.5" fill="solid: ffedfa00" hasStroke="0"/>
    <RECT pos="0 28 100% 1" fill="solid: ffb6b6b6" hasStroke="0"/>
    <ROUNDRECT pos="4 60 16 16" cornerSize="6.5" fill="solid: ff00ffb2" hasStroke="0"/>
    <ROUNDRECT pos="4 108 16 16" cornerSize="6.5" fill="solid: ffe82950" hasStroke="0"/>
    <ROUNDRECT pos="4 132 16 16" cornerSize="6.5" fill="solid: fffb00ff" hasStroke="0"/>
    <ROUNDRECT pos="4 156 16 16" cornerSize="6.5" fill="solid: ffffae00" hasStroke="0"/>
    <ROUNDRECT pos="28 84 16 16" cornerSize="6.5" fill="solid: ff00ffb2" hasStroke="0"/>
    <ROUNDRECT pos="28 180 16 16" cornerSize="6.5" fill="solid: ffffae00" hasStroke="0"/>
  </BACKGROUND>
  <TOGGLEBUTTON name="new toggle button" id="b60df7f7f718c30b" memberName="enableInputMIDINotes"
                virtualName="" explicitFocusOrder="0" pos="0 32 10M 24" buttonText="Input MIDI Notes"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="cb1dc1d013918258" memberName="midiChannelLabel"
         virtualName="" explicitFocusOrder="0" pos="0 0 50% 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Midi Channel:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="8ead2bc88fb3e993" memberName="midiChannel"
            virtualName="" explicitFocusOrder="0" pos="50% 0 48% 24" editable="0"
            layout="33" items="" textWhenNonSelected="All" textWhenNoItems="(no choices)"/>
  <TOGGLEBUTTON name="new toggle button" id="8f2c3fd526adfa65" memberName="enableChannelPriorityNote"
                virtualName="" explicitFocusOrder="0" pos="0 56 10M 24" buttonText="Channel Priority Note"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="57e1846b00958de3" memberName="enableScale"
                virtualName="" explicitFocusOrder="0" pos="0 104 10M 24" buttonText="Scale"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="24e103118f00410a" memberName="enablePriorityNoteSnappedToScale"
                virtualName="" explicitFocusOrder="0" pos="0 128 10M 24" buttonText="Priority Note Snapped to Scale"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="e607438eaf817a20" memberName="enableOutputMIDIPriorityNote"
                virtualName="" explicitFocusOrder="0" pos="0 152 10M 24" buttonText="Output MIDI for Priority Note"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="ad32aee8547f76f4" memberName="enableOutputPitchbendRange"
                virtualName="" explicitFocusOrder="0" pos="24 176 34M 24" buttonText="Output Pitchbend Range"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="8226d2c04a1395a" memberName="enableInputPitchbendRange"
                virtualName="" explicitFocusOrder="0" pos="24 80 34M 24" buttonText="Input Pitchbend Range"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


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

    keyboard_pitch_bend_range.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (keyboard_pitch_bend_range.get());
    keyboard_pitch_bend_range->setRange (1, 96, 1);
    keyboard_pitch_bend_range->setSliderStyle (juce::Slider::IncDecButtons);
    keyboard_pitch_bend_range->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);

    keyboard_pitch_bend_range->setBounds (8, 56, 150, 24);

    label3.reset (new juce::Label ("new label",
                                   TRANS("Pitch Bend Wheel (semitones)")));
    addAndMakeVisible (label3.get());
    label3->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (juce::Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label3->setBounds (8, 24, 128, 32);

    section_title.reset (new juce::Label ("section_title",
                                          TRANS("From Keyboard\n")));
    addAndMakeVisible (section_title.get());
    section_title->setFont (juce::Font (22.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    section_title->setJustificationType (juce::Justification::centredTop);
    section_title->setEditable (false, false, false);
    section_title->setColour (juce::Label::textColourId, juce::Colours::white);
    section_title->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    section_title->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    keyboard_channel.reset (new juce::ComboBox ("new combo box"));
    addAndMakeVisible (keyboard_channel.get());
    keyboard_channel->setEditableText (false);
    keyboard_channel->setJustificationType (juce::Justification::centredLeft);
    keyboard_channel->setTextWhenNothingSelected (juce::String());
    keyboard_channel->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    keyboard_channel->addItem (TRANS("1"), 1);
    keyboard_channel->addItem (TRANS("2"), 2);
    keyboard_channel->addItem (TRANS("3"), 3);
    keyboard_channel->addItem (TRANS("4"), 4);
    keyboard_channel->addListener (this);

    keyboard_channel->setBounds (168, 112, 150, 24);

    label5.reset (new juce::Label ("new label",
                                   TRANS("Keyboard Channel")));
    addAndMakeVisible (label5.get());
    label5->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (juce::Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label5->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label5->setBounds (168, 88, 150, 24);

    label6.reset (new juce::Label ("new label",
                                   TRANS("Keyboard sends out:")));
    addAndMakeVisible (label6.get());
    label6->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label6->setJustificationType (juce::Justification::centredLeft);
    label6->setEditable (false, false, false);
    label6->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label6->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label6->setBounds (8, 88, 150, 24);

    keyboard_channel2.reset (new juce::ComboBox ("new combo box"));
    addAndMakeVisible (keyboard_channel2.get());
    keyboard_channel2->setEditableText (false);
    keyboard_channel2->setJustificationType (juce::Justification::centredLeft);
    keyboard_channel2->setTextWhenNothingSelected (juce::String());
    keyboard_channel2->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    keyboard_channel2->addItem (TRANS("1"), 1);
    keyboard_channel2->addItem (TRANS("2"), 2);
    keyboard_channel2->addItem (TRANS("3"), 3);
    keyboard_channel2->addItem (TRANS("4"), 4);
    keyboard_channel2->addListener (this);

    keyboard_channel2->setBounds (8, 112, 150, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
//    keyboard_pitch_bend_range->setValue(ProcessorData::getInstance()->keyboard_pitch_bend_range->get());

    inputPitchbendAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(data->apvts, "keyboard_pitch_bend_range", *keyboard_pitch_bend_range.get()));
    //[/Constructor]
}

InputModule::~InputModule()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    keyboard_pitch_bend_range = nullptr;
    label3 = nullptr;
    section_title = nullptr;
    keyboard_channel = nullptr;
    label5 = nullptr;
    label6 = nullptr;
    keyboard_channel2 = nullptr;


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

    if (comboBoxThatHasChanged == keyboard_channel.get())
    {
        //[UserComboBoxCode_keyboard_channel] -- add your combo box handling code here..
        //[/UserComboBoxCode_keyboard_channel]
    }
    else if (comboBoxThatHasChanged == keyboard_channel2.get())
    {
        //[UserComboBoxCode_keyboard_channel2] -- add your combo box handling code here..
        //[/UserComboBoxCode_keyboard_channel2]
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

<JUCER_COMPONENT documentType="Component" className="InputModule" componentName=""
                 parentClasses="public ComponentWithReferenceToData" constructorParams="ProcessorData *dataReference"
                 variableInitialisers="ComponentWithReferenceToData (dataReference)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="323e44">
    <RECT pos="3Cc 24 108 2" fill="solid: ffedfa00" hasStroke="0"/>
  </BACKGROUND>
  <SLIDER name="new slider" id="b64c5755e8e89a8b" memberName="keyboard_pitch_bend_range"
          virtualName="" explicitFocusOrder="0" pos="8 56 150 24" min="1.0"
          max="96.0" int="1.0" style="IncDecButtons" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <LABEL name="new label" id="12ca6725baa12ffb" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="8 24 128 32" edTextCol="ff000000"
         edBkgCol="0" labelText="Pitch Bend Wheel (semitones)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="section_title" id="a42bffd032a0d19b" memberName="section_title"
         virtualName="" explicitFocusOrder="0" pos="0 0 100% 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="From Keyboard&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="22.0" kerning="0.0" bold="1"
         italic="0" justification="12" typefaceStyle="Bold"/>
  <COMBOBOX name="new combo box" id="961218bc77cb0156" memberName="keyboard_channel"
            virtualName="" explicitFocusOrder="0" pos="168 112 150 24" editable="0"
            layout="33" items="1&#10;2&#10;3&#10;4" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="3d96623b8260204" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="168 88 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Keyboard Channel" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="aed837dbad1d3c0" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="8 88 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Keyboard sends out:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="f2e57f2dcc3ce93e" memberName="keyboard_channel2"
            virtualName="" explicitFocusOrder="0" pos="8 112 150 24" editable="0"
            layout="33" items="1&#10;2&#10;3&#10;4" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.7

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "InputModule.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
InputModule::InputModule ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    label4.reset (new Label ("new label",
                             TRANS("Modifier")));
    addAndMakeVisible (label4.get());
    label4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label4->setBounds (8, 168, 144, 24);

    in_pitch_bend_range.reset (new Slider ("new slider"));
    addAndMakeVisible (in_pitch_bend_range.get());
    in_pitch_bend_range->setRange (1, 96, 1);
    in_pitch_bend_range->setSliderStyle (Slider::IncDecButtons);
    in_pitch_bend_range->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    in_pitch_bend_range->addListener (this);

    in_pitch_bend_range->setBounds (8, 64, 150, 24);

    label3.reset (new Label ("new label",
                             TRANS("Input Pitch Bend Range (semitones)\n")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (8, 32, 150, 24);

    section_title.reset (new Label ("section_title",
                                    TRANS("Input")));
    addAndMakeVisible (section_title.get());
    section_title->setFont (Font (22.00f, Font::plain).withTypefaceStyle ("Bold"));
    section_title->setJustificationType (Justification::centredTop);
    section_title->setEditable (false, false, false);
    section_title->setColour (TextEditor::textColourId, Colours::black);
    section_title->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    singleChannelPriorityMode.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (singleChannelPriorityMode.get());
    singleChannelPriorityMode->setEditableText (false);
    singleChannelPriorityMode->setJustificationType (Justification::centredLeft);
    singleChannelPriorityMode->setTextWhenNothingSelected (String());
    singleChannelPriorityMode->setTextWhenNoChoicesAvailable (String());
    singleChannelPriorityMode->addListener (this);

    singleChannelPriorityMode->setBounds (8, 144, 144, 24);

    label2.reset (new Label ("new label",
                             TRANS("Single Channel Note Prioritization")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centredTop);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2->setBounds (8, 104, 144, 32);

    singleChannelPriorityModifier.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (singleChannelPriorityModifier.get());
    singleChannelPriorityModifier->setEditableText (false);
    singleChannelPriorityModifier->setJustificationType (Justification::centredLeft);
    singleChannelPriorityModifier->setTextWhenNothingSelected (String());
    singleChannelPriorityModifier->setTextWhenNoChoicesAvailable (String());
    singleChannelPriorityModifier->addListener (this);

    singleChannelPriorityModifier->setBounds (8, 192, 144, 24);


    //[UserPreSize]
    // FIXME:  All AudioParameters are not initalized when called via the singleton alone due to the processor not creating them
    singleChannelPriorityMode->addItemList(ProcessorData::getInstance()->singleChannelNotePriority->choices, 1);
    singleChannelPriorityMode->setSelectedItemIndex(ProcessorData::getInstance()->singleChannelNotePriority->getIndex());

    singleChannelPriorityModifier->addItemList(ProcessorData::getInstance()->singleChannelNotePriorityModifier->choices, 1);
    singleChannelPriorityModifier->setSelectedItemIndex(ProcessorData::getInstance()->singleChannelNotePriorityModifier->getIndex());
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    in_pitch_bend_range->setValue(ProcessorData::getInstance()->in_pitch_bend_range->get());
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


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void InputModule::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

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

void InputModule::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == in_pitch_bend_range.get())
    {
        //[UserSliderCode_in_pitch_bend_range] -- add your slider handling code here..
        *(ProcessorData::getInstance()->in_pitch_bend_range) = sliderThatWasMoved->getValue();
        //[/UserSliderCode_in_pitch_bend_range]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void InputModule::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == singleChannelPriorityMode.get())
    {
        //[UserComboBoxCode_singleChannelPriorityMode] -- add your combo box handling code here..
        *(ProcessorData::getInstance()->singleChannelNotePriority) = singleChannelPriorityMode->getSelectedItemIndex();
        //[/UserComboBoxCode_singleChannelPriorityMode]
    }
    else if (comboBoxThatHasChanged == singleChannelPriorityModifier.get())
    {
        //[UserComboBoxCode_singleChannelPriorityModifier] -- add your combo box handling code here..
        *(ProcessorData::getInstance()->singleChannelNotePriorityModifier) = singleChannelPriorityModifier->getSelectedItemIndex();
        //[/UserComboBoxCode_singleChannelPriorityModifier]
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
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="323e44"/>
  <LABEL name="new label" id="d861762387e1dd26" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="8 168 144 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Modifier" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="b64c5755e8e89a8b" memberName="in_pitch_bend_range"
          virtualName="" explicitFocusOrder="0" pos="8 64 150 24" min="1.0"
          max="96.0" int="1.0" style="IncDecButtons" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="12ca6725baa12ffb" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="8 32 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Input Pitch Bend Range (semitones)&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <LABEL name="section_title" id="a42bffd032a0d19b" memberName="section_title"
         virtualName="" explicitFocusOrder="0" pos="0 0 100% 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Input" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="22.0"
         kerning="0.0" bold="1" italic="0" justification="12" typefaceStyle="Bold"/>
  <COMBOBOX name="new combo box" id="34c558f948bf284a" memberName="singleChannelPriorityMode"
            virtualName="" explicitFocusOrder="0" pos="8 144 144 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems=""/>
  <LABEL name="new label" id="1112cb5e9cdc4f37" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="8 104 144 32" edTextCol="ff000000"
         edBkgCol="0" labelText="Single Channel Note Prioritization" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="12"/>
  <COMBOBOX name="new combo box" id="2ebd7ab8a0c8a16" memberName="singleChannelPriorityModifier"
            virtualName="" explicitFocusOrder="0" pos="8 192 144 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


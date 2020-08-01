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

#include "OutputModule.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
OutputModule::OutputModule (ProcessorData *dataReference)
    : ComponentWithReferenceToData (dataReference)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    out_pitch_bend_range.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (out_pitch_bend_range.get());
    out_pitch_bend_range->setRange (1, 96, 1);
    out_pitch_bend_range->setSliderStyle (juce::Slider::IncDecButtons);
    out_pitch_bend_range->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);

    out_pitch_bend_range->setBounds (8, 64, 150, 24);

    label.reset (new juce::Label ("new label",
                                  TRANS("Output Pitch Bend Range (semitones)\n")));
    addAndMakeVisible (label.get());
    label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (juce::Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label->setBounds (8, 32, 150, 24);

    section_title.reset (new juce::Label ("section_title",
                                          TRANS("Output")));
    addAndMakeVisible (section_title.get());
    section_title->setFont (juce::Font (22.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    section_title->setJustificationType (juce::Justification::centredTop);
    section_title->setEditable (false, false, false);
    section_title->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    section_title->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label.reset (new juce::Label ("new label",
                                        TRANS("Voice to output")));
    addAndMakeVisible (juce__label.get());
    juce__label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label->setJustificationType (juce::Justification::centredLeft);
    juce__label->setEditable (false, false, false);
    juce__label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label->setBounds (8, 208, 150, 24);

    juce__slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__slider.get());
    juce__slider->setRange (1, 128, 1);
    juce__slider->setSliderStyle (juce::Slider::IncDecButtons);
    juce__slider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    juce__slider->addListener (this);

    juce__slider->setBounds (8, 232, 150, 24);

    label2.reset (new juce::Label ("new label",
                                   TRANS("Voice Selection Method")));
    addAndMakeVisible (label2.get());
    label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (juce::Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label2->setBounds (8, 160, 144, 24);

    singleChannelPriorityModifier2.reset (new juce::ComboBox ("new combo box"));
    addAndMakeVisible (singleChannelPriorityModifier2.get());
    singleChannelPriorityModifier2->setEditableText (false);
    singleChannelPriorityModifier2->setJustificationType (juce::Justification::centredLeft);
    singleChannelPriorityModifier2->setTextWhenNothingSelected (juce::String());
    singleChannelPriorityModifier2->setTextWhenNoChoicesAvailable (juce::String());
    singleChannelPriorityModifier2->addItem (TRANS("Voice Leading"), 1);
    singleChannelPriorityModifier2->addItem (TRANS("Highest"), 2);
    singleChannelPriorityModifier2->addItem (TRANS("Lowest"), 3);
    singleChannelPriorityModifier2->addListener (this);

    singleChannelPriorityModifier2->setBounds (8, 184, 144, 24);

    juce__label2.reset (new juce::Label ("new label",
                                         TRANS("Single Voice (Monophonic)")));
    addAndMakeVisible (juce__label2.get());
    juce__label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    juce__label2->setJustificationType (juce::Justification::centredLeft);
    juce__label2->setEditable (false, false, false);
    juce__label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label2->setBounds (8, 136, 150, 24);

    juce__label3.reset (new juce::Label ("new label",
                                         TRANS("Max Voices: \n")));
    addAndMakeVisible (juce__label3.get());
    juce__label3->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label3->setJustificationType (juce::Justification::centredLeft);
    juce__label3->setEditable (false, false, false);
    juce__label3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label3->setBounds (8, 264, 150, 24);

    juce__component.reset (new MIDIChannelStatusAndToggle());
    addAndMakeVisible (juce__component.get());
    juce__toggleButton.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (juce__toggleButton.get());
    juce__toggleButton->setButtonText (TRANS("Monophonic"));
    juce__toggleButton->addListener (this);

    juce__toggleButton->setBounds (8, 104, 150, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    outputPitchbendAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(data->apvts, "out_pitch_bend_range", *out_pitch_bend_range.get()));
    //[/Constructor]
}

OutputModule::~OutputModule()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    out_pitch_bend_range = nullptr;
    label = nullptr;
    section_title = nullptr;
    juce__label = nullptr;
    juce__slider = nullptr;
    label2 = nullptr;
    singleChannelPriorityModifier2 = nullptr;
    juce__label2 = nullptr;
    juce__label3 = nullptr;
    juce__component = nullptr;
    juce__toggleButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    outputPitchbendAttachment = nullptr;
    //[/Destructor]
}

//==============================================================================
void OutputModule::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void OutputModule::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    section_title->setBounds (0, 0, proportionOfWidth (1.0000f), 24);
    juce__component->setBounds (proportionOfWidth (1.0000f) - 80, 32, 80, 304);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void OutputModule::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == juce__slider.get())
    {
        //[UserSliderCode_juce__slider] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void OutputModule::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == singleChannelPriorityModifier2.get())
    {
        //[UserComboBoxCode_singleChannelPriorityModifier2] -- add your combo box handling code here..
        //[/UserComboBoxCode_singleChannelPriorityModifier2]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void OutputModule::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == juce__toggleButton.get())
    {
        //[UserButtonCode_juce__toggleButton] -- add your button handler code here..
        //[/UserButtonCode_juce__toggleButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="OutputModule" componentName=""
                 parentClasses="public ComponentWithReferenceToData" constructorParams="ProcessorData *dataReference"
                 variableInitialisers="ComponentWithReferenceToData (dataReference)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="323e44"/>
  <SLIDER name="new slider" id="e3a72a963cc8c6fa" memberName="out_pitch_bend_range"
          virtualName="" explicitFocusOrder="0" pos="8 64 150 24" min="1.0"
          max="96.0" int="1.0" style="IncDecButtons" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <LABEL name="new label" id="1ac3af9fe857753" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="8 32 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Output Pitch Bend Range (semitones)&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <LABEL name="section_title" id="a42bffd032a0d19b" memberName="section_title"
         virtualName="" explicitFocusOrder="0" pos="0 0 100% 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Output" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="22.0"
         kerning="0.0" bold="1" italic="0" justification="12" typefaceStyle="Bold"/>
  <LABEL name="new label" id="daaa79bd78832b5e" memberName="juce__label"
         virtualName="" explicitFocusOrder="0" pos="8 208 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Voice to output" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="7164d43cc4741aaf" memberName="juce__slider"
          virtualName="" explicitFocusOrder="0" pos="8 232 150 24" min="1.0"
          max="128.0" int="1.0" style="IncDecButtons" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="449f9c4f70e043fb" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="8 160 144 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Voice Selection Method" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="fbccd8c9d5fe56ee" memberName="singleChannelPriorityModifier2"
            virtualName="" explicitFocusOrder="0" pos="8 184 144 24" editable="0"
            layout="33" items="Voice Leading&#10;Highest&#10;Lowest" textWhenNonSelected=""
            textWhenNoItems=""/>
  <LABEL name="new label" id="c12d2de40275c978" memberName="juce__label2"
         virtualName="" explicitFocusOrder="0" pos="8 136 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Single Voice (Monophonic)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="1" italic="0" justification="33"
         typefaceStyle="Bold"/>
  <LABEL name="new label" id="c5793f22cb5d6932" memberName="juce__label3"
         virtualName="" explicitFocusOrder="0" pos="8 264 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Max Voices: &#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <JUCERCOMP name="" id="1645739cc824c71f" memberName="juce__component" virtualName=""
             explicitFocusOrder="0" pos="100%r 32 80 304" sourceFile="../../Components/MIDIChannelStatusAndToggle.cpp"
             constructorParams=""/>
  <TOGGLEBUTTON name="new toggle button" id="c7362b441ebec1ae" memberName="juce__toggleButton"
                virtualName="" explicitFocusOrder="0" pos="8 104 150 24" buttonText="Monophonic"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


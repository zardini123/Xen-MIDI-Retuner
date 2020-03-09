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

#include "PluginGUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PluginGUI::PluginGUI ()
{
    //[Constructor_pre] You can add your own custom stuff here..
//    startTimerHz(20);
    //[/Constructor_pre]

    out_pitch_bend_range.reset (new Slider ("new slider"));
    addAndMakeVisible (out_pitch_bend_range.get());
    out_pitch_bend_range->setRange (0, 48, 1);
    out_pitch_bend_range->setSliderStyle (Slider::IncDecButtons);
    out_pitch_bend_range->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    out_pitch_bend_range->addListener (this);

    out_pitch_bend_range->setBounds (840, 152, 150, 24);

    label.reset (new Label ("new label",
                            TRANS("Output Pitch Bend Range (semitones)\n")));
    addAndMakeVisible (label.get());
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label->setBounds (832, 120, 150, 24);

    in_pitch_bend_range.reset (new Slider ("new slider"));
    addAndMakeVisible (in_pitch_bend_range.get());
    in_pitch_bend_range->setRange (0, 48, 1);
    in_pitch_bend_range->setSliderStyle (Slider::IncDecButtons);
    in_pitch_bend_range->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    in_pitch_bend_range->addListener (this);

    in_pitch_bend_range->setBounds (16, 152, 150, 24);

    label3.reset (new Label ("new label",
                             TRANS("Input Pitch Bend Range (semitones)\n")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (16, 120, 150, 24);

    comboBox.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox.get());
    comboBox->setEditableText (false);
    comboBox->setJustificationType (Justification::centredLeft);
    comboBox->setTextWhenNothingSelected (String());
    comboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox->addItem (TRANS("Highest Note"), 1);
    comboBox->addItem (TRANS("Lowest Note"), 2);
    comboBox->addItem (TRANS("Velocity"), 3);
    comboBox->addListener (this);

    comboBox->setBounds (425, 208, 150, 24);

    keyboardVisual.reset (new KeyboardVisual());
    addAndMakeVisible (keyboardVisual.get());
    textEditor.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (textEditor.get());
    textEditor->setMultiLine (false);
    textEditor->setReturnKeyStartsNewLine (false);
    textEditor->setReadOnly (true);
    textEditor->setScrollbarsShown (true);
    textEditor->setCaretVisible (false);
    textEditor->setPopupMenuEnabled (true);
    textEditor->setText (String());

    textEditor->setBounds (24, 192, 128, 120);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (1000, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PluginGUI::~PluginGUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    out_pitch_bend_range = nullptr;
    label = nullptr;
    in_pitch_bend_range = nullptr;
    label3 = nullptr;
    comboBox = nullptr;
    keyboardVisual = nullptr;
    textEditor = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PluginGUI::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    {
        int x = 183, y = 0, width = 1, height = proportionOfHeight (0.8000f);
        Colour fillColour = Colour (0xffb6b6b6);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 815, y = 1, width = 1, height = proportionOfHeight (0.8000f);
        Colour fillColour = Colour (0xffb6b6b6);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PluginGUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    keyboardVisual->setBounds (0, getHeight() - proportionOfHeight (0.2000f), proportionOfWidth (1.0000f), proportionOfHeight (0.2000f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PluginGUI::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == out_pitch_bend_range.get())
    {
        //[UserSliderCode_out_pitch_bend_range] -- add your slider handling code here..
        if (processor != NULL)
            processor->out_pitch_bend_range = sliderThatWasMoved->getValue();
        //[/UserSliderCode_out_pitch_bend_range]
    }
    else if (sliderThatWasMoved == in_pitch_bend_range.get())
    {
        //[UserSliderCode_in_pitch_bend_range] -- add your slider handling code here..
        //[/UserSliderCode_in_pitch_bend_range]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void PluginGUI::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox.get())
    {
        //[UserComboBoxCode_comboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void PluginGUI::timerCallback()
{
    if (processor != NULL) {
        std::string s = "";
        for (Note& t : processor->currentNotes)
            s += std::to_string(t.midiNote) + " " + std::to_string(t.velocity) + "\n";
        s += std::to_string(processor->currentNotes.capacity());

        textEditor->setText(s);
    }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginGUI" componentName=""
                 parentClasses="public Component, private Timer" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="1000" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44">
    <RECT pos="183 0 1 80%" fill="solid: ffb6b6b6" hasStroke="0"/>
    <RECT pos="815 1 1 80%" fill="solid: ffb6b6b6" hasStroke="0"/>
  </BACKGROUND>
  <SLIDER name="new slider" id="e3a72a963cc8c6fa" memberName="out_pitch_bend_range"
          virtualName="" explicitFocusOrder="0" pos="840 152 150 24" min="0.0"
          max="48.0" int="1.0" style="IncDecButtons" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="1ac3af9fe857753" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="832 120 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Output Pitch Bend Range (semitones)&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <SLIDER name="new slider" id="b64c5755e8e89a8b" memberName="in_pitch_bend_range"
          virtualName="" explicitFocusOrder="0" pos="16 152 150 24" min="0.0"
          max="48.0" int="1.0" style="IncDecButtons" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="12ca6725baa12ffb" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="16 120 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Input Pitch Bend Range (semitones)&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="7419c0b5a1da276a" memberName="comboBox"
            virtualName="" explicitFocusOrder="0" pos="425 208 150 24" editable="0"
            layout="33" items="Highest Note&#10;Lowest Note&#10;Velocity"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <JUCERCOMP name="" id="9a893a36dc7e0c36" memberName="keyboardVisual" virtualName=""
             explicitFocusOrder="0" pos="0 0Rr 100% 20%" sourceFile="KeyboardVisual.cpp"
             constructorParams=""/>
  <TEXTEDITOR name="new text editor" id="921c0928e692a9c5" memberName="textEditor"
              virtualName="" explicitFocusOrder="0" pos="24 192 128 120" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="1"
              caret="0" popupmenu="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


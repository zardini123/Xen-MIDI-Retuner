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
    //[/Constructor_pre]

    groupComponent2.reset (new GroupComponent ("new group",
                                               TRANS("Tuning Files")));
    addAndMakeVisible (groupComponent2.get());
    groupComponent2->setTextLabelPosition (Justification::centredLeft);
    groupComponent2->setColour (GroupComponent::outlineColourId, Colour (0x6a8e989b));

    groupComponent2->setBounds (200, 0, 600, 72);

    groupComponent.reset (new GroupComponent ("new group",
                                              String()));
    addAndMakeVisible (groupComponent.get());
    groupComponent->setColour (GroupComponent::outlineColourId, Colour (0x6a8e989b));

    groupComponent->setBounds (200, 8, 600, 32);

    scala_button.reset (new TextButton ("new button"));
    addAndMakeVisible (scala_button.get());
    scala_button->setButtonText (TRANS("Scala (.scl)"));
    scala_button->addListener (this);

    scala_button->setBounds (208, 20, 72, 16);

    scala_file_label.reset (new Label ("new label",
                                       TRANS("No File\n")));
    addAndMakeVisible (scala_file_label.get());
    scala_file_label->setFont (Font (10.00f, Font::plain).withTypefaceStyle ("Regular"));
    scala_file_label->setJustificationType (Justification::centredLeft);
    scala_file_label->setEditable (false, false, false);
    scala_file_label->setColour (TextEditor::textColourId, Colours::black);
    scala_file_label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    scala_file_label->setBounds (280, 16, 150, 24);

    kbm_button.reset (new TextButton ("new button"));
    addAndMakeVisible (kbm_button.get());
    kbm_button->setButtonText (TRANS("Keyboard Mapping (.kbm)"));
    kbm_button->addListener (this);

    kbm_button->setBounds (496, 20, 72, 16);

    kbm_file_label.reset (new Label ("new label",
                                     TRANS("No File\n")));
    addAndMakeVisible (kbm_file_label.get());
    kbm_file_label->setFont (Font (10.00f, Font::plain).withTypefaceStyle ("Regular"));
    kbm_file_label->setJustificationType (Justification::centredLeft);
    kbm_file_label->setEditable (false, false, false);
    kbm_file_label->setColour (TextEditor::textColourId, Colours::black);
    kbm_file_label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    kbm_file_label->setBounds (570, 16, 150, 24);

    tun_button.reset (new TextButton ("new button"));
    addAndMakeVisible (tun_button.get());
    tun_button->setButtonText (TRANS("AnaMark Tuning (.tun)"));
    tun_button->addListener (this);

    tun_button->setBounds (208, 44, 72, 16);

    tun_file_label.reset (new Label ("new label",
                                     TRANS("No File\n")));
    addAndMakeVisible (tun_file_label.get());
    tun_file_label->setFont (Font (10.00f, Font::plain).withTypefaceStyle ("Regular"));
    tun_file_label->setJustificationType (Justification::centredLeft);
    tun_file_label->setEditable (false, false, false);
    tun_file_label->setColour (TextEditor::textColourId, Colours::black);
    tun_file_label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    tun_file_label->setBounds (280, 40, 150, 24);

    apply_tun_file.reset (new TextButton ("new button"));
    addAndMakeVisible (apply_tun_file.get());
    apply_tun_file->setButtonText (TRANS("Apply"));
    apply_tun_file->addListener (this);

    apply_tun_file->setBounds (728, 48, 64, 16);

    apply_scala_files.reset (new TextButton ("new button"));
    addAndMakeVisible (apply_scala_files.get());
    apply_scala_files->setButtonText (TRANS("Apply"));
    apply_scala_files->addListener (this);

    apply_scala_files->setBounds (728, 20, 64, 16);

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

    textButton.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton.get());
    textButton->addListener (this);

    textButton->setBounds (16, 128, 150, 24);

    label2.reset (new Label ("new label",
                             TRANS("label text")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2->setBounds (32, 160, 150, 24);

    textEditor.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (textEditor.get());
    textEditor->setMultiLine (false);
    textEditor->setReturnKeyStartsNewLine (false);
    textEditor->setReadOnly (true);
    textEditor->setScrollbarsShown (true);
    textEditor->setCaretVisible (false);
    textEditor->setPopupMenuEnabled (true);
    textEditor->setText (String());

    textEditor->setBounds (8, 192, 168, 160);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (1000, 400);


    //[Constructor] You can add your own custom stuff here..
    keyboardVisual.reset(new KeyboardVisual());
    addAndMakeVisible(keyboardVisual.get());
    keyboardVisual->centreWithSize(600, 200);
    //[/Constructor]
}

PluginGUI::~PluginGUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    groupComponent2 = nullptr;
    groupComponent = nullptr;
    scala_button = nullptr;
    scala_file_label = nullptr;
    kbm_button = nullptr;
    kbm_file_label = nullptr;
    tun_button = nullptr;
    tun_file_label = nullptr;
    apply_tun_file = nullptr;
    apply_scala_files = nullptr;
    out_pitch_bend_range = nullptr;
    label = nullptr;
    textButton = nullptr;
    label2 = nullptr;
    textEditor = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    keyboardVisual = nullptr;
    //[/Destructor]
}

//==============================================================================
void PluginGUI::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    {
        int x = 184, y = -18, width = 632, height = 442;
        Colour strokeColour = Colour (0x58ffffff);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 1);

    }

    {
        int x = 32, y = 56, width = 16, height = 16;
        Colour fillColour = Colour (0xfffff400);
        Colour strokeColour = Colour (0xff3e3e3e);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 1);

    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PluginGUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PluginGUI::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == scala_button.get())
    {
        //[UserButtonCode_scala_button] -- add your button handler code here..
        FileChooser myChooser("Please select a Scala Scale (.scl) file...",
                                File::getSpecialLocation (File::userHomeDirectory),
                                "*.scl");

        if (myChooser.browseForFileToOpen())
        {
            File sclFile(myChooser.getResult());
            scala_file_label->setText(sclFile.getFullPathName(), dontSendNotification);
            processor->temp_scl_import.ReadSCL(sclFile.getFullPathName().toStdString().c_str());

            textEditor->setText(String(processor->scale.Err().GetLastError()));
        }
        //[/UserButtonCode_scala_button]
    }
    else if (buttonThatWasClicked == kbm_button.get())
    {
        //[UserButtonCode_kbm_button] -- add your button handler code here..
        //[/UserButtonCode_kbm_button]
    }
    else if (buttonThatWasClicked == tun_button.get())
    {
        //[UserButtonCode_tun_button] -- add your button handler code here..
        FileChooser myChooser("Please select a Scala Scale (.scl) file...",
                                File::getSpecialLocation (File::userHomeDirectory),
                                "*.tun");

        if (myChooser.browseForFileToOpen())
        {
            File sclFile(myChooser.getResult());
            tun_file_label->setText(sclFile.getFullPathName(), dontSendNotification);
            processor->scale.Read(sclFile.getFullPathName().toStdString().c_str());

            processor->scale.Write("/Users/tp3/Downloads/test.tun");

            textEditor->setText(String(processor->scale.Err().GetLastError()));
        }
        //[/UserButtonCode_tun_button]
    }
    else if (buttonThatWasClicked == apply_tun_file.get())
    {
        //[UserButtonCode_apply_tun_file] -- add your button handler code here..

        //[/UserButtonCode_apply_tun_file]
    }
    else if (buttonThatWasClicked == apply_scala_files.get())
    {
        //[UserButtonCode_apply_scala_files] -- add your button handler code here..
        processor->temp_scl_import.SetSingleScale(processor->scale);
        textEditor->setText(String(processor->scale.Err().GetLastError()));
        //[/UserButtonCode_apply_scala_files]
    }
    else if (buttonThatWasClicked == textButton.get())
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
        label2->setText(String(processor->note_freq_hz), dontSendNotification);
        //[/UserButtonCode_textButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void PluginGUI::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == out_pitch_bend_range.get())
    {
        //[UserSliderCode_out_pitch_bend_range] -- add your slider handling code here..
        processor->out_pitch_bend_range = sliderThatWasMoved->getValue();
        //[/UserSliderCode_out_pitch_bend_range]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginGUI" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="1000" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44">
    <RECT pos="184 -18 632 442" fill="solid: a5a42a" hasStroke="1" stroke="0.7, mitered, butt"
          strokeColour="solid: 58ffffff"/>
    <RECT pos="32 56 16 16" fill="solid: fffff400" hasStroke="1" stroke="1.4, mitered, butt"
          strokeColour="solid: ff3e3e3e"/>
  </BACKGROUND>
  <GROUPCOMPONENT name="new group" id="7b609a195c61a5ed" memberName="groupComponent2"
                  virtualName="" explicitFocusOrder="0" pos="200 0 600 72" outlinecol="6a8e989b"
                  title="Tuning Files" textpos="33"/>
  <GROUPCOMPONENT name="new group" id="7d0445c9886fd43a" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="200 8 600 32" outlinecol="6a8e989b"
                  title=""/>
  <TEXTBUTTON name="new button" id="897e91080675488d" memberName="scala_button"
              virtualName="" explicitFocusOrder="0" pos="208 20 72 16" buttonText="Scala (.scl)"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="1844ca25febfa3a9" memberName="scala_file_label"
         virtualName="" explicitFocusOrder="0" pos="280 16 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="No File&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="e9f0d9f2b89a053e" memberName="kbm_button"
              virtualName="" explicitFocusOrder="0" pos="496 20 72 16" buttonText="Keyboard Mapping (.kbm)"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="48b829fb2e544296" memberName="kbm_file_label"
         virtualName="" explicitFocusOrder="0" pos="570 16 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="No File&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="36f5389da7d1a171" memberName="tun_button"
              virtualName="" explicitFocusOrder="0" pos="208 44 72 16" buttonText="AnaMark Tuning (.tun)"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="57c09ec3a224506e" memberName="tun_file_label"
         virtualName="" explicitFocusOrder="0" pos="280 40 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="No File&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="9666056d12d72072" memberName="apply_tun_file"
              virtualName="" explicitFocusOrder="0" pos="728 48 64 16" buttonText="Apply"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="d4dba57b986310b0" memberName="apply_scala_files"
              virtualName="" explicitFocusOrder="0" pos="728 20 64 16" buttonText="Apply"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
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
  <TEXTBUTTON name="new button" id="95ea9e5a75a0576" memberName="textButton"
              virtualName="" explicitFocusOrder="0" pos="16 128 150 24" buttonText="new button"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="1c7d9b74a2d9023" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="32 160 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="bfa19eb1ae6a9b0c" memberName="textEditor"
              virtualName="" explicitFocusOrder="0" pos="8 192 168 160" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="1"
              caret="0" popupmenu="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


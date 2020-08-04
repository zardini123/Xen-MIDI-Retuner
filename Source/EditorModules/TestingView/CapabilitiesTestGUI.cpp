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

#include "CapabilitiesTestGUI.h"
#include "TestList.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
CapabilitiesTestGUI::CapabilitiesTestGUI (ProcessorData *dataReference)
    : ComponentWithReferenceToData (dataReference)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    section_title.reset (new juce::Label ("section_title",
                                          TRANS("Enviroment\'s MIDI Capabilities Test (?)\n")));
    addAndMakeVisible (section_title.get());
    section_title->setTooltip (TRANS("Test the capabilities of your MIDI enviroment (i.e. your DAW) to see if sending/retrieving certain MIDI messages is possible.\n"
    "\n"
    "Some DAWs do not support many MIDI messages related to polyphony and the MPE standard (Ableton especially).  Not having this support impeads using this plugin to its full potential."));
    section_title->setFont (juce::Font (22.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    section_title->setJustificationType (juce::Justification::centredTop);
    section_title->setEditable (false, false, false);
    section_title->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    section_title->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    run_all_tests_for_all_channels.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (run_all_tests_for_all_channels.get());
    run_all_tests_for_all_channels->setButtonText (TRANS("Run All Tests for All Channels"));
    run_all_tests_for_all_channels->addListener (this);

    listening_header.reset (new juce::Label ("new label",
                                             TRANS("Listening")));
    addAndMakeVisible (listening_header.get());
    listening_header->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    listening_header->setJustificationType (juce::Justification::centred);
    listening_header->setEditable (false, false, false);
    listening_header->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    listening_header->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    broadcasting_header.reset (new juce::Label ("new label",
                                                TRANS("Broadcasting")));
    addAndMakeVisible (broadcasting_header.get());
    broadcasting_header->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    broadcasting_header->setJustificationType (juce::Justification::centred);
    broadcasting_header->setEditable (false, false, false);
    broadcasting_header->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    broadcasting_header->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label6.reset (new juce::Label ("new label",
                                   TRANS("Test")));
    addAndMakeVisible (label6.get());
    label6->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label6->setJustificationType (juce::Justification::centred);
    label6->setEditable (false, false, false);
    label6->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label6->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label8.reset (new juce::Label ("new label",
                                   TRANS("Status")));
    addAndMakeVisible (label8.get());
    label8->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label8->setJustificationType (juce::Justification::centred);
    label8->setEditable (false, false, false);
    label8->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label8->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    start_all_test_listeners.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (start_all_test_listeners.get());
    start_all_test_listeners->setButtonText (TRANS("Start All Test Listeners"));
    start_all_test_listeners->addListener (this);

    stop_all_test_listeners.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (stop_all_test_listeners.get());
    stop_all_test_listeners->setButtonText (TRANS("Stop All Test Listeners"));
    stop_all_test_listeners->addListener (this);

    timeout_slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (timeout_slider.get());
    timeout_slider->setRange (0, 10, 0.01);
    timeout_slider->setSliderStyle (juce::Slider::IncDecButtons);
    timeout_slider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    timeout_slider->addListener (this);

    timeout_slider_label.reset (new juce::Label ("new label",
                                                 TRANS("Timeout (seconds)")));
    addAndMakeVisible (timeout_slider_label.get());
    timeout_slider_label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    timeout_slider_label->setJustificationType (juce::Justification::centredRight);
    timeout_slider_label->setEditable (false, false, false);
    timeout_slider_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    timeout_slider_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label2.reset (new juce::Label ("new label",
                                   TRANS("Test")));
    addAndMakeVisible (label2.get());
    label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (juce::Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label4.reset (new juce::Label ("new label",
                                   TRANS("Status")));
    addAndMakeVisible (label4.get());
    label4->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (juce::Justification::centred);
    label4->setEditable (false, false, false);
    label4->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label4->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    viewport.reset (new juce::Viewport ("new viewport"));
    addAndMakeVisible (viewport.get());
    viewport->setScrollBarsShown (true, false);
    viewport->setScrollBarThickness (17);
    viewport->setViewedComponent (new TestList (data));

    label.reset (new juce::Label ("new label",
                                  TRANS("MIDI Channel Independent Messages\n")));
    addAndMakeVisible (label.get());
    label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (juce::Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    component.reset (new MIDIChannelToolbar());
    addAndMakeVisible (component.get());
    run_all_tests.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (run_all_tests.get());
    run_all_tests->setButtonText (TRANS("Run All Tests"));
    run_all_tests->addListener (this);

    component2.reset (new ActionButtonAndStatus (data));
    addAndMakeVisible (component2.get());
    component3.reset (new ActionButtonAndStatus (data));
    addAndMakeVisible (component3.get());
    textButton3.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (textButton3.get());
    textButton3->setButtonText (TRANS("Run All Tests for Channel Independent Messages"));
    textButton3->addListener (this);

    textButton4.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (textButton4.get());
    textButton4->setButtonText (TRANS("Start Test Listeners for Channel Indepenent"));
    textButton4->addListener (this);

    textButton5.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (textButton5.get());
    textButton5->setButtonText (TRANS("Stop Test Listeners for Channel Indepenent"));
    textButton5->addListener (this);

    start_test_listeners_for_all_channels.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (start_test_listeners_for_all_channels.get());
    start_test_listeners_for_all_channels->setButtonText (TRANS("Start Test Listeners for All Channels"));
    start_test_listeners_for_all_channels->addListener (this);

    stop_test_listeners_for_all_channels.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (stop_test_listeners_for_all_channels.get());
    stop_test_listeners_for_all_channels->setButtonText (TRANS("Stop Test Listeners for All Channels"));
    stop_test_listeners_for_all_channels->addListener (this);

    autostart_all_listeners.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (autostart_all_listeners.get());
    autostart_all_listeners->setButtonText (TRANS("Auto-start All Listeners"));
    autostart_all_listeners->addListener (this);
    autostart_all_listeners->setToggleState (true, dontSendNotification);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

CapabilitiesTestGUI::~CapabilitiesTestGUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    section_title = nullptr;
    run_all_tests_for_all_channels = nullptr;
    listening_header = nullptr;
    broadcasting_header = nullptr;
    label6 = nullptr;
    label8 = nullptr;
    start_all_test_listeners = nullptr;
    stop_all_test_listeners = nullptr;
    timeout_slider = nullptr;
    timeout_slider_label = nullptr;
    label2 = nullptr;
    label4 = nullptr;
    viewport = nullptr;
    label = nullptr;
    component = nullptr;
    run_all_tests = nullptr;
    component2 = nullptr;
    component3 = nullptr;
    textButton3 = nullptr;
    textButton4 = nullptr;
    textButton5 = nullptr;
    start_test_listeners_for_all_channels = nullptr;
    stop_test_listeners_for_all_channels = nullptr;
    autostart_all_listeners = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void CapabilitiesTestGUI::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        int x = proportionOfWidth (0.5000f), y = 30, width = 1, height = proportionOfHeight (1.0000f);
        juce::Colour fillColour = juce::Colour (0xffb6b6b6);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void CapabilitiesTestGUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    section_title->setBounds (0, 0, proportionOfWidth (1.0000f), 24);
    run_all_tests_for_all_channels->setBounds (proportionOfWidth (0.7519f) - (proportionOfWidth (0.4499f) / 2), 208, proportionOfWidth (0.4499f), 24);
    listening_header->setBounds (0, 24, proportionOfWidth (0.5004f), 24);
    broadcasting_header->setBounds (proportionOfWidth (0.5004f), 24, proportionOfWidth (0.5004f), 24);
    label6->setBounds (0, 96, juce::roundToInt (proportionOfWidth (0.5004f) * 0.5000f), 24);
    label8->setBounds (0 + juce::roundToInt (proportionOfWidth (0.5004f) * 0.4931f), 96, juce::roundToInt (proportionOfWidth (0.5004f) * 0.5000f), 24);
    start_all_test_listeners->setBounds (0, 304, proportionOfWidth (0.2502f), 24);
    stop_all_test_listeners->setBounds (proportionOfWidth (0.2502f), 304, proportionOfWidth (0.2502f), 24);
    timeout_slider->setBounds (proportionOfWidth (0.3333f), 48, proportionOfWidth (0.1662f), 24);
    timeout_slider_label->setBounds (proportionOfWidth (0.1662f), 48, proportionOfWidth (0.1662f), 24);
    label2->setBounds (proportionOfWidth (0.5004f) + 2, 96, juce::roundToInt (proportionOfWidth (0.5004f) * 0.5000f), 24);
    label4->setBounds (proportionOfWidth (0.5004f) + juce::roundToInt (proportionOfWidth (0.5004f) * 0.5000f), 96, juce::roundToInt (proportionOfWidth (0.5004f) * 0.5000f), 24);
    viewport->setBounds (0, 120, proportionOfWidth (1.0000f), 88);
    label->setBounds (0, 232, proportionOfWidth (1.0000f), 24);
    component->setBounds (0, 72, proportionOfWidth (1.0000f), 24);
    run_all_tests->setBounds (proportionOfWidth (0.5004f), 304, proportionOfWidth (0.5004f), 24);
    component2->setBounds (proportionOfWidth (0.7502f) - (proportionOfWidth (0.4499f) / 2), 256, proportionOfWidth (0.4499f), 24);
    component3->setBounds (proportionOfWidth (0.2498f) - (proportionOfWidth (0.4499f) / 2), 256, proportionOfWidth (0.4499f), 24);
    textButton3->setBounds (proportionOfWidth (0.7519f) - (proportionOfWidth (0.4499f) / 2), 280, proportionOfWidth (0.4499f), 24);
    textButton4->setBounds (proportionOfWidth (0.2502f) - proportionOfWidth (0.2245f), 280, proportionOfWidth (0.2245f), 24);
    textButton5->setBounds (proportionOfWidth (0.2502f), 280, proportionOfWidth (0.2245f), 24);
    start_test_listeners_for_all_channels->setBounds (proportionOfWidth (0.2502f) - proportionOfWidth (0.2245f), 208, proportionOfWidth (0.2245f), 24);
    stop_test_listeners_for_all_channels->setBounds (proportionOfWidth (0.2485f), 208, proportionOfWidth (0.2245f), 24);
    autostart_all_listeners->setBounds (proportionOfWidth (0.0000f), 48, proportionOfWidth (0.1662f), 24);
    //[UserResized] Add your own custom resize handling here..
    viewport->getViewedComponent()->setSize(viewport->getWidth(), viewport->getHeight());

    timeout_slider->setValue(2.0);
    //[/UserResized]
}

void CapabilitiesTestGUI::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == run_all_tests_for_all_channels.get())
    {
        //[UserButtonCode_run_all_tests_for_all_channels] -- add your button handler code here..
        //[/UserButtonCode_run_all_tests_for_all_channels]
    }
    else if (buttonThatWasClicked == start_all_test_listeners.get())
    {
        //[UserButtonCode_start_all_test_listeners] -- add your button handler code here..
        //[/UserButtonCode_start_all_test_listeners]
    }
    else if (buttonThatWasClicked == stop_all_test_listeners.get())
    {
        //[UserButtonCode_stop_all_test_listeners] -- add your button handler code here..
        //[/UserButtonCode_stop_all_test_listeners]
    }
    else if (buttonThatWasClicked == run_all_tests.get())
    {
        //[UserButtonCode_run_all_tests] -- add your button handler code here..
        //[/UserButtonCode_run_all_tests]
    }
    else if (buttonThatWasClicked == textButton3.get())
    {
        //[UserButtonCode_textButton3] -- add your button handler code here..
        //[/UserButtonCode_textButton3]
    }
    else if (buttonThatWasClicked == textButton4.get())
    {
        //[UserButtonCode_textButton4] -- add your button handler code here..
        //[/UserButtonCode_textButton4]
    }
    else if (buttonThatWasClicked == textButton5.get())
    {
        //[UserButtonCode_textButton5] -- add your button handler code here..
        //[/UserButtonCode_textButton5]
    }
    else if (buttonThatWasClicked == start_test_listeners_for_all_channels.get())
    {
        //[UserButtonCode_start_test_listeners_for_all_channels] -- add your button handler code here..
        //[/UserButtonCode_start_test_listeners_for_all_channels]
    }
    else if (buttonThatWasClicked == stop_test_listeners_for_all_channels.get())
    {
        //[UserButtonCode_stop_test_listeners_for_all_channels] -- add your button handler code here..
        //[/UserButtonCode_stop_test_listeners_for_all_channels]
    }
    else if (buttonThatWasClicked == autostart_all_listeners.get())
    {
        //[UserButtonCode_autostart_all_listeners] -- add your button handler code here..
        //[/UserButtonCode_autostart_all_listeners]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void CapabilitiesTestGUI::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == timeout_slider.get())
    {
        //[UserSliderCode_timeout_slider] -- add your slider handling code here..
        //[/UserSliderCode_timeout_slider]
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

<JUCER_COMPONENT documentType="Component" className="CapabilitiesTestGUI" componentName=""
                 parentClasses="public ComponentWithReferenceToData" constructorParams="ProcessorData *dataReference"
                 variableInitialisers="ComponentWithReferenceToData (dataReference)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="323e44">
    <RECT pos="50% 30 1 100%" fill="solid: ffb6b6b6" hasStroke="0"/>
  </BACKGROUND>
  <LABEL name="section_title" id="a42bffd032a0d19b" memberName="section_title"
         virtualName="" explicitFocusOrder="0" pos="0 0 100% 24" tooltip="Test the capabilities of your MIDI enviroment (i.e. your DAW) to see if sending/retrieving certain MIDI messages is possible.&#10;&#10;Some DAWs do not support many MIDI messages related to polyphony and the MPE standard (Ableton especially).  Not having this support impeads using this plugin to its full potential."
         edTextCol="ff000000" edBkgCol="0" labelText="Enviroment's MIDI Capabilities Test (?)&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="22.0" kerning="0.0" bold="1"
         italic="0" justification="12" typefaceStyle="Bold"/>
  <TEXTBUTTON name="new button" id="2f1cdad724c2fbd6" memberName="run_all_tests_for_all_channels"
              virtualName="" explicitFocusOrder="0" pos="75.193%c 208 44.987% 24"
              buttonText="Run All Tests for All Channels" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="417638c1a1b055cd" memberName="listening_header"
         virtualName="" explicitFocusOrder="0" pos="0 24 50.043% 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Listening" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="f6c83cc2f28e8d2c" memberName="broadcasting_header"
         virtualName="" explicitFocusOrder="0" pos="50.043% 24 50.043% 24"
         edTextCol="ff000000" edBkgCol="0" labelText="Broadcasting" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="dcf3299df648f527" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="0 96 50% 24" posRelativeW="417638c1a1b055cd"
         edTextCol="ff000000" edBkgCol="0" labelText="Test" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="bd7a26b3020bbc31" memberName="label8" virtualName=""
         explicitFocusOrder="0" pos="49.315% 96 50% 24" posRelativeX="417638c1a1b055cd"
         posRelativeW="417638c1a1b055cd" edTextCol="ff000000" edBkgCol="0"
         labelText="Status" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="new button" id="d296b21f6b0998bc" memberName="start_all_test_listeners"
              virtualName="" explicitFocusOrder="0" pos="0 304 25.021% 24"
              buttonText="Start All Test Listeners" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="be54a46ad953004b" memberName="stop_all_test_listeners"
              virtualName="" explicitFocusOrder="0" pos="25.021% 304 25.021% 24"
              buttonText="Stop All Test Listeners" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <SLIDER name="new slider" id="a96119be99b37cad" memberName="timeout_slider"
          virtualName="" explicitFocusOrder="0" pos="33.333% 48 16.624% 24"
          min="0.0" max="10.0" int="0.01" style="IncDecButtons" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="ae317d23d937b427" memberName="timeout_slider_label"
         virtualName="" explicitFocusOrder="0" pos="16.624% 48 16.624% 24"
         edTextCol="ff000000" edBkgCol="0" labelText="Timeout (seconds)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="34"/>
  <LABEL name="new label" id="58b012b47a410064" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="2 96 50% 24" posRelativeX="f6c83cc2f28e8d2c"
         posRelativeW="f6c83cc2f28e8d2c" edTextCol="ff000000" edBkgCol="0"
         labelText="Test" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="41a59db520bafe6c" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="50% 96 50% 24" posRelativeX="f6c83cc2f28e8d2c"
         posRelativeW="f6c83cc2f28e8d2c" edTextCol="ff000000" edBkgCol="0"
         labelText="Status" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <VIEWPORT name="new viewport" id="999ad0c145a6564d" memberName="viewport"
            virtualName="" explicitFocusOrder="0" pos="0 120 100% 88" vscroll="1"
            hscroll="0" scrollbarThickness="17" contentType="1" jucerFile="TestList.cpp"
            contentClass="" constructorParams="data"/>
  <LABEL name="new label" id="ff72cb192b42ed7" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="0 232 100% 24" edTextCol="ff000000"
         edBkgCol="0" labelText="MIDI Channel Independent Messages&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="36"/>
  <JUCERCOMP name="" id="b824a5dedea20071" memberName="component" virtualName=""
             explicitFocusOrder="0" pos="0 72 100% 24" sourceFile="MIDIChannelToolbar.cpp"
             constructorParams=""/>
  <TEXTBUTTON name="new button" id="3e9ddd45aa807e1f" memberName="run_all_tests"
              virtualName="" explicitFocusOrder="0" pos="50.043% 304 50.043% 24"
              buttonText="Run All Tests" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <JUCERCOMP name="" id="7474405a7e5baa8a" memberName="component2" virtualName=""
             explicitFocusOrder="0" pos="75.021%c 256 44.987% 24" sourceFile="ActionButtonAndStatus.cpp"
             constructorParams="data"/>
  <JUCERCOMP name="" id="169daa2f7421393c" memberName="component3" virtualName=""
             explicitFocusOrder="0" pos="24.979%c 256 44.987% 24" sourceFile="ActionButtonAndStatus.cpp"
             constructorParams="data"/>
  <TEXTBUTTON name="new button" id="4d3cafa5a7af0c70" memberName="textButton3"
              virtualName="" explicitFocusOrder="0" pos="75.193%c 280 44.987% 24"
              buttonText="Run All Tests for Channel Independent Messages" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="c6a2dbb3329f79a9" memberName="textButton4"
              virtualName="" explicitFocusOrder="0" pos="25.021%r 280 22.451% 24"
              buttonText="Start Test Listeners for Channel Indepenent" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="689f5e5be5af45b9" memberName="textButton5"
              virtualName="" explicitFocusOrder="0" pos="25.021% 280 22.451% 24"
              buttonText="Stop Test Listeners for Channel Indepenent" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="4ada209213d48413" memberName="start_test_listeners_for_all_channels"
              virtualName="" explicitFocusOrder="0" pos="25.021%r 208 22.451% 24"
              buttonText="Start Test Listeners for All Channels" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="89d7c9f26a7005a" memberName="stop_test_listeners_for_all_channels"
              virtualName="" explicitFocusOrder="0" pos="24.85% 208 22.451% 24"
              buttonText="Stop Test Listeners for All Channels" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="new toggle button" id="3f487a5b71834efb" memberName="autostart_all_listeners"
                virtualName="" explicitFocusOrder="0" pos="0% 48 16.624% 24"
                buttonText="Auto-start All Listeners" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


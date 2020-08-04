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

#include "ConversionModule.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ConversionModule::ConversionModule (ProcessorData *dataReference)
    : ComponentWithReferenceToData (dataReference)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    label.reset (new juce::Label ("new label",
                                  TRANS("Scale Note Snapping Curve")));
    addAndMakeVisible (label.get());
    label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (juce::Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label->setBounds (0, 16, 224, 40);

    section_title.reset (new juce::Label ("section_title",
                                          TRANS("Conversion\n")));
    addAndMakeVisible (section_title.get());
    section_title->setFont (juce::Font (22.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    section_title->setJustificationType (juce::Justification::centredTop);
    section_title->setEditable (false, false, false);
    section_title->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    section_title->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    transitionCurveGUI.reset (new TransitionCurveGUI (&(data->transitionCurve)));
    addAndMakeVisible (transitionCurveGUI.get());
    transitionSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (transitionSlider.get());
    transitionSlider->setRange (0, 1, 0);
    transitionSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    transitionSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    transitionSlider->setBounds (0, 80, 104, 96);

    label2.reset (new juce::Label ("new label",
                                   TRANS("Transition")));
    addAndMakeVisible (label2.get());
    label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (juce::Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label2->setBounds (0, 48, 104, 40);

    midpointSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (midpointSlider.get());
    midpointSlider->setRange (0, 1, 0);
    midpointSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    midpointSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    midpointSlider->setBounds (0, 200, 104, 96);

    label3.reset (new juce::Label ("new label",
                                   TRANS("Midpoint\n")));
    addAndMakeVisible (label3.get());
    label3->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (juce::Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label3->setBounds (0, 176, 104, 40);

    label5.reset (new juce::Label ("new label",
                                   TRANS("Interploation Dimension\n")));
    addAndMakeVisible (label5.get());
    label5->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (juce::Justification::centredTop);
    label5->setEditable (false, false, false);
    label5->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label5->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label5->setBounds (80, 64, 144, 32);

    interploationDimension.reset (new juce::ComboBox ("new combo box"));
    addAndMakeVisible (interploationDimension.get());
    interploationDimension->setEditableText (false);
    interploationDimension->setJustificationType (juce::Justification::centredLeft);
    interploationDimension->setTextWhenNothingSelected (TRANS("Continuous Midi Note (Cents)"));
    interploationDimension->setTextWhenNoChoicesAvailable (TRANS("Continuous Midi Note (Cents)"));
    interploationDimension->addItem (TRANS("Continuous Midi Note (Cents)"), 1);
    interploationDimension->addItem (TRANS("Frequency"), 2);
    interploationDimension->addListener (this);

    interploationDimension->setBounds (80, 104, 144, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    curveMidpointAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(data->apvts, "transition_curve_midpoint", *midpointSlider.get()));
    curveTransitionAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(data->apvts, "transition_curve_transition", *transitionSlider.get()));

    // Transition Curve GUI is updated via the slider changed callback

    data->apvts.addParameterListener("transition_curve_midpoint", this);
    data->apvts.addParameterListener("transition_curve_transition", this);
    //[/Constructor]
}

ConversionModule::~ConversionModule()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label = nullptr;
    section_title = nullptr;
    transitionCurveGUI = nullptr;
    transitionSlider = nullptr;
    label2 = nullptr;
    midpointSlider = nullptr;
    label3 = nullptr;
    label5 = nullptr;
    interploationDimension = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    curveTransitionAttachment = nullptr;
    curveMidpointAttachment = nullptr;
    //[/Destructor]
}

//==============================================================================
void ConversionModule::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ConversionModule::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    section_title->setBounds (0, 0, proportionOfWidth (1.0000f), 24);
    transitionCurveGUI->setBounds (proportionOfWidth (0.1986f), 32, proportionOfWidth (0.8014f), proportionOfHeight (0.4983f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ConversionModule::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == interploationDimension.get())
    {
        //[UserComboBoxCode_interploationDimension] -- add your combo box handling code here..
        //[/UserComboBoxCode_interploationDimension]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ConversionModule::parameterChanged(const String &parameterID, float newValue)
{
    if (parameterID == "transition_curve_midpoint")
    {
        data->transitionCurve.setMidpoint(newValue);
        transitionCurveGUI->repaint();
    }
    else if (parameterID == "transition_curve_transition")
    {
        data->transitionCurve.setTransition(newValue);
        transitionCurveGUI->repaint();
    }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ConversionModule" componentName=""
                 parentClasses="public ComponentWithReferenceToData, public juce::AudioProcessorValueTreeState::Listener"
                 constructorParams="ProcessorData *dataReference" variableInitialisers="ComponentWithReferenceToData (dataReference)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="323e44"/>
  <LABEL name="new label" id="de0e609ae3dc6772" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="0 16 224 40" edTextCol="ff000000"
         edBkgCol="0" labelText="Scale Note Snapping Curve" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="section_title" id="a42bffd032a0d19b" memberName="section_title"
         virtualName="" explicitFocusOrder="0" pos="0 0 100% 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Conversion&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="22.0" kerning="0.0" bold="1" italic="0" justification="12"
         typefaceStyle="Bold"/>
  <JUCERCOMP name="" id="58460eddec1ae63f" memberName="transitionCurveGUI"
             virtualName="" explicitFocusOrder="0" pos="19.88% 32 80.12% 49.828%"
             sourceFile="../../Components/TransitionCurveGUI.cpp" constructorParams="&amp;(data-&gt;transitionCurve)"/>
  <SLIDER name="new slider" id="9f561ed4f957bf22" memberName="transitionSlider"
          virtualName="" explicitFocusOrder="0" pos="0 80 104 96" min="0.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <LABEL name="new label" id="ce42b31741efd25e" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="0 48 104 40" edTextCol="ff000000"
         edBkgCol="0" labelText="Transition" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="b39d181ab4de0d6d" memberName="midpointSlider"
          virtualName="" explicitFocusOrder="0" pos="0 200 104 96" min="0.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <LABEL name="new label" id="4eb01ae82b3ff35c" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="0 176 104 40" edTextCol="ff000000"
         edBkgCol="0" labelText="Midpoint&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="28b8d285343a10c" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="80 64 144 32" edTextCol="ff000000"
         edBkgCol="0" labelText="Interploation Dimension&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="12"/>
  <COMBOBOX name="new combo box" id="583d3e280c9789d5" memberName="interploationDimension"
            virtualName="" explicitFocusOrder="0" pos="80 104 144 24" editable="0"
            layout="33" items="Continuous Midi Note (Cents)&#10;Frequency"
            textWhenNonSelected="Continuous Midi Note (Cents)" textWhenNoItems="Continuous Midi Note (Cents)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


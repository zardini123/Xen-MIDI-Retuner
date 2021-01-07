/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.5

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

    sectionTitle.reset (new juce::Label ("sectionTitle",
                                         TRANS("Conversion\n")));
    addAndMakeVisible (sectionTitle.get());
    sectionTitle->setFont (juce::Font (22.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    sectionTitle->setJustificationType (juce::Justification::centredTop);
    sectionTitle->setEditable (false, false, false);
    sectionTitle->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    sectionTitle->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    transitionCurveGUI.reset (new TransitionCurveGUI (&(data->transitionCurve)));
    addAndMakeVisible (transitionCurveGUI.get());
    transitionSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (transitionSlider.get());
    transitionSlider->setRange (0, 1, 0);
    transitionSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    transitionSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    transitionLabel.reset (new juce::Label ("new label",
                                            TRANS("Transition")));
    addAndMakeVisible (transitionLabel.get());
    transitionLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    transitionLabel->setJustificationType (juce::Justification::centred);
    transitionLabel->setEditable (false, false, false);
    transitionLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    transitionLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    midpointSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (midpointSlider.get());
    midpointSlider->setRange (0, 1, 0);
    midpointSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    midpointSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    midpointLabel.reset (new juce::Label ("new label",
                                          TRANS("Midpoint\n")));
    addAndMakeVisible (midpointLabel.get());
    midpointLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    midpointLabel->setJustificationType (juce::Justification::centred);
    midpointLabel->setEditable (false, false, false);
    midpointLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    midpointLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    snappingCurveLabel.reset (new juce::Label ("new label",
                                               TRANS("Scale Note Snapping Curve")));
    addAndMakeVisible (snappingCurveLabel.get());
    snappingCurveLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    snappingCurveLabel->setJustificationType (juce::Justification::centred);
    snappingCurveLabel->setEditable (false, false, false);
    snappingCurveLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    snappingCurveLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    // @TODO:  Reintroduce interpolation dimension option

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

    sectionTitle = nullptr;
    transitionCurveGUI = nullptr;
    transitionSlider = nullptr;
    transitionLabel = nullptr;
    midpointSlider = nullptr;
    midpointLabel = nullptr;
    snappingCurveLabel = nullptr;


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

    {
        int x = (getWidth() / 2) - (150 / 2), y = 22, width = 150, height = 2;
        juce::Colour fillColour = juce::Colour (0xfffb00ff);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ConversionModule::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    sectionTitle->setBounds (0, 0, proportionOfWidth (1.0000f), 24);
    transitionCurveGUI->setBounds (proportionOfWidth (0.0000f), (0 + 24) + 16, proportionOfWidth (1.0000f), getHeight() - 160);
    transitionSlider->setBounds (0, getHeight() - 96, proportionOfWidth (0.4987f), 96);
    transitionLabel->setBounds (0 + 0, (getHeight() - 96) + 0 - 16, proportionOfWidth (0.4987f), 16);
    midpointSlider->setBounds (proportionOfWidth (0.4987f), getHeight() - 96, proportionOfWidth (0.4987f), 96);
    midpointLabel->setBounds (proportionOfWidth (0.4987f) + juce::roundToInt (proportionOfWidth (0.4987f) * 0.0000f), (getHeight() - 96) + 0 - 16, juce::roundToInt (proportionOfWidth (0.4987f) * 1.0000f), 16);
    snappingCurveLabel->setBounds ((getWidth() / 2) - (224 / 2), 0 + 24, 224, 16);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
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
  <BACKGROUND backgroundColour="323e44">
    <RECT pos="0Cc 22 150 2" fill="solid: fffb00ff" hasStroke="0"/>
  </BACKGROUND>
  <LABEL name="sectionTitle" id="a42bffd032a0d19b" memberName="sectionTitle"
         virtualName="" explicitFocusOrder="0" pos="0 0 100% 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Conversion&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="22.0" kerning="0.0" bold="1" italic="0" justification="12"
         typefaceStyle="Bold"/>
  <JUCERCOMP name="" id="58460eddec1ae63f" memberName="transitionCurveGUI"
             virtualName="" explicitFocusOrder="0" pos="0% 0R 100% 160M" posRelativeY="de0e609ae3dc6772"
             sourceFile="../../Components/TransitionCurveGUI.cpp" constructorParams="&amp;(data-&gt;transitionCurve)"/>
  <SLIDER name="new slider" id="9f561ed4f957bf22" memberName="transitionSlider"
          virtualName="" explicitFocusOrder="0" pos="0 0Rr 49.846% 96"
          min="0.0" max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="0"/>
  <LABEL name="new label" id="ce42b31741efd25e" memberName="transitionLabel"
         virtualName="" explicitFocusOrder="0" pos="0 0r 49.846% 16" posRelativeX="9f561ed4f957bf22"
         posRelativeY="9f561ed4f957bf22" edTextCol="ff000000" edBkgCol="0"
         labelText="Transition" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="b39d181ab4de0d6d" memberName="midpointSlider"
          virtualName="" explicitFocusOrder="0" pos="49.846% 0Rr 49.846% 96"
          min="0.0" max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="0"/>
  <LABEL name="new label" id="4eb01ae82b3ff35c" memberName="midpointLabel"
         virtualName="" explicitFocusOrder="0" pos="0% 0r 100% 16" posRelativeX="b39d181ab4de0d6d"
         posRelativeY="b39d181ab4de0d6d" posRelativeW="b39d181ab4de0d6d"
         edTextCol="ff000000" edBkgCol="0" labelText="Midpoint&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="de0e609ae3dc6772" memberName="snappingCurveLabel"
         virtualName="" explicitFocusOrder="0" pos="0Cc 0R 224 16" posRelativeY="a42bffd032a0d19b"
         edTextCol="ff000000" edBkgCol="0" labelText="Scale Note Snapping Curve"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


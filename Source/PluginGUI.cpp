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
PluginGUI::PluginGUI (XenMidiRetunerAudioProcessor *processorA)
{
    //[Constructor_pre] You can add your own custom stuff here..
    processor = processorA;
    //[/Constructor_pre]

    keyboardVisual.reset (new KeyboardVisual());
    addAndMakeVisible (keyboardVisual.get());
    scaleFrequenciesOverlay.reset (new ScaleFrequenciesOverlay (keyboardVisual.get(), processor));
    addAndMakeVisible (scaleFrequenciesOverlay.get());
    out_pitch_bend_range.reset (new Slider ("new slider"));
    addAndMakeVisible (out_pitch_bend_range.get());
    out_pitch_bend_range->setRange (1, 96, 1);
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

    noteAndFreqOverlay.reset (new NoteAndFrequencyOverlay (keyboardVisual.get(), processor));
    addAndMakeVisible (noteAndFreqOverlay.get());
    component.reset (new InputModule (processor));
    addAndMakeVisible (component.get());
    component2.reset (new ScaleEditor (processor));
    addAndMakeVisible (component2.get());
    conversionModule.reset (new ConversionModule());
    addAndMakeVisible (conversionModule.get());

    //[UserPreSize]
    //[/UserPreSize]

    setSize (1000, 400);


    //[Constructor] You can add your own custom stuff here..
    out_pitch_bend_range->setValue(processor->out_pitch_bend_range->get());
    processor->interpolationCurve = conversionModule->getTransitionCurve();
    //[/Constructor]
}

PluginGUI::~PluginGUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    keyboardVisual = nullptr;
    scaleFrequenciesOverlay = nullptr;
    out_pitch_bend_range = nullptr;
    label = nullptr;
    noteAndFreqOverlay = nullptr;
    component = nullptr;
    component2 = nullptr;
    conversionModule = nullptr;


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
        int x = proportionOfWidth (0.2000f), y = 0, width = 1, height = proportionOfHeight (0.8000f);
        Colour fillColour = Colour (0xffb6b6b6);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = proportionOfWidth (0.8000f), y = 1, width = 1, height = proportionOfHeight (0.8000f);
        Colour fillColour = Colour (0xffb6b6b6);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = proportionOfWidth (0.4000f), y = 0, width = 1, height = proportionOfHeight (0.8000f);
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
    scaleFrequenciesOverlay->setBounds (0 + 0, (getHeight() - proportionOfHeight (0.2000f)) + proportionOfHeight (0.2000f) - (roundToInt (proportionOfHeight (0.2000f) * 0.6000f)), roundToInt (proportionOfWidth (1.0000f) * 1.0000f), roundToInt (proportionOfHeight (0.2000f) * 0.6000f));
    noteAndFreqOverlay->setBounds (0 + 0, (getHeight() - proportionOfHeight (0.2000f)) + proportionOfHeight (0.2000f) - (roundToInt (proportionOfHeight (0.2000f) * 0.6000f)), roundToInt (proportionOfWidth (1.0000f) * 1.0000f), roundToInt (proportionOfHeight (0.2000f) * 0.6000f));
    component->setBounds (0, 0, proportionOfWidth (0.2000f), proportionOfHeight (0.8000f));
    component2->setBounds (proportionOfWidth (0.2000f), 0, proportionOfWidth (0.2000f), proportionOfHeight (0.8000f));
    conversionModule->setBounds (proportionOfWidth (0.4000f), 0, proportionOfWidth (0.4000f), proportionOfHeight (0.8000f));
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
            *(processor->out_pitch_bend_range) = sliderThatWasMoved->getValue();
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
                 parentClasses="public Component" constructorParams="XenMidiRetunerAudioProcessor *processorA"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="1000" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44">
    <RECT pos="20% 0 1 80%" fill="solid: ffb6b6b6" hasStroke="0"/>
    <RECT pos="80% 1 1 80%" fill="solid: ffb6b6b6" hasStroke="0"/>
    <RECT pos="40% 0 1 80%" fill="solid: ffb6b6b6" hasStroke="0"/>
  </BACKGROUND>
  <JUCERCOMP name="" id="9a893a36dc7e0c36" memberName="keyboardVisual" virtualName=""
             explicitFocusOrder="0" pos="0 0Rr 100% 20%" sourceFile="EditorModules/KeyboardVisual.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="31178f5ce0e8830f" memberName="scaleFrequenciesOverlay"
             virtualName="" explicitFocusOrder="0" pos="0 0Rr 100% 60%" posRelativeX="9a893a36dc7e0c36"
             posRelativeY="9a893a36dc7e0c36" posRelativeW="9a893a36dc7e0c36"
             posRelativeH="9a893a36dc7e0c36" sourceFile="EditorModules/ScaleFrequenciesOverlay.cpp"
             constructorParams="keyboardVisual.get(), processor"/>
  <SLIDER name="new slider" id="e3a72a963cc8c6fa" memberName="out_pitch_bend_range"
          virtualName="" explicitFocusOrder="0" pos="840 152 150 24" min="1.0"
          max="96.0" int="1.0" style="IncDecButtons" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="1ac3af9fe857753" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="832 120 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Output Pitch Bend Range (semitones)&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <JUCERCOMP name="" id="d4b4c1a2077d41bb" memberName="noteAndFreqOverlay"
             virtualName="" explicitFocusOrder="0" pos="0 0Rr 100% 60%" posRelativeX="9a893a36dc7e0c36"
             posRelativeY="9a893a36dc7e0c36" posRelativeW="9a893a36dc7e0c36"
             posRelativeH="9a893a36dc7e0c36" sourceFile="EditorModules/NoteAndFrequencyOverlay.cpp"
             constructorParams="keyboardVisual.get(), processor"/>
  <JUCERCOMP name="" id="718dd2c51df8bc00" memberName="component" virtualName=""
             explicitFocusOrder="0" pos="0 0 20% 80%" sourceFile="EditorModules/InputModule.cpp"
             constructorParams="processor"/>
  <JUCERCOMP name="" id="362421b4abac7430" memberName="component2" virtualName=""
             explicitFocusOrder="0" pos="20% 0 20% 80%" sourceFile="EditorModules/ScaleEditor.cpp"
             constructorParams="processor"/>
  <JUCERCOMP name="" id="3e17f48e254318d" memberName="conversionModule" virtualName=""
             explicitFocusOrder="0" pos="40% 0 40% 80%" sourceFile="EditorModules/ConversionModule.cpp"
             constructorParams=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


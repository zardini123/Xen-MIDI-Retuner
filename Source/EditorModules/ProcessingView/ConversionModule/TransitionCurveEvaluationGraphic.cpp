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

#include "TransitionCurveEvaluationGraphic.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TransitionCurveEvaluationGraphic::TransitionCurveEvaluationGraphic ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    juce__label.reset (new juce::Label ("new label",
                                        TRANS("Scale Note Above")));
    addAndMakeVisible (juce__label.get());
    juce__label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label->setJustificationType (juce::Justification::centredRight);
    juce__label->setEditable (false, false, false);
    juce__label->setColour (juce::Label::textColourId, juce::Colour (0xffffdada));
    juce__label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label2.reset (new juce::Label ("new label",
                                         TRANS("Scale Note Below")));
    addAndMakeVisible (juce__label2.get());
    juce__label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label2->setJustificationType (juce::Justification::centredLeft);
    juce__label2->setEditable (false, false, false);
    juce__label2->setColour (juce::Label::textColourId, juce::Colour (0xffffdada));
    juce__label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label3.reset (new juce::Label ("new label",
                                         TRANS("Input Note")));
    addAndMakeVisible (juce__label3.get());
    juce__label3->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    juce__label3->setJustificationType (juce::Justification::centred);
    juce__label3->setEditable (false, false, false);
    juce__label3->setColour (juce::Label::textColourId, juce::Colour (0xffc8ffee));
    juce__label3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label4.reset (new juce::Label ("new label",
                                         TRANS("Output Pitch")));
    addAndMakeVisible (juce__label4.get());
    juce__label4->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    juce__label4->setJustificationType (juce::Justification::centred);
    juce__label4->setEditable (false, false, false);
    juce__label4->setColour (juce::Label::textColourId, juce::Colour (0xfffeb7ff));
    juce__label4->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label4->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label5.reset (new juce::Label ("new label",
                                         TRANS("Above")));
    addAndMakeVisible (juce__label5.get());
    juce__label5->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label5->setJustificationType (juce::Justification::centredTop);
    juce__label5->setEditable (false, false, false);
    juce__label5->setColour (juce::Label::textColourId, juce::Colour (0xffffdada));
    juce__label5->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label5->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label6.reset (new juce::Label ("new label",
                                         TRANS("Below")));
    addAndMakeVisible (juce__label6.get());
    juce__label6->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label6->setJustificationType (juce::Justification::centred);
    juce__label6->setEditable (false, false, false);
    juce__label6->setColour (juce::Label::textColourId, juce::Colour (0xffffdada));
    juce__label6->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label6->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

TransitionCurveEvaluationGraphic::~TransitionCurveEvaluationGraphic()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    juce__label = nullptr;
    juce__label2 = nullptr;
    juce__label3 = nullptr;
    juce__label4 = nullptr;
    juce__label5 = nullptr;
    juce__label6 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TransitionCurveEvaluationGraphic::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        float x = 0, y = 0;
        juce::Colour strokeColour = juce::Colour (0x659e9e9e);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.strokePath (internalPath1, juce::PathStrokeType (5.000f, juce::PathStrokeType::mitered, juce::PathStrokeType::rounded), juce::AffineTransform::translation(x, y));
    }

    {
        float x = 0, y = 0;
        juce::Colour strokeColour = juce::Colour (0xc79e9e9e);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.strokePath (internalPath2, juce::PathStrokeType (5.000f, juce::PathStrokeType::mitered, juce::PathStrokeType::rounded), juce::AffineTransform::translation(x, y));
    }

    {
        float x = 0, y = 0;
        juce::Colour strokeColour = juce::Colour (0xc79e9e9e);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.strokePath (internalPath3, juce::PathStrokeType (5.000f, juce::PathStrokeType::mitered, juce::PathStrokeType::rounded), juce::AffineTransform::translation(x, y));
    }

    {
        float x = 0, y = 0;
        juce::Colour strokeColour = juce::Colour (0xffe82950);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.strokePath (internalPath4, juce::PathStrokeType (5.000f, juce::PathStrokeType::mitered, juce::PathStrokeType::rounded), juce::AffineTransform::translation(x, y));
    }

    {
        float x = 0, y = 0;
        juce::Colour strokeColour = juce::Colour (0xffe82950);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.strokePath (internalPath5, juce::PathStrokeType (5.000f, juce::PathStrokeType::mitered, juce::PathStrokeType::rounded), juce::AffineTransform::translation(x, y));
    }

    {
        float x = 0, y = 0;
        juce::Colour strokeColour = juce::Colour (0xffe82950);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.strokePath (internalPath6, juce::PathStrokeType (5.000f, juce::PathStrokeType::mitered, juce::PathStrokeType::rounded), juce::AffineTransform::translation(x, y));
    }

    {
        float x = 0, y = 0;
        juce::Colour strokeColour = juce::Colour (0xffe82950);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.strokePath (internalPath7, juce::PathStrokeType (5.000f, juce::PathStrokeType::mitered, juce::PathStrokeType::rounded), juce::AffineTransform::translation(x, y));
    }

    {
        float x = 0, y = 0;
        juce::Colour strokeColour = juce::Colour (0xff00ffb2);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.strokePath (internalPath8, juce::PathStrokeType (5.000f, juce::PathStrokeType::mitered, juce::PathStrokeType::rounded), juce::AffineTransform::translation(x, y));
    }

    {
        float x = 0, y = 0;
        juce::Colour strokeColour = juce::Colour (0xfffb00ff);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.strokePath (internalPath9, juce::PathStrokeType (5.000f, juce::PathStrokeType::mitered, juce::PathStrokeType::rounded), juce::AffineTransform::translation(x, y));
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TransitionCurveEvaluationGraphic::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    juce__label->setBounds (proportionOfWidth (0.7506f) - 150, getHeight() - 24, 150, 24);
    juce__label2->setBounds (proportionOfWidth (0.0000f), getHeight() - 24, 150, 24);
    juce__label3->setBounds (proportionOfWidth (0.3813f) - (150 / 2), 0, 150, 24);
    juce__label4->setBounds (proportionOfWidth (0.8003f), 0, proportionOfWidth (0.1997f), 24);
    juce__label5->setBounds (proportionOfWidth (0.8003f), 26, proportionOfWidth (0.1997f), 16);
    juce__label6->setBounds (proportionOfWidth (0.8003f), getHeight() - 24, proportionOfWidth (0.1997f), 24);
    internalPath1.clear();
    internalPath1.startNewSubPath (static_cast<float> (proportionOfWidth (0.8000f)), static_cast<float> (proportionOfHeight (0.5000f)));
    internalPath1.lineTo (static_cast<float> (proportionOfWidth (0.5000f)), static_cast<float> (proportionOfHeight (0.5000f)));

    internalPath2.clear();
    internalPath2.startNewSubPath (static_cast<float> (proportionOfWidth (0.8000f)), 24.0f);
    internalPath2.lineTo (static_cast<float> (proportionOfWidth (0.8000f)), static_cast<float> (getHeight() - 30));

    internalPath3.clear();
    internalPath3.startNewSubPath (static_cast<float> (proportionOfWidth (0.7500f)), static_cast<float> (getHeight() - 30));
    internalPath3.lineTo (10.0f, static_cast<float> (getHeight() - 30));

    internalPath4.clear();
    internalPath4.startNewSubPath (10.0f, 24.0f);
    internalPath4.lineTo (10.0f, static_cast<float> (getHeight() - 30));

    internalPath5.clear();
    internalPath5.startNewSubPath (static_cast<float> (proportionOfWidth (0.7500f)), 24.0f);
    internalPath5.lineTo (static_cast<float> (proportionOfWidth (0.7500f)), static_cast<float> (getHeight() - 30));

    internalPath6.clear();
    internalPath6.startNewSubPath (static_cast<float> (getWidth() - 10), 24.0f);
    internalPath6.lineTo (static_cast<float> (proportionOfWidth (0.8021f)), 24.0f);

    internalPath7.clear();
    internalPath7.startNewSubPath (static_cast<float> (getWidth() - 10), static_cast<float> (getHeight() - 30));
    internalPath7.lineTo (static_cast<float> (proportionOfWidth (0.8000f)), static_cast<float> (getHeight() - 30));

    internalPath8.clear();
    internalPath8.startNewSubPath (static_cast<float> (proportionOfWidth (0.5000f)), 24.0f);
    internalPath8.lineTo (static_cast<float> (proportionOfWidth (0.5000f)), static_cast<float> (getHeight() - 30));

    internalPath9.clear();
    internalPath9.startNewSubPath (static_cast<float> (getWidth() - 10), static_cast<float> (proportionOfHeight (0.5000f)));
    internalPath9.lineTo (static_cast<float> (proportionOfWidth (0.8000f)), static_cast<float> (proportionOfHeight (0.5000f)));

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TransitionCurveEvaluationGraphic"
                 componentName="" parentClasses="public juce::Component" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="323e44">
    <PATH pos="0 0 100 100" fill="solid: a52a2b" hasStroke="1" stroke="5, mitered, rounded"
          strokeColour="solid: 659e9e9e" nonZeroWinding="1">s 80% 50% l 50% 50%</PATH>
    <PATH pos="0 0 100 100" fill="solid: a52a2b" hasStroke="1" stroke="5, mitered, rounded"
          strokeColour="solid: c79e9e9e" nonZeroWinding="1">s 80% 24 l 80% 30R</PATH>
    <PATH pos="0 0 100 100" fill="solid: a52a2b" hasStroke="1" stroke="5, mitered, rounded"
          strokeColour="solid: c79e9e9e" nonZeroWinding="1">s 75% 30R l 10 30R</PATH>
    <PATH pos="0 0 100 100" fill="solid: a52a2b" hasStroke="1" stroke="5, mitered, rounded"
          strokeColour="solid: ffe82950" nonZeroWinding="1">s 10 24 l 10 30R</PATH>
    <PATH pos="0 0 100 100" fill="solid: a52a2b" hasStroke="1" stroke="5, mitered, rounded"
          strokeColour="solid: ffe82950" nonZeroWinding="1">s 75% 24 l 75% 30R</PATH>
    <PATH pos="0 0 100 100" fill="solid: a52a2b" hasStroke="1" stroke="5, mitered, rounded"
          strokeColour="solid: ffe82950" nonZeroWinding="1">s 10R 24 l 80.206% 24</PATH>
    <PATH pos="0 0 100 100" fill="solid: a52a2b" hasStroke="1" stroke="5, mitered, rounded"
          strokeColour="solid: ffe82950" nonZeroWinding="1">s 10R 30R l 80% 30R</PATH>
    <PATH pos="0 0 100 100" fill="solid: a52a2b" hasStroke="1" stroke="5, mitered, rounded"
          strokeColour="solid: ff00ffb2" nonZeroWinding="1">s 50% 24 l 50% 30R</PATH>
    <PATH pos="0 0 100 100" fill="solid: a52a2b" hasStroke="1" stroke="5, mitered, rounded"
          strokeColour="solid: fffb00ff" nonZeroWinding="1">s 10R 50% l 80% 50%</PATH>
  </BACKGROUND>
  <LABEL name="new label" id="6b71234c2e8cc65a" memberName="juce__label"
         virtualName="" explicitFocusOrder="0" pos="75.064%r 0Rr 150 24"
         textCol="ffffdada" edTextCol="ff000000" edBkgCol="0" labelText="Scale Note Above"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="34"/>
  <LABEL name="new label" id="15cc2af9d1c259bb" memberName="juce__label2"
         virtualName="" explicitFocusOrder="0" pos="0% 0Rr 150 24" textCol="ffffdada"
         edTextCol="ff000000" edBkgCol="0" labelText="Scale Note Below"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <LABEL name="new label" id="cb515b8df61b4129" memberName="juce__label3"
         virtualName="" explicitFocusOrder="0" pos="38.132%c 0 150 24"
         textCol="ffc8ffee" edTextCol="ff000000" edBkgCol="0" labelText="Input Note"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="1"
         italic="0" justification="36" typefaceStyle="Bold"/>
  <LABEL name="new label" id="14583853aa9d533d" memberName="juce__label4"
         virtualName="" explicitFocusOrder="0" pos="80.034% 0 19.966% 24"
         textCol="fffeb7ff" edTextCol="ff000000" edBkgCol="0" labelText="Output Pitch"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="1"
         italic="0" justification="36" typefaceStyle="Bold"/>
  <LABEL name="new label" id="ee7edf8ab79d938f" memberName="juce__label5"
         virtualName="" explicitFocusOrder="0" pos="80.034% 26 19.966% 16"
         textCol="ffffdada" edTextCol="ff000000" edBkgCol="0" labelText="Above"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="12"/>
  <LABEL name="new label" id="e3b770dbce9bae82" memberName="juce__label6"
         virtualName="" explicitFocusOrder="0" pos="80.034% 0Rr 19.966% 24"
         textCol="ffffdada" edTextCol="ff000000" edBkgCol="0" labelText="Below"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


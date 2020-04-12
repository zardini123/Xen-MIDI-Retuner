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

#include "ConversionModule.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ConversionModule::ConversionModule ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    section_title.reset (new Label ("section_title",
                                    TRANS("Conversion\n")));
    addAndMakeVisible (section_title.get());
    section_title->setFont (Font (22.00f, Font::plain).withTypefaceStyle ("Bold"));
    section_title->setJustificationType (Justification::centredTop);
    section_title->setEditable (false, false, false);
    section_title->setColour (TextEditor::textColourId, Colours::black);
    section_title->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    transitionCurve.reset (new TransitionCurve());
    addAndMakeVisible (transitionCurve.get());
    slider.reset (new Slider ("new slider"));
    addAndMakeVisible (slider.get());
    slider->setRange (0, 1, 0);
    slider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    slider->addListener (this);

    slider->setBounds (0, 80, 104, 104);

    label.reset (new Label ("new label",
                            TRANS("Scale Note Snapping Curve")));
    addAndMakeVisible (label.get());
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label->setBounds (0, 40, 104, 40);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ConversionModule::~ConversionModule()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    section_title = nullptr;
    transitionCurve = nullptr;
    slider = nullptr;
    label = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ConversionModule::paint (Graphics& g)
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
    transitionCurve->setBounds (proportionOfWidth (0.1000f), 32, proportionOfWidth (0.9000f), 208);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ConversionModule::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == slider.get())
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
        transitionCurve->setTransition(slider->getValue());
        //[/UserSliderCode_slider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
TransitionCurve *ConversionModule::getTransitionCurve()
{
    return &(*transitionCurve);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ConversionModule" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="323e44"/>
  <LABEL name="section_title" id="a42bffd032a0d19b" memberName="section_title"
         virtualName="" explicitFocusOrder="0" pos="0 0 100% 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Conversion&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="22.0" kerning="0.0" bold="1" italic="0" justification="12"
         typefaceStyle="Bold"/>
  <JUCERCOMP name="" id="58460eddec1ae63f" memberName="transitionCurve" virtualName=""
             explicitFocusOrder="0" pos="9.991% 32 90.009% 208" sourceFile="Components/TransitionCurve.cpp"
             constructorParams=""/>
  <SLIDER name="new slider" id="9f561ed4f957bf22" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="0 80 104 104" min="0.0" max="1.0"
          int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="de0e609ae3dc6772" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="0 40 104 40" edTextCol="ff000000"
         edBkgCol="0" labelText="Scale Note Snapping Curve" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.8

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
    out_pitch_bend_range->setTooltip (TRANS("Output Pitch Bend should be set to the Input Pitch Bend Range of your instrument that you are sending the MIDI to.\n"
    "\n"
    "Output should be equal to or greater than this plugin\'s Input pitch bend if note retrigger is unwanted."));
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


    //[Destructor]. You can add your own custom destruction code here..
    outputPitchbendAttachment = nullptr;
    //[/Destructor]
}

//==============================================================================
void OutputModule::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        int x = (getWidth() / 2) - (108 / 2), y = 24, width = 108, height = 2;
        juce::Colour fillColour = juce::Colour (0xffffae00);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void OutputModule::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    section_title->setBounds (0, 0, proportionOfWidth (1.0000f), 24);
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

<JUCER_COMPONENT documentType="Component" className="OutputModule" componentName=""
                 parentClasses="public ComponentWithReferenceToData" constructorParams="ProcessorData *dataReference"
                 variableInitialisers="ComponentWithReferenceToData (dataReference)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="323e44">
    <RECT pos="0Cc 24 108 2" fill="solid: ffffae00" hasStroke="0"/>
  </BACKGROUND>
  <SLIDER name="new slider" id="e3a72a963cc8c6fa" memberName="out_pitch_bend_range"
          virtualName="" explicitFocusOrder="0" pos="8 64 150 24" tooltip="Output Pitch Bend should be set to the Input Pitch Bend Range of your instrument that you are sending the MIDI to.&#10;&#10;Output should be equal to or greater than this plugin's Input pitch bend if note retrigger is unwanted."
          min="1.0" max="96.0" int="1.0" style="IncDecButtons" textBoxPos="TextBoxLeft"
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
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


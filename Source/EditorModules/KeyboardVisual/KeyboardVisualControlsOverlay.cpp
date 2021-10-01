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

#include "KeyboardVisualControlsOverlay.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
KeyboardVisualControlsOverlay::KeyboardVisualControlsOverlay (ProcessorData *dataReference, KeyboardVisual *keyboardVis)
    : ComponentWithReferenceToData (dataReference)
{
    //[Constructor_pre] You can add your own custom stuff here..
    keyboard = keyboardVis;
    //[/Constructor_pre]

    viewStartingMidiNote.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (viewStartingMidiNote.get());
    viewStartingMidiNote->setRange (-20, 140, 0);
    viewStartingMidiNote->setSliderStyle (juce::Slider::LinearBar);
    viewStartingMidiNote->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);

    viewEndingMidiNote.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (viewEndingMidiNote.get());
    viewEndingMidiNote->setRange (-20, 140, 0);
    viewEndingMidiNote->setSliderStyle (juce::Slider::LinearBar);
    viewEndingMidiNote->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);

    viewZoomIn.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (viewZoomIn.get());
    viewZoomIn->setButtonText (TRANS("+"));
    viewZoomIn->setConnectedEdges (juce::Button::ConnectedOnLeft | juce::Button::ConnectedOnRight);
    viewZoomIn->addListener (this);
    viewZoomIn->setColour (juce::TextButton::buttonColourId, juce::Colour (0xc71b1b1b));

    viewZoomOut.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (viewZoomOut.get());
    viewZoomOut->setButtonText (TRANS("-"));
    viewZoomOut->setConnectedEdges (juce::Button::ConnectedOnLeft);
    viewZoomOut->addListener (this);
    viewZoomOut->setColour (juce::TextButton::buttonColourId, juce::Colour (0xc71b1b1b));

    viewShiftRight.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (viewShiftRight.get());
    viewShiftRight->setButtonText (TRANS(">"));
    viewShiftRight->setConnectedEdges (juce::Button::ConnectedOnLeft | juce::Button::ConnectedOnRight);
    viewShiftRight->addListener (this);
    viewShiftRight->setColour (juce::TextButton::buttonColourId, juce::Colour (0xc71b1b1b));

    viewShiftLeft.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (viewShiftLeft.get());
    viewShiftLeft->setButtonText (TRANS("<"));
    viewShiftLeft->setConnectedEdges (juce::Button::ConnectedOnRight);
    viewShiftLeft->addListener (this);
    viewShiftLeft->setColour (juce::TextButton::buttonColourId, juce::Colour (0xc71b1b1b));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    // visualOptionsViewport->setVisible(false);

    viewStartingMidiNoteAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(data->apvts, "keyboard_visuals-viewport_starting_note", *viewStartingMidiNote.get()));
    viewEndingMidiNoteAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(data->apvts, "keyboard_visuals-viewport_ending_note", *viewEndingMidiNote.get()));

    data->apvts.addParameterListener("keyboard_visuals-viewport_starting_note", this);
    data->apvts.addParameterListener("keyboard_visuals-viewport_ending_note", this);

    keyboard->setKeyboardSettings(viewStartingMidiNote->getValue(), viewEndingMidiNote->getValue());
    //[/Constructor]
}

KeyboardVisualControlsOverlay::~KeyboardVisualControlsOverlay()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    viewStartingMidiNote = nullptr;
    viewEndingMidiNote = nullptr;
    viewZoomIn = nullptr;
    viewZoomOut = nullptr;
    viewShiftRight = nullptr;
    viewShiftLeft = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void KeyboardVisualControlsOverlay::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        float x = static_cast<float> (getWidth() - -21 - proportionOfWidth (0.2708f)), y = static_cast<float> (-4), width = static_cast<float> (proportionOfWidth (0.2708f)), height = 32.0f;
        juce::Colour fillColour = juce::Colour (0xad494848);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 3.500f);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void KeyboardVisualControlsOverlay::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    viewStartingMidiNote->setBounds (proportionOfWidth (0.9146f) - proportionOfWidth (0.0723f), 0, proportionOfWidth (0.0723f), 23);
    viewEndingMidiNote->setBounds (proportionOfWidth (0.9931f) - proportionOfWidth (0.0723f), 0, proportionOfWidth (0.0723f), 23);
    viewZoomIn->setBounds (proportionOfWidth (0.8161f) - proportionOfWidth (0.0215f), 0, proportionOfWidth (0.0215f), 24);
    viewZoomOut->setBounds (proportionOfWidth (0.8354f) - proportionOfWidth (0.0215f), 0, proportionOfWidth (0.0215f), 24);
    viewShiftRight->setBounds (proportionOfWidth (0.7961f) - proportionOfWidth (0.0215f), 0, proportionOfWidth (0.0215f), 24);
    viewShiftLeft->setBounds (proportionOfWidth (0.7761f) - proportionOfWidth (0.0215f), 0, proportionOfWidth (0.0215f), 24);
    //[UserResized] Add your own custom resize handling here..

    // juce::Component *visualOptionsComponent = visualOptionsViewport->getViewedComponent();
    // visualOptionsComponent->setSize(visualOptionsViewport->getWidth(), visualOptionsComponent->getHeight());

    //[/UserResized]
}

void KeyboardVisualControlsOverlay::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    bool isViewRelatedButton = false;
    bool isZoomButton = false;
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == viewZoomIn.get())
    {
        //[UserButtonCode_viewZoomIn] -- add your button handler code here..
        isViewRelatedButton = true;
        isZoomButton = true;
        //[/UserButtonCode_viewZoomIn]
    }
    else if (buttonThatWasClicked == viewZoomOut.get())
    {
        //[UserButtonCode_viewZoomOut] -- add your button handler code here..
        isViewRelatedButton = true;
        isZoomButton = true;
        //[/UserButtonCode_viewZoomOut]
    }
    else if (buttonThatWasClicked == viewShiftRight.get())
    {
        //[UserButtonCode_viewShiftRight] -- add your button handler code here..
        isViewRelatedButton = true;
        //[/UserButtonCode_viewShiftRight]
    }
    else if (buttonThatWasClicked == viewShiftLeft.get())
    {
        //[UserButtonCode_viewShiftLeft] -- add your button handler code here..
        isViewRelatedButton = true;
        //[/UserButtonCode_viewShiftLeft]
    }

    //[UserbuttonClicked_Post]
    if (isViewRelatedButton) {
        RangedAudioParameter *startingNoteParameter = this->data->apvts.getParameter("keyboard_visuals-viewport_starting_note");
        RangedAudioParameter *endingNoteParameter = this->data->apvts.getParameter("keyboard_visuals-viewport_ending_note");

        float startingNote = startingNoteParameter->convertFrom0to1(startingNoteParameter->getValue());
        float endingNote = endingNoteParameter->convertFrom0to1(endingNoteParameter->getValue());

        float newStartingNote = startingNote;
        float newEndingNote = endingNote;

        // @TODO: Ensure the bounds never flip (i.e. max becomes min).
        if (isZoomButton) {
            // Zoom
            float mid = (startingNote + endingNote) / 2.0f;
            if (buttonThatWasClicked == viewZoomIn.get()) {
                newStartingNote = (mid + startingNote) / 2.0f;
                newEndingNote = (mid + endingNote) / 2.0f;
            } else {
                newStartingNote = (startingNote * 2) - mid;
                newEndingNote = (endingNote * 2) - mid;
            }
        } else {
            // Shift
            float difference = endingNote - startingNote;
            float amountToShift = difference / 8;
            newStartingNote += amountToShift * ((buttonThatWasClicked == viewShiftRight.get())? 1 : -1);
            newEndingNote += amountToShift * ((buttonThatWasClicked == viewShiftRight.get())? 1 : -1);

            float lowerBound = startingNoteParameter->getNormalisableRange().start;
            float upperBound = endingNoteParameter->getNormalisableRange().end;
            if (newStartingNote < lowerBound) {
                newEndingNote = lowerBound + difference;
            }
            if (newEndingNote > upperBound) {
                newStartingNote = upperBound - difference;
            }
        }

        // viewTest->setText(std::to_string(newStartingNote) + " " + std::to_string(newEndingNote), dontSendNotification);

        if (std::abs(newStartingNote - newEndingNote) > 1) {
            startingNoteParameter->setValueNotifyingHost(startingNoteParameter->convertTo0to1(newStartingNote));
            endingNoteParameter->setValueNotifyingHost(endingNoteParameter->convertTo0to1(newEndingNote));
        }
    }
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void KeyboardVisualControlsOverlay::parameterChanged(const String &parameterID, float newValue)
{
    if (parameterID == "keyboard_visuals-viewport_starting_note")
    {
        keyboard->setKeyboardSettings(newValue, keyboard->getEndingMidiNote());
    }
    else if (parameterID == "keyboard_visuals-viewport_ending_note")
    {
        keyboard->setKeyboardSettings(keyboard->getStartingMidiNote(), newValue);
    }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="KeyboardVisualControlsOverlay"
                 componentName="" parentClasses="public ComponentWithReferenceToData, public juce::AudioProcessorValueTreeState::Listener"
                 constructorParams="ProcessorData *dataReference, KeyboardVisual *keyboardVis"
                 variableInitialisers="ComponentWithReferenceToData (dataReference)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="0">
    <ROUNDRECT pos="-21Rr -4 27.078% 32" cornerSize="3.5" fill="solid: ad494848"
               hasStroke="0"/>
  </BACKGROUND>
  <SLIDER name="new slider" id="3ab8f24ac17b1ecb" memberName="viewStartingMidiNote"
          virtualName="" explicitFocusOrder="0" pos="91.462%r 0 7.231% 23"
          min="-20.0" max="140.0" int="0.0" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="67d1cdb27238fff2" memberName="viewEndingMidiNote"
          virtualName="" explicitFocusOrder="0" pos="99.308%r 0 7.231% 23"
          min="-20.0" max="140.0" int="0.0" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <TEXTBUTTON name="new button" id="18e3d9dff2ff4a22" memberName="viewZoomIn"
              virtualName="" explicitFocusOrder="0" pos="81.615%r 0 2.154% 24"
              bgColOff="c71b1b1b" buttonText="+" connectedEdges="3" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="19880e01f407e55" memberName="viewZoomOut"
              virtualName="" explicitFocusOrder="0" pos="83.538%r 0 2.154% 24"
              bgColOff="c71b1b1b" buttonText="-" connectedEdges="1" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="434951d4a86802b4" memberName="viewShiftRight"
              virtualName="" explicitFocusOrder="0" pos="79.615%r 0 2.154% 24"
              bgColOff="c71b1b1b" buttonText="&gt;" connectedEdges="3" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="8480ec4bdf0d0b9e" memberName="viewShiftLeft"
              virtualName="" explicitFocusOrder="0" pos="77.615%r 0 2.154% 24"
              bgColOff="c71b1b1b" buttonText="&lt;" connectedEdges="2" needsCallback="1"
              radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


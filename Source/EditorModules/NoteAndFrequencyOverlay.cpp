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
#include "../Utilities.h"
#include <sstream> //for std::stringstream
//[/Headers]

#include "NoteAndFrequencyOverlay.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
NoteAndFrequencyOverlay::NoteAndFrequencyOverlay (ProcessorData *dataReference, KeyboardVisual *keyboardVis)
    : ComponentWithReferenceToData (dataReference)
{
    //[Constructor_pre] You can add your own custom stuff here..
    keyboard = keyboardVis;
    //[/Constructor_pre]


    //[UserPreSize]
//    const void * address = static_cast<const void*>(keyboardVis);
//    std::stringstream ss;
//    ss << address;
//
//    label->setText(ss.str(), dontSendNotification);
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    startTimerHz (UPDATE_RATE);
    //[/Constructor]
}

NoteAndFrequencyOverlay::~NoteAndFrequencyOverlay()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void NoteAndFrequencyOverlay::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    /*
    int firstNote = keyboard->getFirstMidiNote();
    int lastNote = keyboard->getLastMidiNote();
    double continuousMidiNote = (2 * (lastNote - firstNote) / PI) * std::abs(std::asin(std::sin(2 * (PI / 200) * time))) + firstNote;
    int discreteMidiNote = std::round(continuousMidiNote);

    int x = keyboard->ConvertDiscreteMidiNoteToPercentWidth(discreteMidiNote) * proportionOfWidth(0.8f);
    int y = 0, width = 1, height = 100;
    Colour fillColour = Colour (0xffd1e40b);
    g.setColour (fillColour);
    g.fillRect (x, y, width, height);

    x = keyboard->ConvertContinuousMidiNoteToPercentWidth(continuousMidiNote) * proportionOfWidth(0.8f);
    fillColour = Colour (0xff00ff54);
    g.setColour (fillColour);
    g.fillRect (x, y, width, height);
     */

    ProcessorData *processorData = data;

    int y = 0, width = 1, height = 100;
    int widthOfComponent = proportionOfWidth(1.0f);
    for (int i = 0; i < MAX_MIDI_CHANNELS; i++) {
        // Check to see if input vector is being used on the processor thread
        const ScopedTryLock myScopedTryLock (processorData->inputLock);

        if (myScopedTryLock.isLocked())
        {
            int in_pitch_bend_range = *data->apvts.getRawParameterValue("in_pitch_bend_range");
            int out_pitch_bend_range = *data->apvts.getRawParameterValue("out_pitch_bend_range");
            
            for (std::vector<Note>::iterator it = processorData->input[i].notes.begin(); it != processorData->input[i].notes.end(); ++it) {
                float continuousMidiNote = it->midiNote + pitchwheelPosToSemitones(processorData->input[i].pitchwheel, in_pitch_bend_range);

                double x = keyboard->ConvertContinuousMidiNoteToPercentWidth(continuousMidiNote) * widthOfComponent;
                double midiNoteX = keyboard->ConvertDiscreteMidiNoteToPercentWidth(it->midiNote) * widthOfComponent;

                Note *currentNote = &(*it);

                if (currentNote == processorData->input[i].priorityNote) {
                    // In pitchbend visualzation under priority note
                    Colour fillColour = Colour (0x3f00ffb2);
                    int x1 = keyboard->ConvertContinuousMidiNoteToPercentWidth((float)it->midiNote - in_pitch_bend_range) * widthOfComponent;
                    int x2 = keyboard->ConvertContinuousMidiNoteToPercentWidth((float)it->midiNote + in_pitch_bend_range) * widthOfComponent;

                    g.setColour (fillColour);
                    g.fillRect (x1, y, x2 - x1, height);

                    /*
                    // Show the resolution of MIDI 1's 14 bit pitchwheel parameter
                    for (int p = 0; p <= 16383; p++)
                    {
                        double offset = pitchwheelPosToSemitones(p, processorData->out_pitch_bend_range);
                        g.setColour (fillColour);
                        g.fillRect (x1 + offset, y, 1, height);
                    }
                     */

                    // Draw Continous priority note
                    fillColour = Colour (0xff00ffb2);
                    g.setColour (fillColour);
                    g.fillRect (x - 1, y, width + 3, height);

                    // Draw prioirty note
                    fillColour = Colour (0xff00ffb2);
                    g.setColour (fillColour);
                    g.fillRect (midiNoteX - 1, y, width + 3, height);

                    // Converted Note
                    double xConverted = keyboard->ConvertContinuousMidiNoteToPercentWidth(processorData->input[i].scaleConvertedPriorityNote) * widthOfComponent;
                    fillColour = Colour (0xfffb00ff);
                    g.setColour (fillColour);
                    g.fillRect (xConverted - 1, y, width + 3, height);
                } else {
                    Colour fillColour = Colour (0xffd1e40b);

                    // Draw Continous Note
                    g.setColour (fillColour);
                    g.fillRect (x, y, width, height);

                    // Draw Note
                    fillColour = Colour (0x5dd1e40b);
                    g.setColour (fillColour);
                    g.fillRect (midiNoteX, y, width, height);
                }
            }

            if (processorData->input[i].notes.size() > 0)
            {
                // Converted Note Closest Note
                double xConverted = keyboard->ConvertDiscreteMidiNoteToPercentWidth(processorData->output[i].initalMidiNote) * widthOfComponent;
                Colour fillColour = Colour (0x4dfb00ff);
                g.setColour (fillColour);
                g.fillRect (xConverted - 1, y, width + 3, height);

                // Out pitchbend
                fillColour = Colour (0x3f00a2ff);
                int x3 = keyboard->ConvertDiscreteMidiNoteToPercentWidth(processorData->output[i].initalMidiNote - out_pitch_bend_range) * widthOfComponent;
                int x4 = keyboard->ConvertDiscreteMidiNoteToPercentWidth(processorData->output[i].initalMidiNote + out_pitch_bend_range) * widthOfComponent;

                g.setColour (fillColour);
                g.fillRect (x3, y, x4 - x3, height);

                // Current Midi Note
                xConverted = keyboard->ConvertDiscreteMidiNoteToPercentWidth(processorData->output[i].currentMidiNoteNumber) * widthOfComponent;
                fillColour = Colour (0xffffae00);
                g.setColour (fillColour);
                g.fillRect (xConverted - 1, y, width + 3, height);
            }
        }
    }
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void NoteAndFrequencyOverlay::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void NoteAndFrequencyOverlay::timerCallback()
{
    repaint();
    time += 1 / (double)UPDATE_RATE;
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="NoteAndFrequencyOverlay"
                 componentName="" parentClasses="public ComponentWithReferenceToData, private Timer"
                 constructorParams="ProcessorData *dataReference, KeyboardVisual *keyboardVis"
                 variableInitialisers="ComponentWithReferenceToData (dataReference)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="323e44"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


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
#include "../../Utilities.h"
//[/Headers]

#include "ScaleFrequenciesOverlay.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ScaleFrequenciesOverlay::ScaleFrequenciesOverlay (ProcessorData *dataReference, KeyboardVisual *keyboardVis)
    : ComponentWithReferenceToData (dataReference)
{
    //[Constructor_pre] You can add your own custom stuff here..
    keyboard = keyboardVis;
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    this->data->scaleChangeBroadcaster.addChangeListener(this);
    this->data->scaleNoteMapping.addChangeListener(this);

    startTimerHz (60);
    //[/Constructor]
}

ScaleFrequenciesOverlay::~ScaleFrequenciesOverlay()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ScaleFrequenciesOverlay::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    juce::Colour strokeColour = juce::Colour (0x9942EC1E);
    juce::Colour playingStrokeColour = juce::Colour (0xff42EC1E);

    juce::Colour scaleColour = juce::Colour (0x9982BB43);
    juce::Colour playingScaleColour = juce::Colour (0xffFF0059);

    juce::Colour secondaryStrokeColour = juce::Colour (0x99C626C6);
    juce::Colour playingSecondaryStrokeColour = juce::Colour (0xffC626C6);

    juce::Colour secondaryScaleColour = juce::Colour (0x99E663AA);
    int connectionYPos = 35;

    // Secondary mapping scale note line
    // @TODO: Create a iterator for scale to iterate over midi note, scale note (non-mapped), and frequency order
    for (auto midiNote = AnaMark::Scale::firstTunableScaleNote; midiNote < AnaMark::Scale::afterLastTunableScaleNote; ++midiNote) {
      int scaleNote;
      ScaleNoteMapping::NoteMappingType ret = data->scaleNoteMapping.getMidiNoteMapping(midiNote, scaleNote);
      if (ret == ScaleNoteMapping::SECONDARY_MAPPING) {
        // Frequency
        double frequency = data->scale.FrequencyForMIDINote(scaleNote);
        double centerPixelPosition = keyboard->ConvertContinuousMidiNoteToPercentWidth(freqHZToContinuousMidiNote(frequency)) * getWidth();

        bool scaleNotePlaying = false;
        for (const auto &outChannel : data->output) {
          if (!outChannel.notes.empty() && outChannel.scaleNote == scaleNote) {
            scaleNotePlaying = true;
            break;
          }
        }

        int markerWidth = (scaleNotePlaying)? 5 : 3;
        keyboard->drawMarker(centerPixelPosition, markerWidth, connectionYPos, 1, secondaryScaleColour, g);
      }
    }

    // Primary and secondary scale note connector
    for (auto midiNote = AnaMark::Scale::firstTunableScaleNote; midiNote < AnaMark::Scale::afterLastTunableScaleNote; ++midiNote) {
      int scaleNote;
      ScaleNoteMapping::NoteMappingType ret = data->scaleNoteMapping.getMidiNoteMapping(midiNote, scaleNote);
      if (ret != ScaleNoteMapping::NO_MAPPING) {
        // Connector
        double frequency = data->scale.FrequencyForMIDINote(scaleNote);
        int frequencyXPos = keyboard->ConvertContinuousMidiNoteToPercentWidth(freqHZToContinuousMidiNote(frequency)) * getWidth();
        // if ((midiNoteXPos >= 0 && midiNoteXPos < getWidth()) || (frequencyXPos >= 0 && frequencyXPos < getWidth())) {

        int midiNoteXPos = keyboard->ConvertDiscreteMidiNoteToPercentWidth(midiNote) * getWidth();

        juce::Path internalPath1;

        internalPath1.startNewSubPath (frequencyXPos, connectionYPos);
        internalPath1.lineTo (midiNoteXPos, this->getHeight());

        bool scaleNotePlaying = false;
        for (const auto &outChannel : data->output) {
          if (!outChannel.notes.empty() && outChannel.scaleNote == scaleNote) {
            scaleNotePlaying = true;
            break;
          }
        }

        if (ret == ScaleNoteMapping::SECONDARY_MAPPING) {
          if (scaleNotePlaying) {
            g.setColour (playingSecondaryStrokeColour);
          } else {
            g.setColour (secondaryStrokeColour);
          }
        } else {
          if (scaleNotePlaying) {
            g.setColour(playingScaleColour);
          } else {
            g.setColour(strokeColour);
          }
        }

        float strokeWidth = (data->playingMidiNotes.count(midiNote) == 1)? 5.0f : 3.0f;
        g.strokePath (internalPath1, juce::PathStrokeType (strokeWidth), juce::AffineTransform::translation(0, 0));
      }
    }

    // Primary mapping scale note line
    for (auto i = AnaMark::Scale::firstTunableScaleNote; i < AnaMark::Scale::afterLastTunableScaleNote; ++i) {
        // Frequency
        double frequency = data->scale.FrequencyForMIDINote(i);
        double centerPixelPosition = keyboard->ConvertContinuousMidiNoteToPercentWidth(freqHZToContinuousMidiNote(frequency)) * getWidth();

        bool scaleNotePlaying = false;
        for (const auto &outChannel : data->output) {
          if (!outChannel.notes.empty() && outChannel.scaleNote == i) {
            scaleNotePlaying = true;
            break;
          }
        }
        int markerWidth = (scaleNotePlaying)? 5 : 3;

        keyboard->drawMarker(centerPixelPosition, markerWidth, connectionYPos, 1, scaleNotePlaying? playingScaleColour : scaleColour, g);
    }
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ScaleFrequenciesOverlay::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ScaleFrequenciesOverlay::changeListenerCallback (ChangeBroadcaster *source) {
    repaint();
}

void ScaleFrequenciesOverlay::timerCallback()
{
    repaint();
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ScaleFrequenciesOverlay"
                 componentName="" parentClasses="public ComponentWithReferenceToData, public juce::ChangeListener, private Timer"
                 constructorParams="ProcessorData *dataReference, KeyboardVisual *keyboardVis"
                 variableInitialisers="ComponentWithReferenceToData (dataReference)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="dc143c"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


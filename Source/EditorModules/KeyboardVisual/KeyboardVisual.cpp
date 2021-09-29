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
#include <math.h>
#include "../../Utilities.h"
//[/Headers]

#include "KeyboardVisual.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...

// From https://stackoverflow.com/a/11714601/6183001
int euclidean_remainder(int a, int b)
{
  jassert(b != 0);
  // C++11 requires integer division to be non-Euclidean: it requires an implementation that truncates towards zero.
  int r = a % b;
  return r >= 0 ? r : r + std::abs(b);
}

double euclidean_remainder(double a, double b)
{
  jassert(b != 0.0);
  // C++11 requires integer division to be non-Euclidean: it requires an implementation that truncates towards zero.
  double r = fmod(a, b);
  return r >= 0.0 ? r : r + std::abs(b);
}

double lerp(double a, double b, double t) {
  return (a * (1.0 - t)) + (b * t);
}
//[/MiscUserDefs]

//==============================================================================
KeyboardVisual::KeyboardVisual (ProcessorData *dataReference)
    : ComponentWithReferenceToData (dataReference)
{
    //[Constructor_pre] You can add your own custom stuff here..
    setToClassicKeyboardSpacing();
    //[/Constructor_pre]

    noteAndFreqOverlay.reset (new NoteAndFrequencyOverlay (this->data, this));
    addAndMakeVisible (noteAndFreqOverlay.get());

    //[UserPreSize]
    // Can't set KeyboardVisual to opaque at the moment, as the keys are somewhat transparent.
    // setOpaque(true);

    // Force the overlays and their children to not accept mouse events, and therefore let KeyboardVisual deal with the events
    noteAndFreqOverlay->setInterceptsMouseClicks(false, false);

    //[/UserPreSize]

    setSize (1000, 50);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

KeyboardVisual::~KeyboardVisual()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    noteAndFreqOverlay = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void KeyboardVisual::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    double whiteKeyWidth = (ConvertDiscreteMidiNoteToPercentWidth(2) - ConvertDiscreteMidiNoteToPercentWidth(0)) * entireWidth;

    // Pass 0: White keys
    // Pass 1: Black keys
    //    Results in Black keys being drawn on top
    for (int pass = 0; pass < 2; pass++)
    {
        for (int midiNote = std::floor(this->startingMidiNote); midiNote <= std::ceil(this->endingMidiNote); midiNote++)
        {
            int keyDistanceIndex = euclidean_remainder(midiNote, 12);

            bool isBlackKey = MidiMessage::isMidiNoteBlack(keyDistanceIndex);

            if (pass == 0 && isBlackKey)
                continue;
            if (pass == 1 && !isBlackKey)
                continue;

            double percentWidth = ConvertDiscreteMidiNoteToPercentWidth(midiNote);
            double centerXPos = percentWidth * entireWidth;

            bool inRange = (midiNote < 128) && (midiNote >= 0);
            // bool inRange = true;

            int y = isBlackKey? -30 : 0;

            double width = isBlackKey? (whiteKeyWidth / 2) : whiteKeyWidth;
            double x = centerXPos - (width / 2);
            int intX = std::round(x);
            int intWidth = std::round(width);

            // Fill

            if (inRange) {
              if (isBlackKey) {
                g.setColour (Colour (0xff2d2d2d));
              } else {
                g.setColour (Colour (0xfff8f8f8));
              }
            } else {
              if (isBlackKey) {
                if (isBlackKey) {
                  g.setColour (Colour(0xff575757));
                } else {
                  g.setColour (Colour(0xffbfbfbf));
                }
              }
            }
            g.fillRect (intX, y, intWidth, entireHeight);

            // Draw Outline on top

            if (inRange) {
              g.setColour (Colour (0xff808080));
            } else {
              g.setColour (Colour (0xff5b5b5b));
            }
            g.drawRect (intX, y, intWidth, entireHeight, 1);

            // Equal tempermeant lines
            // int height = 40;
            // width = 1;
            // Colour baseColor = Colour(0x4f457ea9);
            // Colour contrastingBaseColor = baseColor.darker(0.2f);
            // g.setColour (contrastingBaseColor);
            // //          x, y, width, height
            // g.fillRect (centerXPos - 1, 0, width + (2 * 1), height);

            // Second pass: base color center line
            // g.setColour (baseColor);
            // g.fillRect (centerXPos, 0, width, height - 1);
        }
    }

    //[/UserPaint]
}

void KeyboardVisual::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    setKeyboardDimensions(proportionOfWidth(1.0f), proportionOfHeight(1.0f));
    //[/UserPreResize]

    noteAndFreqOverlay->setBounds (0, getHeight() - proportionOfHeight (0.6000f), proportionOfWidth (1.0000f), proportionOfHeight (0.6000f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void KeyboardVisual::mouseMove (const juce::MouseEvent& e)
{
    //[UserCode_mouseMove] -- Add your code here...
    // mousePosition->setText(std::to_string(e.getPosition().x), dontSendNotification);
//    convertedMidiNote->setText(std::to_string(ConvertPixelsToContinuousMidiNote(e.getPosition().x)), dontSendNotification);
    //[/UserCode_mouseMove]
}

void KeyboardVisual::mouseDown (const juce::MouseEvent& e)
{
    //[UserCode_mouseDown] -- Add your code here...
    if (e.mods.isRightButtonDown()) {
      this->dragingView = true;
      this->lastDragPosition = e.getPosition().x;
    }
    //[/UserCode_mouseDown]
}

void KeyboardVisual::mouseDrag (const juce::MouseEvent& e)
{
    //[UserCode_mouseDrag] -- Add your code here...
    if (this->dragingView) {
        int currentX = e.getPosition().x;
        int delta = currentX - this->lastDragPosition;

        RangedAudioParameter *startingNoteParameter = this->data->apvts.getParameter("keyboard_visuals-viewport_starting_note");
        RangedAudioParameter *endingNoteParameter = this->data->apvts.getParameter("keyboard_visuals-viewport_ending_note");

        // @FIXME: Due to KeyboardVisualControlsOverlay having a listener to both parameters resulting in keyboard update,
        //    draging results in two calls and two repaints of the keyboard per mouseDrag call.
        startingNoteParameter->setValueNotifyingHost(startingNoteParameter->convertTo0to1(ConvertPixelsToContinuousMidiNote(-delta)));
        endingNoteParameter->setValueNotifyingHost(endingNoteParameter->convertTo0to1(ConvertPixelsToContinuousMidiNote(getWidth() - delta)));

        this->lastDragPosition = currentX;
    }
    //[/UserCode_mouseDrag]
}

void KeyboardVisual::mouseUp (const juce::MouseEvent& e)
{
    //[UserCode_mouseUp] -- Add your code here...
    if (e.mods.isRightButtonDown()) {
      this->dragingView = false;
    }
    //[/UserCode_mouseUp]
}

void KeyboardVisual::mouseWheelMove (const juce::MouseEvent& e, const juce::MouseWheelDetails& wheel)
{
    //[UserCode_mouseWheelMove] -- Add your code here...
    RangedAudioParameter *startingNoteParameter = this->data->apvts.getParameter("keyboard_visuals-viewport_starting_note");
    RangedAudioParameter *endingNoteParameter = this->data->apvts.getParameter("keyboard_visuals-viewport_ending_note");

    double finalDeltaX = wheel.deltaX * 100.0f;
    double finalDeltaY = wheel.deltaY * 250.0f;

    // @FIXME: Due to KeyboardVisualControlsOverlay having a listener to both parameters resulting in keyboard update,
    //    draging results in two calls and two repaints of the keyboard per mouseDrag call.
    startingNoteParameter->setValueNotifyingHost(startingNoteParameter->convertTo0to1(ConvertPixelsToContinuousMidiNote(-finalDeltaX + finalDeltaY)));
    endingNoteParameter->setValueNotifyingHost(endingNoteParameter->convertTo0to1(ConvertPixelsToContinuousMidiNote(getWidth() - (finalDeltaX + finalDeltaY))));
    //[/UserCode_mouseWheelMove]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void KeyboardVisual::setKeyboardSettings(double startingMidiNoteIn, double endingMidiNoteIn)
{
    this->startingMidiNote = startingMidiNoteIn;
    this->endingMidiNote = endingMidiNoteIn;

    double startingNoteToEndOfOctaveDistance = 0.0;
    double startOfOctaveToEndingNoteDistance = 0.0;

    {
        // this->startingNoteNumber = euclidean_remainder(startingMidiNoteInteger, 12);
        double startingNoteNumFloat = euclidean_remainder(this->startingMidiNote, 12.0);

        // fractional and integer will always be positive due to euclidean_remainder
        double fractional;
        double integerDouble;
        fractional = modf(startingNoteNumFloat, &integerDouble);
        int integer = static_cast<int>(integerDouble);

        if (integer == 0 && fractional == 0.0) {
          // Set startingNoteToEndOfOctaveDistance to 0.0 when we are EXACTLY at the start of a octave,
          //    as this is now considered a complete octave (dealt with by firstCompleteOctave)
          // startingNoteToEndOfOctaveDistance will be 0.0 as initalized
          this->leftOffscreenKeyDistance = 0;
        } else {
          double interKeyDistance = lerp(keyDistances[integer], keyDistances[integer + 1], fractional);
          this->leftOffscreenKeyDistance = interKeyDistance;
          startingNoteToEndOfOctaveDistance = 1.0 - this->leftOffscreenKeyDistance;
        }
    }

    {
        double endingNoteNumFloat = euclidean_remainder(this->endingMidiNote, 12.0);

        double fractional;
        double integerDouble;
        fractional = modf(endingNoteNumFloat, &integerDouble);
        int integer = static_cast<int>(integerDouble);

        double interKeyDistance = lerp(keyDistances[integer], keyDistances[integer + 1], fractional);
        startOfOctaveToEndingNoteDistance = interKeyDistance;
    }

    int firstCompleteOctave = static_cast<int>(std::ceil(this->startingMidiNote / 12.0));
    int lastCompleteOctave = static_cast<int>(std::floor(this->endingMidiNote / 12.0));

    int numberOfCompleteOctaves = lastCompleteOctave - firstCompleteOctave;
    this->totalOctavesShown = startingNoteToEndOfOctaveDistance + startOfOctaveToEndingNoteDistance + numberOfCompleteOctaves;

    this->startingNoteOctave = static_cast<int>(std::floor(this->startingMidiNote / 12.0));

    // testText->setText(std::to_string(ConvertPixelsToContinuousMidiNote(0)) + " " + std::to_string(ConvertPixelsToContinuousMidiNote(this->entireWidth)) + " " + std::to_string(ConvertPixelsToContinuousMidiNote(this->entireWidth) - ConvertPixelsToContinuousMidiNote(0)), dontSendNotification);

    // Notify subscribers that keyboard visual has changed and they should update
    this->sendChangeMessage();
    this->repaint();
}

void KeyboardVisual::setKeyboardDimensions(int widthIn, int heightIn)
{
  this->entireWidth = widthIn;
  this->entireHeight = heightIn;
}

void KeyboardVisual::setToClassicKeyboardSpacing()
{
    for (int i = 0; i < 13; i++)
    {
        bool previousNoteWhite = !MidiMessage::isMidiNoteBlack(i + 59);
        bool noteWhite = !MidiMessage::isMidiNoteBlack(i + 60);
        bool doubleWhite = previousNoteWhite && noteWhite;

        int lastIndex = i - 1;
        keyDistances[i] = ((i == 0)? 0 : (doubleWhite? 1.0 : 0.5)) + ((lastIndex >= 0)? keyDistances[lastIndex] : 0);
    }
    // Normalize the key distances so the first key (C, the 1st key) is 0.0, and the octave (the 13th key) is 1.0.
    for (int i = 0; i < 13; i++) {
        keyDistances[i] /= keyDistances[12];
    }
}

double KeyboardVisual::getStartingMidiNote()
{
    return this->startingMidiNote;
}

double KeyboardVisual::getEndingMidiNote()
{
    return this->endingMidiNote;
}

// @FIXME:  All the below functions do not respect the keyboard's width/height!!
double KeyboardVisual::ConvertDiscreteMidiNoteToPercentWidth(int discreteMidiNote)
{
    int keyIndexTemp = 0;
    return ConvertDiscreteMidiNoteToPercentWidth(discreteMidiNote, keyIndexTemp);
}

double KeyboardVisual::ConvertDiscreteMidiNoteToPercentWidth(int discreteMidiNote, int& keyIndex)
{
    int inNoteOctave = static_cast<int>(std::floor(discreteMidiNote / 12.0));
    int octaveDistance = inNoteOctave - this->startingNoteOctave;

    int inNoteNoteNumber = euclidean_remainder(discreteMidiNote, 12);

    // Neumerical units of octaves.  Key distances array is 0-1, where 1 is a full octave.
    // startingNoteOctave contains this->leftOffscreenKeyDistance worth of octave that is off-screen to the left.
    double octavesToNoteFromLeftBorder = keyDistances[inNoteNoteNumber] + octaveDistance - this->leftOffscreenKeyDistance;

    // Total number of octaves from starting note to discrete note is scaled down to 0-1 by total octaves shown in viewport
    double percentWidth = octavesToNoteFromLeftBorder / this->totalOctavesShown;

    return percentWidth;
}

/**
 * Converts a continous midi note value (integer part: midi note
 * (usually 0 to 127), decimal part: percent to next midi note)
 * @param  continousMidiNote [description]
 * @return                   [description]
 */
double KeyboardVisual::ConvertContinuousMidiNoteToPercentWidth(double continousMidiNote)
{
    double fractional;
    double integer;

    fractional = modf(continousMidiNote, &integer);
    double base = ConvertDiscreteMidiNoteToPercentWidth((int)continousMidiNote);

    int nextNoteIndex = (int)(continousMidiNote) + ((continousMidiNote < 0)? std::floor(fractional) : std::ceil(fractional));

    double percentWidth = base;
    if (base != nextNoteIndex) {
        double nextNote = ConvertDiscreteMidiNoteToPercentWidth(nextNoteIndex);

        // std::lerp not implemented until C++20
        percentWidth = lerp(base, nextNote, std::abs(fractional));
    }

    return percentWidth;
}

double KeyboardVisual::ConvertPixelsToContinuousMidiNote(int xPositionInPixels)
{
   return ConvertPercentWidthToContinuousMidiNote(xPositionInPixels / static_cast<double>(getWidth()));
}

double KeyboardVisual::ConvertPercentWidthToContinuousMidiNote(double percentWidth)
{
   int keyIndex = 0;

   // Inverse of equation used in ConvertDiscreteMidiNoteToPercentWidth
   double octaveDistance = (percentWidth * this->totalOctavesShown) - keyDistances[keyIndex] + this->leftOffscreenKeyDistance;
   double currentOctave = octaveDistance + this->startingNoteOctave;

   int currentOctaveFloored = static_cast<int>(std::floor(currentOctave));
   // Creates sawtooth function where slope does not flip when in negatives
   double interOctavePosition = currentOctave - currentOctaveFloored;

   // Binary Search for the keys that the percentWidth is in between
   int keyDistanceFirstIndex = 0;
   int keyDistanceLastIndex = 12;
   bool positionAndKeyDistanceAreEqual = false;
   // Naturally end when the indexes are right next to one another, or overlapping
   while (keyDistanceLastIndex - keyDistanceFirstIndex > 1) {
     int middleIndex = (keyDistanceFirstIndex + keyDistanceLastIndex) / 2;
     if (interOctavePosition < keyDistances[middleIndex]) {
       keyDistanceLastIndex = middleIndex;
     } else if (interOctavePosition > keyDistances[middleIndex]) {
       keyDistanceFirstIndex = middleIndex;
     } else {
       // interOctavePosition and keyDistance is equal.  We know for sure that therefore the percentWidth is on this one key.  Exit early.
       keyDistanceFirstIndex = middleIndex;
       keyDistanceLastIndex = middleIndex;
       positionAndKeyDistanceAreEqual = true;
       break;
     }
   }

   // keyDistancesIndexes->setText(std::to_string(currentOctaveFloored) + " " + std::to_string(interOctavePosition) + "\n" + std::to_string(keyDistances[keyDistanceFirstIndex]) + " " + std::to_string(keyDistances[keyDistanceLastIndex]), dontSendNotification);

   double continuousMidiNoteFractionPart = 0.0;
   if (!positionAndKeyDistanceAreEqual) {
     // Do some linear math to find exactly how much "key" is the percentWidth between the two found keys
     double distanceDiff = keyDistances[keyDistanceLastIndex] - keyDistances[keyDistanceFirstIndex];
     continuousMidiNoteFractionPart = (interOctavePosition - keyDistances[keyDistanceFirstIndex]) / distanceDiff;
   }

   int midiNoteIntegerPart = currentOctaveFloored * 12 + keyDistanceFirstIndex;
   double continuousMidiNote = midiNoteIntegerPart + continuousMidiNoteFractionPart;

   // keyDistancesIndexes->setText(std::to_string(continuousMidiNoteFractionPart) + " " + std::to_string(midiNoteIntegerPart), dontSendNotification);

   return continuousMidiNote;
}

void KeyboardVisual::drawMarker(double centerPixelPosition, int width, int height, int borderWidth, juce::Colour baseColor, juce::Graphics& graphics) {
    // First pass: darker outline
    Colour contrastingBaseColor = baseColor.darker(0.4f);
    graphics.setColour (contrastingBaseColor);
    //          x, y, width, height
    graphics.fillRect ((centerPixelPosition - borderWidth) - (width * 0.5), 0, width + (2 * borderWidth), height);

    // Second pass: base color center line
    graphics.setColour (baseColor);
    graphics.fillRect (centerPixelPosition - (width * 0.5), 0, width, height - 1);
}

void KeyboardVisual::drawMarkerAtDiscreteMidiNote(int midiNote, juce::Colour baseColor, juce::Graphics& graphics) {
    double centerPixelPosition = this->ConvertDiscreteMidiNoteToPercentWidth(midiNote) * proportionOfWidth(1.0f);

    drawMarker(centerPixelPosition, 1, 100, 1, baseColor, graphics);
}

void KeyboardVisual::drawMarkerAtContinuousMidiNote(double continousMidiNote, juce::Colour baseColor, juce::Graphics& graphics) {
    double centerPixelPosition = this->ConvertContinuousMidiNoteToPercentWidth(continousMidiNote) * proportionOfWidth(1.0f);

    drawMarker(centerPixelPosition, 1, 100, 1, baseColor, graphics);
}

void KeyboardVisual::drawMarkerAtFrequencyHz(double frequencyHz, juce::Colour baseColor, juce::Graphics& graphics) {
    drawMarkerAtContinuousMidiNote(freqHZToContinuousMidiNote(frequencyHz), baseColor, graphics);
}

void KeyboardVisual::drawLargerMarkerAtDiscreteMidiNote(int midiNote, juce::Colour baseColor, juce::Graphics& graphics) {
    double centerPixelPosition = this->ConvertDiscreteMidiNoteToPercentWidth(midiNote) * proportionOfWidth(1.0f);

    drawMarker(centerPixelPosition, 3, 100, 2, baseColor, graphics);
}

void KeyboardVisual::drawLargerMarkerAtContinuousMidiNote(double continousMidiNote, juce::Colour baseColor, juce::Graphics& graphics) {
    double centerPixelPosition = this->ConvertContinuousMidiNoteToPercentWidth(continousMidiNote) * proportionOfWidth(1.0f);

    drawMarker(centerPixelPosition, 3, 100, 2, baseColor, graphics);
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="KeyboardVisual" componentName=""
                 parentClasses="public ComponentWithReferenceToData, public juce::ChangeBroadcaster"
                 constructorParams="ProcessorData *dataReference" variableInitialisers="ComponentWithReferenceToData (dataReference)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="1000" initialHeight="50">
  <METHODS>
    <METHOD name="mouseWheelMove (const juce::MouseEvent&amp; e, const juce::MouseWheelDetails&amp; wheel)"/>
    <METHOD name="mouseMove (const juce::MouseEvent&amp; e)"/>
    <METHOD name="mouseDrag (const juce::MouseEvent&amp; e)"/>
    <METHOD name="mouseDown (const juce::MouseEvent&amp; e)"/>
    <METHOD name="mouseUp (const juce::MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="494848"/>
  <JUCERCOMP name="" id="d4b4c1a2077d41bb" memberName="noteAndFreqOverlay"
             virtualName="" explicitFocusOrder="0" pos="0 0Rr 100% 60%" posRelativeX="9a893a36dc7e0c36"
             posRelativeY="9a893a36dc7e0c36" posRelativeW="9a893a36dc7e0c36"
             posRelativeH="9a893a36dc7e0c36" sourceFile="NoteAndFrequencyOverlay.cpp"
             constructorParams="this-&gt;data, this"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

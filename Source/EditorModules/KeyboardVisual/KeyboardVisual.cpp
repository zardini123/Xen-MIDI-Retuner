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
#include <math.h>
#include "../../Utilities.h"
//[/Headers]

#include "KeyboardVisual.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...

const Colour KeyboardVisual::inRangeWhiteKeyColour(0xaaffffff);

// From https://stackoverflow.com/a/11714601/6183001
int euclidean_remainder(int a, int b)
{
  jassert(b != 0);
  // C++11 requires integer division to be non-Euclidean: it requires an implementation that truncates towards zero.
  int r = a % b;
  return r >= 0 ? r : r + std::abs(b);
}
//[/MiscUserDefs]

//==============================================================================
KeyboardVisual::KeyboardVisual (ProcessorData *dataReference)
    : ComponentWithReferenceToData (dataReference)
{
    //[Constructor_pre] You can add your own custom stuff here..
    setEqualSpacingValues();
    //[/Constructor_pre]

    scaleFrequenciesOverlay.reset (new ScaleFrequenciesOverlay (this->data, this));
    addAndMakeVisible (scaleFrequenciesOverlay.get());
    noteAndFreqOverlay.reset (new NoteAndFrequencyOverlay (this->data, this));
    addAndMakeVisible (noteAndFreqOverlay.get());
    controlsOverlay.reset (new KeyboardVisualControlsOverlay (this->data, this));
    addAndMakeVisible (controlsOverlay.get());

    //[UserPreSize]
    // Can't set KeyboardVisual to opaque at the moment, as the keys are somewhat transparent.
    // setOpaque(true);

    // Force the overlays and their children to not accept mouse events, and therefore let KeyboardVisual deal with the events
    scaleFrequenciesOverlay->setInterceptsMouseClicks(false, false);
    noteAndFreqOverlay->setInterceptsMouseClicks(false, false);

    // Dont allow clicks on the control overlay, but allow it in the child components of the overlay
    controlsOverlay->setInterceptsMouseClicks(false, true);

    //[/UserPreSize]

    setSize (1000, 50);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

KeyboardVisual::~KeyboardVisual()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    scaleFrequenciesOverlay = nullptr;
    noteAndFreqOverlay = nullptr;
    controlsOverlay = nullptr;


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
    for (int pass = 0; pass < 2; pass++)
    {
        for (int midiNote = this->firstMidiNote; midiNote <= this->lastMidiNote; midiNote++)
        {
            int keyDistanceIndex = euclidean_remainder(midiNote, 12);

            bool isBlack = MidiMessage::isMidiNoteBlack(keyDistanceIndex);

            if (pass == 0 && isBlack)
                continue;
            if (pass == 1 && !isBlack)
                continue;

            double percentWidth = ConvertDiscreteMidiNoteToPercentWidth(midiNote);
            double centerXPos = percentWidth * entireWidth;

            bool inRange = (midiNote < 128) && (midiNote >= 0);
            Colour fillColour = inRange? (isBlack? Colour (0xaa000000) : KeyboardVisual::inRangeWhiteKeyColour) : Colour(isBlack? 0xaa575757 : 0xaabfbfbf);
            g.setColour (fillColour);

            int y = isBlack? -30 : 0;

            double width = isBlack? (whiteKeyWidth / 2) : whiteKeyWidth;
            double x = centerXPos - (width / 2);
            int intX = std::round(x);
            int intWidth = std::round(width);

            // Fill
            g.fillRect (intX, y, intWidth, entireHeight);

            // Outline
            g.setColour (Colour (0xaa808080));
            g.drawRect (intX, y, intWidth, entireHeight, 1);

            // Equal tempermeant lines
            int height = 40;
            width = 1;
            Colour baseColor = Colour(0x4f457ea9);
            Colour contrastingBaseColor = baseColor.darker(0.2f);
            g.setColour (contrastingBaseColor);
            //          x, y, width, height
            g.fillRect (centerXPos - 1, 0, width + (2 * 1), height);

            // Second pass: base color center line
            g.setColour (baseColor);
            g.fillRect (centerXPos, 0, width, height - 1);
        }
    }

    //[/UserPaint]
}

void KeyboardVisual::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    setKeyboardDimensions(proportionOfWidth(1.0f), proportionOfHeight(1.0f));
    //[/UserPreResize]

    scaleFrequenciesOverlay->setBounds (0, getHeight() - proportionOfHeight (0.6000f), proportionOfWidth (1.0000f), proportionOfHeight (0.6000f));
    noteAndFreqOverlay->setBounds (0, getHeight() - proportionOfHeight (0.6000f), proportionOfWidth (1.0000f), proportionOfHeight (0.6000f));
    controlsOverlay->setBounds (0, 0, proportionOfWidth (1.0000f), proportionOfHeight (1.0000f));
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

void KeyboardVisual::mouseDrag (const juce::MouseEvent& e)
{
    //[UserCode_mouseDrag] -- Add your code here...
//    mousePosition->setText(std::to_string(e.getOffsetFromDragStart().x) + " " + std::to_string(e.getPosition().x) + " " + std::to_string(ConvertPixelsToContinuousMidiNote(e.getMouseDownPosition().x)), dontSendNotification);
    //[/UserCode_mouseDrag]
}

void KeyboardVisual::mouseWheelMove (const juce::MouseEvent& e, const juce::MouseWheelDetails& wheel)
{
    //[UserCode_mouseWheelMove] -- Add your code here...
//    juce__label->setText(std::to_string(ConvertPixelsToContinuousMidiNote(e.getPosition().x)), dontSendNotification);
    //[/UserCode_mouseWheelMove]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void KeyboardVisual::setKeyboardSettings(int firstMidiNoteIn, int lastMidiNoteIn)
{
    this->firstMidiNote = firstMidiNoteIn;
    this->lastMidiNote = lastMidiNoteIn;

    double firstKeyDistFromEndOfOctave = 0.0;
    double lastKeyDistFromBeginningOfOctave = 0.0;

    this->firstMidiNoteAsKeyInTwelveKeyRange = euclidean_remainder(this->firstMidiNote, 12);
    if (this->firstMidiNoteAsKeyInTwelveKeyRange != 0) {
        firstKeyDistFromEndOfOctave = 1.0 - keyDistances[this->firstMidiNoteAsKeyInTwelveKeyRange];
    }

    int lastMidiNoteAsKeyInTwelveKeyRange = euclidean_remainder(this->lastMidiNote, 12);
    if (lastMidiNoteAsKeyInTwelveKeyRange != 0)
        lastKeyDistFromBeginningOfOctave = keyDistances[lastMidiNoteAsKeyInTwelveKeyRange];

    int remaningOctStart = std::ceil(firstMidiNote / 12.0) * 12;
    int remaningOctEnd = std::floor(lastMidiNote / 12.0) * 12;

    int remaningOctaves = (remaningOctEnd - remaningOctStart) / 12;

    this->entireDistance = firstKeyDistFromEndOfOctave + lastKeyDistFromBeginningOfOctave + remaningOctaves;

    this->startOctave = static_cast<int>(std::floor(firstMidiNote / 12.0));

    // testText->setText(std::to_string(ConvertPixelsToContinuousMidiNote(0)) + " " + std::to_string(ConvertPixelsToContinuousMidiNote(this->entireWidth)) + " " + std::to_string(ConvertPixelsToContinuousMidiNote(this->entireWidth) - ConvertPixelsToContinuousMidiNote(0)), dontSendNotification);
}

void KeyboardVisual::setKeyboardDimensions(int widthIn, int heightIn)
{
  this->entireWidth = widthIn;
  this->entireHeight = heightIn;
}

void KeyboardVisual::setEqualSpacingValues()
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

int KeyboardVisual::getFirstMidiNote()
{
    return this->firstMidiNote;
}

int KeyboardVisual::getLastMidiNote()
{
    return this->lastMidiNote;
}

// @FIXME:  All the below functions do not respect the keyboard's width/height!!
double KeyboardVisual::ConvertDiscreteMidiNoteToPercentWidth(int discreteMidiNote)
{
    int keyIndexTemp = 0;
    return ConvertDiscreteMidiNoteToPercentWidth(discreteMidiNote, keyIndexTemp);
}

double KeyboardVisual::ConvertDiscreteMidiNoteToPercentWidth(int discreteMidiNote, int& keyIndex)
{
    keyIndex = euclidean_remainder(discreteMidiNote, 12);
    int currentOctave = static_cast<int>(std::floor(discreteMidiNote / 12.0));

    int octaveDistance = currentOctave - this->startOctave;

    double percentWidth = (keyDistances[keyIndex] + octaveDistance - keyDistances[this->firstMidiNoteAsKeyInTwelveKeyRange]) / this->entireDistance;
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
    double fractional, integer;
    fractional = modf(continousMidiNote, &integer);
    double base = ConvertDiscreteMidiNoteToPercentWidth((int)continousMidiNote);

    int nextNoteIndex = (int)(continousMidiNote) + ((continousMidiNote < 0)? std::floor(fractional) : std::ceil(fractional));

    double percentWidth = base;
    if (base != nextNoteIndex) {
        double nextNote = ConvertDiscreteMidiNoteToPercentWidth(nextNoteIndex);

        // std::lerp not implemented until C++20
//        percentWidth = std::lerp(base, nextNote, std::abs(fractional));
        double t = std::abs(fractional);
        percentWidth = (base * (1.0 - t)) + (nextNote * t);
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
   double octaveDistance = (percentWidth * this->entireDistance) - keyDistances[keyIndex] + keyDistances[this->firstMidiNoteAsKeyInTwelveKeyRange];
   double currentOctave = octaveDistance + this->startOctave;

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

void drawMarker(double centerPixelPosition, int width, int borderWidth, juce::Colour baseColor, juce::Graphics& graphics) {
    int height = 100;

    // First pass: darker outline
    // Colour contrastingBaseColor = Colour::contrasting(baseColor, KeyboardVisual::inRangeWhiteKeyColour);
    Colour contrastingBaseColor = baseColor.darker(0.4f);
    graphics.setColour (contrastingBaseColor);
    //          x, y, width, height
    graphics.fillRect (centerPixelPosition - borderWidth, 0, width + (2 * borderWidth), height);

    // Second pass: base color center line
    graphics.setColour (baseColor);
    graphics.fillRect (centerPixelPosition, 0, width, height - 1);
}

void KeyboardVisual::drawMarkerAtDiscreteMidiNote(int midiNote, juce::Colour baseColor, juce::Graphics& graphics) {
    double centerPixelPosition = this->ConvertDiscreteMidiNoteToPercentWidth(midiNote) * proportionOfWidth(1.0f);

    drawMarker(centerPixelPosition, 1, 1, baseColor, graphics);
}

void KeyboardVisual::drawMarkerAtContinuousMidiNote(double continousMidiNote, juce::Colour baseColor, juce::Graphics& graphics) {
    double centerPixelPosition = this->ConvertContinuousMidiNoteToPercentWidth(continousMidiNote) * proportionOfWidth(1.0f);

    drawMarker(centerPixelPosition, 1, 1, baseColor, graphics);
}

void KeyboardVisual::drawMarkerAtFrequencyHz(double frequencyHz, juce::Colour baseColor, juce::Graphics& graphics) {
    drawMarkerAtContinuousMidiNote(freqHZToContinuousMidiNote(frequencyHz), baseColor, graphics);
}

void KeyboardVisual::drawLargerMarkerAtDiscreteMidiNote(int midiNote, juce::Colour baseColor, juce::Graphics& graphics) {
    double centerPixelPosition = this->ConvertDiscreteMidiNoteToPercentWidth(midiNote) * proportionOfWidth(1.0f);

    drawMarker(centerPixelPosition, 3, 2, baseColor, graphics);
}

void KeyboardVisual::drawLargerMarkerAtContinuousMidiNote(double continousMidiNote, juce::Colour baseColor, juce::Graphics& graphics) {
    double centerPixelPosition = this->ConvertContinuousMidiNoteToPercentWidth(continousMidiNote) * proportionOfWidth(1.0f);

    drawMarker(centerPixelPosition, 3, 2, baseColor, graphics);
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="KeyboardVisual" componentName=""
                 parentClasses="public ComponentWithReferenceToData" constructorParams="ProcessorData *dataReference"
                 variableInitialisers="ComponentWithReferenceToData (dataReference)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="1000" initialHeight="50">
  <METHODS>
    <METHOD name="mouseWheelMove (const juce::MouseEvent&amp; e, const juce::MouseWheelDetails&amp; wheel)"/>
    <METHOD name="mouseMove (const juce::MouseEvent&amp; e)"/>
    <METHOD name="mouseDrag (const juce::MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="494848"/>
  <JUCERCOMP name="" id="31178f5ce0e8830f" memberName="scaleFrequenciesOverlay"
             virtualName="" explicitFocusOrder="0" pos="0 0Rr 100% 60%" posRelativeX="9a893a36dc7e0c36"
             posRelativeY="9a893a36dc7e0c36" posRelativeW="9a893a36dc7e0c36"
             posRelativeH="9a893a36dc7e0c36" sourceFile="ScaleFrequenciesOverlay.cpp"
             constructorParams="this-&gt;data, this"/>
  <JUCERCOMP name="" id="d4b4c1a2077d41bb" memberName="noteAndFreqOverlay"
             virtualName="" explicitFocusOrder="0" pos="0 0Rr 100% 60%" posRelativeX="9a893a36dc7e0c36"
             posRelativeY="9a893a36dc7e0c36" posRelativeW="9a893a36dc7e0c36"
             posRelativeH="9a893a36dc7e0c36" sourceFile="NoteAndFrequencyOverlay.cpp"
             constructorParams="this-&gt;data, this"/>
  <JUCERCOMP name="" id="21258a0fb7996dd" memberName="controlsOverlay" virtualName=""
             explicitFocusOrder="0" pos="0 0 100% 100%" sourceFile="KeyboardVisualControlsOverlay.cpp"
             constructorParams="this-&gt;data, this"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


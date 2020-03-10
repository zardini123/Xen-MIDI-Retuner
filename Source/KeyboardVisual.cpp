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

#include "KeyboardVisual.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
double keyDistances[13];

void SetEqualSpacingValues()
{
    for (int i = 0; i < 13; i++)
    {
        bool previousNoteWhite = !MidiMessage::isMidiNoteBlack(i + 59);
        bool noteWhite = !MidiMessage::isMidiNoteBlack(i + 60);
        bool doubleWhite = previousNoteWhite && noteWhite;

        int lastIndex = i - 1;
        keyDistances[i] = ((i == 0)? 0 : (doubleWhite? 1.0 : 0.5)) + ((lastIndex >= 0)? keyDistances[lastIndex] : 0);
    }
    for (int i = 0; i < 13; i++) {
        keyDistances[i] /= keyDistances[12];
    }
}

/**
 * Converts a continous midi note value (integer part: midi note
 * (usually 0 to 127), decimal part: percent to next midi note)
 * @param  continousMidiNote [description]
 * @return                   [description]
 */
int ConvertContinuousMidiNoteToKeyboardPixel(double continousMidiNote) {
    return 0;
}
//[/MiscUserDefs]

//==============================================================================
KeyboardVisual::KeyboardVisual ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    SetEqualSpacingValues();
    //[/Constructor_pre]

    label.reset (new Label ("new label",
                            TRANS("label text")));
    addAndMakeVisible (label.get());
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::topLeft);
    label->setEditable (false, false, false);
    label->setColour (Label::textColourId, Colours::red);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label->setBounds (0, 0, 472, 56);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (1000, 50);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

KeyboardVisual::~KeyboardVisual()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void KeyboardVisual::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff61a1ff));

    //[UserPaint] Add your own custom painting code here..
    int entireWidth = proportionOfWidth(1.0f);
    int entireHeight = proportionOfHeight(1.0f);

    int firstMidiNote = -11;
    int lastMidiNote = 11;

    double firstKeyDistFromEndOfOctave = 0.0;
    double lastKeyDistFromBeginningOfOctave = 0.0;

    int repeatedFirstMidiNote = (firstMidiNote < 0)? (12 - (std::abs(firstMidiNote) % 12)) : firstMidiNote % 12;
    if (repeatedFirstMidiNote != 0) {
        firstKeyDistFromEndOfOctave = 1.0 - keyDistances[repeatedFirstMidiNote];
    }

    int repeatedLastMidiNote = (lastMidiNote < 0)? (12 - (std::abs(lastMidiNote) % 12)) : lastMidiNote % 12;
    if (repeatedLastMidiNote != 0)
        lastKeyDistFromBeginningOfOctave = keyDistances[repeatedLastMidiNote];

    int remaningOctStart = std::ceil(firstMidiNote / 12.0) * 12;
    int remaningOctEnd = std::floor(lastMidiNote / 12.0) * 12;

    int remaningOctaves = (remaningOctEnd - remaningOctStart) / 12;

    double entireDistance = firstKeyDistFromEndOfOctave + lastKeyDistFromBeginningOfOctave + remaningOctaves;

//    std::string s = std::to_string(firstKeyDistFromEndOfOctave) + " " + std::to_string(lastKeyDistFromBeginningOfOctave) + " " + std::to_string(remaningOctStart) + " " + std::to_string(remaningOctEnd) + " " + std::to_string(remaningOctaves) + " " + std::to_string(entireDistance) + "\n";

    double scaledRemainingOctStart = firstKeyDistFromEndOfOctave / entireDistance;
    double scaledRemainingOctEnd = lastKeyDistFromBeginningOfOctave / entireDistance;
    double scaledRestOctaves = remaningOctaves / entireDistance;

//    s += std::to_string(scaledRemainingOctStart) + " " + std::to_string(scaledRemainingOctEnd) + " " + std::to_string(scaledRestOctaves);
//    label->setText(s, dontSendNotification);

    int startOctave = (firstMidiNote < 0)? ((firstMidiNote - 12) / 12) : (firstMidiNote / 12);
//    std::string s = std::to_string(startOctave);
    for (int midiNote = firstMidiNote; midiNote <= lastMidiNote; midiNote++)
    {
        int keyDistanceIndex = (midiNote < 0)? (12 - (std::abs(midiNote) % 12)) : midiNote % 12;
        // Shift midiNote down 12 when midiNote is less than 0 to remove issue where, for example, -3/12 and 3/12 both equal 0.  Therefore all divisons of 12 are independent.
        int currentOctave = (midiNote < 0)? ((midiNote - 12) / 12) : (midiNote / 12);
//        s += " " + std::to_string(currentOctave);
        int octaveDistance = currentOctave - startOctave;

        double percentWidth = (keyDistances[keyDistanceIndex] + octaveDistance - keyDistances[repeatedFirstMidiNote]) / entireDistance;
        int x = percentWidth * entireWidth;

        bool isBlack = MidiMessage::isMidiNoteBlack(keyDistanceIndex);

        bool inRange = (midiNote < 128) && (midiNote >= 0);
        Colour fillColour = inRange? Colour (isBlack? 0xff000000 : 0xffffffff) : Colour(isBlack? 0xff575757 : 0xffbfbfbf);
        g.setColour (fillColour);

        int y = isBlack? -20 : 0;
        g.fillRect (x, y, 1, entireHeight);

//        g.setColour (Colour (0xff808080));
//        g.drawRect (x, y, 1, entireHeight, 1);
    }
//    label->setText(s, dontSendNotification);

    /*
    int drawnKeys = 0;

    int sections[3][2] = {{repeatedFirstMidiNote, 11}, {0, 12 * remaningOctaves}, {1, repeatedLastMidiNote}};

    // Determine width of a white key using distance calculations used later
    double whiteKeyWidth = 0.0;
    if (repeatedFirstMidiNote != 0) {
        whiteKeyWidth = ((keyDistances[2] - keyDistances[0]) / firstKeyDistFromEndOfOctave) * scaledRemainingOctStart * entireWidth;
    } else if (repeatedLastMidiNote != 0) {
        whiteKeyWidth = ((keyDistances[2] - keyDistances[0]) / remaningOctaves * scaledRestOctaves) * entireWidth;
    } else {
        whiteKeyWidth = (((keyDistances[2] - keyDistances[0]) / lastKeyDistFromBeginningOfOctave) * scaledRemainingOctEnd) * entireWidth;
    }

    // Black keys should be drawn on top of white keys
    for (int pass = 0; pass < 2; pass++)
    {
        int midiNote = firstMidiNote - 1;
        for (int section = 0; section < 3; section++) {
            for (int noteInScale = sections[section][0]; noteInScale <= sections[section][1]; noteInScale++) {

                int i = std::abs(noteInScale % 12);
                bool isBlack = MidiMessage::isMidiNoteBlack(i);

                midiNote++;

                // White Pass
                if (pass == 0 && isBlack)
                    continue;
                // Black Pass
                if (pass == 1 && !isBlack)
                    continue;

                double x = 0.0;
                switch(section) {
                    case 0:
                        x = ((keyDistances[i] - keyDistances[repeatedFirstMidiNote]) / firstKeyDistFromEndOfOctave) * scaledRemainingOctStart * entireWidth;
                        break;
                    case 1: {
                        int octave = noteInScale / 12;
                        x = (((keyDistances[i] + octave) / remaningOctaves * scaledRestOctaves) + scaledRemainingOctStart) * entireWidth;
                        break;
                    }
                    case 2:
                        x = (((keyDistances[i] / lastKeyDistFromBeginningOfOctave) * scaledRemainingOctEnd) + scaledRemainingOctStart + scaledRestOctaves) * entireWidth;
                        break;
                }

                bool inRange = (midiNote < 128) && (midiNote >= 0);
                Colour fillColour = inRange? Colour (isBlack? 0xff000000 : 0xffffffff) : Colour(isBlack? 0xff575757 : 0xffbfbfbf);
                g.setColour (fillColour);

                double width = isBlack? (whiteKeyWidth / 2) : whiteKeyWidth;
                x -= width / 2;

                int y = isBlack? -20 : 0;
                g.fillRect (std::round(x), y, std::round(width), entireHeight);

                g.setColour (Colour (0xff808080));
                g.drawRect (std::round(x), y, std::round(width), entireHeight, 1);

                drawnKeys++;
            }
        }
    }
//    std::string b = std::to_string(drawnKeys) + " " + std::to_string(lastMidiNote - firstMidiNote);
//    label->setText(b, dontSendNotification);
     */

    /*
    if (repeatedFirstMidiNote != 0) {
        for (int pass = 0; pass < 2; pass++)
        {
            for (int midiNote = repeatedFirstMidiNote; midiNote < 12; midiNote++)
            {
                int i = std::abs(midiNote % 12);
                bool isBlack = MidiMessage::isMidiNoteBlack(i);

                // White Pass
                if (pass == 0 && isBlack)
                    continue;
                // Black Pass
                if (pass == 1 && !isBlack)
                    continue;

                int x = ((keyDistances[i] - keyDistances[repeatedFirstMidiNote]) / firstKeyDistFromEndOfOctave) * scaledRemainingOctStart * entireWidth;
                int y = isBlack? -20 : 0;

                bool inRange = (midiNote < 128) && (midiNote >= 0);
                Colour fillColour = inRange? Colour (isBlack? 0xff000000 : 0xffffffff) : Colour(isBlack? 0xff575757 : 0xffbfbfbf);
                g.setColour (fillColour);

                g.fillRect (x, y, 10, entireWidth);

                drawnKeys++;
            }
        }
    }


    if (remaningOctaves != 0) {
        std::string a = "";
        for (int pass = 0; pass < 2; pass++)
        {
            for (int midiNote = 0; midiNote <= (12 * remaningOctaves); midiNote++)
            {
                int i = std::abs(midiNote % 12);
                bool isBlack = MidiMessage::isMidiNoteBlack(i);

                // White Pass
                if (pass == 0 && isBlack)
                    continue;
                // Black Pass
                if (pass == 1 && !isBlack)
                    continue;

                int octave = midiNote / 12;

                int x = (((keyDistances[i] + octave) / remaningOctaves * scaledRestOctaves) + scaledRemainingOctStart) * entireWidth;
                a += std::to_string(keyDistances[i] + octave) + " ";
                int y = isBlack? -20 : 0;

                bool inRange = true;
                Colour fillColour = inRange? Colour (isBlack? 0xff000000 : 0xffffffff) : Colour(isBlack? 0xff575757 : 0xffbfbfbf);
                g.setColour (fillColour);

                g.fillRect (x, y, 1, entireWidth);

                drawnKeys++;
            }
        }
    //    label->setText(a, dontSendNotification);
    }

    if (repeatedLastMidiNote != 0) {
        for (int pass = 0; pass < 2; pass++)
        {
            for (int midiNote = 1; midiNote <= repeatedLastMidiNote; midiNote++)
            {
                int i = std::abs(midiNote % 12);
                bool isBlack = MidiMessage::isMidiNoteBlack(i);

                // White Pass
                if (pass == 0 && isBlack)
                    continue;
                // Black Pass
                if (pass == 1 && !isBlack)
                    continue;

                int x = (((keyDistances[i] / lastKeyDistFromBeginningOfOctave) * scaledRemainingOctEnd) + scaledRemainingOctStart + scaledRestOctaves) * entireWidth;
                int y = isBlack? -20 : 0;

                bool inRange = (midiNote < 128) && (midiNote >= 0);
                Colour fillColour = inRange? Colour (isBlack? 0xff000000 : 0xffffffff) : Colour(isBlack? 0xff575757 : 0xffbfbfbf);
                g.setColour (fillColour);

                g.fillRect (x, y, 1, entireWidth);

                drawnKeys++;
            }
        }
    }
     */

    /*
    int midiNoteMin = 0,
        midiNoteMax = 55;
    int entireWidth = proportionOfWidth(1.0f);
    int octaveWidth = std::ceil(entireWidth / ((midiNoteMax - midiNoteMin) / 12.0));
    int keyWidth = std::ceil((octaveWidth / 12.0) * 2);
    int height = proportionOfHeight(1.0f);
    for (int b = 0; b < 2; b++)
    {
        for (int midiNote = midiNoteMin; midiNote < midiNoteMax; midiNote++)
        {
            int i = std::abs(midiNote % 12);
            bool isBlack = MidiMessage::isMidiNoteBlack(i);

            // White Pass
            if (b == 0 && isBlack)
                continue;
            // Black Pass
            if (b == 1 && !isBlack)
                continue;

            bool inRange = (midiNote < 128) && (midiNote >= 0);
            int octave = midiNote / 12;

            int width = isBlack? (keyWidth / 2) : keyWidth;
            int x = (keyDistances[i] * octaveWidth) - (width / 2) + octaveWidth * octave;
            int y = isBlack? -20 : 0;

            Colour fillColour = inRange? Colour (isBlack? 0xff000000 : 0xffffffff) : Colour(isBlack? 0xff575757 : 0xffbfbfbf);
            g.setColour (fillColour);
            g.fillRect (x, y, width, height);
            g.setColour (Colour (0xff808080));
            g.drawRect (x, y, width, height, 1);
        }
    }
    */

    //[/UserPaint]
}

void KeyboardVisual::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

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

<JUCER_COMPONENT documentType="Component" className="KeyboardVisual" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="1000" initialHeight="50">
  <BACKGROUND backgroundColour="ff61a1ff"/>
  <LABEL name="new label" id="a928f55955fd1a75" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="0 0 472 56" textCol="ffff0000" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="9"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


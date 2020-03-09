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
//[/MiscUserDefs]

//==============================================================================
KeyboardVisual::KeyboardVisual ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    SetEqualSpacingValues();
    //[/Constructor_pre]

    label.reset (new Label ("new label",
                            TRANS("A")));
    addAndMakeVisible (label.get());
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::topLeft);
    label->setEditable (false, false, false);
    label->setColour (Label::textColourId, Colours::red);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


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

    int firstMidiNote = 0;
    int lastMidiNote = 128;

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

    std::string s = std::to_string(firstKeyDistFromEndOfOctave) + " " + std::to_string(lastKeyDistFromBeginningOfOctave) + " " + std::to_string(remaningOctStart) + " " + std::to_string(remaningOctEnd) + " " + std::to_string(remaningOctaves) + " " + std::to_string(entireDistance) + "\n";

    double scaledRemainingOctStart = firstKeyDistFromEndOfOctave / entireDistance;
    double scaledRemainingOctEnd = lastKeyDistFromBeginningOfOctave / entireDistance;
    double scaledRestOctaves = remaningOctaves / entireDistance;

    s += std::to_string(scaledRemainingOctStart) + " " + std::to_string(scaledRemainingOctEnd) + " " + std::to_string(scaledRestOctaves);
    label->setText(s, dontSendNotification);
    
    int drawnKeys = 0;
    
    /*
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

            int x = 0;
            if (repeatedFirstMidiNote != 0) {
                x = ((keyDistances[i] - keyDistances[repeatedFirstMidiNote]) / firstKeyDistFromEndOfOctave) * scaledRemainingOctStart * entireWidth;
            }
            if (remaningOctaves != 0) {
                int octave = midiNote / 12;
                x = (((keyDistances[i] + octave) / remaningOctaves * scaledRestOctaves) + scaledRemainingOctStart) * entireWidth;
            }
            if (repeatedLastMidiNote != 0) {
                x = (((keyDistances[i] / lastKeyDistFromBeginningOfOctave) * scaledRemainingOctEnd) + scaledRemainingOctStart + scaledRestOctaves) * entireWidth;
            }
            int y = isBlack? -20 : 0;

            bool inRange = (midiNote < 128) && (midiNote >= 0);
            Colour fillColour = inRange? Colour (isBlack? 0xff000000 : 0xffffffff) : Colour(isBlack? 0xff575757 : 0xffbfbfbf);
            g.setColour (fillColour);

            g.fillRect (x, y, 10, entireWidth);
            
            drawnKeys++;
        }
    }
     */
    
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
            for (int midiNote = 0; midiNote < (12 * remaningOctaves); midiNote++)
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

                g.fillRect (x, y, 10, entireWidth);
                
                drawnKeys++;
            }
        }
    //    label->setText(a, dontSendNotification);
    }
    
    if (repeatedLastMidiNote != 0) {
        for (int pass = 0; pass < 2; pass++)
        {
            for (int midiNote = 0; midiNote < repeatedLastMidiNote; midiNote++)
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
    
    std::string b = std::to_string(drawnKeys) + " " + std::to_string(lastMidiNote - firstMidiNote);
    label->setText(b, dontSendNotification);

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

    label->setBounds (proportionOfWidth (0.0071f), 8, 872, 48);
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
  <LABEL name="new label" id="fefd9f62685d5174" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="0.707% 8 872 48" textCol="ffff0000"
         edTextCol="ff000000" edBkgCol="0" labelText="A" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="9"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


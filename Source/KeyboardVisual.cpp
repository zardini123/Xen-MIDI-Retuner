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
//[/MiscUserDefs]

//==============================================================================
KeyboardVisual::KeyboardVisual ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    setEqualSpacingValues();
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

    keyboardOverlay.reset (new NoteAndFrequencyOverlay (this));
    addAndMakeVisible (keyboardOverlay.get());

    //[UserPreSize]
    //[/UserPreSize]

    setSize (1000, 50);


    //[Constructor] You can add your own custom stuff here..
    setKeyboardSettings(-20, 140, proportionOfWidth(0.8f), proportionOfHeight(1.0f));
    //[/Constructor]
}

KeyboardVisual::~KeyboardVisual()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label = nullptr;
    keyboardOverlay = nullptr;


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
    for (int midiNote = m_firstMidiNote; midiNote <= m_lastMidiNote; midiNote++)
    {
        int keyDistanceIndex = 0;

        double percentWidth = ConvertDiscreteMidiNoteToPercentWidth(midiNote, keyDistanceIndex);
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

    //[/UserPaint]
}

void KeyboardVisual::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    keyboardOverlay->setBounds (0, 0, proportionOfWidth (1.0000f), proportionOfHeight (1.0000f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void KeyboardVisual::setKeyboardSettings(int firstMidiNote, int lastMidiNote, int width, int height)
{
    entireWidth = width;
    entireHeight = height;

    m_firstMidiNote = firstMidiNote;
    m_lastMidiNote = lastMidiNote;

    double firstKeyDistFromEndOfOctave = 0.0;
    double lastKeyDistFromBeginningOfOctave = 0.0;

    m_repeatedFirstMidiNote = (firstMidiNote < 0)? (12 - (std::abs(firstMidiNote) % 12)) : firstMidiNote % 12;
    if (m_repeatedFirstMidiNote != 0) {
        firstKeyDistFromEndOfOctave = 1.0 - keyDistances[m_repeatedFirstMidiNote];
    }

    int repeatedLastMidiNote = (lastMidiNote < 0)? (12 - (std::abs(lastMidiNote) % 12)) : lastMidiNote % 12;
    if (repeatedLastMidiNote != 0)
        lastKeyDistFromBeginningOfOctave = keyDistances[repeatedLastMidiNote];

    int remaningOctStart = std::ceil(firstMidiNote / 12.0) * 12;
    int remaningOctEnd = std::floor(lastMidiNote / 12.0) * 12;

    int remaningOctaves = (remaningOctEnd - remaningOctStart) / 12;

    m_entireDistance = firstKeyDistFromEndOfOctave + lastKeyDistFromBeginningOfOctave + remaningOctaves;

    // Shift midiNote down 12 when midiNote is less than 0 to remove issue where, for example, -3/12 and 3/12 both equal 0.  Therefore all divisons of 12 are independent.
    m_startOctave = (firstMidiNote < 0)? ((firstMidiNote - 12) / 12) : (firstMidiNote / 12);
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
    for (int i = 0; i < 13; i++) {
        keyDistances[i] /= keyDistances[12];
    }
}

double KeyboardVisual::ConvertDiscreteMidiNoteToPercentWidth(int discreteMidiNote, int& keyDistanceIndex)
{
    keyDistanceIndex = (discreteMidiNote < 0)? (12 - (std::abs(discreteMidiNote) % 12)) : discreteMidiNote % 12;

    // Shift midiNote down 12 when midiNote is less than 0 to remove issue where, for example, -3/12 and 3/12 both equal 0.  Therefore all divisons of 12 are independent.
    int currentOctave = (discreteMidiNote < 0)? ((discreteMidiNote - 12) / 12) : (discreteMidiNote / 12);

    int octaveDistance = currentOctave - m_startOctave;

    double percentWidth = (keyDistances[keyDistanceIndex] + octaveDistance - keyDistances[m_repeatedFirstMidiNote]) / m_entireDistance;
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
    return 0;
}
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
  <JUCERCOMP name="" id="2ad7383270c298a1" memberName="keyboardOverlay" virtualName=""
             explicitFocusOrder="0" pos="0 0 100% 100%" sourceFile="NoteAndFrequencyOverlay.cpp"
             constructorParams="this"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


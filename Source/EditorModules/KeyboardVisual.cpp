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
#include <math.h>
//[/Headers]

#include "KeyboardVisual.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
KeyboardVisual::KeyboardVisual (ProcessorData *dataReference)
    : ComponentWithReferenceToData (dataReference)
{
    //[Constructor_pre] You can add your own custom stuff here..
    setEqualSpacingValues();
    //[/Constructor_pre]

    highest.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (highest.get());
    highest->setRange (-20, 140, 1);
    highest->setSliderStyle (juce::Slider::IncDecButtons);
    highest->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    highest->addListener (this);

    lowest.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (lowest.get());
    lowest->setRange (-20, 140, 1);
    lowest->setSliderStyle (juce::Slider::IncDecButtons);
    lowest->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    lowest->addListener (this);


    //[UserPreSize]
//    const void * address = static_cast<const void*>(this);
//    std::stringstream ss;
//    ss << address;
//
//    label->setText(ss.str(), dontSendNotification);
    //[/UserPreSize]

    setSize (1000, 50);


    //[Constructor] You can add your own custom stuff here..
    setKeyboardSettings(-20, 140, proportionOfWidth(1.0f), proportionOfHeight(1.0f));
    highest->setValue(140);
    lowest->setValue(-20);
    //[/Constructor]
}

KeyboardVisual::~KeyboardVisual()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    highest = nullptr;
    lowest = nullptr;


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
        for (int midiNote = m_firstMidiNote; midiNote <= m_lastMidiNote; midiNote++)
        {
            int keyDistanceIndex = (midiNote < 0)? (12 - (std::abs(midiNote) % 12)) : midiNote % 12;

            bool isBlack = MidiMessage::isMidiNoteBlack(keyDistanceIndex);

            if (pass == 0 && isBlack)
                continue;
            if (pass == 1 && !isBlack)
                continue;

            double percentWidth = ConvertDiscreteMidiNoteToPercentWidth(midiNote);
            double centerXPos = percentWidth * entireWidth;

            bool inRange = (midiNote < 128) && (midiNote >= 0);
            Colour fillColour = inRange? Colour (isBlack? 0xaa000000 : 0xaaffffff) : Colour(isBlack? 0xaa575757 : 0xaabfbfbf);
            g.setColour (fillColour);

            int y = isBlack? -20 : 0;

            double width = isBlack? (whiteKeyWidth / 2) : whiteKeyWidth;
            double x = centerXPos - (width / 2);
            int intX = std::round(x);
            int intWidth = std::round(width);

            // Fill
            g.fillRect (intX, y, intWidth, entireHeight);

            // Outline
            g.setColour (Colour (0xaa808080));
            g.drawRect (intX, y, intWidth, entireHeight, 1);
        }
    }

    //[/UserPaint]
}

void KeyboardVisual::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    highest->setBounds (proportionOfWidth (0.9000f), proportionOfHeight (0.0000f), proportionOfWidth (0.1000f), 23);
    lowest->setBounds (proportionOfWidth (0.8000f), proportionOfHeight (0.0000f), proportionOfWidth (0.1000f), 23);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void KeyboardVisual::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == highest.get())
    {
        //[UserSliderCode_highest] -- add your slider handling code here..
        setKeyboardSettings(lowest->getValue(), highest->getValue(), proportionOfWidth(1.0f), proportionOfHeight(1.0f));
        repaint();
        //[/UserSliderCode_highest]
    }
    else if (sliderThatWasMoved == lowest.get())
    {
        //[UserSliderCode_lowest] -- add your slider handling code here..
        setKeyboardSettings(lowest->getValue(), highest->getValue(), proportionOfWidth(1.0f), proportionOfHeight(1.0f));
        repaint();
        //[/UserSliderCode_lowest]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
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

int KeyboardVisual::getFirstMidiNote()
{
    return m_firstMidiNote;
}

int KeyboardVisual::getLastMidiNote()
{
    return m_lastMidiNote;
}

double KeyboardVisual::ConvertDiscreteMidiNoteToPercentWidth(int discreteMidiNote)
{
    int keyIndexTemp = 0;
    return ConvertDiscreteMidiNoteToPercentWidth(discreteMidiNote, keyIndexTemp);
}

double KeyboardVisual::ConvertDiscreteMidiNoteToPercentWidth(int discreteMidiNote, int& keyIndex)
{
    keyIndex = (discreteMidiNote < 0)? (12 - (std::abs(discreteMidiNote) % 12)) : discreteMidiNote % 12;

    // Shift midiNote down 12 when midiNote is less than 0 to remove issue where, for example, -3/12 and 3/12 both equal 0.  Therefore all divisons of 12 are independent.
    int currentOctave = (discreteMidiNote < 0)? ((discreteMidiNote - 12) / 12) : (discreteMidiNote / 12);

    int octaveDistance = currentOctave - m_startOctave;

    double percentWidth = (keyDistances[keyIndex] + octaveDistance - keyDistances[m_repeatedFirstMidiNote]) / m_entireDistance;
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
  <BACKGROUND backgroundColour="61a1ff"/>
  <SLIDER name="new slider" id="67d1cdb27238fff2" memberName="highest"
          virtualName="" explicitFocusOrder="0" pos="90% 0% 10% 23" min="-20.0"
          max="140.0" int="1.0" style="IncDecButtons" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="3ab8f24ac17b1ecb" memberName="lowest" virtualName=""
          explicitFocusOrder="0" pos="80% 0% 10% 23" min="-20.0" max="140.0"
          int="1.0" style="IncDecButtons" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


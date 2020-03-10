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

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class KeyboardVisual  : public Component
{
public:
    //==============================================================================
    KeyboardVisual ();
    ~KeyboardVisual() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setKeyboardSettings(int firstMidiNote, int lastMidiNote, int width, int height);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    void setEqualSpacingValues();
    
    double ConvertDiscreteMidiNoteToPercentWidth(int discreteMidiNote, int& keyDistanceIndex);
    double ConvertContinuousMidiNoteToPercentWidth(double continousMidiNote);
    
    // Keyboard settings
    int entireWidth;
    int entireHeight;
    int m_firstMidiNote;
    int m_lastMidiNote;
    
    // Keyboard cached values
    double keyDistances[13];
    
    int m_startOctave;
    int m_repeatedFirstMidiNote;
    double m_entireDistance;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Label> label;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KeyboardVisual)
};

//[EndFile] You can add extra defines here...
//[/EndFile]


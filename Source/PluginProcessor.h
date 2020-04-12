/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "AnaMark-Tuning-Library/SCL_Import.h"
#include "EditorModules/Components/TransitionCurve.h"

//==============================================================================
/**
*/
const int MAX_MIDI_CHANNELS = 16;
const int CENTER_PITCHWHEEL = 8192;

enum SingleChannelNotePrioritzation
{
    NOTE = 0,
    VELOCITY,
    RANDOM
};

enum SingleChannelNotePrioritzationModifier
{
    MOST_RECENT = 0,
    FIRST,
    HIGHEST_NOTE,
    LOWEST_NOTE
};

enum InterpolationDimension
{
    CENTS = 0,
    FREQUENCY
};

struct Note
{
    int midiNote;
    uint8 velocity;
    
    bool turnOffFlag = false;
};

struct Channel
{
    uint16 pitchwheel = CENTER_PITCHWHEEL; // Default to pitchbend wheel at center
    const Note *priorityNote;
    
    float scaleConvertedPriorityNote;
    std::vector<Note> notes;
};

struct OutputChannel
{
    int initalMidiNote;
    int initalJump;
    
    int noteOffset;
    int currentMidiNoteNumber;
};

class XenMidiRetunerAudioProcessor  : public AudioProcessor
{
public:
    // Processor data
    Channel input[MAX_MIDI_CHANNELS];
    CriticalSection inputLock;
    
    OutputChannel output[MAX_MIDI_CHANNELS];
    std::vector<Note> outputNotes[MAX_MIDI_CHANNELS];

    TUN::CSingleScale scale;

    AudioParameterInt *in_pitch_bend_range;
    AudioParameterInt *out_pitch_bend_range;
    
    AudioParameterChoice *singleChannelNotePriority;
    AudioParameterChoice *singleChannelNotePriorityModifier;
    
    InterpolationDimension interploationDimension = CENTS;
    
    TransitionCurve *interpolationCurve = nullptr;
    // END Processor data

    //==============================================================================
    XenMidiRetunerAudioProcessor();
    ~XenMidiRetunerAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (XenMidiRetunerAudioProcessor)
};

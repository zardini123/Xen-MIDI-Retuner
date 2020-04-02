/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "AnaMark-Tuning-Library/SCL_Import.h"

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
    int velocity;
};

struct Channel
{
    uint16 pitchwheel = CENTER_PITCHWHEEL; // Default to pitchbend wheel at center
    const Note *priorityNote;
    std::vector<Note> notes;
};

struct OutputChannel
{
    Channel *inputChannel;
    
};

class XenMidiRetunerAudioProcessor  : public AudioProcessor
{
public:
    // Processor data
    Channel input[MAX_MIDI_CHANNELS];
    OutputChannel output[MAX_MIDI_CHANNELS];

    TUN::CSingleScale scale;

    int in_pitch_bend_range;
    int out_pitch_bend_range;
    
    SingleChannelNotePrioritzation singleChannelNotePriority = NOTE;
    SingleChannelNotePrioritzationModifier singleChannelNotePriorityModifier = MOST_RECENT;
    InterpolationDimension interploationDimension = CENTS;
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

/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "ProcessorData.h"
#include <random>

//==============================================================================
/**
*/
class XenMidiRetunerAudioProcessor  : public AudioProcessor,
                                      public juce::AudioProcessorValueTreeState::Listener
{
private:
    std::random_device seed;
    std::mt19937 engine = std::mt19937(seed());
    
    const Note* getPriorityNote(const std::vector<Note>& noteStack, SingleChannelNotePrioritzation priority, SingleChannelNotePrioritzationModifier priorityModifier);
    void updateBlock(MidiBuffer& processedMidi, int channelIndex, bool updateInitialNotes, int time);
public:
    
    void parameterChanged (const String &parameterID, float newValue) override;
    bool updatePitch = false;
    bool updatePriority = false;
    
    ProcessorData processorData;
    
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
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (XenMidiRetunerAudioProcessor)
};

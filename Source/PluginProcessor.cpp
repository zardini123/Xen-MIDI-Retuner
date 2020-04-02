/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

#include "Utilities.h"
#include <random>

//==============================================================================
XenMidiRetunerAudioProcessor::XenMidiRetunerAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
//    scale = TUN::CSingleScale();
}

XenMidiRetunerAudioProcessor::~XenMidiRetunerAudioProcessor()
{
}

//==============================================================================
const String XenMidiRetunerAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool XenMidiRetunerAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool XenMidiRetunerAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool XenMidiRetunerAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double XenMidiRetunerAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int XenMidiRetunerAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int XenMidiRetunerAudioProcessor::getCurrentProgram()
{
    return 0;
}

void XenMidiRetunerAudioProcessor::setCurrentProgram (int index)
{
}

const String XenMidiRetunerAudioProcessor::getProgramName (int index)
{
    return {};
}

void XenMidiRetunerAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void XenMidiRetunerAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void XenMidiRetunerAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool XenMidiRetunerAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

std::default_random_engine generator;

const Note* getPriorityNote(const std::vector<Note>& noteStack, SingleChannelNotePrioritzation priority, SingleChannelNotePrioritzationModifier priorityModifier)
{
    const Note *thePriorityNote = nullptr;
    switch (priority)
    {
        case NOTE:
            switch (priorityModifier)
            {
                case MOST_RECENT:
                    thePriorityNote = &noteStack.back();
                    break;
                case FIRST:
                    thePriorityNote = &noteStack.front();
                    break;
                case HIGHEST_NOTE: {
                    uint8_t highestNoteVal = 0;
                    for (auto it = noteStack.begin(); it != noteStack.end(); ++it) {
                        if (it->midiNote > highestNoteVal)
                        {
                            highestNoteVal = it->midiNote;
                            thePriorityNote = &(*it);
                        }
                    }
                    break;
                }
                case LOWEST_NOTE:
                    uint8_t lowestNoteVal = 255;
                    for (auto it = noteStack.begin(); it != noteStack.end(); ++it) {
                        if (it->midiNote < lowestNoteVal)
                        {
                            lowestNoteVal = it->midiNote;
                            thePriorityNote = &(*it);
                        }
                    }
                    break;
            }
            break;
        case VELOCITY:
            break;
        case RANDOM: {
            std::uniform_int_distribution<int> distribution(0, (int)noteStack.size() - 1);
            
            thePriorityNote = &noteStack[distribution(generator)];
            break;
        }
        default:
            // Should not get here
            break;
    }
    
    return thePriorityNote;
}

void XenMidiRetunerAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    buffer.clear();

    MidiBuffer processedMidi;
    int time;
    MidiMessage m;

    // For loop runs only if there is MIDI events to parse
    for (MidiBuffer::Iterator i (midiMessages); i.getNextEvent (m, time);)
    {
        bool update = false;
        
        // STACK CREATION
        // Pack all information into a Channel array with Note vectors for ease of interpretation later
        //      (especially for single channel note prioirtization)
        int channel = m.getChannel() - 1;
        if (m.isPitchWheel())
        {
            // Input of pitchwheel does not change any values of the Note stack, and therefore does NOT adjust note prioritzation.
            // But, it does affect the notes percieved frequency,
            //      and therefore may TODO: require note updates if perceived frequency is greater than output pitch range
            input[channel].pitchwheel = m.getPitchWheelValue();
            
            /*
            std::vector<Note> currentNotes = input[channel].notes;
            for (std::vector<Note>::iterator it = currentNotes.begin(); it != currentNotes.end(); ++it) {
                it->convertedFrequency = noteAndSemitonesToFreqHz(it->midiNote, pitchwheelPosToSemitones(input[channel].pitchwheel, in_pitch_bend_range));
            }
             */
            
            // DOES Not update note prioritzation
            // Though, it does change input frequencies, therefore has an effect on interpretation and scale interploation
            update = true;
        }
        if (m.isNoteOn())
        {
            // Add the new, played midi note.
            // First remove midi note if the note already exists (which is important for time-based prioritization)...
            std::vector<Note> currentNotes = input[channel].notes;
            for (std::vector<Note>::iterator it = currentNotes.begin(); it != currentNotes.end(); ++it) {
                if (it->midiNote == m.getNoteNumber()) {
                    it = currentNotes.erase(it);
                    break;
                }
            }
            
            // Then, Add the newest note to the end of the stack (append to last element of vector)
            currentNotes.push_back(Note {
                m.getNoteNumber(),
                m.getVelocity()/*,
                noteAndSemitonesToFreqHz(m.getNoteNumber(), pitchwheelPosToSemitones(input[channel].pitchwheel, in_pitch_bend_range)) */
            });
            input[channel].notes = currentNotes;
            
            // This condition updates prioritization
            input[channel].priorityNote = getPriorityNote(input[channel].notes, singleChannelNotePriority, singleChannelNotePriorityModifier);
            
            // Update scale interpretation
            update = true;
        }
        if (m.isNoteOff())
        {
            // Remove the note that was called to be off from the stack
            std::vector<Note> currentNotes = input[channel].notes;
            for (std::vector<Note>::iterator it = currentNotes.begin(); it != currentNotes.end(); ++it) {
                if (it->midiNote == m.getNoteNumber()) {
                    it = currentNotes.erase(it);
                    break;
                }
            }
            input[channel].notes = currentNotes;
            
            // This condition updates prioritization
            input[channel].priorityNote = getPriorityNote(input[channel].notes, singleChannelNotePriority, singleChannelNotePriorityModifier);
            
            // Update scale interpretation
            update = true;
        }
        
        // Interpretate and convert played notes of the current channel into the tuned value
        if (update)
        {
            
        }
        
        /*
        // Find out where the current note lays in regards to the scale
        float inputFrequency = noteAndSemitonesToFreqHz(input[channel].priorityNote->midiNote, pitchwheelPosToSemitones(input[channel].pitchwheel, in_pitch_bend_range));
        
        // TODO: REVIEW: There must be a more efficent way to find where a note lies in a vector of scale frequencies
        double lowerScaleNote;
        double higherScaleNote;
        bool found = false;
        for (auto it = scale.GetNoteFrequenciesHz().begin(); it != scale.GetNoteFrequenciesHz().end() - 1; ++it) {
            auto next = std::next(it);
            if (inputFrequency > *it && inputFrequency < *next)
            {
                lowerScaleNote = *it;
                higherScaleNote = *next;
                found = true;
                break;
            }
        }
        
        if (found)
        {
            float lowerContMidiNote = 0.0f;
            float higherContMidiNote = 0.0f;
            int noteNum;
            double semitones;
            
            // Convert scale frequencies to continuous midi notes
            freqHZToNoteAndSemitones(lowerScaleNote, noteNum, semitones);
            lowerContMidiNote = noteNum + semitones;
            freqHZToNoteAndSemitones(higherScaleNote, noteNum, semitones);
            higherContMidiNote = noteNum + semitones;
            
            // Convert range of lower and upper scale midi note to range of 0.0 - 1.0
            float inputInRange = juce::jmap(inputFrequency, lowerContMidiNote, higherContMidiNote, 0.0f, 1.0f);
            
            // Round range to find note to snap to
            int note = std::round(inputInRange);
        }
        */

        processedMidi.addEvent(m, time);
        // processedMidi.addEvent(MidiMessage::pitchWheel(m.getChannel(), random(0,16383)), time);
        // processedMidi.addEvent(MidiMessage::noteOn(m.getChannel(), random(0,100), (uint8)random(0,100)), time);
    }

    midiMessages.swapWith(processedMidi);
}

//==============================================================================
bool XenMidiRetunerAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* XenMidiRetunerAudioProcessor::createEditor()
{
    return new XenMidiRetunerAudioProcessorEditor (*this);
}

//==============================================================================
void XenMidiRetunerAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void XenMidiRetunerAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new XenMidiRetunerAudioProcessor();
}

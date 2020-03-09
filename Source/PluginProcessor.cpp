/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

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

double NoteAndPitchBendtoFreqHZ(int noteNum, int pitchBend)
{
    int maxPitch = 0x3fff;
    double pitchAdjust = ((pitchBend * 2.0) / maxPitch) - 1.0;
    
    double frequency = std::pow(2, ((noteNum + pitchAdjust) - 69) / 12.0) * 440;
    
    return frequency;
}

void FreqHZToNoteAndSemitones(double frequency, int &noteNum, double &semitones)
{
  // Convert frequency to the midi note number with decimal result kept
  double exactNoteNum = 12 * std::log2(frequency / 440) + 69;

  // Get nearest integer midi note number
  int closestNoteNum = std::round(exactNoteNum);

  noteNum = closestNoteNum;
  semitones = exactNoteNum - closestNoteNum;
}

int random(int min, int max) //range : [min, max)
{
   static bool first = true;
   if (first)
   {
      std::srand( std::time(NULL) ); //seeding for the first time only!
      first = false;
   }
   return min + std::rand() % (( max + 1 ) - min);
}

int lastPitchWheel = 0;

void XenMidiRetunerAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    // ScopedNoDenormals noDenormals;
    // auto totalNumInputChannels  = getTotalNumInputChannels();
    // auto totalNumOutputChannels = getTotalNumOutputChannels();
    //
    // // In case we have more outputs than inputs, this code clears any output
    // // channels that didn't contain input data, (because these aren't
    // // guaranteed to be empty - they may contain garbage).
    // // This is here to avoid people getting screaming feedback
    // // when they first compile a plugin, but obviously you don't need to keep
    // // this code if your algorithm always overwrites all the output channels.
    // for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
    //     buffer.clear (i, 0, buffer.getNumSamples());
    //
    // // This is the place where you'd normally do the guts of your plugin's
    // // audio processing...
    // // Make sure to reset the state if your inner loop is processing
    // // the samples and the outer loop is handling the channels.
    // // Alternatively, you can process the samples with the channels
    // // interleaved by keeping the same state.
    // for (int channel = 0; channel < totalNumInputChannels; ++channel)
    // {
    //     auto* channelData = buffer.getWritePointer (channel);
    //
    //     // ..do something to the data...
    // }

    buffer.clear();

    MidiBuffer processedMidi;
    int time;
    MidiMessage m;

    for (MidiBuffer::Iterator i (midiMessages); i.getNextEvent (m, time);)
    {
        if (m.isNoteOn())
        {
            for (std::vector<Note>::iterator it = currentNotes.begin(); it != currentNotes.end(); ++it) {
                if (it->midiNote == m.getNoteNumber()) {
                    it = currentNotes.erase(it);
                    break;
                }
            }
            
            currentNotes.push_back(Note {
                m.getNoteNumber(),
                m.getVelocity()
            });
        }
        if (m.isNoteOff())
        {
            for (std::vector<Note>::iterator it = currentNotes.begin(); it != currentNotes.end(); ++it) {
                if (it->midiNote == m.getNoteNumber()) {
                    it = currentNotes.erase(it);
                    break;
                }
            }
        }
        
        if (m.isNoteOn() || m.isNoteOff())
        {
            
            uint8 newVel = (uint8)m.getVelocity();

            int note_num = 0;
            uint16 pitchBend = 0;
            // double freq = scale.GetMIDINoteFreqHz(m.getNoteNumber());
            double freq = scale.GetMIDINoteFreqHz(m.getNoteNumber());
            lastPitchWheel = m.getNoteNumber();
            double semitones = 0.0;
            FreqHZToNoteAndSemitones(freq, note_num, semitones);
            pitchBend = MidiMessage::pitchbendToPitchwheelPos(semitones, 1);

            if (m.isNoteOn()) {
              processedMidi.addEvent(MidiMessage::pitchWheel(m.getChannel(), pitchBend), time);
              m = MidiMessage::noteOn(m.getChannel(), note_num, newVel);
            } else if (m.isNoteOff())
            {
              m = MidiMessage::noteOff(m.getChannel(), note_num);
            }
        }

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

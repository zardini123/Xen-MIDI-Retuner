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
    ProcessorData *data = ProcessorData::getInstance();
    
    addParameter(data->in_pitch_bend_range = new AudioParameterInt("in_pitch_bend_range", "Input Pitch Bend Range", 1, 96, 48));
    addParameter(data->out_pitch_bend_range = new AudioParameterInt("out_pitch_bend_range", "Output Pitch Bend Range", 1, 96, 48));
    
    addParameter(data->singleChannelNotePriority = new AudioParameterChoice("singleChannelNotePriority", "Single Channel Note Priority", {
        "Note", "Velocity", "Random"
    }, 0));
    addParameter(data->singleChannelNotePriorityModifier = new AudioParameterChoice("singleChannelNotePriorityModifier", "Single Channel Note Priority Modifier", {"Most Recent", "Oldest", "Greatest", "Lowest"}, 0));
    
//    scale = TUN::CSingleScale();
    data->transitionCurve = TransitionCurve();
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
                    if (!noteStack.empty())
                        thePriorityNote = &noteStack.back();
                    break;
                case FIRST:
                    if (!noteStack.empty())
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
    // TODO: FIXME:  Paramemters that are adjusted by outside classes can be adjusted during processBlock, therefore calculations can change midway through.  Store paramemters in a temporarily variable so paramemters do not change throughout.
    buffer.clear();

    MidiBuffer processedMidi;
    int time;
    MidiMessage m;
    
    ProcessorData *data = ProcessorData::getInstance();
    
    if (data->midiEnviromentTestManager.isThereTestsAvaliable())
    {
        data->midiEnviromentTestManager.updateLoop(midiMessages, buffer.getNumSamples(), 44100);
    } else { // Lmao
        // For loop runs only if there is MIDI events to parse
        for (MidiBuffer::Iterator i (midiMessages); i.getNextEvent (m, time);)
        {
            bool update = false;
            bool updateInitalNotes = false;
            
            // STACK CREATION
            // Pack all information into a Channel array with Note vectors for ease of interpretation later
            //      (especially for single channel note prioirtization)
            int channel = m.getChannel() - 1;
            if (m.isPitchWheel())
            {
                // Input of pitchwheel does not change any values of the Note stack, and therefore does NOT adjust note prioritzation.
                // But, it does affect the notes percieved frequency,
                //      and therefore may TODO: require note updates if perceived frequency is greater than output pitch range
                data->input[channel].pitchwheel = m.getPitchWheelValue();
                
                // DOES Not update note prioritzation
                // It does change input frequencies, therefore has an effect on interpretation and scale interploation
                // Though, if no notes are playing (priorityNote is null), it cannot update any information regarding converted notes
                if (data->input[channel].priorityNote != nullptr)
                {
                    update = true;
                }
            } else if (m.isNoteOn())
            {
                {
                    // Lock the input channel array
                    const ScopedLock myScopedLock (data->inputLock);
                    
                    // Add the new, played midi note.
                    // First remove midi note if the note already exists (which is important for time-based prioritization)...
                    std::vector<Note> currentNotes = data->input[channel].notes;
                    for (std::vector<Note>::iterator it = currentNotes.begin(); it != currentNotes.end(); ++it) {
                        if (it->midiNote == m.getNoteNumber()) {
                            it = currentNotes.erase(it);
                            break;
                        }
                    }
                    
                    // Then, Add the newest note to the end of the stack (append to vector)
                    Note newNote = Note {
                        m.getNoteNumber(),
                        m.getVelocity()
                    };
                    currentNotes.push_back(newNote);
                    data->input[channel].notes = currentNotes;
                }
                
                // This condition of note on updates prioritization
                data->input[channel].priorityNote = getPriorityNote(data->input[channel].notes, (SingleChannelNotePrioritzation)data->singleChannelNotePriority->getIndex(), (SingleChannelNotePrioritzationModifier)data->singleChannelNotePriorityModifier->getIndex());
                
                // Update scale interpretation
                update = true;
                // ... and updates what the inital notes are
                updateInitalNotes = true;
                
            } else if (m.isNoteOff())
            {
                {
                    // Lock the input channel array
                    const ScopedLock myScopedLock (data->inputLock);
                    
                    // Remove the note that was called to be off from the stack
                    std::vector<Note> currentNotes = data->input[channel].notes;
                    for (std::vector<Note>::iterator it = currentNotes.begin(); it != currentNotes.end(); ++it) {
                        if (it->midiNote == m.getNoteNumber()) {
                            it = currentNotes.erase(it);
                            break;
                        }
                    }
                    data->input[channel].notes = currentNotes;
                }
                
                // This condition of note off updates prioritization
                // Prioirty Note should be set to nullptr if there are no notes to choose from
                data->input[channel].priorityNote = getPriorityNote(data->input[channel].notes, (SingleChannelNotePrioritzation)data->singleChannelNotePriority->getIndex(), (SingleChannelNotePrioritzationModifier)data->singleChannelNotePriorityModifier->getIndex());
                
                if (data->input[channel].priorityNote != nullptr)
                {
                    // Update scale interpretation
                    update = true;
                    // ... and updates what the inital notes are
                    updateInitalNotes = true;
                }
                
                // If all input is empty, therefore nothing should be playing.  Ensure all notes on output are set to off.
                // Priority Note will be nullptr as well, either because there is no notes to choose from, due to a prioirty function not being implemented, or having edge cases.
                // Its best to use empty() instead of if == nullptr because of those last two reasons.
                if (data->input[channel].notes.empty())
                {
                    // Iterate through all notes and find all the notes ready for turn off
                    for (std::vector<Note>::iterator it = data->outputNotes[channel].begin(); it != data->outputNotes[channel].end(); ++it) {
                        processedMidi.addEvent(MidiMessage::noteOff(m.getChannel(), it->midiNote), time);
                    }
                    
                    data->outputNotes[channel].clear();
                }
            } else {
                processedMidi.addEvent(m, time);
            }
            
            // Interpretate and convert played notes of the current channel into the tuned value
            // Will not run if there are no more notes in the stack
            if (update)
            {
                float prioritySemitones = pitchwheelPosToSemitones(data->input[channel].pitchwheel, data->in_pitch_bend_range->get());
                // FIXME:  Created Segmentation Fault very low note is played
                float priorityNoteFreq = noteAndSemitonesToFreqHz(data->input[channel].priorityNote->midiNote, prioritySemitones);
                
                double lowerScaleNoteFreq;
                double higherScaleNoteFreq;
                
                // FIXME: Finding the nearest two scale note frequencies assumes the scale increases in a sorted order.  Some scales may not follow this paradigm!
                for (auto it = data->scale.GetNoteFrequenciesHz().begin(); it != data->scale.GetNoteFrequenciesHz().end(); ++it)
                {
                    auto nextIt = std::next(it);
                    if (priorityNoteFreq >= *it && priorityNoteFreq < *nextIt)
                    {
                        lowerScaleNoteFreq = *it;
                        higherScaleNoteFreq = *nextIt;
                        break;
                    }
                }
                
                // TODO: Have different interpolation dimensions (i.e. frequency or midi note (cents)).  Interpolation dimension currently is cents.
                float priorityContMidiNote = data->input[channel].priorityNote->midiNote + prioritySemitones;
                float lowerContMidiNote = 0.0f;
                float higherContMidiNote = 0.0f;
                
                lowerContMidiNote = freqHZToContinuousMidiNote(lowerScaleNoteFreq);
                higherContMidiNote = freqHZToContinuousMidiNote(higherScaleNoteFreq);
                
                float percentBetween = jmap(priorityContMidiNote, lowerContMidiNote, higherContMidiNote, 0.0f, 1.0f);
                float interpolatedBetween = data->transitionCurve.evaluate(percentBetween);
                float mappedBackToContinuousMidiNote = jmap(interpolatedBetween, 0.0f, 1.0f, lowerContMidiNote, higherContMidiNote);
                
                // For this channel, this is the target continuous midi note that the priority note needs to reach
                data->input[channel].scaleConvertedPriorityNote = mappedBackToContinuousMidiNote;
                
                
                if (updateInitalNotes)
                {
                    data->output[channel].initalMidiNote = std::round(data->input[channel].scaleConvertedPriorityNote);
                    data->output[channel].initalJump = data->output[channel].initalMidiNote - data->input[channel].priorityNote->midiNote;
                }
                
                data->output[channel].noteOffset = std::round((data->input[channel].scaleConvertedPriorityNote - data->output[channel].initalMidiNote) / (data->out_pitch_bend_range->get() * 2)) * (data->out_pitch_bend_range->get() * 2);
                data->output[channel].currentMidiNoteNumber = data->output[channel].noteOffset + data->output[channel].initalMidiNote;
                
                // Set all notes for removal.  The next loop will re-set notes to stay on if input midi calls for it
                int amountMarkedForRemoval = static_cast<int>(data->outputNotes[channel].size());
                for (std::vector<Note>::iterator it = data->outputNotes[channel].begin(); it != data->outputNotes[channel].end(); ++it) {
                    it->turnOffFlag = true;
                }
                
                for (std::vector<Note>::iterator it = data->input[channel].notes.begin(); it != data->input[channel].notes.end(); ++it) {
                    int inputMidiNoteAdjusted = it->midiNote + data->output[channel].initalJump + data->output[channel].noteOffset;
                    
                    bool noteAlreadyExists = false;
                    for (std::vector<Note>::iterator it = data->outputNotes[channel].begin(); it != data->outputNotes[channel].end(); ++it) {
                        if (it->midiNote == inputMidiNoteAdjusted) {
                            // Note already exists.  Make sure it stays for next update and is not removed.
                            it->turnOffFlag = false;
                            amountMarkedForRemoval--;
                            noteAlreadyExists = true;
                            break;
                        }
                    }
                    
                    if (!noteAlreadyExists)
                    {
                        Note currentConvertedNote = *it;
                        currentConvertedNote.midiNote = inputMidiNoteAdjusted;
                        
                        // If this is the first time adding this note, turn it on.
                        data->outputNotes[channel].push_back(currentConvertedNote);
                        
                        processedMidi.addEvent(MidiMessage::noteOn(m.getChannel(), inputMidiNoteAdjusted, it->velocity), time);
                    }
                }
                
                // Iterate through all notes and find all the notes ready for turn off
                for (int i = 0; i < amountMarkedForRemoval; i++) {
                    for (std::vector<Note>::iterator it = data->outputNotes[channel].begin(); it != data->outputNotes[channel].end(); ++it) {
                        if (it->turnOffFlag) {
                            processedMidi.addEvent(MidiMessage::noteOff(m.getChannel(), it->midiNote), time);
                            it = data->outputNotes[channel].erase(it);
                            // Cannot erase and then continue for loop.  Therefore, restart loop for as many times there are elements (notes) to remove
                            break;
                        }
                    }
                }
                
                // Destination - source
                float semitonesAdjust = data->input[channel].scaleConvertedPriorityNote - (data->input[channel].priorityNote->midiNote + data->output[channel].initalJump + data->output[channel].noteOffset);
                uint16 pitchWheel = MidiMessage::pitchbendToPitchwheelPos(semitonesAdjust, data->out_pitch_bend_range->get());
                
                processedMidi.addEvent(MidiMessage::pitchWheel(m.getChannel(), pitchWheel), time);
            }
            
            // processedMidi.addEvent(MidiMessage::pitchWheel(m.getChannel(), random(0,16383)), time);
            // processedMidi.addEvent(MidiMessage::noteOn(m.getChannel(), random(0,100), (uint8)random(0,100)), time);
        }

        midiMessages.swapWith(processedMidi);
    }
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
    
    ProcessorData *data = ProcessorData::getInstance();
    
    // TODO: Make xml setAttributes "dynamic", where an array of AudioProcessorAttrubute pointers are iterated over and saved
    std::unique_ptr<XmlElement> xml (new XmlElement ("XenMIDIRetuner"));
    xml->setAttribute("save_version", "0.0.1");
    
    xml->setAttribute ("in_pitch_bend_range", *data->in_pitch_bend_range);
    xml->setAttribute("out_pitch_bend_range", *data->out_pitch_bend_range);
    xml->setAttribute("singleChannelNotePriority", data->singleChannelNotePriority->getIndex());
    xml->setAttribute("singleChannelNotePriorityModifier", data->singleChannelNotePriorityModifier->getIndex());
    
    std::ostringstream stream;
    data->scale.Write(stream);
    std::string str = stream.str();
    xml->setAttribute("scale_file", str);
    
    copyXmlToBinary (*xml, destData);
}

void XenMidiRetunerAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    
    ProcessorData *processorData = ProcessorData::getInstance();
    
    std::unique_ptr<XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));
 
    if (xmlState.get() != nullptr) {
        if (xmlState->hasTagName ("XenMIDIRetuner")) {
            *processorData->in_pitch_bend_range = xmlState->getIntAttribute("in_pitch_bend_range", 48);
            *processorData->out_pitch_bend_range = xmlState->getIntAttribute("out_pitch_bend_range", 48);
            *processorData->singleChannelNotePriority = xmlState->getIntAttribute("singleChannelNotePriority", 0);
            *processorData->singleChannelNotePriorityModifier = xmlState->getIntAttribute("singleChannelNotePriorityModifier", 0);
            
            std::string scaleString = xmlState->getStringAttribute("scale_file").toStdString();
            std::istringstream scaleStringStream(scaleString);
            
            // String which will receive the current line from the file
            TUN::CStringParser    strparser;
            strparser.InitStreamReading();

            // Read the file
            long lResult = processorData->scale.Read(scaleStringStream, strparser);
        }
    }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new XenMidiRetunerAudioProcessor();
}

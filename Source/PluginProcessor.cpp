/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

#include "Utilities.h"

//==============================================================================
XenMidiRetunerAudioProcessor::XenMidiRetunerAudioProcessor() :
#ifndef JucePlugin_PreferredChannelConfigurations
    AudioProcessor (BusesProperties()
        #if ! JucePlugin_IsMidiEffect
            #if ! JucePlugin_IsSynth
            .withInput  ("Input",  AudioChannelSet::stereo(), true)
            #endif
            .withOutput ("Output", AudioChannelSet::stereo(), true)
        #endif
    ),
#endif
    processorData(*this)
{
//    scale = TUN::CSingleScale();
    processorData.transitionCurve = TransitionCurve();
    
    processorData.apvts.addParameterListener("transition_curve_midpoint", this);
    processorData.apvts.addParameterListener("transition_curve_transition", this);
    processorData.apvts.addParameterListener("singleChannelNotePriority", this);
    processorData.apvts.addParameterListener("singleChannelNotePriorityModifier", this);
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

const Note* XenMidiRetunerAudioProcessor::getPriorityNote(const std::vector<Note>& noteStack, SingleChannelNotePrioritzation priority, SingleChannelNotePrioritzationModifier priorityModifier)
{
    const Note *thePriorityNote = nullptr;
    
    // Don't bother deciding a prioirty note if there is no notes to choose from in the first place
    if (noteStack.empty())
        return nullptr;
    
    switch (priority)
    {
        case SingleChannelNotePrioritzation::MOST_RECENT_NOTE:
            thePriorityNote = &noteStack.back();
            break;
        case SingleChannelNotePrioritzation::OLDEST_NOTE:
            thePriorityNote = &noteStack.front();
            break;
        case SingleChannelNotePrioritzation::NOTE_PITCH:
            switch (priorityModifier)
            {
                case SingleChannelNotePrioritzationModifier::GREATEST: {
                    int highestNoteVal = std::numeric_limits<int>::min();
                    for (auto it = noteStack.begin(); it != noteStack.end(); ++it) {
                        if (it->midiNote > highestNoteVal)
                        {
                            highestNoteVal = it->midiNote;
                            thePriorityNote = &(*it);
                        }
                    }
                    break;
                }
                case SingleChannelNotePrioritzationModifier::LOWEST: {
                    int lowestNoteVal = std::numeric_limits<int>::max();
                    for (auto it = noteStack.begin(); it != noteStack.end(); ++it) {
                        if (it->midiNote < lowestNoteVal)
                        {
                            lowestNoteVal = it->midiNote;
                            thePriorityNote = &(*it);
                        }
                    }
                    break;
                }
            }
            break;
        case SingleChannelNotePrioritzation::VELOCITY:
            switch (priorityModifier)
            {
                case SingleChannelNotePrioritzationModifier::GREATEST: {
                    uint8_t highestVelocityNote = std::numeric_limits<uint8_t>::min();
                    for (auto it = noteStack.begin(); it != noteStack.end(); ++it) {
                        if (it->velocity > highestVelocityNote)
                        {
                            highestVelocityNote = it->velocity;
                            thePriorityNote = &(*it);
                        }
                    }
                    break;
                }
                case SingleChannelNotePrioritzationModifier::LOWEST: {
                    uint8_t lowestVelocityNote = std::numeric_limits<uint8_t>::max();
                    for (auto it = noteStack.begin(); it != noteStack.end(); ++it) {
                        if (it->velocity < lowestVelocityNote)
                        {
                            lowestVelocityNote = it->velocity;
                            thePriorityNote = &(*it);
                        }
                    }
                    break;
                }
            }
            break;
        case SingleChannelNotePrioritzation::RANDOM: {
            // https://rosettacode.org/wiki/Pick_random_element#C.2B.2B
            std::uniform_int_distribution<int> choose(0, (int)(noteStack.size() - 1));
            int randomIndex = choose(engine);
            
            thePriorityNote = &noteStack[randomIndex];
            
            processorData.logger->logMessage(std::to_string(randomIndex));
            break;
        }
        default:
            // Should not get here
            break;
    }
    
    return thePriorityNote;
}

bool removeFirstNoteAtNoteNumber(const int noteNumber, std::vector<Note> &notes)
{
    for (std::vector<Note>::iterator it = notes.begin(); it != notes.end(); ++it) {
        if (it->midiNote == noteNumber) {
            it = notes.erase(it);
            return true;
        }
    }
    
    return false;
}

void XenMidiRetunerAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    // TODO: FIXME:  Paramemters that are adjusted by outside classes can be adjusted during processBlock, therefore calculations can change midway through.  Store paramemters in a temporarily variable so paramemters do not change throughout.
    buffer.clear();

    MidiBuffer processedMidi;
    int time;
    MidiMessage m;
    
    ProcessorData *data = &processorData;
    
    if (data->midiEnviromentTestManager.isThereTestsAvaliable())
    {
        data->midiEnviromentTestManager.updateLoop(midiMessages, buffer.getNumSamples(), 44100);
    } else { // Lmao
        // For loop runs only if there is MIDI events to parse
        for (const MidiMessageMetadata metadata : midiMessages)
        {
            m = metadata.getMessage();
            time = metadata.samplePosition;
            
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
                
            } else if (m.isNoteOn())
            {
                {
                    // Lock the input channel array
                    const ScopedLock myScopedLock (data->inputLock);
                    
                    // Add the new, played midi note.
                    // First remove midi note if the note already exists (which is important for time-based prioritization)...
                    removeFirstNoteAtNoteNumber(m.getNoteNumber(), data->input[channel].notes);
                    
                    // Then, Add the newest note to the end of the stack (append to vector)
                    Note newNote = Note {
                        m.getNoteNumber(),
                        m.getVelocity()
                    };
                    data->input[channel].notes.push_back(newNote);
                }
                
                // This condition of note on updates prioritization
                data->input[channel].priorityNote = getPriorityNote(data->input[channel].notes, (SingleChannelNotePrioritzation)(int)*data->apvts.getRawParameterValue("singleChannelNotePriority"), (SingleChannelNotePrioritzationModifier)(int)*data->apvts.getRawParameterValue("singleChannelNotePriorityModifier"));
                
            } else if (m.isNoteOff())
            {
                {
                    // Lock the input channel array
                    const ScopedLock myScopedLock (data->inputLock);
                    
                    // Remove the note that was called to be off from the stack
                    removeFirstNoteAtNoteNumber(m.getNoteNumber(), data->input[channel].notes);
                }
                
                // This condition of note off updates prioritization
                // Prioirty Note should be set to nullptr if there are no input notes
                data->input[channel].priorityNote = getPriorityNote(data->input[channel].notes, (SingleChannelNotePrioritzation)(int)*data->apvts.getRawParameterValue("singleChannelNotePriority"), (SingleChannelNotePrioritzationModifier)(int)*data->apvts.getRawParameterValue("singleChannelNotePriorityModifier"));
                
                // If all input is empty, therefore nothing should be playing.  Ensure all notes on output are set to off.
                // Priority Note will be nullptr as well, either because there is no notes to choose from, due to a prioirty function not being implemented, or having edge cases.
                // Its best to use empty() instead of if == nullptr because of those last two reasons.
                if (data->input[channel].notes.empty())
                {
                    // Iterate through all notes and find all the notes ready for turn off
                    for (std::vector<Note>::iterator it = data->output[channel].notes.begin(); it != data->output[channel].notes.end(); ++it) {
                        processedMidi.addEvent(MidiMessage::noteOff(m.getChannel(), it->midiNote), time);
                    }
                    
                    data->output[channel].notes.clear();
                }
            } else {
                processedMidi.addEvent(m, time);
            }
            
            // Priority note required to determine how to adjust notes/pitchbend for the channel
            if (data->input[channel].priorityNote != nullptr)
            {
                bool isNoteMessage = m.isNoteOn() || m.isNoteOff();
                
                // Note messages and pitchwheel changes input frequencies, therefore has an effect on interpretation and scale interploation
                update = isNoteMessage || m.isPitchWheel();
                
                // The input priority note scale converted rounded to closest midi note is only updated on midi note messages
                updateInitalNotes = isNoteMessage;
            }
            
            // Interpretate and convert played notes of the current channel into the tuned value
            // Will not run if there are no more notes in the stack
            if (update)
            {
                updateBlock(processedMidi, channel, updateInitalNotes, time);
            }
        }
        
        if (updatePitch || updatePriority)
        {
            for (int i = 0; i < MAX_MIDI_CHANNELS; i++)
            {
                if (updatePriority)
                {
                    data->input[i].priorityNote = getPriorityNote(data->input[i].notes, (SingleChannelNotePrioritzation)(int)*data->apvts.getRawParameterValue("singleChannelNotePriority"), (SingleChannelNotePrioritzationModifier)(int)*data->apvts.getRawParameterValue("singleChannelNotePriorityModifier"));
                }
                
                if (data->input[i].priorityNote != nullptr)
                    updateBlock(processedMidi, i, updatePriority, time);
            }
            
            updatePitch = false;
            updatePriority = false;
        }

        midiMessages.swapWith(processedMidi);
    }
}

void XenMidiRetunerAudioProcessor::updateBlock(MidiBuffer& processedMidi, int channelIndex, bool updateInitialNotes, int time)
{
    float prioritySemitones = pitchwheelPosToSemitones(processorData.input[channelIndex].pitchwheel, *processorData.apvts.getRawParameterValue("in_pitch_bend_range"));
    // FIXME:  Created Segmentation Fault very low note is played
    float priorityNoteFreq = noteAndSemitonesToFreqHz(processorData.input[channelIndex].priorityNote->midiNote, prioritySemitones);
    
    double lowerScaleNoteFreq;
    double higherScaleNoteFreq;
    
    // FIXME: Finding the nearest two scale note frequencies assumes the scale increases in a sorted order.  Some scales may not follow this paradigm!
    for (auto it = processorData.scale.GetNoteFrequenciesHz().begin(); it != processorData.scale.GetNoteFrequenciesHz().end(); ++it)
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
    float priorityContMidiNote = processorData.input[channelIndex].priorityNote->midiNote + prioritySemitones;
    float lowerContMidiNote = 0.0f;
    float higherContMidiNote = 0.0f;
    
    lowerContMidiNote = freqHZToContinuousMidiNote(lowerScaleNoteFreq);
    higherContMidiNote = freqHZToContinuousMidiNote(higherScaleNoteFreq);
    
    float percentBetween = jmap(priorityContMidiNote, lowerContMidiNote, higherContMidiNote, 0.0f, 1.0f);
    float interpolatedBetween = processorData.transitionCurve.evaluate(percentBetween);
    float mappedBackToContinuousMidiNote = jmap(interpolatedBetween, 0.0f, 1.0f, lowerContMidiNote, higherContMidiNote);
    
    // scaleConvertedPriorityNote is the continuous midi note that the selected priority note needs to reach
    processorData.input[channelIndex].scaleConvertedPriorityNote = mappedBackToContinuousMidiNote;
    
    // Updated only when midi note on/off messages are inputted
    if (updateInitialNotes)
    {
        // Displayed by NoteAndFrequencyOverlay as center of output pitchbend range (blue strip).
        processorData.output[channelIndex].roundedInputScaleConvertedPriorityNote = std::round(processorData.input[channelIndex].scaleConvertedPriorityNote);
        
        // ∆ = Destination - source
        processorData.output[channelIndex].deltaFromInputPriorityNoteToScaleRoundedMidiNote = processorData.output[channelIndex].roundedInputScaleConvertedPriorityNote - processorData.input[channelIndex].priorityNote->midiNote;
    }
    
    float outPitchBendRange = *processorData.apvts.getRawParameterValue("out_pitch_bend_range");
    
    processorData.output[channelIndex].noteOffset = std::round((processorData.input[channelIndex].scaleConvertedPriorityNote - processorData.output[channelIndex].roundedInputScaleConvertedPriorityNote) / (outPitchBendRange * 2)) * (outPitchBendRange * 2);
    
    // Following code is to manage the output of note on and off messages
    // If, for example, holding a chord and pitchbending upwards results in a voice having same midi note as previously held midi note, do not send a off message (sustain the note longer).
    
    // The currently outputed midi note corresponding to the priority note on this channel
    // Shown via NoteAndFrequencyOverlay as yellow strip.
    processorData.output[channelIndex].currentMidiNoteNumber = processorData.output[channelIndex].noteOffset + processorData.output[channelIndex].roundedInputScaleConvertedPriorityNote;
    
    // Set all notes for removal.  The next for-loop block will re-set notes to stay on if input midi calls for it
    for (std::vector<Note>::iterator it = processorData.output[channelIndex].notes.begin(); it != processorData.output[channelIndex].notes.end(); ++it) {
        it->turnOffFlag = true;
    }
    // Used for outputNotes element erasing workaround later
    int amountMarkedForRemoval = static_cast<int>(processorData.output[channelIndex].notes.size());
    
    // Translate all input notes by translation values for tiling midi notes.
    // If the translated input notes does NOT equal any output note currently stored in output[channelIndex].notes,
    //      add the note to output[channelIndex].notes and send out a NoteOn message.
    // The output notes not paired with any translated input notes will have its turnOffFlag still set to true.
    // The next loop will go through all output notes and if its turnOffFlag is true, the note will be removed and a NoteOff will be sent out.
    for (std::vector<Note>::iterator it = processorData.input[channelIndex].notes.begin(); it != processorData.input[channelIndex].notes.end(); ++it) {
        int inputMidiNoteAdjusted = it->midiNote + processorData.output[channelIndex].deltaFromInputPriorityNoteToScaleRoundedMidiNote + processorData.output[channelIndex].noteOffset;
        
        bool noteAlreadyExists = false;
        for (std::vector<Note>::iterator it2 = processorData.output[channelIndex].notes.begin(); it2 != processorData.output[channelIndex].notes.end(); ++it2) {
            if (it2->midiNote == inputMidiNoteAdjusted) {
                // A translated input note has been found to equal a output[channelIndex].notes note.  Don't add any notes or send out any NoteOn messages and exit early.
                it2->turnOffFlag = false;
                amountMarkedForRemoval--;
                noteAlreadyExists = true;
                break;
            }
        }
        
        if (!noteAlreadyExists)
        {
            // Copy all note data (velocity) but change note number
            Note currentConvertedNote = *it;
            currentConvertedNote.midiNote = inputMidiNoteAdjusted;
            
            processorData.output[channelIndex].notes.push_back(currentConvertedNote);
            
            processedMidi.addEvent(MidiMessage::noteOn(channelIndex + 1, inputMidiNoteAdjusted, it->velocity), time);
        }
    }
    
    // FIXME: Re-assignment of iterator from the erase function and continuing loop results in crash for some reason
    // Workaround is restarting loop when an erase occurs for as many elements there are to erase.
    // Iterate through all notes and find all the notes ready for turn off
    for (int i = 0; i < amountMarkedForRemoval; i++) {
        for (std::vector<Note>::iterator it = processorData.output[channelIndex].notes.begin(); it != processorData.output[channelIndex].notes.end(); ++it) {
            if (it->turnOffFlag) {
                processedMidi.addEvent(MidiMessage::noteOff(channelIndex + 1, it->midiNote), time);
                // Troublesome line mentioned in fixme.
                it = processorData.output[channelIndex].notes.erase(it);
                
                break;
            }
        }
    }
    
    // Final pitchbend for this channel's priority note to reach the scale-snapped priority note.
    // ∆ = Destination - source
    float semitonesAdjust = processorData.input[channelIndex].scaleConvertedPriorityNote - processorData.output[channelIndex].currentMidiNoteNumber;
    uint16 pitchWheel = MidiMessage::pitchbendToPitchwheelPos(semitonesAdjust, *processorData.apvts.getRawParameterValue("out_pitch_bend_range"));
    
    processedMidi.addEvent(MidiMessage::pitchWheel(channelIndex + 1, pitchWheel), time);
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
    
    auto state = processorData.apvts.copyState();
    std::unique_ptr<juce::XmlElement> xml (state.createXml());
    
    xml->setAttribute("save_version", "0.0.1");
    
    std::ostringstream stream;
    processorData.scale.Write(stream);
    std::string str = stream.str();
    xml->setAttribute("scale_file", str);
    
    copyXmlToBinary (*xml, destData);
}

void XenMidiRetunerAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    
    std::unique_ptr<juce::XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));
 
    if (xmlState.get() != nullptr) {
        if (xmlState->hasTagName (processorData.apvts.state.getType())) {
            processorData.apvts.replaceState (juce::ValueTree::fromXml (*xmlState));
//            processorData.apvts.state.copyPropertiesAndChildrenFrom(juce::ValueTree::fromXml (*xmlState), &processorData.undoManager);
        }
        
        std::string scaleString = xmlState->getStringAttribute("scale_file").toStdString();
        std::istringstream scaleStringStream(scaleString);
        
        // String which will receive the current line from the file
        TUN::CStringParser strparser;
        strparser.InitStreamReading();

        // Read the file
        // TODO: Report error to user if scale could not be read for some reason
        long lResult = processorData.scale.Read(scaleStringStream, strparser);
        processorData.scaleChangedBroadcaster.sendChangeMessage();
    }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new XenMidiRetunerAudioProcessor();
}

void XenMidiRetunerAudioProcessor::parameterChanged (const String &parameterID, float newValue)
{
    if (parameterID == "transition_curve_midpoint" || parameterID == "transition_curve_transition")
    {
        updatePitch = true;
    }
    
    if (parameterID == "singleChannelNotePriority" || parameterID == "singleChannelNotePriorityModifier")
    {
        updatePriority = true;
    }
}

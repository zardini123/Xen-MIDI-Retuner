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
XenMidiRetunerAudioProcessor::XenMidiRetunerAudioProcessor()
    :
#ifndef JucePlugin_PreferredChannelConfigurations
      AudioProcessor(BusesProperties()
#if !JucePlugin_IsMidiEffect
#if !JucePlugin_IsSynth
                         .withInput("Input", AudioChannelSet::stereo(), true)
#endif
                         .withOutput("Output", AudioChannelSet::stereo(), true)
#endif
                         ),
#endif
      data(*this) {
  data.apvts.addParameterListener("transition_curve_midpoint", this);
  data.apvts.addParameterListener("transition_curve_transition", this);
  data.apvts.addParameterListener("tuned_note_per_keyboard_channel", this);
  data.apvts.addParameterListener("tuned_note_per_keyboard_channel_modifier", this);

  data.apvts.addParameterListener("legacy_mapping", &data.scaleNoteMapping);
}

XenMidiRetunerAudioProcessor::~XenMidiRetunerAudioProcessor() {
  if (data.scale.IsAttachedToAStateProvider()) {
    data.scale.DetachFromStateProvider();
  }
  delete data.mtsESPClient;
}

//==============================================================================
const String XenMidiRetunerAudioProcessor::getName() const {
  return JucePlugin_Name;
}

bool XenMidiRetunerAudioProcessor::acceptsMidi() const {
#if JucePlugin_WantsMidiInput
  return true;
#else
  return false;
#endif
}

bool XenMidiRetunerAudioProcessor::producesMidi() const {
#if JucePlugin_ProducesMidiOutput
  return true;
#else
  return false;
#endif
}

bool XenMidiRetunerAudioProcessor::isMidiEffect() const {
#if JucePlugin_IsMidiEffect
  return true;
#else
  return false;
#endif
}

double XenMidiRetunerAudioProcessor::getTailLengthSeconds() const {
  return 0.0;
}

int XenMidiRetunerAudioProcessor::getNumPrograms() {
  return 1; // NB: some hosts don't cope very well if you tell them there are 0 programs,
            // so this should be at least 1, even if you're not really implementing
            // programs.
}

int XenMidiRetunerAudioProcessor::getCurrentProgram() {
  return 0;
}

void XenMidiRetunerAudioProcessor::setCurrentProgram(int index) {}

const String XenMidiRetunerAudioProcessor::getProgramName(int index) {
  return {};
}

void XenMidiRetunerAudioProcessor::changeProgramName(int index, const String &newName) {}

//==============================================================================
void XenMidiRetunerAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock) {
  // Use this method as the place to do any pre-playback
  // initialisation that you need..

  // Cannot access parameter values in getStateInformation, data constructor, or plugin
  // constructor as apvts is not ready yet.  This is the only function I know of that is
  // best for that timing.
  int mtsEspState = (int)*data.apvts.getRawParameterValue("enable_mts_esp");
  // data.logger->logMessage("enable_mts_esp: " + std::to_string(mtsEspState));
  if (mtsEspState == 1) {
    if (data.mtsESPClient == nullptr && !data.scale.IsAttachedToAStateProvider()) {
      data.mtsESPClient = new AnaMark::MTSESPClient();
      data.scale.AttachToStateProvider(&data.mtsESPClient->SingleChannel());
    }
  }
}

void XenMidiRetunerAudioProcessor::releaseResources() {
  // When playback stops, you can use this as an opportunity to free up any
  // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool XenMidiRetunerAudioProcessor::isBusesLayoutSupported(
    const BusesLayout &layouts) const {
#if JucePlugin_IsMidiEffect
  ignoreUnused(layouts);
  return true;
#else
  // This is the place where you check if the layout is supported.
  // In this template code we only support mono or stereo.
  if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono() &&
      layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
    return false;

    // This checks if the input layout matches the output layout
#if !JucePlugin_IsSynth
  if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
    return false;
#endif

  return true;
#endif
}
#endif

//==============================================================================
// Change Listening

void XenMidiRetunerAudioProcessor::parameterChanged(const String &parameterID,
                                                    float newValue) {
  if (parameterID == "transition_curve_midpoint" ||
      parameterID == "transition_curve_transition") {
    updatePitch = true;
  }

  if (parameterID == "tuned_note_per_keyboard_channel" ||
      parameterID == "tuned_note_per_keyboard_channel_modifier") {
    updatePriority = true;
  }
}

//==============================================================================

const Note *XenMidiRetunerAudioProcessor::determineNoteToTune(
    const std::vector<Note> &noteStack, SingleChannelNotePrioritzation priority,
    SingleChannelNotePrioritzationModifier priorityModifier) {
  // Don't bother deciding a prioirty note if there is no notes to choose from in the
  // first place
  if (noteStack.empty())
    return nullptr;

  const Note *thePriorityNote = nullptr;

  switch (priority) {
  case SingleChannelNotePrioritzation::MOST_RECENT_NOTE:
    thePriorityNote = &noteStack.back();
    break;
  case SingleChannelNotePrioritzation::OLDEST_NOTE:
    thePriorityNote = &noteStack.front();
    break;
  case SingleChannelNotePrioritzation::NOTE_PITCH:
    switch (priorityModifier) {
    case SingleChannelNotePrioritzationModifier::GREATEST: {
      int highestNoteVal = std::numeric_limits<int>::min();
      for (auto it = noteStack.begin(); it != noteStack.end(); ++it) {
        if (it->midiNote > highestNoteVal) {
          highestNoteVal = it->midiNote;
          thePriorityNote = &(*it);
        }
      }
      break;
    }
    case SingleChannelNotePrioritzationModifier::LOWEST: {
      int lowestNoteVal = std::numeric_limits<int>::max();
      for (auto it = noteStack.begin(); it != noteStack.end(); ++it) {
        if (it->midiNote < lowestNoteVal) {
          lowestNoteVal = it->midiNote;
          thePriorityNote = &(*it);
        }
      }
      break;
    }
    }
    break;
  case SingleChannelNotePrioritzation::VELOCITY:
    switch (priorityModifier) {
    case SingleChannelNotePrioritzationModifier::GREATEST: {
      uint8_t highestVelocityNote = std::numeric_limits<uint8_t>::min();
      for (auto it = noteStack.begin(); it != noteStack.end(); ++it) {
        if (it->velocity > highestVelocityNote) {
          highestVelocityNote = it->velocity;
          thePriorityNote = &(*it);
        }
      }
      break;
    }
    case SingleChannelNotePrioritzationModifier::LOWEST: {
      uint8_t lowestVelocityNote = std::numeric_limits<uint8_t>::max();
      for (auto it = noteStack.begin(); it != noteStack.end(); ++it) {
        if (it->velocity < lowestVelocityNote) {
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

    // data.logger->logMessage(std::to_string(randomIndex));
    break;
  }
  default:
    // Should not get here
    assert(false);
    break;
  }

  return thePriorityNote;
}

bool removeFirstNoteAtNoteNumber(const int noteNumber, std::vector<Note> &notes) {
  for (std::vector<Note>::iterator it = notes.begin(); it != notes.end(); ++it) {
    if (it->midiNote == noteNumber) {
      it = notes.erase(it);
      return true;
    }
  }

  return false;
}

void XenMidiRetunerAudioProcessor::processBlock(AudioBuffer<float> &buffer,
                                                MidiBuffer &midiMessages) {
  // TODO: FIXME:  Paramemters that are adjusted by outside classes can be adjusted during
  // processBlock, therefore calculations can change midway through.  Store paramemters in
  // a temporarily variable so paramemters do not change throughout.
  buffer.clear();

  MidiBuffer processedMidi;
  int time;
  MidiMessage m;

  // For loop runs only if there is MIDI events to parse
  for (const MidiMessageMetadata metadata : midiMessages) {
    m = metadata.getMessage();
    time = metadata.samplePosition;

    // STACK CREATION
    // Pack all information into a InputChannel array with Note vectors for ease of
    // interpretation later
    //      (especially for single channel note prioirtization)
    int channel = m.getChannel() - 1;
    ProcessorData::InputChannel &inputChannel = data.input[channel];
    ProcessorData::OutputChannel &outputChannel = data.output[channel];
    if (m.isPitchWheel()) {
      // Input of pitchwheel does not change any values of the Note stack, and therefore
      // does NOT adjust note prioritzation. But, it does affect the notes percieved
      // frequency,
      //      and therefore may TODO: require note updates if perceived frequency is
      //      greater than output pitch range
      inputChannel.pitchwheel = m.getPitchWheelValue();

    } else if (m.isNoteOn()) {
      {
        // Lock the input channel array
        const ScopedLock myScopedLock(data.inputLock);

        // Add the new, played midi note.
        // First remove midi note if the note already exists (which is important for
        // time-based prioritization)...
        removeFirstNoteAtNoteNumber(m.getNoteNumber(), inputChannel.notes);

        // Then, Add the newest note to the end of the stack (append to vector)
        Note newNote = Note{m.getNoteNumber(), m.getVelocity()};
        inputChannel.notes.push_back(newNote);
      }

      // This condition of note on updates prioritization
      inputChannel.noteToTune = determineNoteToTune(
          inputChannel.notes,
          (SingleChannelNotePrioritzation)(int)*data.apvts.getRawParameterValue(
              "tuned_note_per_keyboard_channel"),
          (SingleChannelNotePrioritzationModifier)(int)*data.apvts.getRawParameterValue(
              "tuned_note_per_keyboard_channel_modifier"));

    } else if (m.isNoteOff()) {
      {
        // Lock the input channel array
        const ScopedLock myScopedLock(data.inputLock);

        // Remove the note that was called to be off from the stack
        removeFirstNoteAtNoteNumber(m.getNoteNumber(), inputChannel.notes);
      }

      // This condition of note off updates prioritization
      // Prioirty Note should be set to nullptr if there are no input notes
      inputChannel.noteToTune = determineNoteToTune(
          inputChannel.notes,
          (SingleChannelNotePrioritzation)(int)*data.apvts.getRawParameterValue(
              "tuned_note_per_keyboard_channel"),
          (SingleChannelNotePrioritzationModifier)(int)*data.apvts.getRawParameterValue(
              "tuned_note_per_keyboard_channel_modifier"));

      // If all input is empty, therefore nothing should be playing.  Ensure all notes on
      // output are set to off. Priority Note will be nullptr as well, either because
      // there is no notes to choose from, due to a prioirty function not being
      // implemented, or having edge cases. Its best to use empty() instead of if ==
      // nullptr because of those last two reasons.
      if (inputChannel.notes.empty()) {
        // Iterate through all notes and find all the notes ready for turn off
        for (std::vector<Note>::iterator it = outputChannel.notes.begin();
             it != outputChannel.notes.end();
             ++it) {
          processedMidi.addEvent(MidiMessage::noteOff(m.getChannel(), it->midiNote),
                                 time);
        }

        outputChannel.notes.clear();
      }
    } else {
      // Passthrough of non-conversion related MIDI messages
      processedMidi.addEvent(m, time);
    }

    // Priority note required to determine how to adjust notes/pitchbend for the channel
    if (inputChannel.noteToTune != nullptr) {
      bool isNoteMessage = m.isNoteOn() || m.isNoteOff();

      // Note messages and pitchwheel changes input frequencies, therefore has an effect
      // on interpretation and scale interploation
      if (isNoteMessage || m.isPitchWheel()) {
        // Interpretate and convert played notes of the current channel into the tuned
        // value Will not run if there are no more notes in the stack

        // The input priority note scale converted rounded to closest midi note is only
        // updated on midi note messages
        updateBlock(processedMidi, channel, isNoteMessage, time);
      }
    }
  }

  if (updatePitch || updatePriority) {
    for (int i = 0; i < MAX_MIDI_CHANNELS; i++) {
      if (updatePriority) {
        data.input[i].noteToTune = determineNoteToTune(
            data.input[i].notes,
            (SingleChannelNotePrioritzation)(int)*data.apvts.getRawParameterValue(
                "tuned_note_per_keyboard_channel"),
            (SingleChannelNotePrioritzationModifier)(int)*data.apvts.getRawParameterValue(
                "tuned_note_per_keyboard_channel_modifier"));
      }

      if (data.input[i].noteToTune != nullptr) {
        updateBlock(processedMidi, i, updatePriority, time);
      }
    }

    updatePitch = false;
    updatePriority = false;
  }

  midiMessages.swapWith(processedMidi);
}

// One channel to one channel
//    Tune one note (user choice)
// One channel to multi channel (and mpe)
//    Allocate each note to a output channel and tune each individually.
//    More than 16 notes:  prioritize based on user choice (note height, timing, velocity,
//    etc)
// Multi channel (and mpe) to one channel
//    Condense all input channels into "one channel" and tune to one note (user choice)
// Multi channel (and mpe) to multi channel (and mpe)
//    Tune each of the channels seperately, where each channel has one note tuned (user
//    choice)
// One channel input will first convert MPE to multi-channel if MPE is being inputted

void XenMidiRetunerAudioProcessor::updateBlock(MidiBuffer &processedMidi,
                                               int channelIndex,
                                               bool noteToTuneHasChanged, int time) {
  ProcessorData::InputChannel &inChannel = data.input[channelIndex];
  ProcessorData::OutputChannel &outChannel = data.output[channelIndex];

  // If noteToTune note is not mapped, do not play
  // If noteToTune is mapped, find

  // Do not play if noteToTune (discerete midi note) does not map to a frequency
  // Convert tuned note to continuous midi note (note + semitones)
  // Find first lower and upper mapped midi note to that continuous midi note
  //    (Search lower from closest discrete midi note from note for lower, search upward
  //    from note for upper)
  // Do not pitchbend if upper or lower is not found (which means no more mapped notes
  // lower/upper)
  //    Use discrete note (noteToTune) as frequency

  // @HACK: Query the note first as it will trigger a ScaleChange event if there is a
  // change in frequency. That will in turn update the mapping.
  data.scale.FrequencyForMIDINote(inChannel.noteToTune->midiNote);

  bool synthIsAlreadyTuned =
      (bool)*data.apvts.getRawParameterValue("synth_is_already_tuned");

  int scaleNote;
  ScaleNoteMapping::NoteMappingType mappingType =
      data.scaleNoteMapping.getMidiNoteMapping(inChannel.noteToTune->midiNote, scaleNote);
  bool isTunedNoteMapped = mappingType != ScaleNoteMapping::NO_MAPPING;
  if (!synthIsAlreadyTuned && isTunedNoteMapped) {
    // continuousTunedNote is the continuous midi note that the selected priority
    // note needs to reach

    inChannel.continuousTunedNote =
        freqHZToContinuousMidiNote(data.scale.FrequencyForMIDINote(scaleNote));

    // https://github.com/zardini123/AnaMark-Tuning-Library/issues/2#issuecomment-658591163

    float noteToTuneSemitones = pitchwheelPosToSemitones(
        inChannel.pitchwheel,
        *data.apvts.getRawParameterValue("keyboard_pitch_bend_range"));

    // Updated only when note to tune has changed
    //    (midi note on/off messages are inputted, or choice for note to tune has changed)
    if (noteToTuneHasChanged) {
      // Displayed by NoteAndFrequencyOverlay as center of output pitchbend range (blue
      // strip).
      outChannel.centerOfOutputPitchbendRangeStatic =
          std::round(inChannel.continuousTunedNote);

      // ∆ = Destination - source
      outChannel.noteToTuneToContinuousTunedNoteDifference =
          outChannel.centerOfOutputPitchbendRangeStatic - inChannel.noteToTune->midiNote;
    }

    float outPitchBendRange = *data.apvts.getRawParameterValue("synth_pitch_bend_range");

    outChannel.offsetOutputPitchbendRange =
        std::round((inChannel.continuousTunedNote -
                    outChannel.centerOfOutputPitchbendRangeStatic) /
                   (outPitchBendRange * 2)) *
        (outPitchBendRange * 2);

    // Following code is to manage the output of note on and off messages
    // If, for example, holding a chord and pitchbending upwards results in a voice having
    // same midi note as previously held midi note, do not send a off message (sustain the
    // note longer).

    // The currently outputed midi note corresponding to the priority note on this channel
    // Shown via NoteAndFrequencyOverlay as yellow strip.
    outChannel.outputMidiNoteForTunedNote = outChannel.offsetOutputPitchbendRange +
                                            outChannel.centerOfOutputPitchbendRangeStatic;
  }

  // Set all notes for removal.  The next for-loop block will re-set notes to stay on if
  // input midi calls for it
  for (std::vector<Note>::iterator it = outChannel.notes.begin();
       it != outChannel.notes.end();
       ++it) {
    it->turnOffFlag = true;
  }
  // Used for outputNotes element erasing workaround later
  int numNotesMarkedForShutoff = static_cast<int>(outChannel.notes.size());

  // Only play notes if there is a mapping
  if (isTunedNoteMapped) {
    // Translate all input notes by translation values for tiling midi notes.
    // If the translated input notes does NOT equal any output note currently stored in
    // output[channelIndex].notes,
    //      add the note to output[channelIndex].notes and send out a NoteOn message.
    // The output notes not paired with any translated input notes will have its
    // turnOffFlag still set to true. The next loop will go through all output notes and
    // if its turnOffFlag is true, the note will be removed and a NoteOff will be sent
    // out.
    bool sendOutUntunedNotes =
        data.apvts.getParameterAsValue("send_out_untuned_notes").getValue();
    for (std::vector<Note>::iterator it = inChannel.notes.begin();
         it != inChannel.notes.end();
         ++it) {
      // Skip playing a note if its not the tuned note
      if (!synthIsAlreadyTuned && !sendOutUntunedNotes &&
          it->midiNote != inChannel.noteToTune->midiNote) {
        // Won't be played and will turn off as previously the note was marked for off.
        continue;
      }

      // When it->midiNote is noteToTune, the result of inputMidiNoteAdjusted is equal to
      //    outChannel.outputMidiNoteForTunedNote (when !synthIsAlreadyTuned)
      int inputMidiNoteAdjusted = 0;
      if (synthIsAlreadyTuned) {
        int scaleNote;
        ScaleNoteMapping::NoteMappingType ret =
            data.scaleNoteMapping.getMidiNoteMapping(it->midiNote, inputMidiNoteAdjusted);
        // Dont play if no mapping
        if (ret == ScaleNoteMapping::NO_MAPPING) {
          continue;
        }
      } else {
        inputMidiNoteAdjusted = it->midiNote +
                                outChannel.noteToTuneToContinuousTunedNoteDifference +
                                outChannel.offsetOutputPitchbendRange;
      }

      bool noteAlreadyExists = false;
      // @FIXME: Entire array is traversed just to find if note exists in array.  Use a
      // unordered_map instead to get a O(1) mapping.
      for (std::vector<Note>::iterator it2 = outChannel.notes.begin();
           it2 != outChannel.notes.end();
           ++it2) {
        if (it2->midiNote == inputMidiNoteAdjusted) {
          // A translated input note has been found to equal a output[channelIndex].notes
          // note.  Don't add any notes or send out any NoteOn messages and exit early.
          it2->turnOffFlag = false;
          numNotesMarkedForShutoff--;
          noteAlreadyExists = true;
          break;
        }
      }

      if (!noteAlreadyExists) {
        // Copy all note data (velocity) but change note number
        Note currentConvertedNote = *it;
        currentConvertedNote.midiNote = inputMidiNoteAdjusted;

        outChannel.notes.push_back(currentConvertedNote);

        processedMidi.addEvent(
            MidiMessage::noteOn(channelIndex + 1, inputMidiNoteAdjusted, it->velocity),
            time);
      }
    }
  }

  // @FIXME: Re-assignment of iterator from the erase function and continuing loop results
  // in crash for some reason Workaround is restarting loop when an erase occurs for as
  // many elements there are to erase. Iterate through all notes and find all the notes
  // ready for turn off
  for (int i = 0; i < numNotesMarkedForShutoff; i++) {
    for (std::vector<Note>::iterator it = outChannel.notes.begin();
         it != outChannel.notes.end();
         ++it) {
      if (it->turnOffFlag) {
        processedMidi.addEvent(MidiMessage::noteOff(channelIndex + 1, it->midiNote),
                               time);
        // Troublesome line mentioned in fixme.
        it = outChannel.notes.erase(it);

        // Restart loop
        break;
      }
    }
  }

  // Final pitchbend for this channel's priority note to reach the scale-snapped priority
  // note. ∆ = Destination - source
  float semitonesAdjust =
      inChannel.continuousTunedNote - outChannel.outputMidiNoteForTunedNote;
  uint16 pitchWheel = MidiMessage::pitchbendToPitchwheelPos(
      semitonesAdjust, *data.apvts.getRawParameterValue("synth_pitch_bend_range"));

  processedMidi.addEvent(MidiMessage::pitchWheel(channelIndex + 1, pitchWheel), time);
}

//==============================================================================
bool XenMidiRetunerAudioProcessor::hasEditor() const {
  return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor *XenMidiRetunerAudioProcessor::createEditor() {
  return new XenMidiRetunerAudioProcessorEditor(*this);
}

//==============================================================================
void XenMidiRetunerAudioProcessor::getStateInformation(MemoryBlock &destData) {
  // You should use this method to store your parameters in the memory block.
  // You could do that either as raw data, or use the XML or ValueTree classes
  // as intermediaries to make it easy to save and load complex data.

  auto state = data.apvts.copyState();
  std::unique_ptr<juce::XmlElement> xml(state.createXml());

  xml->setAttribute("save_version", "0.0.1");

  // std::ostringstream stream;
  // data.scale.Write(stream);
  // std::string str = stream.str();
  // xml->setAttribute("scale_file", str);

  copyXmlToBinary(*xml, destData);
}

void XenMidiRetunerAudioProcessor::setStateInformation(const void *binaryData,
                                                       int sizeInBytes) {
  // You should use this method to restore your parameters from this memory block,
  // whose contents will have been created by the getStateInformation() call.

  std::unique_ptr<juce::XmlElement> xmlState(getXmlFromBinary(binaryData, sizeInBytes));

  if (xmlState.get() != nullptr) {
    if (xmlState->hasTagName(data.apvts.state.getType())) {
      data.apvts.replaceState(juce::ValueTree::fromXml(*xmlState));
      //            data.apvts.state.copyPropertiesAndChildrenFrom(juce::ValueTree::fromXml
      //            (*xmlState), &data.undoManager);
    }

    std::string scaleString = xmlState->getStringAttribute("scale_file").toStdString();
    std::istringstream scaleStringStream(scaleString);

    // String which will receive the current line from the file
    //        TUN::CStringParser strparser;
    //        strparser.InitStreamReading();

    // Read the file
    // TODO: Report error to user if scale could not be read for some reason
    //        long lResult = data.scale.Read(scaleStringStream, strparser);
    //        data.scaleChangedBroadcaster.sendChangeMessage();
  }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor *JUCE_CALLTYPE createPluginFilter() {
  return new XenMidiRetunerAudioProcessor();
}

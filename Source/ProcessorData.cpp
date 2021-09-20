/*
  ==============================================================================

    ProcessorData.cpp
    Created: 22 May 2020 12:42:24pm
    Author:  Taras A. Palczynski III

  ==============================================================================
*/

#include "ProcessorData.h"

AudioProcessorValueTreeState::ParameterLayout createParameterLayout() {
  AudioProcessorValueTreeState::ParameterLayout layout;

  ////////////////////////////////
  // From Keyboard

  layout.add(std::make_unique<AudioParameterInt>(
      "keyboard_pitch_bend_range", "Input Pitch Bend Range", 1, 96, 2));

  StringArray midiChannels;
  for (int i = 1; i <= 16; i++) {
    midiChannels.add(std::to_string(i));
  }

  layout.add(std::make_unique<AudioParameterChoice>(
      "keyboard_channel", "Keyboard Channel", midiChannels, 0));

  StringArray midiTypes = StringArray("One Channel", "Multi Channel", "MPE");

  layout.add(std::make_unique<AudioParameterChoice>(
      "keyboard_midi_type", "Keyboard MIDI Type", midiTypes, 1));

  ////////////////////////////////
  // Scale

  layout.add(std::make_unique<AudioParameterChoice>(
      "enable_mts_esp", "Enable MTS-ESP", StringArray("Off", "On"), 0));

  ////////////////////////////////
  // To Synth

  layout.add(std::make_unique<AudioParameterInt>(
      "synth_pitch_bend_range", "Output Pitch Bend Range", 1, 96, 2));

  layout.add(std::make_unique<AudioParameterChoice>(
      "synth_midi_type", "Synth MIDI Type", midiTypes, 0));
  layout.add(std::make_unique<AudioParameterChoice>(
      "synth_channel", "Synth Channel", midiChannels, 0));

  layout.add(std::make_unique<AudioParameterBool>(
      "send_out_untuned_notes", "Send Out Un-tuned Notes", false));

  layout.add(std::make_unique<AudioParameterChoice>(
      "tuned_note_per_keyboard_channel",
      "Tuned Note",
      StringArray("Most Recent Note", "Oldest Note", "Note Pitch", "Velocity", "Random"),
      0));
  layout.add(
      std::make_unique<AudioParameterChoice>("tuned_note_per_keyboard_channel_modifier",
                                             "Single Channel Note Priority Modifier",
                                             StringArray("Highest", "Lowest"),
                                             0));

  ////////////////////////////////
  // Keyboard Visuals

  auto grp = std::make_unique<AudioProcessorParameterGroup>(
      "keyboard_visuals", "Keyboard Visuals", " - ");

  grp->addChild(
      std::make_unique<AudioParameterFloat>("keyboard_visuals-viewport_starting_note",
                                            "View Starting MIDI Note",
                                            NormalisableRange<float>(-20.0f, 140.0f),
                                            20.0f));
  grp->addChild(
      std::make_unique<AudioParameterFloat>("keyboard_visuals-viewport_ending_note",
                                            "View Ending MIDI Note",
                                            NormalisableRange<float>(-20.0f, 140.0f),
                                            100.0f));

  // StringArray midiChannelsAndAll = midiChannels;
  // midiChannelsAndAll.add("All");

  // // @TODO: Dynmaically create these parameters, especially for the potential for
  // // multiple keyboard views
  // grp->addChild(std::make_unique<AudioParameterChoice>(
  //     "keyboard_visuals-midi_channel", "View MIDI Channel", midiChannelsAndAll, 0));
  //
  // grp->addChild(std::make_unique<AudioParameterBool>(
  //     "keyboard_visuals-enable_input_MIDI_notes", "Show Input MIDI Notes", true));
  // grp->addChild(std::make_unique<AudioParameterBool>(
  //     "keyboard_visuals-enable_channel_priority_note",
  //     "Show Channel Priority Note",
  //     true));
  // grp->addChild(std::make_unique<AudioParameterBool>(
  //     "keyboard_visuals-enable_scale", "Show Scale", true));
  // grp->addChild(std::make_unique<AudioParameterBool>(
  //     "keyboard_visuals-enable_priority_note_snapped_to_scale",
  //     "Show Priority Note Snapped to Scale",
  //     true));
  // grp->addChild(std::make_unique<AudioParameterBool>(
  //     "keyboard_visuals-enable_output_MIDI_priority_note",
  //     "Show Output MIDI Priority Note",
  //     false));
  // grp->addChild(std::make_unique<AudioParameterBool>(
  //     "keyboard_visuals-enable_output_pitchbend_range",
  //     "Show Output Pitchbend Range",
  //     false));
  // grp->addChild(std::make_unique<AudioParameterBool>(
  //     "keyboard_visuals-enable_input_pitchbend_range",
  //     "Show Input Pitchbend Range",
  //     false));

  layout.add(std::move(grp));

  return layout;
}

ProcessorData::ProcessorData(AudioProcessor &processorForApvts)
    : apvts(processorForApvts, &undoManager, "PARAMETERS", createParameterLayout()),
      undoManager() {
  logger.reset(FileLogger::createDefaultAppLogger(
      "", "xen_midi_retuner.log", "Xen MIDI Retuner Debug Log"));

  midiNoteToScaleNoteMapping.fill(-1);
  secondaryMapping.fill(-1);

  scaleChangeBroadcaster.AttachToChangeProvider(&scale);
};

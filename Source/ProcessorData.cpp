/*
  ==============================================================================

    ProcessorData.cpp
    Created: 22 May 2020 12:42:24pm
    Author:  Taras A. Palczynski III

  ==============================================================================
*/

#include "ProcessorData.h"

AudioProcessorValueTreeState::ParameterLayout createParameterLayout()
{
    AudioProcessorValueTreeState::ParameterLayout layout;

    layout.add(std::make_unique<AudioParameterInt>("in_pitch_bend_range", "Input Pitch Bend Range", 1, 96, 2));
    layout.add(std::make_unique<AudioParameterInt>("out_pitch_bend_range", "Output Pitch Bend Range", 1, 96, 2));
    layout.add(std::make_unique<AudioParameterChoice>("single_channel_note_priority", "Single Channel Note Priority",
                                                      StringArray("Most Recent Note", "Oldest Note", "Note Pitch", "Velocity", "Random"), 0));
    layout.add(std::make_unique<AudioParameterChoice>("single_channel_note_priority_modifier", "Single Channel Note Priority Modifier",
                                                      StringArray("Greatest", "Lowest"), 0));

    layout.add(std::make_unique<AudioParameterFloat>("transition_curve_midpoint", "Transition Curve Midpoint", NormalisableRange<float>(0.0f, 1.0f), 0.5f));
    layout.add(std::make_unique<AudioParameterFloat>("transition_curve_transition", "Transition Curve Transition", NormalisableRange<float>(0.0f, 1.0f), 0.0f));

    layout.add(std::make_unique<AudioParameterBool>("update_note_priority_note_off", "Update Priority Note in event of Note Off", true));

    auto grp = std::make_unique<AudioProcessorParameterGroup>("keyboard_visuals", "Keyboard Visuals", " - ");

    grp->addChild(std::make_unique<AudioParameterInt>("keyboard_visuals-viewport_starting_note", "View Starting MIDI Note", -20.0f, 140.0f, 20.0f));
    grp->addChild(std::make_unique<AudioParameterInt>("keyboard_visuals-viewport_ending_note", "View Ending MIDI Note", -20.0f, 140.0f, 100.0f));

    StringArray midiChannels;
    midiChannels.add("All");
    for (int i = 1; i <= 16; i++) {
        midiChannels.add(std::to_string(i));
    }

    // @TODO: Dynmaically create these parameters, especially for the potential for multiple keyboard views
    grp->addChild(std::make_unique<AudioParameterChoice>("keyboard_visuals-midi_channel", "View MIDI Channel", midiChannels, 0));

    grp->addChild(std::make_unique<AudioParameterBool>("keyboard_visuals-enable_input_MIDI_notes", "Show Input MIDI Notes", true));
    grp->addChild(std::make_unique<AudioParameterBool>("keyboard_visuals-enable_channel_priority_note", "Show Channel Priority Note", true));
    grp->addChild(std::make_unique<AudioParameterBool>("keyboard_visuals-enable_scale", "Show Scale", true));
    grp->addChild(std::make_unique<AudioParameterBool>("keyboard_visuals-enable_priority_note_snapped_to_scale", "Show Priority Note Snapped to Scale", true));
    grp->addChild(std::make_unique<AudioParameterBool>("keyboard_visuals-enable_output_MIDI_priority_note", "Show Output MIDI Priority Note", false));
    grp->addChild(std::make_unique<AudioParameterBool>("keyboard_visuals-enable_output_pitchbend_range", "Show Output Pitchbend Range", false));
    grp->addChild(std::make_unique<AudioParameterBool>("keyboard_visuals-enable_input_pitchbend_range", "Show Input Pitchbend Range", false));

    layout.add(std::move(grp));

//    addParameter(data->in_pitch_bend_range = new AudioParameterInt("in_pitch_bend_range", "Input Pitch Bend Range", 1, 96, 48));
//    addParameter(data->out_pitch_bend_range = new AudioParameterInt("out_pitch_bend_range", "Output Pitch Bend Range", 1, 96, 48));
//
//    addParameter(data->singleChannelNotePriority = new AudioParameterChoice("single_channel_note_priority", "Single Channel Note Priority", {
//        "Note", "Velocity", "Random"
//    }, 0));
//    addParameter(data->singleChannelNotePriorityModifier = new AudioParameterChoice("single_channel_note_priority_modifier", "Single Channel Note Priority Modifier", {"Most Recent", "Oldest", "Greatest", "Lowest"}, 0));

//    for (int i = 1; i < 9; ++i)
//        layout.add (std::make_unique<AudioParameterInt> (String (i), String (i), 0, i, 0));

    return layout;
}

ProcessorData::ProcessorData(AudioProcessor &processorForApvts) :
    apvts (processorForApvts, &undoManager, "PARAMETERS", createParameterLayout()),
    undoManager ()
{
    logger.reset(FileLogger::createDefaultAppLogger("", "xen_midi_retuner.log", "Xen MIDI Retuner Debug Log"));
}

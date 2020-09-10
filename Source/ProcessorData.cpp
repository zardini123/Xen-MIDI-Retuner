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

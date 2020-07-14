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
    
    layout.add(std::make_unique<AudioParameterInt>("in_pitch_bend_range", "Input Pitch Bend Range", 1, 96, 48));
    layout.add(std::make_unique<AudioParameterInt>("out_pitch_bend_range", "Output Pitch Bend Range", 1, 96, 48));
    layout.add(std::make_unique<AudioParameterChoice>("singleChannelNotePriority", "Single Channel Note Priority",
                                                      StringArray("Note", "Velocity", "Random"), 0));
    layout.add(std::make_unique<AudioParameterChoice>("singleChannelNotePriorityModifier", "Single Channel Note Priority Modifier",
                                                      StringArray("Most Recent", "Oldest", "Greatest", "Lowest"), 0));
    
    layout.add(std::make_unique<AudioParameterFloat>("transition_curve_midpoint", "Transition Curve Midpoint", NormalisableRange<float>(0.0f, 1.0f), 0.5f));
    layout.add(std::make_unique<AudioParameterFloat>("transition_curve_transition", "Transition Curve Transition", NormalisableRange<float>(0.0f, 1.0f), 0.0f));
    
    
//    addParameter(data->in_pitch_bend_range = new AudioParameterInt("in_pitch_bend_range", "Input Pitch Bend Range", 1, 96, 48));
//    addParameter(data->out_pitch_bend_range = new AudioParameterInt("out_pitch_bend_range", "Output Pitch Bend Range", 1, 96, 48));
//
//    addParameter(data->singleChannelNotePriority = new AudioParameterChoice("singleChannelNotePriority", "Single Channel Note Priority", {
//        "Note", "Velocity", "Random"
//    }, 0));
//    addParameter(data->singleChannelNotePriorityModifier = new AudioParameterChoice("singleChannelNotePriorityModifier", "Single Channel Note Priority Modifier", {"Most Recent", "Oldest", "Greatest", "Lowest"}, 0));
    
//    for (int i = 1; i < 9; ++i)
//        layout.add (std::make_unique<AudioParameterInt> (String (i), String (i), 0, i, 0));
 
    return layout;
}

ProcessorData::ProcessorData(AudioProcessor &processorForApvts) :
    apvts (processorForApvts, &undoManager, "PARAMETERS", createParameterLayout()),
    undoManager ()
{
    
}

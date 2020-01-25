# Xen MIDI Retuner

A MIDI Effect plugin (VST.2x/AU) that eventually retune MIDI streams (see section **PROJECT GOALS**).

For compiling to VST.2x plugin, the VST.2x SDK is needed. The global path for VST.2x sdk must be set your VST.2x sdk. VST.2x sdk that used to be embedded into JUCE can be found at [this commit](https://github.com/WeAreROLI/JUCE/tree/8317738112ccceb2c58deac3e4bb167c62682916/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces).

_NOTE:_ This project may not support VST.3x for a while, as the VST.3x specifications does not allow easy MIDI CC and Pitch-bend output (see this: [Add support for sending Midi CCs out of VST3 plugins](https://forum.juce.com/t/add-support-for-sending-midi-ccs-out-of-vst3-plugins/35781)).

## Project Goals / Specifications

_(Note: This section is for a understanding of the broad goals of this project. Some or all of the points listed may not be implemented yet.)_

A MIDI Effect plugin that will retune a input MIDI stream
(single channel, multi channel, and MPE) to another tuning specified by tuning parameters.
This will utilize [Mark Henning's AnaMark tuning library](https://github.com/zardini123/AnaMark-Tuning-Library) for interpreting .tun, .scl, .kbm, and .msf files in C++. Eventually, [other tuning files](https://hpi.zentral.zone/filetypes) will be supported. Tuning can be modified in realtime via tuning controls provided in interface. Tuning can also be modified realtime using the MTS protocol (see MTS (MIDI Tuning Standard) section [here](https://www.midi.org/articles-old/microtuning-and-alternative-intonation-systems), though sysex support is DAW dependent)
The output MIDI stream can be set to multi channel or MPE. Single channel output will have options for converting the input signal to a single channel, as Roli's Seaboard Dashboard does.

This retuner will also have a _reference tuner_ mode.
Performers with continuous, possibly MPE enabled controllers (Roli's Seaboard) will be able to see how their specifically tempered (equal tempered) controller can be played to achieve their wanted tuning.
The reference tuner mode will act as a teaching tool for one to learn how to play in different tunings using their continuous controller.

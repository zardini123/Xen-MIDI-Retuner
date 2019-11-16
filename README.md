# Xen MIDI Retuner

## Project Goals / Specifications

_(Note: This section is for a understanding of the broad goals of this project. Some or all of the points listed may not be implemented yet.)_

A MIDI Effect plugin that will retune a input MIDI stream
(single channel, multi channel, and MPE) to another tuning specified by tuning parameters.
Tuning parameters will be determined by importing [Scala](http://www.huygens-fokker.org/scala/scl_format.html) (.scl), [Keyboard Mapping](http://www.huygens-fokker.org/scala/help.htm#mappings) (.kbm), and [AnaMark Tuning](https://www.mark-henning.de/files/am/Tuning_File_V2_Doc.pdf) (.tun), and [other tuning files](https://hpi.zentral.zone/filetypes). Tuning can be modified in realtime via tuning controls provided in interface. Tuning can also be modified realtime using the MTS protocol (see MTS (MIDI Tuning Standard) section [here](https://www.midi.org/articles-old/microtuning-and-alternative-intonation-systems), though sysex support is DAW dependent)
The output MIDI stream can be set to multi channel or MPE. Single channel output will have options for converting the input signal to a single channel, as Roli's Seaboard Dashboard does.

This retuner will also have a _reference tuner_ mode.
Performers with continuous, possibly MPE enabled controllers (Roli's Seaboard) will be able to see how their specifically tempered (equal tempered) controller can be played to achieve their wanted tuning.
The reference tuner mode will act as a teaching tool for one to learn how to play in different tunings using their continuous controller.

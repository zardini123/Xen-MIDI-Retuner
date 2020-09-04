# Xen MIDI Retuner

Xen MIDI Retuner is a MIDI plugin that retunes MIDI input to microtonal and xenharmonic scales via clever midi note and pitch-bend output. Currently, the scale to retune to is defined by AnaMark (.tun) files.

This uses [Mark Henning's AnaMark tuning library](https://github.com/zardini123/AnaMark-Tuning-Library) for interpreting .tun files.

## Why?

Creating microtonal and xenharmonic music has typically been accomplished by loading tuning/scale files (.scl, .kbm, and/or .tun) or Midi Tuning Standard (MTS) SysEx messages into one's favorite synthesizer or DAW. Unfortunately, many synthesizers and DAWs (Ableton) do not support these retuning file formats.

Thankfully, practically all synthesizers and DAWs follow the Musical Instrument Digital Interface (MIDI) standard. Xen MIDI Retuner uses this standard to its advantage, retuning midi notes using pitch-bend messages to achieve the frequencies defined by tuning/scale files (explained in more detail in section **How? (Usage)**). If a synthesizer/DAW can take in note and pitch-bend MIDI messages, with Xen MIDI Retuner, by proxy, the synthesizer/DAW now supports tuning/scale files.

Xen MIDI Retuner additionally functions as a novel way for musicians to begin easily experimenting with the complex intervals of microtonal and xenharmonic music. Synthesizers with tuning/scale file support maps each MIDI note (each keyboard key) directly to scale note. Therefore, if one is using an octave scale with only 7 notes in it (i.e. 7 EDO), playing a tritone (A + D#) on one's keyboard results in hearing an octave. Pianists who have practiced for years associating the feeling playing an octave on a keyboard with hearing an octave would have to re-learn their association for specific scales. Xen MIDI Retuner removes this barrier of entry by mapping the frequencies of imported scales to the physical layout of the MIDI controller. In other words, Xen MIDI Retuner will "snap" incoming notes to the closest scale frequency, and outputs that frequency using the combination of new MIDI notes plus pitch-bend. Therefore, playing an octave results in hearing the closest interval to an octave of the imported scale.

## How? (Usage)

To begin using Xen MIDI Retuner as intended, _Output Pitch Bend Range_ (in section _Output_) must be set properly. Set the _Output Pitch Bend Range_ to the pitch-bend range of the instrument that Xen MIDI Retuner is outputting MIDI to. For example, if your instrument has pitch-bend range set to +/- 5st, set _Output Pitch Bend Range_ to 5.

_Input Pitch Bend Range_ is the semitones the MIDI notes you play into Xen MIDI Retuner will he pitched up/down when pitch wheel MIDI messages are also inputted. For example, if you play notes into Xen MIDI Retuner, have _Input Pitch Bend Range_ set to 2, and move your controller's pitch wheel all the way up, the notes will be pitched up by 2 semitones. This is identical to how synthesizers deal with pitch-bend.

Note that this shifting of MIDI notes due to input pitch-bend is _pre-conversion_.

The notes played into Xen MIDI Retuner (after being shifted by inputted pitch-bend) are then "snapped" to the closest scale frequency. How "aggressive" the snapping is defined by the _Scale Note Snapping Curve_ parameter. Setting _Scale Note Snapping Curve_ to 1 results in no snapping, therefore no retuning is applied.

Not every note is "snapped" to the closest scale frequency, though. This is due to limitations of the original MIDI standards. For Xen MIDI Retuner to create MIDI to send to your favorite synthesizer that results in the frequencies of your chosen scale, Xen MIDI Retuner sends out pitch-bend (along with notes). The original MIDI standard only allows pitch-bend per MIDI channel, _not_ per note. Therefore, Xen MIDI Retuner must choose a single note that is use for retuning, and output pitch-bend for the channel so that note reaches the scale frequency. The chosen note that Xen MIDI Retuner chooses (a.k.a the priority note) is determined by the parameters _Single Channel Note Prioritization_. Some _Single Channel Note Prioritization_ options provide a _Single Channel Note Prioritization Modifier_ that effects which note is chosen.

Currently, a "single channel mode" has only been created. Each channel of MIDI inputted into Xen MIDI Retuner is dealt with independently. In other words, each channel passes through independently, and no MIDI messages are moved between channels.

The input of the plugin assumes that each MIDI note _represents_ a note of scale 12 equal divisions of the octave where A4 (midi note 69)=440 Hz.

### Download (DAW Support Table)

To download Xen MIDI Retuner, find your DAW in the list below, then click the hyperlink in the right-most column (in column "Recommended Download Version").

| DAW     | VST2 |    VST2 MIDI Effect     | AU  |         AU MIDI Effect          | Pipe MIDI input to Instrument<sup>\*</sup> plugin | Pipe MIDI output from Instrument plugin | Recommended Download Version |
| ------- | :--: | :---------------------: | :-: | :-----------------------------: | :-----------------------------------------------: | :-------------------------------------: | :--------------------------: |
| Ableton |  ✓   | ✓ (Loads as Instrument) |  ✓  | Plugin does not show in browser |                         ✓                         |                    ✓                    |       VST2 Instrument        |
| Logic   |      |                         |  ✓  |                ✓                |                         ✓                         |                                         |        AU MIDI Effect        |

<sup>\*</sup>Instrument (a.k.a. Synth) plugins are defined as a plugin with MIDI input and Audio output. Some DAWs support being able to extract (pipe) the MIDI output from Instrument plugins.

## License

Mark Henning's AnaMark tuning library is under the MIT license. This project currently makes no modifications to that original source.

Xen MIDI Retuner's original code is licensed under GNU General Public License v3.0. See file LICENSE.md for more details.

## Contributing

If you make any changes to the source that enhances this plugin, or can be benifical for others, please provide a pull request! If you want to work on a feature thats in **Feature Todo**, please let me know so we don't accidentally both work on the same thing at the same time, or we can work together to get the feature done faster! :)

## Compiling

For compiling to VST.2x plugin, the VST.2x SDK is needed. The global path for VST.2x sdk must be set your VST.2x sdk. VST.2x sdk that used to be embedded into JUCE can be found at [this commit](https://github.com/WeAreROLI/JUCE/tree/8317738112ccceb2c58deac3e4bb167c62682916/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces).

Mark Henning's AnaMark library is part of the repository as a submodule. Initalize the submodule using:

`git submodule update --init --recursive`

## Feature Todo / Roadmap without a timeline

Feature todos may or may not be completed in order of listing.

- .scl and .kbm scale file support
- Mapping midi note to scale note (with interpolation)
- _Reference tuner_ mode.
  - Performers with continuous, possibly MPE enabled controllers (Roli's Seaboard) will be able to see how their specifically tempered (equal tempered) controller can be played to achieve their wanted tuning.
  - The reference tuner mode will act as a teaching tool for one to learn how to play in different tunings using their continuous controller.
- Global refining of scale (moving reference note)
- Scale Editor (modify AnaMark scale dynamically)
- Exposing scale information as editable parameters
- Remapping single channel polyphony input to multichannel output
- Remapping single channel polyphony input to MPE output
- Multiple scales (programs / presets)
- Scale transition (crossfade between scale)
- Export / import Sevish Workshop url
- [Other tuning files](https://hpi.zentral.zone/filetypes)

Far Future:

- Tuning modified in realtime using the MTS protocol (see MTS (MIDI Tuning Standard) section [here](https://www.midi.org/articles-old/microtuning-and-alternative-intonation-systems), though sysex support is DAW dependent)

_NOTE:_ This project may not support VST.3x for a while, as the VST.3x specifications for MIDI CC and Pitch-bend output is much, _much_ different than VST.2x (see this: [Add support for sending Midi CCs out of VST3 plugins](https://forum.juce.com/t/add-support-for-sending-midi-ccs-out-of-vst3-plugins/35781)).

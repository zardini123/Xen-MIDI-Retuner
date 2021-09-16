# Xen MIDI Retuner

Xen MIDI Retuner is a novel way for musicians to begin easily experimenting with the complex intervals of microtonal and xenharmonic music.

Xen MIDI Retuner uses the MIDI standard retuning midi notes using pitch-bend to achieve the frequencies defined by a scale. If a synthesizer/DAW can take in note and pitch-bend MIDI messages, with Xen MIDI Retuner, by proxy, the synthesizer/DAW now supports tuning/scale files.

Xen MIDI Retuner is a MIDI plugin that retunes MIDI input to microtonal and xenharmonic scales via clever midi note and pitch-bend output. Currently, the scale to retune to is defined by AnaMark (.tun) files.

## Why?

Creating microtonal and xenharmonic music has typically been accomplished by loading tuning/scale files (.scl, .kbm, and/or .tun) or Midi Tuning Standard (MTS) SysEx messages into one's favorite synthesizer or DAW. Unfortunately, many synthesizers and DAWs (Ableton) do not support these retuning file formats.

Thankfully, practically all synthesizers and DAWs follow the Musical Instrument Digital Interface (MIDI) standard. Xen MIDI Retuner uses this standard to its advantage, retuning midi notes using pitch-bend messages to achieve the frequencies defined by tuning/scale files (explained in more detail in section **How? (Usage)**). If a synthesizer/DAW can take in note and pitch-bend MIDI messages, with Xen MIDI Retuner, by proxy, the synthesizer/DAW now supports tuning/scale files.

Xen MIDI Retuner additionally functions as a novel way for musicians to begin easily experimenting with the complex intervals of microtonal and xenharmonic music. Synthesizers with tuning/scale file support maps each MIDI note (each keyboard key) directly to scale note. Therefore, if one is using an octave scale with only 7 notes in it (i.e. 7 EDO), playing a tritone (A + D#) on one's keyboard results in hearing an octave. Pianists who have practiced for years associating the feeling playing an octave on a keyboard with hearing an octave would have to re-learn their association for specific scales. Xen MIDI Retuner removes this barrier of entry by mapping the frequencies of imported scales to the physical layout of the MIDI controller. In other words, Xen MIDI Retuner will "snap" incoming notes to the closest scale frequency, and outputs that frequency using the combination of new MIDI notes plus pitch-bend. Therefore, playing an octave results in hearing the closest interval to an octave of the imported scale.

## Setup

Download the tuning host ["MTS-ESP Mini" by ODDSound](https://oddsound.com/mtsespmini.php) to be able to load scale files into Xen MIDI Retuner.  This is required currently as Xen MIDI Retuner currently only supports the MTS-ESP tuning API for acquiring tuning information.  You do not need MTS-ESP Mini if you already have a MTS-ESP host installed.

You can quickly start experimenting with different scales by downloading Sevish's Tuning Packs ([page link](https://sevish.com/music-resources/), [direct download](https://sevish.com/musicmakingstuff/sevish-tunings-pack-v1.1.zip)), or creating your own tuning files online with [Sevish's Workshop](https://sevish.com/scaleworkshop/).  These tuning files can be loaded into Xen MIDI Retuner via the tuning host MTS-ESP Mini as mentioned above.

## How? (Usage)

To begin using Xen MIDI Retuner as intended, _Output Pitch Bend Range_ (in section _Output_) must be set properly. Set the _Output Pitch Bend Range_ to the pitch-bend range of the instrument that Xen MIDI Retuner is outputting MIDI to. For example, if your instrument has pitch-bend range set to +/- 5st, set _Output Pitch Bend Range_ to 5.

_Input Pitch Bend Range_ is the semitones the MIDI notes you play into Xen MIDI Retuner will he pitched up/down when pitch wheel MIDI messages are also inputted. For example, if you play notes into Xen MIDI Retuner, have _Input Pitch Bend Range_ set to 2, and move your controller's pitch wheel all the way up, the notes will be pitched up by 2 semitones. This is identical to how synthesizers deal with pitch-bend.

Note that this shifting of MIDI notes due to input pitch-bend is _pre-conversion_.

The notes played into Xen MIDI Retuner (after being shifted by inputted pitch-bend) are then "snapped" to the closest scale frequency. How "aggressive" the snapping is defined by the _Scale Note Snapping Curve_ parameter. Setting _Scale Note Snapping Curve_ to 1 results in no snapping, therefore no retuning is applied.

Not every note is "snapped" to the closest scale frequency, though. This is due to limitations of the original MIDI standards. For Xen MIDI Retuner to create MIDI to send to your favorite synthesizer that results in the frequencies of your chosen scale, Xen MIDI Retuner sends out pitch-bend (along with notes). The original MIDI standard only allows pitch-bend per MIDI channel, _not_ per note. Therefore, Xen MIDI Retuner must choose a single note that is use for retuning, and output pitch-bend for the channel so that note reaches the scale frequency. The chosen note that Xen MIDI Retuner chooses (a.k.a the priority note) is determined by the parameters _Single Channel Note Prioritization_. Some _Single Channel Note Prioritization_ options provide a _Single Channel Note Prioritization Modifier_ that effects which note is chosen.

Currently, a "single channel mode" has only been created. Each channel of MIDI inputted into Xen MIDI Retuner is dealt with independently. In other words, each channel passes through independently, and no MIDI messages are moved between channels.

The input of the plugin assumes that each MIDI note _represents_ a note of scale 12 equal divisions of the octave where A4 (midi note 69)=440 Hz.

### Download

One can find the most recent downloadable version of Xen MIDI Retuner [under Releases](https://github.com/zardini123/Xen-MIDI-Retuner/releases).

### DAW Support Table

Eventually, the following table will help users to download Xen MIDI Retuner. One would find their DAW in the list below, then click the hyperlink in the right-most column (in column "Recommended Download Version"). Currently as all releases are pre-releases, getting the links to the compiled assets is not possible.

If your DAW is not listed, please create an issue titled "_<insert DAW name here>_ MIDI Support Table Entry". If you can, then find out if your DAW supports the properties that are listed in the table. Make sure to note any inconsistencies like I did for Ableton. I can then add what you found to the table.

| DAW     | VST2 |    VST2 MIDI Effect     | AU (macOS Only) |         AU MIDI Effect          | Pipe MIDI input to Instrument<sup>\*</sup> plugin | Pipe MIDI output from Instrument plugin | Recommended Download Version |
| ------- | :--: | :---------------------: | :-------------: | :-----------------------------: | :-----------------------------------------------: | :-------------------------------------: | :--------------------------: |
| Ableton |  ✓   | ✓ (Loads as Instrument) |        ✓        | Plugin does not show in browser |                         ✓                         |                    ✓                    |       VST2 Instrument        |
| Logic   |      |                         |        ✓        |                ✓                |                         ✓                         |                                         |        AU MIDI Effect        |

<sup>\*</sup>Instrument (a.k.a. Synth) plugins are defined as a plugin with MIDI input and Audio output. Some DAWs support being able to extract (pipe) the MIDI output from Instrument plugins.

## License

Mark Henning's AnaMark tuning library is under the MIT license. This project currently makes no modifications to that original source.

Xen MIDI Retuner's original code is licensed under GNU General Public License v3.0. See file LICENSE.md for more details.

## Contribution

### Compiling

This plugin uses [JUCE](https://juce.com/get-juce/download) and the `api_redesign` branch of [AnaMark Tuning Library](https://github.com/zardini123/AnaMark-Tuning-Library/tree/api_redesign).  JUCE and AnaMark Tuning Library are included as git submodules in the `lib/` directory.

Initialize the submodules using this in the project's root directory:

`git submodule update --init --recursive`

As of currently, VST.2x is used over VST.3x as I have not had enough time to research the effort required to make the conversion.  VST.3x specifications for MIDI CC and Pitch-bend output is much, _much_ different than VST.2x (see this: [Add support for sending Midi CCs out of VST3 plugins](https://forum.juce.com/t/add-support-for-sending-midi-ccs-out-of-vst3-plugins/35781)).  Eventually the plugin will be written for exclusive VST.3x support only.

To compile the plugin now, the VST.2x SDK is required.  VST.2x SDK is not included in JUCE anymore.  The last JUCE commit that had the VST.2x SDK embedded in it can be found [here](https://github.com/juce-framework/JUCE/tree/8317738112ccceb2c58deac3e4bb167c62682916/modules/juce_audio_processors/format_types/VST3_SDK). Download the entire commit ([direct download](https://github.com/juce-framework/JUCE/archive/8317738112ccceb2c58deac3e4bb167c62682916.zip)), extract folder VST3_SDK (located at `modules/juce_audio_processors/format_types/VST3_SDK`) out of the archive, and move the VST3_SDK folder to somewhere you can locate later.  _Note_ it says VST3, but it contains the VST.2x SDK code.

CMake needs to know of the location of your VST.2x SDK, so we need to set a global (i.e. absolute) path to it.  This is done when preparing the build next.

Prepare the build by running this command in the root folder of this project:

`cmake -B build -D JUCE_GLOBAL_VST2_SDK_PATH=<path to VST3_SDK folder>`

CMake uses the instance of JUCE in the `lib/` directory.  If the submodule was not initialized, the plugin will fail to compile.

**Notice:** Make sure _JUCE_GLOBAL_VST2_SDK_PATH_ is the path to your VST3_SDK folder as mentioned earlier.

After preparing the build, run this command:

`cmake --build build --config Release -j 8`

**Notice:** Option `-j` sets number of threads to use for compiling. Usually set this number to the number of cores your computer has.

This will now build the plugins for your operating system. The plugins will automatically installed to the default path for plugins for your system. JUCE will print the path to the automatically installed plugins at the end of the plugin compilation.

If you want to install the plugins to a custom location, the compiled plugins are under `build/midi_plugin_artefacts/` and `build/synth_plugin_artefacts/`.

### Projucer Dependency

Projucer is primarily used for quick and easy prototyping of the user interface with the what-you-see-is-what-you-get (WYSIWYG) GUI editor.  To keep the Projucer file (_.jucer_ in root directory of project) in sync with development changes, ensure the following is done in Projucer:

- Creating/adding files or new components
- Deleting files
- Modifying GUI of Projcer-created components

Projucer is not used for compiling in this project.

As Projucer makes automated changes to components using the GUI editor, any additions to those components must be done in dedicated areas of the Projucer files.  Any removals must be done through the GUI editor.  If not, your changes will be lost when someone updates some layout in a GUI component.

Projucer is not provided pre-compiled in the JUCE repository found in `lib/`.  You can either download Projucer via the JUCE website, or preferably you can compile it using your included submodule.  Navigate to `/lib/JUCE/` and run the following:

```
cmake . -B cmake-build -DJUCE_BUILD_EXAMPLES=OFF -DJUCE_BUILD_EXTRAS=ON
cmake --build cmake-build --target Projucer
```

Your built Projucer is located from the JUCE path at `cmake-build/extras/Projucer/Projucer_artefacts`.  Open Projucer, go to "Tools" and enable "GUI Editor Enabled".  You can create a symlink/alias to your Applications folder (macOS) or to your desktop (Windows) to have a quick way to access Projucer next to your IDE.

### Contribution Conclusion

If you make any changes to the source that enhances this plugin, or can be benifical for others, please provide a pull request!

Many scale-related features planned for Xen MIDI Retuner are actually [AnaMark Tuning Library](https://github.com/zardini123/AnaMark-Tuning-Library) related features. If you are interested in the development of the following features, please consider looking at the AnaMark Tuning Library GitHub page.

- .scl and .kbm scale file support
- Scale Editor (modify AnaMark scale dynamically)
- Exposing scale information as editable parameters
- Export / import Sevish Workshop url
- Tuning modified in realtime using the MTS protocol (see MTS (MIDI Tuning Standard) section [here](https://www.midi.org/articles-old/microtuning-and-alternative-intonation-systems), though sysex support is DAW dependent)
- [Other tuning files](https://hpi.zentral.zone/filetypes)

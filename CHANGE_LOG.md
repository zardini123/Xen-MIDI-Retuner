# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

## [0.0.4] - 2021-10-01

### Changed

- The entire plugin functionality.
  - Entire concept of the interpolation/transition function has been replaced with closest scale note mapping.
- Keyboard visualization works with continuous midi notes instead of discrete midi notes.
- Renamed input and output pitchbend to "Keyboard" and "Synth" pitchbend.

### Added

- Keyboard visualization has zoom and drag of the view.
- "_Synth is already tuned_" for playing synthesizers that have tuning functionality, yielding polyphonic tuning over one MIDI channel.
  - Requires both Xen MIDI Retuner and the synth to be tuned to the same scale.
- "_Send out untuned notes_" allowing interesting tuning potential with the byproduct of playing the notes not subjected to tuning by pitchbend per channel.

### Known Issues

- "_Pitch Bend Wheel (semitones)_" does not do anything as scale-oriented pitchbend has to be implemented.

## [0.0.3] - 2021-01-06

### Known Issues

- Enabling/disabling view options in Keyboard view is not instantaneous.
- Reloading Xen MIDI Retuner state results in all keyboard notes/pitches not showing even though they are enabled in the controls.

### Added

- Added colored underlines under each section to help users understand where each of the lines in keyboard view are coming from.
- Output notes/pitchbend changes in realtime when changing "Transition", "Midpoint", and "Note Prioritization" when input notes are held.
- Output Pitch Bend and Note Priority controls now have tooltips.
- Keyboard Visual Additions
  - Added navigation buttons (shift left/right, zoom in/out). Currently temporary until full mouse navigation is implemented.
  - Added options to view specific notes/pitches displayed on the keyboard view.
  - Added ability to view specific MIDI channel in keyboard view.
  - Provided 12-tone equal temperament reference lines.
- Added option to disable Note Prioritization updates in event of Note Off. Can be useful to prevent quick changes in note priority.

### Changed

- Changed _Input Pitch Bend Range_ and _Output Pitch Bend Range_ default values to 2 semitones (previously 48).
- Changed _Single Channel Priority Note_ and its _Single Channel Priority Note Modifier_'s internal parameter name to utilize underscores instead of capitals to make parameter names more consistent.
- Keyboard Visual Changes
  - Changed default starting and ending MIDI note from -20 and 140 to 20 and 100.
  - Changed starting and ending MIDI note sliders from increment to linear bar type.
  - More discernible display lines for notes/pitches.
    - Some notes/pitches are larger than others for means of distinguishing importance.
- Changed "Single Channel Note Prioritization" label to "Note Prioritization" (internal parameter names are not changed).

### Fixed

- Fixed plugin crashing in Trackation Waveform 8. Issue was due to "priority note" Note pointer in Channel struct not being set to nullptr on initialization.

## [0.0.2] - 2020-08-04

### Known Issues

- Plugin crashes at a uncontrolled time upon inputting a MIDI note in Tracktion Waveform 8.
- Only active _Interpolation Dimension_ option is still "Continuous Midi Note (Cents)."
- "MIDI Environment Tests" functionality is incomplete.
- Loading previous state of plugin (i.e. when loading DAW project) does not update GUI components.

### Added

- Gave ability to adjust center point of Scale Note Snapping Curve (Resolves Issue #4).
- Added simple label in Scale Editor section that displays the _.tun_ file scale name.

### Changed

- Migrated all processor data out of PluginProcessor into struct ProcessorData.

### Fixed

- Modifying parameters from the host updates its corresponding GUI components.
- Processor data is per plugin instance, not shared between instances (Fixes Issue #5).
- All non-processed MIDI is passed through unscathed.
- Fixed issue where retuner will not output anything until the GUI is first started up. This was fixed by splitting TransitionCurve GUI and logic.
- _Scale Note Snapping Curve's_ controls (transition and midpoint) now save.
- Velocity and Random single channel note prioritization now implemented and works (no segmentation faults) (Fixes Issue #1).
- Adjusting _Single Channel Priority Note_ parameters and/or _Scale Note Snapping Curve_ parameters while holding notes results in output updates.

## [0.0.1] - 2020-04-13

- Inital Release.

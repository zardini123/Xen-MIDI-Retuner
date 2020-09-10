# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

## [0.0.3]

### Fixed

- Fixed plugin crashing in Trackation Waveform 8. Issue was due to "priority note" Note pointer in Channel struct not being set to nullptr on initialization.

### Changed

- Changed _Input Pitch Bend Range_ and _Output Pitch Bend Range_ default values to 2 semitones (previously 48).
- Changed _Single Channel Priority Note_ and its _Single Channel Priority Note Modifier_'s internal parameter name to utilize underscores instead of capitals to make parameter names more consistent.

## [0.0.2]

### Known Issues

- Plugin crashes at a uncontrolled time upon inputting a MIDI note in Tracktion Waveform 8.
- Only active _Interpolation Dimension_ option is still "Continuous Midi Note (Cents)."
- "MIDI Enviroment Tests" functionality is incomplete.
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

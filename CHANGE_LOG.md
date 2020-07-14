# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

## [0.0.2]
### Added
- Gave ability to adjust center point of Scale Note Snapping Curve (Resolves Issue #4).

### Changed
- Migrated all processor data out of PluginProcessor into struct ProcessorData.

### Fixed
- Modifying parameters from the host updates its corresponding GUI components.
- Processor data is per plugin instance, not shared between instances (Fixes Issue #5).
- All non-processed MIDI is passed through unscathed.
- Fixed issue where retuner will not output anything until the GUI is first started up.  This was fixed by splitting TransitionCurve GUI and logic.
- _Scale Note Snapping Curve's_ controls (transition and midpoint) now save.

## [0.0.1] - 2020-04-13
- Inital Release.

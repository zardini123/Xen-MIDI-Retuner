cmake_minimum_required(VERSION 3.15)

project(XEN_MIDI_RETUNER VERSION 0.0.3)

set(CMAKE_CXX_STANDARD 14)

# For JSON Compilation Database Format Specification used by clang-tidy
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(lib/JUCE)

# VST2 SDK path
# Set during first cmake command line using -D JUCE_GLOBAL_VST2_SDK_PATH=/path/to/sdk
# if(JUCE_GLOBAL_VST2_SDK_PATH)
#     juce_set_vst2_sdk_path("${JUCE_GLOBAL_VST2_SDK_PATH}")
# endif()

function(my_add_custom_plugin_target target_name is_synth is_midi_effect)
  if(is_synth)
    set(PRODUCT_NAME_FINAL "Xen MIDI Retuner (Instrument)")
  endif()

  if(is_midi_effect)
    set(PRODUCT_NAME_FINAL "Xen MIDI Retuner (MIDI Effect)")
  endif()

  juce_add_plugin("${target_name}"
    IS_SYNTH "${is_synth}"
    NEEDS_MIDI_INPUT TRUE
    NEEDS_MIDI_OUTPUT TRUE
    IS_MIDI_EFFECT "${is_midi_effect}"

    EDITOR_WANTS_KEYBOARD_FOCUS TRUE # Does the editor need keyboard focus?
    COPY_PLUGIN_AFTER_BUILD TRUE      # Should the plugin be installed to a default location after building?

    # Plugin Categories
    # VST2_CATEGORY kPlugCategUnknown
    # VST3_CATEGORIES Fx Tools
    # AU_MAIN_TYPE kAudioUnitType_MIDIProcessor
    # AAX_CATEGORY AAX_ePlugInCategory_Effect

    # other settings...
    PLUGIN_MANUFACTURER_CODE Tap3
    PLUGIN_CODE Xenm
    FORMATS AU VST
    BUNDLE_ID com.TarasPalczynskiIII.XenMIDIRetuner
    COMPANY_NAME "Taras Palczynski III"
    PRODUCT_NAME "${PRODUCT_NAME_FINAL}"
    )

  juce_generate_juce_header("${target_name}")

  # Sources found using bash command:  find ./Source -name \*.cpp -print
  target_sources("${target_name}" PRIVATE
    ./lib/AnaMark-Tuning-Library/lib/MTS-ESP/Master/libMTSMaster.cpp
    ./lib/AnaMark-Tuning-Library/lib/MTS-ESP/Client/libMTSClient.cpp
    ./Source/Utilities.cpp
    ./Source/Components/TransitionCurveGUI.cpp
    ./Source/Components/TransitionCurve.cpp
    ./Source/EditorModules/ProcessingView/ConversionModule/TransitionCurveEvaluationGraphic.cpp
    ./Source/EditorModules/ProcessingView/OutputModule.cpp
    ./Source/EditorModules/ProcessingView/ScaleEditor.cpp
    ./Source/EditorModules/ProcessingView/InputModule.cpp
    ./Source/EditorModules/ProcessingView/ConversionModule.cpp
    ./Source/EditorModules/KeyboardVisual/KeyboardVisualControlsOverlay.cpp
    ./Source/EditorModules/KeyboardVisual/KeyboardVisualOptions.cpp
    ./Source/EditorModules/KeyboardVisual/KeyboardVisual.cpp
    ./Source/EditorModules/KeyboardVisual/NoteAndFrequencyOverlay.cpp
    ./Source/EditorModules/KeyboardVisual/ScaleFrequenciesOverlay.cpp
    ./Source/EditorModules/ProcessingView.cpp
    ./Source/EditorModules/TestingView/CapabilitiesTestGUI.cpp
    ./Source/PluginProcessor.cpp
    ./Source/PluginGUI.cpp
    ./Source/PluginEditor.cpp
    ./Source/ProcessorData.cpp
    ./Source/ComponentWithReferenceToData.cpp
    )

  target_compile_definitions("${target_name}" PUBLIC
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_VST3_CAN_REPLACE_VST2=0
    # JucePlugin_IsMidiEffect=1
    )

  target_link_libraries("${target_name}" PRIVATE
    juce::juce_audio_utils
    juce::juce_recommended_config_flags
    juce::juce_recommended_lto_flags
    juce::juce_recommended_warning_flags)

endfunction()

my_add_custom_plugin_target(synth_plugin TRUE FALSE)
my_add_custom_plugin_target(midi_plugin TRUE TRUE)

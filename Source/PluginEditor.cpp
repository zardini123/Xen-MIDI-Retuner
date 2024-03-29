/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginEditor.h"

//==============================================================================
XenMidiRetunerAudioProcessorEditor::XenMidiRetunerAudioProcessorEditor (XenMidiRetunerAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    PluginGUI *comp = new PluginGUI(p.getDataReference());

    addAndMakeVisible(comp);
    setSize (comp->getWidth(), comp->getHeight());
}

XenMidiRetunerAudioProcessorEditor::~XenMidiRetunerAudioProcessorEditor()
{
}

//==============================================================================
void XenMidiRetunerAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void XenMidiRetunerAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

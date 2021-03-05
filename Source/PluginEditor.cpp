/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
IdealSynthesizerAudioProcessorEditor::IdealSynthesizerAudioProcessorEditor (IdealSynthesizerAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), osc1Gui (p), osc2Gui (p), ampEnvGui (p), fil1Gui (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 400);

    addAndMakeVisible(&osc1Gui);
    addAndMakeVisible(&osc2Gui);
    addAndMakeVisible(&ampEnvGui);
    addAndMakeVisible(&fil1Gui);
 

    //Slider parameters
    /*midiVolume.setSliderStyle(Slider::LinearBarVertical);
    midiVolume.setRange(0.0, 127.0, 1.0);
    midiVolume.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    midiVolume.setPopupDisplayEnabled(true, false, this);
    midiVolume.setTextValueSuffix(" Volume");
    midiVolume.setValue(1.0);

    //Add Volume slider to editor
    addAndMakeVisible(&midiVolume);

    //Add listener to Volume slider
    midiVolume.addListener(this);*/
}

//==============================================================================
/*void IdealSynthesizerAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    processor.noteOnVel = midiVolume.getValue();
}*/

IdealSynthesizerAudioProcessorEditor::~IdealSynthesizerAudioProcessorEditor()
{
}

//==============================================================================
void IdealSynthesizerAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));

}

void IdealSynthesizerAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    Rectangle<int> area = getLocalBounds();

    const int componentWidth = 300;
    const int componentHeight = 200;

    osc1Gui.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight));
    osc2Gui.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight));
    ampEnvGui.setBounds(0, 200, 300, 200);
    fil1Gui.setBounds(300, 200, 300, 200);

    //Setting position and size of slider (x, y, width, height)
    //midiVolume.setBounds(40, 30, 20, getHeight() - 60);
}

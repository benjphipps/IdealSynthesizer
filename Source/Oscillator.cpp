/*
  ==============================================================================

    Oscillator.cpp
    Created: 24 May 2020 4:30:34pm
    Author:  Benjamin

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Oscillator.h"

//==============================================================================
Oscillator::Oscillator(IdealSynthesizerAudioProcessor& p) :
processor(p)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    setSize(300, 200);

    oscSelect.addItem("Saw", 1);
    oscSelect.addItem("Square", 2);
    oscSelect.addItem("Triangle", 3);
    oscSelect.addItem("Sine", 4);
    oscSelect.setJustificationType(Justification::centred);
    oscSelect.addListener(this);
    oscSelect.setTooltip("This menu allows you to select a waveform to be produced by the oscillator");
    addAndMakeVisible(&oscSelect);
    osc1WaveSelect = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "waveform", oscSelect);

    oscVolume.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    oscVolume.setRange(0.0f, 1.0f);
    oscVolume.setValue(0.7f);
    oscVolume.setTextBoxStyle(Slider::TextBoxBelow, false, 60.0, 20.0);
    oscVolume.setTooltip("This dial changes the octave of the note that the synthesizer will play");
    addAndMakeVisible(&oscVolume);
    osc1VolumeVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "osc1volume", oscVolume);

    oscLblVol.attachToComponent(&oscVolume, false);
    oscLblVol.setText("Volume", dontSendNotification);
    addAndMakeVisible(&oscLblVol);

    oscTranspose.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    oscTranspose.setRange(1, 11);
    oscTranspose.setValue(1);

    oscTranspose.setTextBoxStyle(Slider::TextBoxBelow, false, 60.0, 20.0);
    oscTranspose.setTextValueSuffix("st");
    addAndMakeVisible(&oscTranspose);
    osc1TransposeVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "osc1transpose", oscTranspose);

    oscLblTrans.attachToComponent(&oscTranspose, false);
    oscLblTrans.setText("Transpose", dontSendNotification);
    addAndMakeVisible(&oscLblTrans);

    oscOctave.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    oscOctave.setRange(0.0f, 1.0f);
    oscOctave.setValue(0.7f);
    oscOctave.setTextBoxStyle(Slider::TextBoxBelow, false, 60.0, 20.0);
    oscOctave.setTextValueSuffix("oct");
    addAndMakeVisible(&oscOctave);
    osc1OctaveVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "osc1octave", oscOctave);

    oscLblOctave.attachToComponent(&oscOctave, false);
    oscLblOctave.setText("Octave", dontSendNotification);
    addAndMakeVisible(&oscLblOctave);
}

Oscillator::~Oscillator()
{

}

void Oscillator::paint (Graphics& g)
{
    Rectangle<int> osc1Title(0, 10, getWidth(), 20);

    g.fillAll(Colours::darkgrey);
    g.setColour(Colours::white);
    g.drawText("Oscillator 1", osc1Title, Justification::centredTop);

    Rectangle<float> osc1Contain(0, 0, 300, 200);

    g.setColour(Colours::black);
    g.drawRect(osc1Contain, 3.0f);
}

void Oscillator::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    Rectangle<int> area = getLocalBounds().reduced(40);

    oscSelect.setBounds(area.removeFromTop(20));

    oscTranspose.setBounds(20, 100, 70, 70);
    oscOctave.setBounds(100, 100, 70, 70);
    oscVolume.setBounds(180, 100, 70, 70);
    //oscLblVol.setBounds(250, 150, 70, 70);

}

void Oscillator::comboBoxChanged(ComboBox* box)
{

}

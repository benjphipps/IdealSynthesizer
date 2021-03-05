/*
  ==============================================================================

    Oscillator2.cpp
    Created: 26 May 2020 6:26:59am
    Author:  Benjamin

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Oscillator2.h"

//==============================================================================
Oscillator2::Oscillator2(IdealSynthesizerAudioProcessor& p) :
processor(p)
{
    setSize(300, 200);

    osc2Select.addItem("Saw", 1);
    osc2Select.addItem("Square", 2);
    osc2Select.addItem("Triangle", 3);
    osc2Select.addItem("Sine", 4);
    osc2Select.setJustificationType(Justification::centred);
    osc2Select.addListener(this);
    addAndMakeVisible(&osc2Select);

    osc2Volume.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    osc2Volume.setRange(0.0f, 1.0f);
    osc2Volume.setValue(0.7f);
    osc2Volume.setTextBoxStyle(Slider::TextBoxBelow, false, 60.0, 20.0);
    osc2Volume.setTooltip("This dial changes the octave of the note that the synthesizer will play");
    addAndMakeVisible(&osc2Volume);
    osc2VolumeVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "osc2volume", osc2Volume);

    osc2LblVol.attachToComponent(&osc2Volume, false);
    osc2LblVol.setText("Volume", dontSendNotification);
    addAndMakeVisible(&osc2LblVol);

    osc2Transpose.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    osc2Transpose.setRange(1, 11);
    osc2Transpose.setValue(1);
    //oscTranspose.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 60.0, 20.0);
    osc2Transpose.setTextBoxStyle(Slider::TextBoxBelow, false, 60.0, 20.0); //PREVIOUS TEXTBOX STYLE SETTING
    osc2Transpose.setTextValueSuffix("st");
    addAndMakeVisible(&osc2Transpose);
    osc2TransposeVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "osc2transpose", osc2Transpose);

    osc2LblTrans.attachToComponent(&osc2Transpose, false);
    osc2LblTrans.setText("Transpose", dontSendNotification);
    addAndMakeVisible(&osc2LblTrans);

    osc2Octave.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    osc2Octave.setRange(0.0f, 1.0f);
    osc2Octave.setValue(0.7f);
    osc2Octave.setTextBoxStyle(Slider::TextBoxBelow, false, 60.0, 20.0);
    osc2Octave.setTextValueSuffix("oct");
    addAndMakeVisible(&osc2Octave);
    osc2OctaveVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "osc2octave", osc2Octave);

    osc2LblOctave.attachToComponent(&osc2Octave, false);
    osc2LblOctave.setText("Octave", dontSendNotification);
    addAndMakeVisible(&osc2LblOctave);

    osc2WaveSelect = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "waveform2", osc2Select);

}

Oscillator2::~Oscillator2()
{
}

void Oscillator2::paint (Graphics& g)
{
    Rectangle<int> osc2Title(0, 10, getWidth(), 20);

    g.fillAll(Colours::darkgrey);
    g.setColour(Colours::white);
    Rectangle<float> osc2Contain(0, 0, 300, 200);

    g.drawText("Oscillator 2", osc2Title, Justification::centredTop);

    g.setColour(Colours::black);
    g.drawRect(osc2Contain, 3.0f);
}

void Oscillator2::resized()
{
    // This method is where you should set the bounds of any child
// components that your component contains..
    Rectangle<int> area = getLocalBounds().reduced(40);

    osc2Select.setBounds(area.removeFromTop(20));

    osc2Transpose.setBounds(20, 100, 70, 70);
    osc2Octave.setBounds(100, 100, 70, 70);
    osc2Volume.setBounds(180, 100, 70, 70);

}

void Oscillator2::comboBoxChanged(ComboBox* box)
{

}

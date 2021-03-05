/*
  ==============================================================================

    AmpEnvelope.cpp
    Created: 25 May 2020 9:21:35pm
    Author:  Benjamin

  ==============================================================================
*/

#include <JuceHeader.h>
#include "AmpEnvelope.h"

//==============================================================================
AmpEnvelope::AmpEnvelope(IdealSynthesizerAudioProcessor& p) :
processor(p)
{
    setSize(250, 200);

    attSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    attSlider.setRange(1.0f, 10000.0f);
    attSlider.setValue(10.0f);
    attSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50.0, 20.0); //PREVIOUS AMP ENVELOPE TEXTBOX STYLE
    //attSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    attSlider.setTextValueSuffix("ms");
    addAndMakeVisible(&attSlider);

    ampLblAtt.attachToComponent(&attSlider, false);
    ampLblAtt.setText("Attack", dontSendNotification);
    addAndMakeVisible(&ampLblAtt);

    decSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    decSlider.setRange(1.0f, 10000.0f);
    decSlider.setValue(1000.0f);
    decSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50.0, 20.0);
    decSlider.setTextValueSuffix("ms");
    addAndMakeVisible(&decSlider);

    ampLblDec.attachToComponent(&decSlider, false);
    ampLblDec.setText("Decay", dontSendNotification);
    addAndMakeVisible(&ampLblDec);

    susSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    susSlider.setRange(0.0f, 1.0f);
    susSlider.setValue(0.7f);
    susSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50.0, 20.0);
    susSlider.setTextValueSuffix("ms");
    addAndMakeVisible(&susSlider);

    ampLblSus.attachToComponent(&susSlider, false);
    ampLblSus.setText("Sustain", dontSendNotification);
    addAndMakeVisible(&ampLblSus);

    relSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    relSlider.setRange(1.0f, 10000.0f);
    relSlider.setValue(200.0f);
    relSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50.0, 20.0);
    relSlider.setTextValueSuffix("ms");
    addAndMakeVisible(&relSlider);

    ampLblRel.attachToComponent(&relSlider, false);
    ampLblRel.setText("Release", dontSendNotification);
    addAndMakeVisible(&ampLblRel);

    attTree = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "attack", attSlider);
    decTree = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "decay", decSlider);
    susTree = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "sustain", susSlider);
    relTree = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "release", relSlider);
}

AmpEnvelope::~AmpEnvelope()
{
}

void AmpEnvelope::paint (Graphics& g)
{
    Rectangle<int> ampEnvTitle(0, 10, getWidth(), 20);

    g.fillAll(Colours::darkgrey);
    g.setColour(Colours::white);
    Rectangle<float> ampEnvContain(0, 0, 300, 200);

    g.drawText("Amplitude Envelope", ampEnvTitle, Justification::centredTop);

    g.setColour(Colours::black);
    g.drawRect(ampEnvContain, 3.0f);
}

void AmpEnvelope::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
        
    Rectangle<int> area = getLocalBounds();

    attSlider.setBounds(20, 50, 50, 100);
    decSlider.setBounds(85, 50, 50, 100);
    susSlider.setBounds(170, 50, 50, 100);
    relSlider.setBounds(235, 50, 50, 100);

}

/*
  ==============================================================================

    Filter1.cpp
    Created: 25 May 2020 11:36:23pm
    Author:  Benjamin

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Filter1.h"

//==============================================================================
Filter1::Filter1(IdealSynthesizerAudioProcessor& p) :
processor(p)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    setSize(300, 200);

    f1Select.addItem("Low Pass", 1);
    f1Select.addItem("High Pass", 2);
    f1Select.addItem("Band Pass", 3);
    f1Select.setText("Low Pass", 1);
    f1Select.setJustificationType(Justification::centred);
    addAndMakeVisible(&f1Select);
    f1SelectVal = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "filter1Type", f1Select);
    
    f1Cutoff.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    f1Cutoff.setRange(30.0, 8000.0);
    f1Cutoff.setValue(8000.0f);
    f1Cutoff.setTextBoxStyle(Slider::TextBoxBelow, true, 60.0, 20.0);
    f1Cutoff.setTextValueSuffix(" Hz");
    f1Cutoff.setSkewFactorFromMidPoint(1000.0);
    addAndMakeVisible(&f1Cutoff);
    f1CutoffVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filter1cutoff", f1Cutoff);

    f1LblCutoff.attachToComponent(&f1Cutoff, false);
    f1LblCutoff.setText("Cutoff", dontSendNotification);
    addAndMakeVisible(&f1Cutoff);

    f1Reso.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    f1Reso.setRange(1, 5);
    f1Reso.setValue(1);
    f1Reso.setTextBoxStyle(Slider::TextBoxBelow, true, 60.0, 20.0); //PREVIOUS SLIDER TEXTBOX STYLE
    addAndMakeVisible(&f1Reso);
    f1ResoVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filter1reso", f1Reso);

    f1LblReso.attachToComponent(&f1Reso, false);
    f1LblReso.setText("Resonance", dontSendNotification);
    addAndMakeVisible(&f1Reso);

}

Filter1::~Filter1()
{
}

void Filter1::paint (Graphics& g)
{
    Rectangle<int> f1Title(0, 10, getWidth(), 20);

    g.fillAll(Colours::darkgrey);
    g.setColour(Colours::white);
    g.drawText("Filter 1", f1Title, Justification::centredTop);

    Rectangle<float> f1Contain(0, 0, 300, 200);

    g.setColour(Colours::black);
    g.drawRect(f1Contain, 3.0f);

}

void Filter1::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    Rectangle<int> area = getLocalBounds().reduced(40);

    f1Select.setBounds(area.removeFromTop(20));
    f1Cutoff.setBounds(75, 80, 70, 70);
    f1Reso.setBounds(150, 80, 70, 70);

}

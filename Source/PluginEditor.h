/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Oscillator.h"
#include "Oscillator2.h"
#include "AmpEnvelope.h"
#include "Filter1.h"

//==============================================================================
/**
*/
class IdealSynthesizerAudioProcessorEditor  : public AudioProcessorEditor

{
public:
    IdealSynthesizerAudioProcessorEditor (IdealSynthesizerAudioProcessor&);
    ~IdealSynthesizerAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;



private:
    //void sliderValueChanged(Slider* slider) override; //[3]

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    IdealSynthesizerAudioProcessor& processor;

    Oscillator osc1Gui;
    Oscillator2 osc2Gui;
    AmpEnvelope ampEnvGui;
    Filter1 fil1Gui;

    //Slider midiVolume; // [1]

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (IdealSynthesizerAudioProcessorEditor)
};

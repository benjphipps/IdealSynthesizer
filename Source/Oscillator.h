/*
  ==============================================================================

    Oscillator.h
    Created: 24 May 2020 4:30:34pm
    Author:  Benjamin

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class Oscillator    : public Component,
                      private ComboBox::Listener
                      //private juce::SettableTooltipClient
{
public:
    Oscillator(IdealSynthesizerAudioProcessor&);
    ~Oscillator();

    void paint (Graphics&) override;
    void resized() override;

    void comboBoxChanged(ComboBox*) override;

    //void setTooltip();

private:
    ComboBox oscSelect;
    Slider oscVolume;
    Label oscLblVol;
    Slider oscTranspose;
    Label oscLblTrans;
    Slider oscOctave;
    Label oscLblOctave;


    ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> osc1WaveSelect;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> osc1VolumeVal;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> osc1TransposeVal;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> osc1OctaveVal;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    IdealSynthesizerAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Oscillator)
};

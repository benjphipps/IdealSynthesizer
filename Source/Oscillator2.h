/*
  ==============================================================================

    Oscillator2.h
    Created: 26 May 2020 6:26:59am
    Author:  Benjamin

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class Oscillator2    : public Component,
                       private ComboBox::Listener
{
public:
    Oscillator2(IdealSynthesizerAudioProcessor&);
    ~Oscillator2();

    void paint (Graphics&) override;
    void resized() override;

    void comboBoxChanged(ComboBox*) override;

private:
    ComboBox osc2Select;
    Slider osc2Volume;
    Label osc2LblVol;
    Slider osc2Transpose;
    Label osc2LblTrans;
    Slider osc2Octave;
    Label osc2LblOctave;

    ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> osc2WaveSelect;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> osc2VolumeVal;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> osc2TransposeVal;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> osc2OctaveVal;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    IdealSynthesizerAudioProcessor& processor;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Oscillator2)
};

/*
  ==============================================================================

    Filter1.h
    Created: 25 May 2020 11:36:23pm
    Author:  Benjamin

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class sliderLookAndFeel : public LookAndFeel_V4
{
public:


private:


};

class Filter1    : public Component
{
public:
    Filter1(IdealSynthesizerAudioProcessor&);
    ~Filter1();

    void paint (Graphics&) override;
    void resized() override;

private:
    Slider f1Cutoff;
    Slider f1Reso;

    ComboBox f1Select;

    Label f1LblCutoff;
    Label f1LblReso;

    LookAndFeel_V4 sliderLookAndFeel;

    ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> f1SelectVal;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> f1CutoffVal;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> f1ResoVal;

    // This reference is provided as a quick way for your editor to
// access the processor object that created it.
    IdealSynthesizerAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Filter1)
};

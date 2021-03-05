/*
  ==============================================================================

    AmpEnvelope.h
    Created: 25 May 2020 9:21:35pm
    Author:  Benjamin

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class AmpEnvelope    : public Component

{
public:
    AmpEnvelope(IdealSynthesizerAudioProcessor&);
    ~AmpEnvelope();

    void paint (Graphics&) override;
    void resized() override;

private:
   ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> attTree;
   ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> decTree;
   ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> susTree;
   ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> relTree;

   Slider attSlider;
   Label ampLblAtt;
   Slider decSlider;
   Label ampLblDec;
   Slider susSlider;
   Label ampLblSus;
   Slider relSlider;
   Label ampLblRel;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    IdealSynthesizerAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AmpEnvelope)
};

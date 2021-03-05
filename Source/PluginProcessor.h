/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SynthSound.h"
#include "SynthVoice.h"

//==============================================================================
/**
*/
class IdealSynthesizerAudioProcessor  : public AudioProcessor
{
public:
    //Creating variable for setting Volume slider to set
    //float noteOnVel;

    //==============================================================================
    IdealSynthesizerAudioProcessor();
    ~IdealSynthesizerAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    float attTime;
    float decTime;
    float susTime;
    float relTime;

    float env2AttTime;
    float env2DecTime;
    float env2SusTime;
    float env2RelTime;

    float env3AttTime;
    float env3DecTime;
    float env3SusTime;
    float env3RelTime;

    AudioProcessorValueTreeState tree;

private:
    Synthesiser idealSynth;
    SynthVoice* idealVoice;

    double lastSampleRate;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (IdealSynthesizerAudioProcessor)
};

/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
IdealSynthesizerAudioProcessor::IdealSynthesizerAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
tree (*this, nullptr)
#endif
{
    //Creating and assigning the parameters to ValueTree, connecting parameters to gui controls

    //Assigning Amp Envelope Parameters
    NormalisableRange<float> attParam(1.0f, 10000.0f);
    NormalisableRange<float> decParam(1.0f, 10000.0f);
    NormalisableRange<float> susParam(0.0f, 1.0f);
    NormalisableRange<float> relParam(1.0f, 10000.0f);

    tree.createAndAddParameter("attack", "Attack", "Attack", attParam, 10.0f, nullptr, nullptr);
    tree.createAndAddParameter("decay", "Decay", "Decay", decParam, 1000.0f, nullptr, nullptr);
    tree.createAndAddParameter("sustain", "Sustain", "Sustain", susParam, 0.7f, nullptr, nullptr);
    tree.createAndAddParameter("release", "Release", "Release", relParam, 200.0f, nullptr, nullptr);

    //Assigning Oscillator 1 Parameters
    NormalisableRange<float> waveformParam(0, 3);
    NormalisableRange<float> osc1VolumeParam(0.0f, 1.0f);
    NormalisableRange<float> osc1TransposeParam(1, 11);
    NormalisableRange<float> osc1OctaveParam(1, 5);
    tree.createAndAddParameter("waveform", "Waveform", "waveform", waveformParam, 0, nullptr, nullptr);
    tree.createAndAddParameter("osc1volume", "Osc1Volume", "osc1volume", osc1VolumeParam, 0.7f, nullptr, nullptr);
    tree.createAndAddParameter("osc1transpose", "Osc1Transpose", "osc1transpose", osc1TransposeParam, 1, nullptr, nullptr);
    tree.createAndAddParameter("osc1octave", "Osc1Octave", "osc1octave", osc1OctaveParam, 3, nullptr, nullptr);

    //Assigning Oscillator 2 Waveform Selection Parameters
    NormalisableRange<float> waveform2Param(0, 3);
    NormalisableRange<float> osc2VolumeParam(0.0f, 1.0f);
    NormalisableRange<float> osc2TransposeParam(1, 11);
    NormalisableRange<float> osc2OctaveParam(1, 5);
    tree.createAndAddParameter("waveform2", "Waveform2", "waveform2", waveform2Param, 0, nullptr, nullptr);
    tree.createAndAddParameter("osc2volume", "Osc2Volume", "osc2volume", osc2VolumeParam, 0.7f, nullptr, nullptr);
    tree.createAndAddParameter("osc2transpose", "Osc2Transpose", "osc2transpose", osc2TransposeParam, 1, nullptr, nullptr);
    tree.createAndAddParameter("osc2octave", "Osc2Octave", "osc2octave", osc2OctaveParam, 3, nullptr, nullptr);

    //Assigning Filter 1 Values
    //Note: Value maximum is 8000.0f, check on equalizer shows no change in waveform frequency past this value. Maximilian filter also seems to break when pushed past 10000.0f.
    NormalisableRange<float> f1TypeParam(0, 2);
    NormalisableRange<float> f1CutoffParam(30.0, 8000.0);
    NormalisableRange<float> f1ResoParam(1, 5);
    tree.createAndAddParameter("filter1type", "Filter1Type", "filter1type", f1TypeParam, 0, nullptr, nullptr);
    tree.createAndAddParameter("filter1cutoff", "Filter1Cutoff", "filter1cutoff", f1CutoffParam, 8000.0, nullptr, nullptr);
    tree.createAndAddParameter("filter1reso", "Filter1Reso", "filter1reso", f1ResoParam, 1, nullptr, nullptr);

    //Setting tree states
    tree.state = ValueTree("Attack");
    tree.state = ValueTree("Decay");
    tree.state = ValueTree("Sustain");
    tree.state = ValueTree("Release");

    idealSynth.clearVoices();

    //Setting for loop to allow up to 10 notes to be played at the same time
    for (int i = 0; i < 10; i++)
    {
        idealSynth.addVoice (new SynthVoice());
    }

    idealSynth.clearSounds();
    idealSynth.addSound(new SynthSound());

}

IdealSynthesizerAudioProcessor::~IdealSynthesizerAudioProcessor()
{
}

//==============================================================================
const String IdealSynthesizerAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool IdealSynthesizerAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool IdealSynthesizerAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool IdealSynthesizerAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double IdealSynthesizerAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int IdealSynthesizerAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int IdealSynthesizerAudioProcessor::getCurrentProgram()
{
    return 0;
}

void IdealSynthesizerAudioProcessor::setCurrentProgram (int index)
{
}

const String IdealSynthesizerAudioProcessor::getProgramName (int index)
{
    return {};
}

void IdealSynthesizerAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void IdealSynthesizerAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    ignoreUnused(samplesPerBlock);
    lastSampleRate = sampleRate;
    idealSynth.setCurrentPlaybackSampleRate(lastSampleRate);
}

void IdealSynthesizerAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool IdealSynthesizerAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

//Checks for notes being played, if note is being played applies values to it (ADSR, Filter, Wavetype)
void IdealSynthesizerAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    for (int i = 0; i < idealSynth.getNumVoices(); i++)
    {
        if (idealVoice = dynamic_cast<SynthVoice*>(idealSynth.getVoice(i)))
        {
            float* osc1WaveFloatPtr = (float*)tree.getRawParameterValue("waveform");
            float* osc1VolumeFloatPtr = (float*)tree.getRawParameterValue("osc1volume");
            float* osc1OctaveFloatPtr = (float*)tree.getRawParameterValue("osc1octave");
            float* osc1TransposeFloatPtr = (float*)tree.getRawParameterValue("osc1transpose");
            idealVoice->getOsc1WaveType(osc1WaveFloatPtr);
            idealVoice->getOsc1Volume(osc1VolumeFloatPtr);
            idealVoice->getOsc1Octave(osc1OctaveFloatPtr);
            idealVoice->getOsc1Transpose(osc1TransposeFloatPtr);

            float* osc2WaveFloatPtr = (float*)tree.getRawParameterValue("waveform2");
            float* osc2VolumeFloatPtr = (float*)tree.getRawParameterValue("osc2volume");
            float* osc2OctaveFloatPtr = (float*)tree.getRawParameterValue("osc2octave");
            float* osc2TransposeFloatPtr = (float*)tree.getRawParameterValue("osc2transpose");
            idealVoice->getOsc2WaveType(osc2WaveFloatPtr);
            idealVoice->getOsc2Volume(osc2VolumeFloatPtr);
            idealVoice->getOsc2Octave(osc2OctaveFloatPtr);
            idealVoice->getOsc2Transpose(osc2TransposeFloatPtr);

            float* attFloatPtr = (float*)tree.getRawParameterValue("attack");
            float* decFloatPtr = (float*)tree.getRawParameterValue("decay");
            float* susFloatPtr = (float*)tree.getRawParameterValue("sustain");
            float* relFloatPtr = (float*)tree.getRawParameterValue("release");
            idealVoice->getAdsrParams(attFloatPtr, decFloatPtr, susFloatPtr, relFloatPtr);

            float* fil1TypePtr = (float*)tree.getRawParameterValue("filter1type");
            float* fil1CutoffPtr = (float*)tree.getRawParameterValue("filter1cutoff");
            float* fil1ResoPtr = (float*)tree.getRawParameterValue("filter1reso");
            idealVoice->getFilter1Params(fil1TypePtr, fil1CutoffPtr, fil1ResoPtr);

        }
    }

    buffer.clear();

    idealSynth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
}

//==============================================================================
bool IdealSynthesizerAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* IdealSynthesizerAudioProcessor::createEditor()
{
    return new IdealSynthesizerAudioProcessorEditor (*this);
}

//==============================================================================
void IdealSynthesizerAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void IdealSynthesizerAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new IdealSynthesizerAudioProcessor();
}

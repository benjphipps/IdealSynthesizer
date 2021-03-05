/*
  ==============================================================================

    SynthVoice.h
    Created: 11 May 2020 7:23:00pm
    Author:  Benjamin

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "SynthSound.h"
#include "Maximilian.h"

class SynthVoice : public SynthesiserVoice
{
public:
    bool canPlaySound(SynthesiserSound* sound)
    {
        return dynamic_cast<SynthSound*>(sound) != nullptr;
    }

    //Gets Oscillator 1's waveform from processBlock
    void getOsc1WaveType(float* selection)
    {
        waveform = *selection;
    }

    //Gets Oscillator 1's octave slider's value from processBlock
    void getOsc1Octave(float* osc1octave)
    {
        osc1Octave = *osc1octave;
    }

    //Sets the octave being played by Oscillator 1 by dividing or multiplying frequency
    double setOsc1Octave()
    {
        if (osc1Octave == 1)
        {
            return freq / 4;
        }

        if (osc1Octave == 2)
        {
            return freq / 2;
        }

        if (osc1Octave == 3)
        {
            return freq;
        }

        if (osc1Octave == 4)
        {
            return freq * 2;
        }

        if (osc1Octave == 5)
        {
            return freq * 4;
        }

        else
        {
            return freq;
        }
    }

    //Gets Oscillator 1's transpose slider's value from processBlock
    void getOsc1Transpose(float* osc1transpose)
    {
        //osc1Transpose = *osc1transpose;
    }

    //Sets the transpose value played by Oscillator 1 by adding 1 / 12 * variable value selected from processBlock
    double setOsc1Transpose()
    {

        /*if (osc1Transpose >= 2)
        {
            return freq * 2;
        }

        if (osc1Transpose >= 3)
        {
            return freq * 3;
        }

        if (osc1Transpose >= 4)
        {
            return freq * 4;
        }

        if (osc1Transpose >= 5)
        {
            return freq * 5;
        }

        if (osc1Transpose >= 6)
        {
            return freq * 6;
        }

        if (osc1Transpose >= 7)
        {
            return freq * 7;
        }

        if (osc1Transpose >= 8)
        {
            return freq * 8;
        }

        if (osc1Transpose >= 9)
        {
            return freq * 9;
        }

        if (osc1Transpose >= 10)
        {
            return freq * 10;
        }

        if (osc1Transpose >= 11)
        {
            return freq * 11;
        }

        else
        {
            return freq;
        }*/
    }

    //Sets Oscillator 1's waveform and calls setOsc1Octave() to apply the frequency played
    double setOsc1WaveType()
    {
        if (waveform == 0)
        {
            return osc1.saw(setOsc1Octave()); // + setOsc1Transpose
        }
        if (waveform == 1)
        {
            return osc1.square(setOsc1Octave());
        }
        if (waveform == 2)
        {
            return osc1.triangle(setOsc1Octave());
        }
        if (waveform == 3)
        {
            return osc1.sinewave(setOsc1Octave());
        }
        else
        {
            return osc1.saw(setOsc1Octave());
        }
    }

    //Gets Oscillator 1's volume slider value from processBlock
    void getOsc1Volume(float* osc1volume)
    {

    }

    //Oscillator 2 getters and setters follow same rules of retrieving and setting values as Oscillator 1
    void getOsc2WaveType(float* selection)
    {
        waveform2 = *selection;
    }

    void getOsc2Octave(float* osc2octave)
    {
        osc1Octave = *osc2octave;
    }

    double setOsc2Octave()
    {
        if (osc1Octave == 1)
        {
            return freq / 4;
        }

        if (osc1Octave == 2)
        {
            return freq / 2;
        }

        if (osc1Octave == 3)
        {
            return freq;
        }

        if (osc1Octave == 4)
        {
            return freq * 2;
        }

        if (osc1Octave == 5)
        {
            return freq * 4;
        }

        else
        {
            return freq;
        }
    }

    void getOsc2Transpose(float* osc2transpose)
    {
        //osc1Transpose = *osc1transpose;
    }

    double setOsc2Transpose()
    {

        /*if (osc1Transpose >= 2)
        {
            return freq * 2;
        }

        if (osc1Transpose >= 3)
        {
            return freq * 3;
        }

        if (osc1Transpose >= 4)
        {
            return freq * 4;
        }

        if (osc1Transpose >= 5)
        {
            return freq * 5;
        }

        if (osc1Transpose >= 6)
        {
            return freq * 6;
        }

        if (osc1Transpose >= 7)
        {
            return freq * 7;
        }

        if (osc1Transpose >= 8)
        {
            return freq * 8;
        }

        if (osc1Transpose >= 9)
        {
            return freq * 9;
        }

        if (osc1Transpose >= 10)
        {
            return freq * 10;
        }

        if (osc1Transpose >= 11)
        {
            return freq * 11;
        }

        else
        {
            return freq;
        }*/
    }

    double setOsc2WaveType()
    {
        if (waveform2 == 0)
        {
            return osc2.saw(setOsc2Octave());
        }
        if (waveform2 == 1)
        {
            return osc2.square(setOsc2Octave());
        }
        if (waveform2 == 2)
        {
            return osc2.triangle(setOsc2Octave());
        }
        if (waveform2 == 3)
        {
            return osc2.sinewave(setOsc2Octave());
        }
        else
        {
            return osc2.saw(setOsc2Octave());
        }
    }

    void getOsc2Volume(float* osc2volume)
    {

    }

    //ADSR setup, retrieving ADSR parameter values from processBlock
    void getAdsrParams(float* attack, float* decay, float* sustain, float* release)
    {
        ampEnv.setAttack(double(*attack));
        ampEnv.setDecay(double(*decay));
        ampEnv.setSustain(double(*sustain));
        ampEnv.setRelease(double(*release));
    }

    //Sets the ADSR values to affect the oscillators by calling the setOscWaveType() functions
    double setAdsr()
    {
        return ampEnv.adsr(setOsc1WaveType(), ampEnv.trigger);
    }

    //Filter1 setup, retrieving filter parameter values from processBlock
    void getFilter1Params(float* filter1type, float* filter1cutoff, float* filter1reso)
    {
        filter1Type = *filter1type;
        filter1Cutoff = *filter1cutoff;
        filter1Resonance = *filter1reso;
    }

    //Sets the filter type received from the filter comboBox, alongside the cutoff, and resonance
    double setFilter1()
    {
        if (filter1Type == 0)
        {
            return filter1.lores(setAdsr(), filter1Cutoff, filter1Resonance);
        }

        if (filter1Type == 1)
        {
            return filter1.hires(setAdsr(), filter1Cutoff, filter1Resonance);
        }

        if (filter1Type == 2)
        {
            return filter1.bandpass(setAdsr(), filter1Cutoff, filter1Resonance);
        }

        else
        {
            return filter1.lores(setAdsr(), filter1Cutoff, filter1Resonance);
        }
    }

    //Gets Envelope 2's parameter values from processBlock
    void getEnv2Params(float* attack, float* decay, float* sustain, float* release)
    {
        env2.setAttack(double(*attack));
        env2.setDecay(double(*decay));
        env2.setSustain(double(*sustain));
        env2.setRelease(double(*release));
    }

    void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition)
    {
        ampEnv.trigger = 1;
        volume = velocity;
        freq = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    }

    void stopNote(float velocity, bool allowTailOff)
    {
        ampEnv.trigger = 0;
        allowTailOff = true;

        if (velocity == 0)
            clearCurrentNote();
    }

    void pitchWheelMoved(int newPitchWheelValue)
    {

    }

    void controllerMoved(int controllerNumber, int newControllerValue)
    {

    }

    void renderNextBlock(AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
    {

        for (int sample = 0; sample < numSamples; ++sample)
        {
            for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
            {
                outputBuffer.addSample(channel, startSample, setFilter1());
            }
            ++startSample;
        }
    }

    //====================================================

private:
    double volume;
    double osc1Transpose;
    double osc1Octave;
    double freq;
    int waveform;
    int waveform2;

    int filter1Type;
    float filter1Cutoff;
    float filter1Resonance;

    double masterGainVal;

    maxiOsc osc1;
    maxiOsc osc2;
    maxiOsc lfo1;
    maxiEnv ampEnv, env2;
    maxiFilter filter1;
};

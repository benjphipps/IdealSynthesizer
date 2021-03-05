/*
  ==============================================================================

    SynthSound.h
    Created: 11 May 2020 7:22:52pm
    Author:  Benjamin

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class SynthSound : public SynthesiserSound
{
public:
    bool appliesToNote(int /*midiNoteNumber*/)
    {
        return true;
    }

    bool appliesToChannel(int /*midiChannel*/)
    {
        return true;
    }
};

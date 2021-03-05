/*
  ==============================================================================

    Lfo1.h
    Created: 27 May 2020 5:02:18pm
    Author:  Benjamin

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class Lfo1    : public Component
{
public:
    Lfo1();
    ~Lfo1();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Lfo1)
};

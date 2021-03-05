/*
  ==============================================================================

    Delay.h
    Created: 27 May 2020 5:02:51pm
    Author:  Benjamin

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class Delay    : public Component
{
public:
    Delay();
    ~Delay();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Delay)
};

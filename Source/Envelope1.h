/*
  ==============================================================================

    Envelope1.h
    Created: 24 May 2020 9:59:49pm
    Author:  Benjamin

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class Envelope1    : public Component
{
public:
    Envelope1();
    ~Envelope1();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Envelope1)
};

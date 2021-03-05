/*
  ==============================================================================

    MasterVolume.h
    Created: 26 May 2020 4:54:52pm
    Author:  Benjamin

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class MasterVolume    : public Component
{
public:
    MasterVolume();
    ~MasterVolume();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MasterVolume)
};

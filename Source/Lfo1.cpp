/*
  ==============================================================================

    Lfo1.cpp
    Created: 27 May 2020 5:02:18pm
    Author:  Benjamin

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Lfo1.h"

//==============================================================================
Lfo1::Lfo1()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

Lfo1::~Lfo1()
{
}

void Lfo1::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::white);
    g.setFont (14.0f);
    g.drawText ("Lfo1", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
}

void Lfo1::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

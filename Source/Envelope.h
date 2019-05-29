/*
  ==============================================================================

    Envelope.h
    Created: 25 Apr 2019 11:51:40am
    Author:  Giney

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class Envelope    : public Component
{
public:
    Envelope(VstAudioProcessor&);
    ~Envelope();

    void paint (Graphics&) override;
    void resized() override;
	

private:

	
	// This reference is provided as a quick way for your editor to
// access the processor object that created it.
	VstAudioProcessor& processor;


	ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> attackVal;
	ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> releaseVal;
	ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> decayVal;
	ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> sustainVal;

	Slider attackSlider;
	Slider decaySlider;
	Slider releaseSlider;
	Slider sustainSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Envelope)
};

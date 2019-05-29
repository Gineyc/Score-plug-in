/*
  ==============================================================================

    Envelope2.h
    Created: 29 Apr 2019 2:00:57pm
    Author:  Giney

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class Envelope2    : public Component
{
public:
    Envelope2(VstAudioProcessor&);
    ~Envelope2();

    void paint (Graphics&) override;
    void resized() override;

private:
	// This reference is provided as a quick way for your editor to
// access the processor object that created it.
	VstAudioProcessor& processor;
	
	ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> attackVal2;
	ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> releaseVal2;
	ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> decayVal2;
	ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> sustainVal2;

	Slider attackSlider2;
	Slider decaySlider2;
	Slider releaseSlider2;
	Slider sustainSlider2;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Envelope2)
};

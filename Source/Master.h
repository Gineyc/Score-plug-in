/*
  ==============================================================================

    Master.h
    Created: 29 Apr 2019 3:45:00pm
    Author:  Giney

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class Master    : public Component
{
public:
    Master(VstAudioProcessor&);
    ~Master();

    void paint (Graphics&) override;
    void resized() override;

private:
	Slider mastergainSlider;
	Slider pbupSlider;
	Slider pbdownSlider;

	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> mastergainVal;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> pbupVal;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> pbdownVal;
	// This reference is provided as a quick way for your editor to
   // access the processor object that created it.
	VstAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Master)
};

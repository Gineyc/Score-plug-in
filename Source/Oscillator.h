/*
  ==============================================================================

    Oscillator.h
    Created: 24 Apr 2019 10:13:22pm
    Author:  Giney

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class Oscillator    : public Component
{
public:
    Oscillator(VstAudioProcessor&);
    ~Oscillator();

    void paint (Graphics&) override;
    void resized() override;


private:

	ComboBox oscMenu;
	Slider blendslider;
	ScopedPointer <AudioProcessorValueTreeState::ComboBoxAttachment> waveselection;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> blendVal;
	// This reference is provided as a quick way for your editor to
// access the processor object that created it.
	VstAudioProcessor& processor;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Oscillator)
		
};

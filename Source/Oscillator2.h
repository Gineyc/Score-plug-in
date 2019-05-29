/*
  ==============================================================================

    Oscillator2.h
    Created: 25 Apr 2019 11:51:24am
    Author:  Giney

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class Oscillator2    : public Component
	                  
{
public:
    Oscillator2(VstAudioProcessor&);
    ~Oscillator2();

    void paint (Graphics&) override;
    void resized() override;
	

private:
	ComboBox osc2Menu;
	Slider blendslider2;
	ScopedPointer <AudioProcessorValueTreeState::ComboBoxAttachment> waveselection2;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> blendVal2;
	// This reference is provided as a quick way for your editor to
// access the processor object that created it.
	VstAudioProcessor& processor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Oscillator2)
};

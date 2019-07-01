/*
  ==============================================================================

    Filter.h
    Created: 25 Apr 2019 4:33:41pm
    Author:  Giney

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
extern bool statu;
//==============================================================================
/*
*/
class Filter    : public Component
{
public:
    Filter(VstAudioProcessor&);
    ~Filter();

    void paint (Graphics&) override;
    void resized() override;

private:

    Slider filterCutoff;
	Slider filterRes;

	ScopedPointer <AudioProcessorValueTreeState::ComboBoxAttachment> filtertypeVal;
	ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> cutoffVal;
	ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> resVal;
	
	void updateToggleState(Button *button,String name);
	bool status = false;
	ComboBox filterMenu;
	TextButton toggleButton;
	// This reference is provided as a quick way for your editor to
// access the processor object that created it.
	VstAudioProcessor& processor;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Filter)

		

};

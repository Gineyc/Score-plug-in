/*
  ==============================================================================

    Master.cpp
    Created: 29 Apr 2019 3:45:00pm
    Author:  Giney

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Master.h"

//==============================================================================
Master::Master(VstAudioProcessor& p) :
	processor(p)
{
	setSize(130, 150);

	//slider initialization values
	mastergainSlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
	mastergainSlider.setRange(0.0f, 1.0f);
	mastergainSlider.setValue(1.0f);
	mastergainSlider.setTextBoxStyle(Slider::TextBoxRight, true, 0, 0);
	mastergainSlider.setColour(Slider::textBoxTextColourId, Colours::darkgrey);
	addAndMakeVisible(&mastergainSlider);

	pbupSlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
	pbupSlider.setRange(0, 12, 1);
	pbupSlider.setValue(12);
	pbupSlider.setTextBoxStyle(Slider::TextBoxRight, true, 35, 25);
	pbupSlider.setColour(Slider::textBoxTextColourId, Colours::darkgrey);
	addAndMakeVisible(&pbupSlider);

	pbdownSlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
	pbdownSlider.setRange(0, 12, 1);
	pbdownSlider.setValue(12);
	pbdownSlider.setTextBoxStyle(Slider::TextBoxRight, true, 35, 25);
	addAndMakeVisible(&pbdownSlider);
	pbdownSlider.setColour(Slider::textBoxTextColourId, Colours::darkgrey);

	mastergainVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "mastergain", mastergainSlider);
	pbupVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "pbup", pbupSlider);
	pbdownVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "pbdown", pbdownSlider);
}

Master::~Master()
{
}

void Master::paint (Graphics& g)
{
	juce::Rectangle<int> titleArea(0, 10, getWidth(), 20);

	g.fillAll(Colours::white);
	g.setColour(Colours::darkgrey);
	g.drawText("Master", titleArea, Justification::centredTop);
	g.drawText("main", 53, 50, 40, 20, Justification::centredLeft);
	g.drawText("PB Up/Down", 53, 110, 90, 20, Justification::centredLeft);





;
}


void Master::resized()
{
	/*juce::Rectangle<int> area = getLocalBounds().reduced(50);*/
	mastergainSlider.setBounds(10, 20, 150, 50);
	pbdownSlider.setBounds(10,70,150,50);
	pbupSlider.setBounds(10,130,150,50);

}

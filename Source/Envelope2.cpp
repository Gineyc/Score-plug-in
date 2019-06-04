/*
  ==============================================================================

    Envelope2.cpp
    Created: 29 Apr 2019 2:00:57pm
    Author:  Giney

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Envelope2.h"

//==============================================================================
Envelope2::Envelope2(VstAudioProcessor& p) :processor(p)
{
	setSize(200, 300);
	attackSlider2.setSliderStyle(Slider::SliderStyle::Rotary);
	attackSlider2.setRange(0.1f, 5000.0f);
	attackSlider2.setValue(0.1f);
	attackSlider2.setTextBoxStyle(Slider::TextBoxBelow, false, 65.0, 15.0);
	addAndMakeVisible(&attackSlider2);
	attackSlider2.setColour(Slider::textBoxOutlineColourId, Colours::white);
	attackSlider2.setColour(Slider::textBoxTextColourId, Colours::darkgrey);
	attackSlider2.setColour(Slider::trackColourId, Colours::darkgrey);
	attackSlider2.setColour(Slider::rotarySliderFillColourId, Colours::powderblue);
	attackSlider2.setColour(Slider::rotarySliderOutlineColourId, Colours::grey);


	releaseSlider2.setSliderStyle(Slider::SliderStyle::Rotary);
	releaseSlider2.setRange(0.1f, 5000.0f);
	releaseSlider2.setValue(0.1f);
	releaseSlider2.setTextBoxStyle(Slider::TextBoxBelow, false, 65.0, 15.0);
	addAndMakeVisible(&releaseSlider2);
	releaseSlider2.setColour(Slider::textBoxOutlineColourId, Colours::white);
	releaseSlider2.setColour(Slider::textBoxTextColourId, Colours::darkgrey);
	releaseSlider2.setColour(Slider::trackColourId, Colours::darkgrey);
	releaseSlider2.setColour(Slider::rotarySliderFillColourId, Colours::powderblue);
	releaseSlider2.setColour(Slider::rotarySliderOutlineColourId, Colours::grey);

	decaySlider2.setSliderStyle(Slider::SliderStyle::Rotary);
	decaySlider2.setRange(0.1f, 2000.0f);
	decaySlider2.setValue(0.1f);
	decaySlider2.setTextBoxStyle(Slider::TextBoxBelow, false, 65.0, 15.0);
	addAndMakeVisible(&decaySlider2);
	decaySlider2.setColour(Slider::textBoxOutlineColourId, Colours::white);
	decaySlider2.setColour(Slider::textBoxTextColourId, Colours::darkgrey);
	decaySlider2.setColour(Slider::trackColourId, Colours::darkgrey);
	decaySlider2.setColour(Slider::rotarySliderFillColourId, Colours::powderblue);
	decaySlider2.setColour(Slider::rotarySliderOutlineColourId, Colours::grey);

	sustainSlider2.setSliderStyle(Slider::SliderStyle::Rotary);
	sustainSlider2.setRange(0.1f, 1.0f);
	sustainSlider2.setValue(0.1f);
	sustainSlider2.setTextBoxStyle(Slider::TextBoxBelow, false, 65.0, 15.0);
	addAndMakeVisible(&sustainSlider2);
	sustainSlider2.setColour(Slider::textBoxOutlineColourId, Colours::white);
	sustainSlider2.setColour(Slider::textBoxTextColourId, Colours::darkgrey);
	sustainSlider2.setColour(Slider::trackColourId, Colours::darkgrey);
	sustainSlider2.setColour(Slider::rotarySliderFillColourId, Colours::powderblue);
	sustainSlider2.setColour(Slider::rotarySliderOutlineColourId, Colours::grey);

	attackVal2 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "attack2", attackSlider2);
	releaseVal2 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "release2", releaseSlider2);
	sustainVal2 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "sustain2", sustainSlider2);
	decayVal2 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "decay2", decaySlider2);


}

Envelope2::~Envelope2()
{
}

void Envelope2::paint (Graphics& g)
{
   

	g.fillAll(Colours::white);   // clear the background
	g.setColour(Colours::darkgrey);
	g.drawText("Attack", 5, 0, 65, 20, Justification::centredTop);
	g.drawText("Decay", 5, 90, 65, 20, Justification::centredTop);
	g.drawText("Sustain", 75, 0, 65, 20, Justification::centredTop);
	g.drawText("Release", 75, 90, 65, 20, Justification::centredTop);
}

void Envelope2::resized()
{
	juce::Rectangle<int> area = getLocalBounds().reduced(20);
	attackSlider2.setBounds(5, 12, 65, 65);
	decaySlider2.setBounds(5, 100, 65, 65);
	sustainSlider2.setBounds(75, 12, 65, 65);
	releaseSlider2.setBounds(75, 100, 65, 65);

}

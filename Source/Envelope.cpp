/*
  ==============================================================================

    Envelope.cpp
    Created: 25 Apr 2019 11:51:40am
    Author:  Giney

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Envelope.h"

//==============================================================================
Envelope::Envelope(VstAudioProcessor& p):processor(p)
{
	setSize(200, 300);
	attackSlider.setSliderStyle(Slider::SliderStyle::Rotary);
	attackSlider.setRange(0.1f, 5000.0f);
	attackSlider.setValue(0.1f);
	attackSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 65.0, 15.0);
	addAndMakeVisible(&attackSlider);
	attackSlider.setColour(Slider::textBoxOutlineColourId, Colours::white);
	attackSlider.setColour(Slider::textBoxTextColourId, Colours::darkgrey);
	attackSlider.setColour(Slider::trackColourId, Colours::darkgrey);
	attackSlider.setColour(Slider::rotarySliderFillColourId, Colours::powderblue);
	attackSlider.setColour(Slider::rotarySliderOutlineColourId, Colours::grey);
	
	
	releaseSlider.setSliderStyle(Slider::SliderStyle::Rotary);
	releaseSlider.setRange(0.1f, 5000.0f);
	releaseSlider.setValue(0.1f);
	releaseSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 65.0, 15.0);
	addAndMakeVisible(&releaseSlider);
	releaseSlider.setColour(Slider::textBoxOutlineColourId, Colours::white);
	releaseSlider.setColour(Slider::textBoxTextColourId, Colours::darkgrey);
	releaseSlider.setColour(Slider::trackColourId, Colours::darkgrey);
	releaseSlider.setColour(Slider::rotarySliderFillColourId, Colours::powderblue);
	releaseSlider.setColour(Slider::rotarySliderOutlineColourId, Colours::grey);


	decaySlider.setSliderStyle(Slider::SliderStyle::Rotary);
	decaySlider.setRange(0.1f, 2000.0f);
	decaySlider.setValue(0.1f);
	decaySlider.setTextBoxStyle(Slider::TextBoxBelow, false, 65.0, 15.0);
	addAndMakeVisible(&decaySlider);
	decaySlider.setColour(Slider::textBoxOutlineColourId, Colours::white);
	decaySlider.setColour(Slider::textBoxTextColourId, Colours::darkgrey);
	decaySlider.setColour(Slider::trackColourId, Colours::darkgrey);
	decaySlider.setColour(Slider::rotarySliderFillColourId, Colours::powderblue);
	decaySlider.setColour(Slider::rotarySliderOutlineColourId, Colours::grey);

	sustainSlider.setSliderStyle(Slider::SliderStyle::Rotary);
	sustainSlider.setRange(0.1f, 1.0f);
	sustainSlider.setValue(0.1f);
	sustainSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 65.0, 15.0);
	addAndMakeVisible(&sustainSlider);
	sustainSlider.setColour(Slider::textBoxOutlineColourId, Colours::white);
	sustainSlider.setColour(Slider::textBoxTextColourId, Colours::darkgrey);
	sustainSlider.setColour(Slider::trackColourId, Colours::darkgrey);
	sustainSlider.setColour(Slider::rotarySliderFillColourId, Colours::powderblue);
	sustainSlider.setColour(Slider::rotarySliderOutlineColourId, Colours::grey);

	attackVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "attack1", attackSlider);
	releaseVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "release1", releaseSlider);
	sustainVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "sustain1", sustainSlider);
	decayVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "decay1", decaySlider);

}


Envelope::~Envelope()
{
}

void Envelope::paint (Graphics& g)
{


    g.fillAll (Colours::white);   // clear the background
	g.setColour(Colours::darkgrey);
	g.setFont(15.0f);
	g.drawText("Attack", 5, 0, 65, 20, Justification::centredTop);
	g.drawText("Decay", 5, 90, 65, 20, Justification::centredTop);
	g.drawText("Sustain", 75, 0, 65, 20, Justification::centredTop);
	g.drawText("Release", 75, 90, 65, 20, Justification::centredTop);
    
}

void Envelope::resized()
{
	juce::Rectangle<int> area = getLocalBounds().reduced(20);
	attackSlider.setBounds(5, 12, 65, 65);
	decaySlider.setBounds(5, 100, 65, 65);
	sustainSlider.setBounds(75, 12, 65, 65);
	releaseSlider.setBounds(75, 100, 65, 65);

}



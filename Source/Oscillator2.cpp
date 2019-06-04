/*
  ==============================================================================

    Oscillator2.cpp
    Created: 25 Apr 2019 11:51:24am
    Author:  Giney

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator2.h"

//==============================================================================
Oscillator2::Oscillator2(VstAudioProcessor& p):
	processor(p)
{
	setSize(200, 110);

	osc2Menu.addItem("Sine", 1);
	osc2Menu.addItem("Saw", 2);
	osc2Menu.addItem("Square", 3);
	osc2Menu.addItem("Triangle", 4);
	osc2Menu.addItem("CosWave", 5);
	osc2Menu.addItem("Noise", 6);
	addAndMakeVisible(&osc2Menu);
	osc2Menu.setJustificationType(Justification::centred);
	//three types of Oscillator in this menu and arranged centred.
	osc2Menu.setColour(ComboBox::backgroundColourId, Colours::lightgrey);
	osc2Menu.setColour(ComboBox::arrowColourId, Colours::black);
	osc2Menu.setColour(ComboBox::buttonColourId, Colours::green);
	osc2Menu.setColour(ComboBox::textColourId, Colours::black);
	osc2Menu.setColour(ComboBox::outlineColourId, Colours::darkgrey);
	osc2Menu.setColour(ComboBox::focusedOutlineColourId, Colours::darkgrey);

	waveselection2 = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "wavetype2", osc2Menu);

	blendslider2.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
	blendslider2.setRange(0.0f, 1.0f);
	blendslider2.setValue(1.0f);
	blendslider2.setTextBoxStyle(Slider::NoTextBox, true, 60, 10);
	addAndMakeVisible(&blendslider2);

	blendVal2 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "blend2", blendslider2);
}

Oscillator2::~Oscillator2()
{
}

void Oscillator2::paint(Graphics& g)
{
	/* This demo code just fills the component's background and
	   draws some placeholder text to get you started.

	   You should replace everything in this method with your own
	   drawing code..
	*/


	g.fillAll(Colours::white);   // clear the background
	g.setColour(Colours::darkgrey);
	g.setFont(15.0f);
	g.drawText("Oscillator II", getLocalBounds(),
		Justification::centredTop, true);   // draw some placeholder text

	blendVal2 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "blend2", blendslider2);
}

void Oscillator2::resized()
{
	juce::Rectangle<int> area = getLocalBounds().reduced(30);
	osc2Menu.setBounds(5, 25, 135, 30);
	blendslider2.setBounds(5, 60, 135, 20);
}

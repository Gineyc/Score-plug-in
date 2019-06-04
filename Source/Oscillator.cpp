/*
  ==============================================================================

    Oscillator.cpp
    Created: 24 Apr 2019 10:13:22pm
    Author:  Giney

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"

//==============================================================================
Oscillator::Oscillator(VstAudioProcessor& p):
	processor(p)
{
	setSize(200, 110);

	oscMenu.addItem("Sine", 1);
	oscMenu.addItem("Saw", 2);
	oscMenu.addItem("Square", 3);
	oscMenu.addItem("Triangle", 4);
	oscMenu.addItem("CosWave", 5);
	oscMenu.addItem("Noise", 6);
	addAndMakeVisible(&oscMenu);
	oscMenu.setJustificationType(Justification::centred);
	//three types of Oscillator in this menu and arranged centred.
	oscMenu.setColour(ComboBox::backgroundColourId, Colours::lightgrey);
	oscMenu.setColour(ComboBox::arrowColourId, Colours::black);
	oscMenu.setColour(ComboBox::buttonColourId, Colours::green);
	oscMenu.setColour(ComboBox::textColourId, Colours::black);
	oscMenu.setColour(ComboBox::outlineColourId, Colours::darkgrey);
	oscMenu.setColour(ComboBox::focusedOutlineColourId, Colours::darkgrey);
	

	waveselection = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "wavetype1", oscMenu);

	blendslider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
	blendslider.setRange(0.0f, 1.0f);
	blendslider.setValue(1.0f);
	blendslider.setTextBoxStyle(Slider::NoTextBox, true, 60, 10);
	addAndMakeVisible(&blendslider);

	blendVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "blend1", blendslider);

}

Oscillator::~Oscillator()
{
}

void Oscillator::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */
	
    g.fillAll (Colours::white);   // clear the background
	g.setColour(Colours::darkgrey);
    g.setFont (15.0f);
    g.drawText ("Oscillator I", getLocalBounds(),
                Justification::centredTop, true);   // draw some placeholder text
}

void Oscillator::resized()
{
	juce::Rectangle<int> area = getLocalBounds().reduced(30);
	oscMenu.setBounds(5, 25, 135, 30);

	blendslider.setBounds(5, 60, 135, 20);
}


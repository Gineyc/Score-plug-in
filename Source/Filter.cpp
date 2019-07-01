/*
  ==============================================================================

    Filter.cpp
    Created: 25 Apr 2019 4:33:41pm
    Author:  Giney

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Filter.h"
bool statu = false;

//==============================================================================
Filter::Filter(VstAudioProcessor& p):
	processor(p),toggleButton("on/off")
{
	setSize(200, 250);
	filterMenu.addItem("Low Pass", 1);
	filterMenu.addItem("Hi Pass", 2);
	filterMenu.addItem("Band Pass", 3);
	filterMenu.setJustificationType(Justification::centred);
	addAndMakeVisible(filterMenu);

	filterMenu.setColour(ComboBox::backgroundColourId, Colours::lightgrey);
	filterMenu.setColour(ComboBox::arrowColourId, Colours::black);
	filterMenu.setColour(ComboBox::buttonColourId, Colours::green);
	filterMenu.setColour(ComboBox::textColourId, Colours::black);
	filterMenu.setColour(ComboBox::outlineColourId, Colours::darkgrey);
	filterMenu.setColour(ComboBox::focusedOutlineColourId, Colours::darkgrey);

	filtertypeVal = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "filtertype", filterMenu);
    
	filterCutoff.setSliderStyle(Slider::SliderStyle::Rotary);
	filterCutoff.setRange(20.0f, 10000.0f);
	filterCutoff.setValue(600.0);
	filterCutoff.setTextBoxStyle(Slider::TextBoxBelow, false, 65.0, 15.0);
	addAndMakeVisible(&filterCutoff);
	cutoffVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filtercutoff", filterCutoff);
	filterCutoff.setSkewFactorFromMidPoint(1000.0);
	filterCutoff.setColour(Slider::textBoxOutlineColourId, Colours::white);
	filterCutoff.setColour(Slider::textBoxTextColourId, Colours::darkgrey);
	filterCutoff.setColour(Slider::trackColourId, Colours::darkgrey);
	filterCutoff.setColour(Slider::rotarySliderFillColourId, Colours::powderblue);
	filterCutoff.setColour(Slider::rotarySliderOutlineColourId, Colours::grey);

	filterRes.setSliderStyle(Slider::SliderStyle::Rotary);
	filterRes.setRange(1, 5);
	filterRes.setValue(1);
	filterRes.setTextBoxStyle(Slider::TextBoxBelow, false, 65.0, 15.0);
	addAndMakeVisible(&filterRes);
	resVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filterres", filterRes);
	filterRes.setColour(Slider::textBoxOutlineColourId, Colours::white);
	filterRes.setColour(Slider::textBoxTextColourId, Colours::darkgrey);
	filterRes.setColour(Slider::trackColourId, Colours::darkgrey);
	filterRes.setColour(Slider::rotarySliderFillColourId, Colours::powderblue);
	filterRes.setColour(Slider::rotarySliderOutlineColourId, Colours::grey);

	addAndMakeVisible(&toggleButton);
	toggleButton.onClick = [this] {updateToggleState(&toggleButton,"BUTTON"); };
	toggleButton.setToggleState(statu,dontSendNotification);
	

	

}

Filter::~Filter()
{
}

void Filter::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (Colours::white);   // clear the background
	g.setColour(Colours::darkgrey);
    g.setFont (15.0f);

    g.drawText ("Filter",0,0,200,100,Justification::centredTop);   // draw some placeholder text

	g.drawText("Cutoff", 5, 77, 65, 20, Justification::centredTop);
	g.drawText("Resonance", 75, 77, 65, 20, Justification::centredTop);
	g.setFont(12.0f);
}

void Filter::resized()
{
	

	filterMenu.setBounds(5,40,135,30);
	filterCutoff.setBounds(5, 90, 65, 65);
	filterRes.setBounds(75, 90, 65, 65);
	toggleButton.setBounds(0, 0, 50, 25);
	
}

void Filter::updateToggleState(Button *button,String name)
{
	if (statu == true) {
		DBG("on");
	}
	else { DBG("off"); }

	String stateString = statu ? "on" : "off";
	
	
	button->setButtonText(stateString);
	if (statu == false) {
		statu = true;
	}
	else {
		statu = false;
	}

	}
	



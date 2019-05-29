/*
  ==============================================================================

    Filter.cpp
    Created: 25 Apr 2019 4:33:41pm
    Author:  Giney

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Filter.h"


//==============================================================================
Filter::Filter(VstAudioProcessor& p):
	processor(p)
{
	setSize(150, 200);
	filterMenu.addItem("Low Pass", 1);
	filterMenu.addItem("Hi Pass", 2);
	filterMenu.addItem("Band Pass", 3);
	filterMenu.addItem("No Filter", 4);
	filterMenu.setJustificationType(Justification::centred);
	addAndMakeVisible(filterMenu);
	filtertypeVal = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "filtertype", filterMenu);
    
	filterCutoff.setSliderStyle(Slider::SliderStyle::Rotary);
	filterCutoff.setRange(20.0f, 10000.0f);
	filterCutoff.setValue(600.0);
	filterCutoff.setTextBoxStyle(Slider::TextBoxBelow, false, 65.0, 15.0);
	addAndMakeVisible(&filterCutoff);
	cutoffVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filtercutoff", filterCutoff);
	filterCutoff.setSkewFactorFromMidPoint(1000.0);

	filterRes.setSliderStyle(Slider::SliderStyle::Rotary);
	filterRes.setRange(1, 5);
	filterRes.setValue(1);
	filterRes.setTextBoxStyle(Slider::TextBoxBelow, false, 65.0, 15.0);
	addAndMakeVisible(&filterRes);
	resVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filterres", filterRes);
	


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


    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

 
    g.setFont (14.0f);
    g.drawText ("Filter", getLocalBounds(),
                Justification::centredTop, true);   // draw some placeholder text
}

void Filter::resized()
{
	

	filterMenu.setBounds(10,0,135,30);
	filterCutoff.setBounds(5, 60, 65, 65);
	filterRes.setBounds(75, 60, 65, 65);

}

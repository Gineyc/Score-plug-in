/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
VstAudioProcessorEditor::VstAudioProcessorEditor (VstAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p),oscGUI(p),oscGUI2(p),fileGUI(),geneGUI(),videoGUI(),envGUI(p),envGUI2(p),filtGUI(p),masterGUI(p)
	
{
   
    setSize (800, 600);
	
	
	addAndMakeVisible(&oscGUI);
	addAndMakeVisible(&oscGUI2);
	addAndMakeVisible(&fileGUI);
	addAndMakeVisible(&geneGUI);
	addAndMakeVisible(&videoGUI);
	addAndMakeVisible(&envGUI);
	addAndMakeVisible(&filtGUI);
	addAndMakeVisible(&envGUI2);
	addAndMakeVisible(&masterGUI);


	backgroundImage = ImageCache::getFromMemory(BinaryData::background_png, BinaryData::background_pngSize);

}

VstAudioProcessorEditor::~VstAudioProcessorEditor()
{
}

//==============================================================================
void VstAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (Colours::lightgrey);
	g.drawImageAt(backgroundImage, 0, 0);

   
}

void VstAudioProcessorEditor::resized()
{
	
	videoGUI.setBounds(0,70,320,280);
	geneGUI.setBounds(0, 355, 320, 30);
	fileGUI.setBounds(0, 385, 320, 250);

	oscGUI.setBounds(350, 70, 150, 100);
	oscGUI2.setBounds(600, 70, 150, 100);
	envGUI.setBounds(350,180, 150, 200);
	envGUI2.setBounds(600, 180, 150, 200);
	filtGUI.setBounds(350, 400, 200, 200);
	masterGUI.setBounds(600, 380, 200, 200);
	
	
	
	
}

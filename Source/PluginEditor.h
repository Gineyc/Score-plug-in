/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Oscillator.h"
#include "Oscillator2.h"
#include "Filedrag.h"
#include "Video.h"
#include "Generate.h"
#include "Envelope.h"
#include "Envelope2.h"
#include "Filter.h"
#include "Master.h"



//==============================================================================
/**
*/
class VstAudioProcessorEditor : public AudioProcessorEditor
	                            
{
public:
	VstAudioProcessorEditor(VstAudioProcessor&);
	~VstAudioProcessorEditor();
	
	//==============================================================================
	void paint(Graphics&) override;
	void resized() override;
	

private:
	// This reference is provided as a quick way for your editor to
	// access the processor object that created it.
	VstAudioProcessor& processor;
	

	

	Oscillator oscGUI;
	Oscillator2 oscGUI2;
	Filedrag fileGUI;
	Video videoGUI;
	Generate geneGUI;
	Envelope envGUI;
	Envelope2 envGUI2;
	Filter filtGUI;
	Master masterGUI;
	Image backgroundImage;

};



/*
  ==============================================================================

    Functions.cpp
    Created: 25 Apr 2019 11:56:51am
    Author:  Giney

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Filedrag.h"
#include<iostream>
#include<fstream>
using namespace std;

//==============================================================================
Filedrag::Filedrag()
{
	setSize(320, 210);
	addAndMakeVisible(fileTree);
	addAndMakeVisible(&fileChoose);
	setOpaque(true);
	File directory("D:\\Master\\REPO\\pbloem\\score");
	midiList.setDirectory(directory, true, true);
	directoryThread.startThread(10);
	fileTree.setColour(FileTreeComponent::backgroundColourId, Colours::grey);
	fileTree.addListener(this);
	if (generatefinished == 1) {
		midiList.refresh();
	}

}

Filedrag::~Filedrag()
{
	fileTree.removeListener(this);
}

void Filedrag::paint (Graphics& g)
{
  

    g.fillAll (Colours::white);   
    g.setColour (Colours::white);
    g.setFont (14.0f);
  
}

void Filedrag::resized()
{
	
	
	fileTree.setBounds(10, 0, 300, 210);

}

void Filedrag::getFilename()
{
	fileChoose.getName();
	String name = fileChoose.getName();
	DBG("ChoosenName" + name);
}


void Filedrag::fileClicked(const File& file, const MouseEvent& event) {
	
	String name = file.getFullPathName();

	StringArray sArray(name);
	startDragging("THE FILE", this);
	external = container.performExternalDragDropOfFiles(sArray,false,this,nullptr);
	
}



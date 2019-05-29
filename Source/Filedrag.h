/*
  ==============================================================================

    Functions.h
    Created: 25 Apr 2019 11:56:51am
    Author:  Giney

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Generate.h"

//==============================================================================
/*
*/
class Filedrag : public Component,
	                 public DragAndDropContainer,
	                 public FilenameComponentListener,
	                 public FileBrowserListener
{
public:
	Filedrag();
    ~Filedrag();

    void paint (Graphics&) override;
    void resized() override;
	void getFilename();
	


private:
	

	
	
	//Add filetree
	
	WildcardFileFilter midiWildcardFilter{ "*", "*", "MIDI File Filter" };
	TimeSliceThread directoryThread{ "MIDI File Scanner Thread" };
	DirectoryContentsList midiList{ &midiWildcardFilter, directoryThread };
	FileTreeComponent fileTree{midiList};
	DragAndDropContainer container;
	
	FilenameComponent fileChoose{ "MIDI", {}, true, false, false, "*", {}, "(choose a medi file to load)" };
	void filenameComponentChanged(FilenameComponent*) override
	{
		auto url = URL(fileChoose.getCurrentFile());
	}
	void selectionChanged() override
	{
		// we're just going to update the drag description of out tree so that rows can be dragged onto the file players
		fileTree.setDragAndDropDescription(fileTree.getSelectedFile().getFullPathName());
	}
	File directory;
	void fileClicked(const File&, const MouseEvent&) override;
	void fileDoubleClicked(const File&)              override {}
	void browserRootChanged(const File&)             override {}
	bool external;
	
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Filedrag)
};

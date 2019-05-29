/*
  ==============================================================================

    Functions.h
    Created: 25 Apr 2019 11:56:51am
    Author:  Giney

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class Functions    : public Component,
	                 public DragAndDropTarget,
	                 public DragAndDropContainer,
	                 public FilenameComponentListener,
	                 public FileBrowserListener
{
public:
    Functions();
    ~Functions();

    void paint (Graphics&) override;
    void resized() override;
	void setFile(const File& file);
	void itemDragEnter(const SourceDetails&) override;
	void itemDragExit(const SourceDetails&) override;
	void itemDropped(const SourceDetails& dragSourceDetails) override;
	bool isInterestedInDragSource(const SourceDetails&) override { return true; }


private:
	TextButton openButton,
		generateButton;
	//member function openButtonClicked(choose video file and return file location).
	void openButtonClicked();
	//member function playButtonClicked(load and play video)
	void generateButtonClicked();
	VideoComponent videoComp;
	//loadingvideo,if success, play, if filed, output error code.
	void videoLoadingFinished(const URL& , Result);
	
	//Add filetree
	std::unique_ptr<FileChooser> fileChooser;
	WildcardFileFilter midiWildcardFilter{ "*", "*", "MIDI File Filter" };
	TimeSliceThread directoryThread{ "MIDI File Scanner Thread" };
	DirectoryContentsList midiList{ &midiWildcardFilter, directoryThread };
	FileTreeComponent fileTree{midiList};
	

	bool isDragOver = false;
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

	void fileClicked(const File&, const MouseEvent&) override {}
	void fileDoubleClicked(const File&)              override {}
	void browserRootChanged(const File&)             override {}


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Functions)
};

/*
  ==============================================================================

    Functions.cpp
    Created: 25 Apr 2019 11:56:51am
    Author:  Giney

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Functions.h"

//==============================================================================
Functions::Functions():
           openButton("open"),
           generateButton("generate"),
           videoComp("video")
{
	setSize(320, 500);
	openButton.onClick = [this] { openButtonClicked(); };
	generateButton.onClick = [this] { generateButtonClicked(); };
	addAndMakeVisible(&openButton);
	//openButton

	addAndMakeVisible(&generateButton);
	//generateButton

	addAndMakeVisible(&videoComp);
	addAndMakeVisible(&fileTree);
	addAndMakeVisible(&fileChoose);


	
	midiList.setDirectory(File::getSpecialLocation(File::userMusicDirectory), true, true);
	directoryThread.startThread(1);
	fileTree.setColour(FileTreeComponent::backgroundColourId, Colours::lightslategrey);
	

}



Functions::~Functions()
{
	/*fileTree.removeListener(this);*/
}

void Functions::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (Colours::black);   // clear the background

    g.setColour (Colours::black);
    //g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::white);
    g.setFont (14.0f);
  
}

void Functions::resized()
{
	openButton.setBounds(10, 10, 300, 20);
	videoComp.setBounds(10, 40, 300, 200);
	generateButton.setBounds(10, 250, 300, 20);
	fileTree.setBounds(5, 280, 300, 200);

}

void Functions::openButtonClicked()
{

	//choose a file

	FileChooser chooser("choose a file", File::getSpecialLocation(File::userMoviesDirectory), "*.avi;*.mov", false, true);
	//if the user choose a file
	if (chooser.browseForFileToOpen()) {

		//what did the user choose
		auto myFile = chooser.getURLResult(); 
		auto result = videoComp.load(myFile); 
		videoLoadingFinished(myFile, result);

	}
}

void Functions::generateButtonClicked()
{

}

void Functions::videoLoadingFinished(const URL& url , Result result)
{
	ignoreUnused(url);

	if (result.wasOk())
	{
		// loaded the file ok, so let's start it playing..

		videoComp.play();
		videoComp.setAudioVolume(0.5);
		resized(); // update to reflect the video's aspect ratio
	}
	else
	{
		AlertWindow::showMessageBoxAsync(AlertWindow::WarningIcon,
			"Couldn't load the file!",
			result.getErrorMessage());
	}
}


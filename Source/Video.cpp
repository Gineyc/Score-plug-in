/*
  ==============================================================================

    Video.cpp
    Created: 2 May 2019 10:22:10am
    Author:  Giney

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Video.h"
String videoPath;
String videoName;

//==============================================================================

Video::Video() :openButton("open"), playButton("play"), pauseButton("pause"),stopButton("stop"),backButton("-5s"),forwardButton("+5s"), videoComp("video")
{

	setSize(320, 240);

	openButton.onClick     =  [this] { openButtonClicked();};
	playButton.onClick     =  [this] { playButtonClicked();};
	pauseButton.onClick    =  [this] { pauseButtonClicked();};
	stopButton.onClick     =  [this] { stopButtonClicked();};
	backButton.onClick     =  [this] { backButtonClicked();};
	forwardButton.onClick  =  [this] { forwardButtonClicked();};
	

	addAndMakeVisible(&openButton);
	addAndMakeVisible(&playButton);
	addAndMakeVisible(&pauseButton);
	addAndMakeVisible(&stopButton);
	addAndMakeVisible(&backButton);
	addAndMakeVisible(&forwardButton);
	addAndMakeVisible(&videoComp);






};


Video::~Video()
{

}

void Video::paint (Graphics& g)
{

	g.fillAll(Colours::white);  // clear the background
    g.setFont(14.0f);


      // draw some placeholder text
}

void Video::resized()
{

	openButton.setBounds(10, 10, 50, 20);
	playButton.setBounds(70, 10, 50, 20);
	pauseButton.setBounds(130, 10, 50, 20);
	stopButton.setBounds(190, 10, 50, 18);
	backButton.setBounds(250, 10, 30, 18);
	forwardButton.setBounds(280, 10, 30, 20);
	videoComp.setBounds(10, 40, 300, 240);
	

}

void Video::videoLoadingFinished(const URL& url, bool result)
{
	ignoreUnused(url);

	if (result)
	{
		
	}
	
	else
	{
		AlertWindow::showMessageBoxAsync(AlertWindow::WarningIcon,
			"Couldn't load the file!","0" );
			
	}
}

void Video::openButtonClicked()
{

	//choose a file

	FileChooser chooser("choose a file", File::getSpecialLocation(File::userMoviesDirectory), "*", false, true);

	//if the user choose a file
	if (chooser.browseForFileToOpen()) {

		//what did the user choose
		File myFile = chooser.getResult();
		auto myURL = chooser.getURLResult();
	/*	auto result = videoComp.load(myFile);*/
	
		
		videoPath = myFile.getFullPathName();
		videoName = myFile.getFileName();
		Process::makeForegroundProcess();
		
		auto url = URL(chooser.getURLResult());
		auto result = videoComp.load(url);
		if (result.wasOk()) {
			AlertWindow::showMessageBoxAsync(AlertWindow::NoIcon,
				"Loading success!",result.getErrorMessage() );
		}
		else {
			AlertWindow::showMessageBoxAsync(AlertWindow::WarningIcon,
				"Couldn't load the file!",
				result.getErrorMessage());
		}
		
		
	
	
	}

}
void Video::playButtonClicked()
{

	
	videoComp.play();

}

void Video::pauseButtonClicked() {
	videoComp.stop();
}


void Video::stopButtonClicked() {
	videoComp.stop();
	timeStamp = 0.00;
	videoComp.setPlayPosition(timeStamp);
	
}

void Video::backButtonClicked() {
	timeStamp = videoComp.getPlayPosition();
	videoComp.setPlayPosition(timeStamp - 5);
}

void Video::forwardButtonClicked() {
	timeStamp = videoComp.getPlayPosition();
	videoComp.setPlayPosition(timeStamp + 5);
}
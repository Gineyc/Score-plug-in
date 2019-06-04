/*
  ==============================================================================

    Video.h
    Created: 2 May 2019 10:22:10am
    Author:  Giney

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
extern String videoPath;
extern String videoName;
extern String videoNamewithoutextension;

//==============================================================================


class Video : public Component
{
public:
	
	Video();
	~Video();
	void paint(Graphics& g) override;
	void resized() override;
	
	
	
	
private:
	
	
	VideoComponent videoComp;
	TextButton openButton,playButton,pauseButton,stopButton,backButton,forwardButton;
	void openButtonClicked();
	void playButtonClicked();
	void pauseButtonClicked();
	void stopButtonClicked();
	void backButtonClicked();
	void forwardButtonClicked();
	double timeStamp;
	/*FFmpegVideoComponent* videoComp;*/
	//ScopedPointer<AudioTransportSource> transportSource;
	void videoLoadingFinished(const URL& url, bool result);
	/*FFmpegVideoReader*                  vReader;
	AudioTransportSource*               transport;*/

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Video)

		
};

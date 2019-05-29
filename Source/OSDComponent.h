/*
  ==============================================================================

    OSCComponent.h
    Created: 16 May 2019 12:19:51pm
    Author:  Giney

  ==============================================================================
*/

#pragma once
#pragma once
#ifndef OSDCOMPONENT_H_INCLUDED
#define OSDCOMPONENT_H_INCLUDED
#include "../JuceLibraryCode/JuceHeader.h"

class OSDComponent :public Component,
	                public Slider::Listener,
	                public Button::Listener
{
public:
	OSDComponent(FFmpegVideoReader* readerToControl)
		:videoReader(readerToControl)
	{
		setInterceptsMouseClicks(false, true);
		setWantsKeyboardFocus(false);

		openButton = new TextButton("Open", "Open");
		openButton->addListener(this);
		openButton->setWantsKeyboardFocus(false);
		flexBox.items.add(FlexItem(*openButton).withFlex(1.0, 1.0, 0.5).withHeight(10.0));

		seekBar = new Slider(Slider::LinearHorizontal, Slider::NoTextBox);
		addAndMakeVisible(seekBar);
		seekBar->addListener(this);
		seekBar->setWantsKeyboardFocus(false);
		flexBox.items.add(FlexItem(*seekBar).withFlex(6.0, 1.0, 0.5).withHeight(20.0));

		stopButton = new TextButton("Stop", "Stop");
		stopButton->addListener(this);
		stopButton->setWantsKeyboardFocus(false);
		addAndMakeVisible(stopButton);
		flexBox.items.add(FlexItem(*stopButton).withFlex(1.0, 1.0, 0.5).withHeight(20.0));

		pauseButton = new TextButton("Pause", "Pause");
		pauseButton->addListener(this);
		pauseButton->setWantsKeyboardFocus(false);
		addAndMakeVisible(pauseButton);
		flexBox.items.add(FlexItem(*pauseButton).withFlex(1.0, 1.0, 0.5).withHeight(20.0));

		playButton = new TextButton("Play", "Play");
		playButton->addListener(this);
		playButton->setWantsKeyboardFocus(false);
		addAndMakeVisible(playButton);
		flexBox.items.add(FlexItem(*playButton).withFlex(1.0, 1.0, 0.5).withHeight(20.0));

		openButton->setConnectedEdges(TextButton::ConnectedOnRight);
		stopButton->setConnectedEdges(TextButton::ConnectedOnRight);
		pauseButton->setConnectedEdges(TextButton::ConnectedOnRight);
		playButton->setConnectedEdges(TextButton::ConnectedOnRight);

		idle = new MouseIdle(*this);
	}
	~OSDComponent()
	{
	}
	void paint(Graphics& g) override
	{
		if (videoReader && videoReader->getVideoDuration() > 0) {
			g.setColour(Colours::white);
			g.setFont(24);
			String dim = String(videoReader->getVideoWidth()) + " x " + String(videoReader->getVideoHeight());
			g.drawFittedText(dim, getLocalBounds(), Justification::topLeft, 1);
			g.drawFittedText(FFmpegVideoReader::formatTimeCode(videoReader->getCurrentTimeStamp()),
				getLocalBounds(), Justification::topRight, 1);
		}
	}
	void resized() override
	{
		juce::Rectangle<int> bounds = getBounds().withTop(getHeight() - 40);
		flexBox.performLayout(bounds);
	}

	void setCurrentTime(const double time)
	{
		seekBar->setValue(time, dontSendNotification);
	}

	void setVideoLength(const double length)
	{
		seekBar->setRange(0.0, length);
	}
	void sliderValueChanged(juce::Slider* slider) override
	{
		if (slider == seekBar) {
			videoReader->setNextReadPosition(slider->getValue() * videoReader->getVideoSamplingRate());
		}
	}
	void buttonClicked(Button* button) override
	{
		if (button == openButton) {
			transport->stop();
			FileChooser chooser("Open Video File");
			File video = chooser.getResult();
			videoReader->loadMovieFile(video);
			int64 lastPos = videoReader->getNextReadPosition();
			transport->setSource(videoReader, 0, nullptr, videoReader->getVideoSamplingRate(), videoReader->getVideoChannels());
			videoReader->setNextReadPosition(lastPos);
			transport->start();
		}

		else if (button == playButton) {
			int64 lastPos = videoReader->getNextReadPosition();
			transport->setSource(videoReader, 0, nullptr, videoReader->getVideoSamplingRate(), videoReader->getVideoChannels());
			videoReader->setNextReadPosition(lastPos);
			transport->start();
		}
		else if (button == stopButton) {
			transport->stop();
			videoReader->setNextReadPosition(0);
		}
		else if (button == pauseButton) {
			transport->stop();

		}
	}

	class MouseIdle : public MouseListener, public Timer
	{
	public:
		MouseIdle(Component& c) :
			component(c),
			lastMovement(Time::getMillisecondCounter())
		{
			Desktop::getInstance().addGlobalMouseListener(this);
			startTimerHz(20);
		}

		void timerCallback() override
		{
			const int64 relTime = Time::getMillisecondCounter() - lastMovement;
			if (relTime < 2000) {
				component.setVisible(true);
				component.setAlpha(1.0);
				if (Component* parent = component.getParentComponent())
					parent->setMouseCursor(MouseCursor::StandardCursorType::NormalCursor);
			}
			else if (relTime < 2300) {
				component.setAlpha(1.0 - jmax(0.0, (relTime - 2000.0) / 300.0));
			}
			else {
				component.setVisible(false);
				if (Component* parent = component.getParentComponent()) {
					parent->setMouseCursor(MouseCursor::StandardCursorType::NoCursor);
					Desktop::getInstance().getMainMouseSource().forceMouseCursorUpdate();
				}
			}
		}

		void mouseMove(const MouseEvent &event) override
		{
			if (event.position.getDistanceFrom(lastPosition) > 3.0) {
				lastMovement = Time::getMillisecondCounter();
				lastPosition = event.position;
			}
		}
	private:
		Component&   component;
		int64        lastMovement;
		Point<float> lastPosition;
	};

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OSDComponent)
		FlexBox flexBox;
	ScopedPointer<MouseIdle>  idle;
	ScopedPointer<Slider>     seekBar;
	ScopedPointer<TextButton> openButton;
	ScopedPointer<TextButton> pauseButton;
	ScopedPointer<TextButton> stopButton;
	ScopedPointer<TextButton> playButton;
	FFmpegVideoReader* videoReader;
	AudioTransportSource* transport;
};
#endif  // OSDCOMPONENT_H_INCLUDED
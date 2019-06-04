/*
  ==============================================================================

    generate.h
    Created: 2 May 2019 10:22:21am
    Author:  Giney

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Video.h"
extern int generatefinished;


//==============================================================================
/*
*/
class Generate    : public Component
{
public:
    Generate();
    ~Generate();

    void paint (Graphics&) override;
    void resized() override;
	
private:
	void generateButtonClicked();
	void generatePolyButtonClicked();
	TextButton generateButton;
	TextButton generatePolyButton;
	
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Generate)
};

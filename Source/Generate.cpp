/*
  ==============================================================================

    generate.cpp
    Created: 2 May 2019 10:22:21am
    Author:  Giney

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Generate.h"
#include "python.h"
#include "windows.h"
#include<iostream>
int generatefinished = 0;
//==============================================================================
Generate::Generate(): generateButton("generate")
{
	setSize(320, 30);
	generateButton.onClick = [this] { generateButtonClicked(); };

	addAndMakeVisible(&generateButton);
	//generateButton

	


}


Generate::~Generate()
{
}

void Generate::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

	g.fillAll(Colours::white);   // clear the background
	g.setFont(14.0f);
    g.drawText ("generate", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
	
}

void Generate::resized()
{
	generateButton.setBounds(10, 5, 300, 20);
	

}
void Generate::generateButtonClicked()
{

	generatefinished = 0;

	File file(videoPath);
	String directorypath= String("D:\\Master\\REPO\\pbloem\\score\\"+videoName);
	if (file != File::nonexistent)
	{
		
		File videoFileCopy(directorypath);

		if (videoFileCopy.existsAsFile() == false) 
		{
			file.copyFileTo(videoFileCopy);
		}
		else if (videoFileCopy.existsAsFile() == true && file.hasIdenticalContentTo(videoFileCopy) == false)
		{
			videoFileCopy = videoFileCopy.getNonexistentSibling();
			file.copyFileTo(videoFileCopy);
		}
		auto A = videoName.toRawUTF8();
		
		char command[70] = "D:&&cd D:\\Master\\REPO\\pbloem\\score&& python generate.py - i ";
		
		DBG(String(strcat(command, A)));
		system(strcat(command, A));
	}
	
	
	
	generatefinished = 1;

}

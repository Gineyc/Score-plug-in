/*
  ==============================================================================

    SynthSound.h
    Created: 10 Apr 2019 10:49:06am
    Author:  Giney

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
class SynthSound : public SynthesiserSound
{
public:
	bool appliesToNote( int /*midiNoteNumber*/ )
	{
		return true;
	}
	bool appliesToChannel(int /*midiChannel*/)
	{
		return true;
	}

private:

};
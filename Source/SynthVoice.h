/*
  ==============================================================================

    SynthVoice.h
    Created: 10 Apr 2019 10:49:31am
    Author:  Giney

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"
#include "maximilian.h"
class SynthVoice : public SynthesiserVoice 
{
public:
	
	bool canPlaySound(SynthesiserSound* sound) 
	{
		return dynamic_cast<SynthSound*>(sound) != nullptr;
		//return the SynthSound and play the sound
	}

	void setPitchBend(int pitchWheelposition)
	{
		if (pitchWheelposition > 8192)
		{
			pitchBend = float(pitchWheelposition - 8192) / (16383 - 8192);
			//tones up
		}
		else
		{
			pitchBend = float(8192 - pitchWheelposition) / -8192;
			//tones down
		}
	}

	float pitchBendCents()
	{
		if (pitchBend >= 0.0f)
		{
			return pitchBend * pitchBendUpsemi * 100;
		}
		else
		{
			return pitchBend * pitchBendDownsemi * 100;
		}
	}

	static double noteHz(int midiNoteNumber, double centsOffset)
	{
		double hertz = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
		hertz *= std::pow(2.0, centsOffset / 1200);
		return hertz;
	}
	//===========================================================================


	void getOsc1Type(float* selection)
	{
		theWave = *selection;
	}

	void getOsc2Type(float* selection)
	{
		theWave2 = *selection;
	}
	//===========================================================================
	double setOsc1Type()
	{
		
		if (theWave == 0)
		{
			return osc1.sinewave(frequency)*osc1blend;
		}
		if (theWave == 1)
		{
			return osc1.saw(frequency)*osc1blend;
		}
		if (theWave == 2)
		{
			return osc1.square(frequency)*osc1blend;
		}
		if (theWave == 3)
		{
			return osc1.triangle(frequency)*osc1blend;
		}
		if (theWave == 4)
		{
			return osc1.coswave(frequency)*osc1blend;
		}
		if (theWave == 5)
		{
			return osc1.noise()*osc1blend;
		}
		else
		{
			return osc1.sawn(frequency)*osc1blend;
		}
	}

	double setOsc2Type()
	{

		if (theWave2 == 0)
		{
			return osc2.sinewave(frequency)*osc2blend;
		}
		if (theWave2 == 1)
		{
			return osc2.saw(frequency)*osc2blend;
		}
		if (theWave2 == 2)
		{
			return osc2.square(frequency)*osc2blend;
		}
		if (theWave2 == 3)
		{
			return osc2.triangle(frequency)*osc2blend;
		}
		if (theWave2 == 4)
		{
			return osc2.coswave(frequency)*osc2blend;
		}
		if (theWave2 == 5)
		{
			return osc2.noise()*osc2blend;
		}
		else
		{
			return osc2.sawn(frequency)*osc2blend;
		}
	}

	//===========================================================================
	void getEvelope1Param(float* attack,float* release,float* sustain,float* decay) 
	{
		env1.setAttack(double (*attack));
		env1.setRelease(double(*release));
		env1.setSustain(double (*sustain));
		env1.setDecay(double (*decay));
	}
	void getEvelope2Param(float* attack, float* release, float* sustain, float* decay)
	{
		env2.setAttack(double(*attack));
		env2.setRelease(double(*release));
		env2.setSustain(double(*sustain));
		env2.setDecay(double(*decay));
	}

	//===========================================================================
	double setEnvelope1()
	{
		return env1.adsr(setOsc1Type(), env1.trigger) * level;
	}
	double setEnvelope2()
	{
		return env2.adsr(setOsc2Type(), env2.trigger) * level;
	}

	/*double sound()
	{
		thesound = setEnvelope1() + setEnvelope2();
		return thesound;
	}*/
	//===========================================================================
	void getFilter1Param(float* filterType, float* filtercutoff, float* filterRes)
	{
		filterChoice1 = *filterType;
		cutoff1 = *filtercutoff;
		resonance1 = *filterRes;
	}
	void getFilter2Param(float* filterType, float* filtercutoff, float* filterRes)
	{
		filterChoice2 = *filterType;
		cutoff2 = *filtercutoff;
		resonance2 = *filterRes;
	}
	//===========================================================================
	void getWillsParams(float* mGain, float* blend1, float* blend2, float* pbup, float* pbdn)
	{
		masterGain = *mGain;
		osc1blend = *blend1;
		osc2blend = *blend2;
		pitchBendUpsemi = *pbup;
		pitchBendDownsemi = *pbdn;
	}
	//===========================================================================
	
	void startNote(int midiNoteNumber, float velocity, SynthesiserSound *sound, int currentPitchWheelPosition)
	{
		env1.trigger = 1;
		env2.trigger = 1;
		level = velocity;
		setPitchBend(currentPitchWheelPosition);
		frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
		
		
		//What will be happened if we have a note on the keyboard.
	}
	//===========================================================================
	void stopNote(float velocity, bool allowTailOff)
	{
		env1.trigger = 0;
		env2.trigger = 0;

		allowTailOff = true;

		if(velocity ==0)
		{
			clearCurrentNote();
		}
	
	}
	//===========================================================================
	void pitchWheelMoved(int newPitchWheelValue)
	{
		setPitchBend(newPitchWheelValue);
		frequency = noteHz(noteNumber, pitchBendCents());
	}
	//===========================================================================
	void controllerMoved(int controllerNumber, int newControllerValue) 
	{

	}
	//===========================================================================
	void renderNextBlock(AudioBuffer< float > &outputBuffer, int startSample, int numSamples) 
	{
		

		for (int sample = 0; sample < numSamples; ++sample)
		{
			
			
			

			for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
			{ 
				outputBuffer.addSample(channel, startSample, (setEnvelope1()+setEnvelope2())*masterGain);
			}
			++startSample;
		}

	}
	//===========================================================================
private:
	double level;
	double frequency;
	int theWave,theWave2;

	int filterChoice1,filterChoice2;
    float cutoff1,cutoff2;
    float resonance1,resonance2;
    
	int noteNumber;
	float pitchBend = 0.0f;
	float pitchBendUpsemi = 2.0f;
	float pitchBendDownsemi = 2.0f;

	double thesound;
	float masterGain =0.6;
	float osc1blend;
	float osc2blend;

	maxiOsc osc1,osc2;
	maxiEnv env1, env2;;
	maxiFilter filter1,filter2;
};
//set the wave = 440 * level; env(the wave, trigger) adjust the attack decay sustain relase
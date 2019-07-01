/*
/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
VstAudioProcessor::VstAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
	
	tree(*this,nullptr)
		
	/*	"parameter",
		{
			std::make_unique<AudioParameterFloat>("attack", "Attack", NormalisableRange<float>(0.1f, 5000.0f), 0.1f),
			std::make_unique<AudioParameterFloat>("decay", "Decay", NormalisableRange<float>(1.0f, 2000.0f), 1.0f),
			std::make_unique<AudioParameterFloat>("sustain", "Sustain", NormalisableRange<float>(0.0f, 1.0f), 0.8f),
			std::make_unique<AudioParameterFloat>("release", "Release", NormalisableRange<float>(0.1f, 5000.0f), 0.1f),
			std::make_unique<AudioParameterFloat>("wavetype", "WaveType", NormalisableRange<float>(0.0f, 2.0f), 0.0f),
			std::make_unique<AudioParameterFloat>("wavetype2", "WaveType2", NormalisableRange<float>(0.0f, 2.0f), 0.0f),
			std::make_unique<AudioParameterFloat>("filterType", "FilterType", NormalisableRange<float>(0.0f, 2.0f), 0.0f),
			std::make_unique<AudioParameterFloat>("filterCutoff", "FilterCutoff", NormalisableRange<float>(20.0f, 10000.0f), 400.0f),
			std::make_unique<AudioParameterFloat>("filterRes", "FilterRes", NormalisableRange<float>(1.0f, 5.0f), 1.0f)
		})*/
	//initialization of tree
#endif
{
	NormalisableRange<float> attackRange(0.1f,5000.0f);
	NormalisableRange<float> decayRange(0.1f, 2000.0f);
	NormalisableRange<float> sustainRange(0.1f, 1.0f);
	NormalisableRange<float> releaseRange(0.1f, 5000.0f);
	NormalisableRange<float> wavetypeRange(0.0f, 5.0f);
	NormalisableRange<float> filtercutoffRange(20.0f, 10000.0f);
	NormalisableRange<float> filterresRange(1.0f, 5.0f);
	NormalisableRange<float> filterType(0.0f, 2.0f);
	NormalisableRange<float> blendRange(0.0f, 1.0f);
	NormalisableRange<float> pbRange(0.0f, 12.0f);
	NormalisableRange<float> masterRange(0.0f, 1.0f);
	tree.createAndAddParameter("attack1","Attack1","Attack1",attackRange,15.0f,nullptr,nullptr);
	tree.createAndAddParameter("decay1", "Decay1", "Decay1", decayRange, 1.0f, nullptr, nullptr);
	tree.createAndAddParameter("sustain1", "Sustain1", "Sustain1", sustainRange, 0.6f, nullptr, nullptr);
	tree.createAndAddParameter("release1", "Release1", "Release1", releaseRange, 500.0f, nullptr, nullptr);
	tree.createAndAddParameter("attack2", "Attack2", "Attack2", attackRange, 15.0f, nullptr, nullptr);
	tree.createAndAddParameter("decay2", "Decay2", "Decay2", decayRange, 1.0f, nullptr, nullptr);
	tree.createAndAddParameter("sustain2", "Sustain2", "Sustain2", sustainRange, 0.6f, nullptr, nullptr);
	tree.createAndAddParameter("release2", "Release2", "Release2", releaseRange, 200.0f, nullptr, nullptr);

	tree.createAndAddParameter("wavetype1", "Wavetype1", "Wavetype1", wavetypeRange, 0.5, nullptr, nullptr);
	tree.createAndAddParameter("wavetype2", "Wavetype2", "Wavetype2", wavetypeRange, 0.5, nullptr, nullptr);

	tree.createAndAddParameter("blend1", "Osc1Blend", "Osc1Blend", blendRange, 0.6f, nullptr, nullptr);
	tree.createAndAddParameter("blend2", "Osc2Blend", "Osc2Blend", blendRange, 0.6f, nullptr, nullptr);

	tree.createAndAddParameter("filtercutoff", "Filtercutoff", "Filtercutoff", filtercutoffRange, 400.0f, nullptr, nullptr);
	tree.createAndAddParameter("filterres", "Filterres", "Filterres", filterresRange, 1, nullptr, nullptr);
	tree.createAndAddParameter("filtertype", "Filtertype", "Filtertype", filterType, 0, nullptr, nullptr);
	
	tree.createAndAddParameter("pbup", "PBup", "PBup", pbRange, 2.0f, nullptr, nullptr);
	tree.createAndAddParameter("pbdown", "PBdown", "PBdown", pbRange, 2.0f, nullptr, nullptr);
	tree.createAndAddParameter("mastergain", "Mastergain", "Matergain", masterRange, 0.8f, nullptr, nullptr);
	
	tree.state = ValueTree("attack1");
	tree.state = ValueTree("release1");
	tree.state = ValueTree("sustain1");
	tree.state = ValueTree("decay1");
	tree.state = ValueTree("attack2");
	tree.state = ValueTree("release2");
	tree.state = ValueTree("sustain2");
	tree.state = ValueTree("decay2");
	tree.state = ValueTree("wavetype1");
	tree.state = ValueTree("wavetype2");
	tree.state = ValueTree("filtercutoff");
	tree.state = ValueTree("filterres");
	tree.state = ValueTree("filtertype");
	tree.state = ValueTree("blend1");
	tree.state = ValueTree("blend2");
	tree.state = ValueTree("pbup");
	tree.state = ValueTree("pbdown");
	tree.state = ValueTree("mastergain");

	mySynth.clearVoices();

	for (int i = 0; i < 10; i++)
	{
		mySynth.addVoice(new SynthVoice());
	}
	mySynth.clearSounds();
	mySynth.addSound(new SynthSound());
	// the max notes that can play at the same time
}

VstAudioProcessor::~VstAudioProcessor()
{
}

//==============================================================================
const String VstAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool VstAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool VstAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool VstAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double VstAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int VstAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int VstAudioProcessor::getCurrentProgram()
{
    return 0;
}

void VstAudioProcessor::setCurrentProgram (int index)
{
}

const String VstAudioProcessor::getProgramName (int index)
{
    return {};
}

void VstAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void VstAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
	ignoreUnused(samplesPerBlock); //ignore unused samples from the last key we pressed
	lastSampleRate = sampleRate;
	mySynth.setCurrentPlaybackSampleRate(lastSampleRate); //set the SampleRate

	dsp::ProcessSpec spec;
	spec.sampleRate = lastSampleRate;
	spec.maximumBlockSize = samplesPerBlock;
	spec.numChannels = getTotalNumOutputChannels();
	stateVariableFilter.reset();
	stateVariableFilter.prepare(spec);
	updateFilter();
	
	
}

void VstAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool VstAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void VstAudioProcessor::updateFilter()
{
	if (statu == false) {
		int menuChoice = *tree.getRawParameterValue("filtertype");
		int freq = *tree.getRawParameterValue("filtercutoff");
		int res = *tree.getRawParameterValue("filterres");

		if (menuChoice == 0)
		{
			stateVariableFilter.state->type = dsp::StateVariableFilter::Parameters<float>::Type::lowPass;
			stateVariableFilter.state->setCutOffFrequency(lastSampleRate, freq, res);
		}

		if (menuChoice == 1)
		{
			stateVariableFilter.state->type = dsp::StateVariableFilter::Parameters<float>::Type::highPass;
			stateVariableFilter.state->setCutOffFrequency(lastSampleRate, freq, res);

		}

		if (menuChoice == 2)
		{
			stateVariableFilter.state->type = dsp::StateVariableFilter::Parameters<float>::Type::bandPass;
			stateVariableFilter.state->setCutOffFrequency(lastSampleRate, freq, res);
		}
		
	}
	else {
		stateVariableFilter.state->type = dsp::StateVariableFilter::Parameters<float>::Type::lowPass;
		stateVariableFilter.state->setCutOffFrequency(lastSampleRate, 10000, 5);
		
	}
	
}
void VstAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
	
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
	
	for (int i = 0; i < mySynth.getNumVoices(); i++) 
	{
		//if myVoice casts as a synthVoice, get the voice and set parameters.
		if (myVoice = dynamic_cast<SynthVoice*>(mySynth.getVoice(i))) 
		{

			myVoice->getOsc1Type(tree.getRawParameterValue("wavetype1"));
			myVoice->getOsc2Type(tree.getRawParameterValue("wavetype2"));


			myVoice->getEvelope1Param(tree.getRawParameterValue("attack1"),
				                     tree.getRawParameterValue("release1"),
				                     tree.getRawParameterValue("sustain1"),
				                     tree.getRawParameterValue("decay1"));
			
			myVoice->getEvelope2Param(tree.getRawParameterValue("attack2"),
			   	                     tree.getRawParameterValue("release2"),
			  	                     tree.getRawParameterValue("sustain2"),
				                     tree.getRawParameterValue("decay2"));

			myVoice->getFilter1Param(tree.getRawParameterValue("filtertype"),
				                    tree.getRawParameterValue("filtercutoff"),
				                    tree.getRawParameterValue("filterres"));
			
			myVoice->getWillsParams(tree.getRawParameterValue("mastergain"),
			                    	tree.getRawParameterValue("blend1"),
				                    tree.getRawParameterValue("blend2"),
				                    tree.getRawParameterValue("pbup"),
				                    tree.getRawParameterValue("pbdown"));
		}
	}


    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

   
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...

    }
	
	mySynth.renderNextBlock(buffer,midiMessages,0,buffer.getNumSamples() );
	updateFilter();
	dsp::AudioBlock<float> block(buffer);
	stateVariableFilter.process(dsp::ProcessContextReplacing<float>(block));

}

//==============================================================================
bool VstAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* VstAudioProcessor::createEditor()
{
    return new VstAudioProcessorEditor (*this);
}

//==============================================================================
void VstAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void VstAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new VstAudioProcessor();
}

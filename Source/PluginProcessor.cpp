/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthAudioProcessor::SynthAudioProcessor() 
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ), 
    tree(*this, nullptr)
#endif 
{
    //tree.state = ValueTree("Foo");
    //ENVELOPE
    NormalisableRange<float> attackParam(0.1f, 5000.0f);
    NormalisableRange<float> releaseParam(0.1f, 5000.0f);
    NormalisableRange<float> sustainParam(0.0f, 1.0f);
    NormalisableRange<float> decayParam(1.0f, 2000.0f, 0.1f);
    tree.createAndAddParameter("attack", "Attack", "Attack", attackParam, 0.1f, nullptr, nullptr);
    tree.createAndAddParameter("release", "Release", "Release", releaseParam, 0.1f, nullptr, nullptr);
    tree.createAndAddParameter("sustain", "Sustain", "sustain", sustainParam, 0.8f, nullptr, nullptr);
    tree.createAndAddParameter("decay", "Decay", "decay", decayParam, 1.0f, nullptr, nullptr);

    //OSCILLATORS
    NormalisableRange<float> waveTypeParam(0, 4);
    NormalisableRange<float> waveTypeParam2(0, 4);
    NormalisableRange<float> waveTypeParam3(0, 4);
    NormalisableRange<float> waveTypeParam4(0, 4);
    NormalisableRange<float> waveTypeParam5(0, 4);
    NormalisableRange<float> waveTypeParam6(0, 4);
    NormalisableRange<float> blendVal(0.0f, 1.0f, 0.1f);
    NormalisableRange<float> blendVal3(0.0f, 1.f, 0.1f);
    NormalisableRange<float> blendVal4(0.0f, 1.f, 0.1f);
    NormalisableRange<float> blendVal5(0.0f, 1.f, 0.1f);
    NormalisableRange<float> blendVal6(0.0f, 1.f, 0.1f);
    NormalisableRange<float> frequency1Val(0, 3);
    NormalisableRange<float> frequency2Val(0, 3);
    NormalisableRange<float> frequency3Val(0, 3);
    NormalisableRange<float> frequency4Val(0, 3);
    NormalisableRange<float> frequency5Val(0, 3);
    NormalisableRange<float> frequency6Val(0, 3);
    tree.createAndAddParameter("wavetype", "WaveType", "wavetype", waveTypeParam, 2, nullptr, nullptr);
    tree.createAndAddParameter("wavetype2", "WaveType2", "wavetype2", waveTypeParam2, 2, nullptr, nullptr);
    tree.createAndAddParameter("wavetype3", "WaveType3", "wavetype3", waveTypeParam3, 2, nullptr, nullptr);
    tree.createAndAddParameter("wavetype4", "WaveType4", "wavetype4", waveTypeParam4, 2, nullptr, nullptr);
    tree.createAndAddParameter("wavetype5", "WaveType5", "wavetype5", waveTypeParam5, 2, nullptr, nullptr);
    tree.createAndAddParameter("wavetype6", "WaveType6", "wavetype6", waveTypeParam6, 2, nullptr, nullptr);

    tree.createAndAddParameter("blend", "Osc2Blend", "blend", blendVal, 0.0f, nullptr, nullptr);
    tree.createAndAddParameter("blend3", "Osc3Blend", "blend3", blendVal3, 0.0f, nullptr, nullptr);
    tree.createAndAddParameter("blend4", "Osc4Blend", "blend4", blendVal4, 0.0f, nullptr, nullptr);
    tree.createAndAddParameter("blend5", "Osc5Blend", "blend5", blendVal5, 0.0f, nullptr, nullptr);
    tree.createAndAddParameter("blend6", "Osc6Blend", "blend6", blendVal6, 0.0f, nullptr, nullptr);

    tree.createAndAddParameter("frequency1", "Frequency1", "frequency1", frequency1Val, 0, nullptr, nullptr);
    tree.createAndAddParameter("frequency2", "Frequency2", "frequency2", frequency2Val, 0, nullptr, nullptr);
    tree.createAndAddParameter("frequency3", "Frequency3", "frequency3", frequency3Val, 0, nullptr, nullptr);
    tree.createAndAddParameter("frequency4", "Frequency4", "frequency4", frequency4Val, 0, nullptr, nullptr);
    tree.createAndAddParameter("frequency5", "Frequency5", "frequency5", frequency5Val, 0, nullptr, nullptr);
    tree.createAndAddParameter("frequency6", "Frequency6", "frequency6", frequency6Val, 0, nullptr, nullptr);

    //FILTER
    NormalisableRange<float> filterVal(20.0f, 3000.0f);
    NormalisableRange<float> resVal(1, 5);
    NormalisableRange<float> filterTypeVal(0, 2);
    tree.createAndAddParameter("filterType", "FilterType", "filterType", filterTypeVal, 0, nullptr, nullptr);
    tree.createAndAddParameter("filterCutoff", "FilterCutoff", "filterCutoff", filterVal, 400.0f, nullptr, nullptr);
    tree.createAndAddParameter("filterRes", "FilterRes", "filterRes", resVal, 1, nullptr, nullptr);

    //MAIN
    NormalisableRange<float> gain(0.0f, 1.0f);
    NormalisableRange<float> pbupVal(-10.0f, 10.0f, 0.1f);
    NormalisableRange<float> pbdownVal(0.0f, 12.0f);
    tree.createAndAddParameter("mastergain", "MasterGain", "mastergain", gain, 0.1f, nullptr, nullptr);
    tree.createAndAddParameter("pbup", "PBup", "pbup", pbupVal, 0.0f, nullptr, nullptr);
    tree.createAndAddParameter("pbdown", "PBdown", "pbdown", pbdownVal, 0.0f, nullptr, nullptr);
    
    mySynth.clearVoices();
    for (int i = 0; i < 5; i++) {
        mySynth.addVoice(new SynthVoice());
    }

    mySynth.clearSounds();
    mySynth.addSound(new SynthSound());
}

SynthAudioProcessor::~SynthAudioProcessor() {}

//==============================================================================
const String SynthAudioProcessor::getName() const {
    return JucePlugin_Name;
}

bool SynthAudioProcessor::acceptsMidi() const {
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SynthAudioProcessor::producesMidi() const {
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SynthAudioProcessor::isMidiEffect() const {
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SynthAudioProcessor::getTailLengthSeconds() const {
    return 0.0;
}

int SynthAudioProcessor::getNumPrograms() {
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SynthAudioProcessor::getCurrentProgram() {
    return 0;
}

void SynthAudioProcessor::setCurrentProgram (int index) {
}

const String SynthAudioProcessor::getProgramName (int index) {
    return {};
}

void SynthAudioProcessor::changeProgramName (int index, const String& newName) {}
void SynthAudioProcessor::updateFilter() {
    int menuChoice = *tree.getRawParameterValue("filterType");
    int freq = *tree.getRawParameterValue("filterCutoff");
    int res = *tree.getRawParameterValue("filterRes");

    if (menuChoice == 0) {
        stateVariableFilter.state->type = dsp::StateVariableFilter::Parameters<float>::Type::lowPass;
        stateVariableFilter.state->setCutOffFrequency(lastSampleRate, freq, res);
    }
    if (menuChoice == 1) {
        stateVariableFilter.state->type = dsp::StateVariableFilter::Parameters<float>::Type::highPass;
        stateVariableFilter.state->setCutOffFrequency(lastSampleRate, freq, res);
    }

    if (menuChoice == 2) {
        stateVariableFilter.state->type = dsp::StateVariableFilter::Parameters<float>::Type::bandPass;
        stateVariableFilter.state->setCutOffFrequency(lastSampleRate, freq, res);
    }
}
//==============================================================================
void SynthAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock) {
    updateFilter();
    visualHandler.clear();

    // Use this method as the place to do any pre-playback initialisation that you need
    ignoreUnused(samplesPerBlock);
    lastSampleRate = sampleRate;
    midiCollector.reset(sampleRate);
    mySynth.setCurrentPlaybackSampleRate(lastSampleRate);

    dsp::ProcessSpec spec;
    spec.sampleRate = sampleRate;
    spec.maximumBlockSize = samplesPerBlock;
    spec.numChannels = getTotalNumOutputChannels();

    stateVariableFilter.reset();
    stateVariableFilter.prepare(spec);
}



void SynthAudioProcessor::releaseResources() {}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SynthAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const {
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

//this is like the main
void SynthAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages) {
    ScopedNoDenormals noDenormals;
   
    for (int i = 0; i < mySynth.getNumVoices(); i++) {
        if ((myVoice = dynamic_cast<SynthVoice*>(mySynth.getVoice(i)))) {
                //Envelope
                float* newAttackFloatPtr = (float*)tree.getRawParameterValue("attack");
                float* newReleaseFloatPtr = (float*)tree.getRawParameterValue("release");
                float* newSustainFloatPtr = (float*)tree.getRawParameterValue("sustain");
                float* newDecayFloatPtr = (float*)tree.getRawParameterValue("decay");

                //Oscs
                float* newWaveFloatPtr = (float*)tree.getRawParameterValue("wavetype");
                float* newWave2FloatPtr = (float*)tree.getRawParameterValue("wavetype2");
                float* newWave3FloatPtr = (float*)tree.getRawParameterValue("wavetype3");
                float* newWave4FloatPtr = (float*)tree.getRawParameterValue("wavetype4");
                float* newWave5FloatPtr = (float*)tree.getRawParameterValue("wavetype5");
                float* newWave6FloatPtr = (float*)tree.getRawParameterValue("wavetype6");
                float* newBlend1FloatPtr = (float*)tree.getRawParameterValue("blend");
                float* newBlend3FloatPtr = (float*)tree.getRawParameterValue("blend3");
                float* newBlend4FloatPtr = (float*)tree.getRawParameterValue("blend4");
                float* newBlend5FloatPtr = (float*)tree.getRawParameterValue("blend5");
                float* newBlend6FloatPtr = (float*)tree.getRawParameterValue("blend6");
                float* newFrequency1 = (float*)tree.getRawParameterValue("frequency1");
                float* newFrequency2 = (float*)tree.getRawParameterValue("frequency2");
                float* newFrequency3 = (float*)tree.getRawParameterValue("frequency3");
                float* newFrequency4 = (float*)tree.getRawParameterValue("frequency4");
                float* newFrequency5 = (float*)tree.getRawParameterValue("frequency5");
                float* newFrequency6 = (float*)tree.getRawParameterValue("frequency6");

                //Filter
                float* newFilterTypeFloatPtr = (float*)tree.getRawParameterValue("filterType");
                float* newFilterFloatPtr = (float*)tree.getRawParameterValue("filterCutoff");
                float* newResFloatPtr = (float*)tree.getRawParameterValue("filterRes");

                //MASTER
                float* mastGainPtr = (float*)tree.getRawParameterValue("mastergain");
                float* pbupPtr = (float*)tree.getRawParameterValue("pbup");
                float* pbdownPtr = (float*)tree.getRawParameterValue("pbdown");

                myVoice->setMaster(mastGainPtr, pbupPtr, pbdownPtr);
                myVoice->setFrequency1(newFrequency1, newFrequency2, newFrequency3, newFrequency4, newFrequency5, newFrequency6);
                myVoice->setBlendParam(newBlend1FloatPtr, newBlend3FloatPtr, newBlend4FloatPtr, newBlend5FloatPtr, newBlend6FloatPtr);
                myVoice->getEnvelopeParam(newAttackFloatPtr, newReleaseFloatPtr, newSustainFloatPtr, newDecayFloatPtr);
                myVoice->getOscType(newWaveFloatPtr);
                myVoice->getOsc2Type(newWave2FloatPtr);
                myVoice->setOsc3Type(newWave3FloatPtr);
                myVoice->setOsc4Type(newWave4FloatPtr);
                myVoice->setOsc5Type(newWave5FloatPtr);
                myVoice->setOsc6Type(newWave6FloatPtr);
                myVoice->getFilterParams(newFilterTypeFloatPtr, newFilterFloatPtr, newResFloatPtr);
        }
    }
    
    midiCollector.removeNextBlockOfMessages(midiMessages, buffer.getNumSamples());
    keyboardState.processNextMidiBuffer(midiMessages, 0, buffer.getNumSamples(), true);

    buffer.clear();
    mySynth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
    updateFilter();
    dsp::AudioBlock<float> block(buffer);
    stateVariableFilter.process(dsp::ProcessContextReplacing<float> (block));

    visualHandler.pushBuffer(buffer);
}

//==============================================================================
bool SynthAudioProcessor::hasEditor() const {
    return true;
}

AudioProcessorEditor* SynthAudioProcessor::createEditor() {
    return new SynthAudioProcessorEditor (*this);
}

//==============================================================================
void SynthAudioProcessor::getStateInformation (MemoryBlock& destData) {
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void SynthAudioProcessor::setStateInformation (const void* data, int sizeInBytes) {
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new SynthAudioProcessor();
}

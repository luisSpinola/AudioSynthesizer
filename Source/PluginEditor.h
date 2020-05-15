/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Oscillator.h"
#include "Oscillator2.h"
#include "Oscillator3.h"
#include "Oscillator4.h"
#include "Oscillator5.h"
#include "Oscillator6.h"
#include "Envelope.h"
#include "Filter.h"
#include "SynthVoice.h"
#include "MidiHandler.h"
#include "GeneralHandler.h"

//==============================================================================
/**
*/
class SynthAudioProcessorEditor : public AudioProcessorEditor {
    public:
        SynthAudioProcessorEditor (SynthAudioProcessor&);
        ~SynthAudioProcessorEditor();
        
        
        //==============================================================================
        void paint (Graphics&) override;
        void resized() override;

    private:
        // This reference is provided as a quick way for your editor to
        // access the processor object that created it.
        SynthAudioProcessor& processor;

        Oscillator osc1;
        Oscillator2 osc2;
        Oscillator3 osc3;
        Oscillator4 osc4;
        Oscillator5 osc5;
        Oscillator6 osc6;
        Envelope envGui;
        Filter filterGui;
        MidiHandler midiHandler;
        GeneralHandler generalHandler;

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthAudioProcessorEditor)
};

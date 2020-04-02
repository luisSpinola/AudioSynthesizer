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
#include "Envelope.h"

//==============================================================================
/**
*/
class SynthAudioProcessorEditor  : public AudioProcessorEditor{
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

        Oscillator oscGui;
        Envelope envGui;

        //ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> attackTree;
        //ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> releaseTree;

        //Slider attackSlider;
        //Slider releaseSlider;

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthAudioProcessorEditor)
};

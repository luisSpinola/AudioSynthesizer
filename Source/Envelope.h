#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

class Envelope : public Component {
	public:
		Envelope(SynthAudioProcessor&);
		~Envelope();
		void paint(Graphics&) override;
		void resized() override;
	private:
		Slider attackSlider;
		Slider releaseSlider;
		Slider sustainSlider;
		Slider decaySlider;
		ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> attackVal;
		ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> releaseVal;
		ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> sustainVal;
		ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> decayVal;
		SynthAudioProcessor& processor;

		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Envelope)
};
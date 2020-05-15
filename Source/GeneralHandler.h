#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class GeneralHandler : public Component {
public:
	GeneralHandler(SynthAudioProcessor&);
	~GeneralHandler();

	void paint(Graphics&) override;
	void resized() override;
private:
	Slider mastergainSlider;
	Slider pbupSlider;
	Slider pbdownSlider;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> mastergainVal;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> pbupVal;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> pbdownVal;

	SynthAudioProcessor& processor;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GeneralHandler)
};
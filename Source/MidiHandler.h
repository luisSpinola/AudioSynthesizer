#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class MidiHandler : public Component {
public:
	MidiHandler(SynthAudioProcessor&);
	~MidiHandler();

	void paint(Graphics&) override;
	void resized() override;
private:
	SynthAudioProcessor& processor;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiHandler)
};
#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

class FilterBox : public Component {
public:
	FilterBox(SynthAudioProcessor&);
	~FilterBox();

	void paint(Graphics&) override;
	void resized() override;
private:
	ComboBox filterMenu;
	ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> filterTypeVal;

	SynthAudioProcessor& processor;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FilterBox)
};
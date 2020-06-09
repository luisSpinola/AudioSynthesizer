#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

class Images : public Component {
public:
	Images(SynthAudioProcessor&);
	~Images();

	void paint(Graphics&) override;
	void resized() override;
private:
	Slider filterCutoff;
	Slider filterRes;
	ComboBox filterMenu;
	ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> filterTypeVal;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> filterVal;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> resVal;

	SynthAudioProcessor& processor;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Images)
};
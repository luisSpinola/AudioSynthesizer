#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class Filter : public Component {
	public:
		Filter(SynthAudioProcessor&);
		~Filter();

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
		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Filter)
};
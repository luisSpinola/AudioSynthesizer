#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class VisualHandler : public AudioVisualiserComponent {
public:
    VisualHandler();
	~VisualHandler();
private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VisualHandler)
};
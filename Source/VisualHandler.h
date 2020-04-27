/*
  ==============================================================================

    VisualHandler.cpp
    Created: 27 Apr 2020 03:14:16am
    Author:  DaSno

  ==============================================================================
*/

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
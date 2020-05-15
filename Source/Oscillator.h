#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

class Oscillator : public Component {
public:
    Oscillator(SynthAudioProcessor&);
    ~Oscillator();
    void paint(Graphics&) override;
    void resized() override;

private:
    ComboBox oscMenu;
    ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> waveSelection;
    SynthAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Oscillator)
};

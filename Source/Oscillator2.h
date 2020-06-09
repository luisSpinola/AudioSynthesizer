#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

class Oscillator2 : public Component {
public:
    Oscillator2(SynthAudioProcessor&);
    ~Oscillator2();
    void paint(Graphics&) override;
    void resized() override;

private:
    ComboBox oscMenu;
    ComboBox oscFrequency;
    Slider blendSlider;
    ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> waveSelection;
    ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> frequencySelection;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> blendVal;
    SynthAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Oscillator2)
};
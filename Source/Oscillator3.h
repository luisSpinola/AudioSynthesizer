#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

class Oscillator3 : public Component {
public:
    Oscillator3(SynthAudioProcessor&);
    ~Oscillator3();
    void paint(Graphics&) override;
    void resized() override;

private:
    ComboBox oscMenu;
    ComboBox oscFrequency;
    Slider blendSlider;
    ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> waveSelection;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> blendVal;
    SynthAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Oscillator3)
};
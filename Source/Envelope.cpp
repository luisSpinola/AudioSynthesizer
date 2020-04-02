#include <JuceHeader.h>
#include "Envelope.h"

Envelope::Envelope(SynthAudioProcessor& p) : processor(p) {

    setSize(200, 200);

    attackSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    attackSlider.setRange(0.1f, 5000.0f);
    attackSlider.setValue(0.1f);
    attackSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);


    //RELEASE
    releaseSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    releaseSlider.setRange(0.1f, 5000.0f);
    releaseSlider.setValue(0.1f);
    releaseSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);

    //ADD
    addAndMakeVisible(&attackSlider);
    addAndMakeVisible(&releaseSlider);

    attackVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "attack", attackSlider);
    releaseVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "release", releaseSlider);
}
Envelope::~Envelope() {

}
void Envelope::paint(Graphics& g) {
    g.fillAll(Colours::black);
}
void Envelope::resized() {
    juce::Rectangle<int> area = getLocalBounds().reduced(40);
    attackSlider.setBounds(10, 10, 40, 100);
    releaseSlider.setBounds(60, 10, 40, 100);
}

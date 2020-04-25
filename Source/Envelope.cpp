#include <JuceHeader.h>
#include "Envelope.h"

Envelope::Envelope(SynthAudioProcessor& p) : processor(p) {

    setSize(200, 200);

    attackSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    attackSlider.setColour(Slider::trackColourId, Colours::black);
    attackSlider.setColour(Slider::thumbColourId, Colours::black);
    attackSlider.setRange(0.1f, 5000.0f);
    attackSlider.setValue(0.1f);
    attackSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    //ADD
    addAndMakeVisible(&attackSlider);

    //RELEASE
    releaseSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    releaseSlider.setColour(Slider::trackColourId, Colours::black);
    releaseSlider.setColour(Slider::thumbColourId, Colours::black);
    releaseSlider.setRange(0.1f, 5000.0f);
    releaseSlider.setValue(0.1f);
    releaseSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    addAndMakeVisible(&releaseSlider);

    attackVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "attack", attackSlider);
    releaseVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "release", releaseSlider);
}
Envelope::~Envelope() {

}
void Envelope::paint(Graphics& g) {
    juce::Rectangle<int> titleArea(0, 10, getWidth(), 20);
    g.fillAll(Colours::black);
    g.setColour(Colours::white);
    g.drawText("Envelope", titleArea, Justification::centredTop);
    g.drawText("A", 53, 150, 20, 20, Justification::centredTop);
    g.drawText("R", 77, 150, 20, 20, Justification::centredTop);

    juce::Rectangle<float> area(25, 25, 550, 150);
    g.setColour(Colours::grey);
    g.drawRect(area, 5.0f);
    g.fillRect(area);
    //g.drawRoundedRectangle(area, 20.0f, 2.0f);
}
void Envelope::resized() {
    juce::Rectangle<int> area = getLocalBounds().reduced(50);
    int sliderWidth = 25;
    int sliderHeight = 175;

    attackSlider.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));
    releaseSlider.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));
}

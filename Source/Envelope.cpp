#include <JuceHeader.h>
#include "Envelope.h"

Envelope::Envelope(SynthAudioProcessor& p) : processor(p) {
    setSize(335, 140);
    //Attack
    attackSlider.setSliderStyle(Slider::SliderStyle::Rotary);
    attackSlider.setColour(Slider::trackColourId, Colours::floralwhite);
    attackSlider.setColour(Slider::thumbColourId, Colours::floralwhite);
    attackSlider.setColour(Slider::rotarySliderFillColourId, Colours::floralwhite);
    attackSlider.setRange(0.1f, 5000.0f);
    attackSlider.setValue(0.1f);
    attackSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    addAndMakeVisible(&attackSlider);
    attackVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "attack", attackSlider);

    //Release
    releaseSlider.setSliderStyle(Slider::SliderStyle::Rotary);
    releaseSlider.setColour(Slider::trackColourId, Colours::floralwhite);
    releaseSlider.setColour(Slider::thumbColourId, Colours::floralwhite);
    releaseSlider.setColour(Slider::rotarySliderFillColourId, Colours::floralwhite);
    releaseSlider.setRange(0.1f, 5000.0f);
    releaseSlider.setValue(0.1f);
    releaseSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    addAndMakeVisible(&releaseSlider);
    releaseVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "release", releaseSlider);

    //Sustain
    sustainSlider.setSliderStyle(Slider::SliderStyle::Rotary);
    sustainSlider.setColour(Slider::trackColourId, Colours::floralwhite);
    sustainSlider.setColour(Slider::thumbColourId, Colours::floralwhite);
    sustainSlider.setColour(Slider::rotarySliderFillColourId, Colours::floralwhite);
    sustainSlider.setRange(0.1f, 1.0f);
    sustainSlider.setValue(1.0f);
    sustainSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    addAndMakeVisible(&sustainSlider);
    sustainVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "sustain", sustainSlider);

    //Decay
    decaySlider.setSliderStyle(Slider::SliderStyle::Rotary);
    decaySlider.setColour(Slider::trackColourId, Colours::floralwhite);
    decaySlider.setColour(Slider::thumbColourId, Colours::floralwhite);
    decaySlider.setColour(Slider::rotarySliderFillColourId, Colours::floralwhite);
    decaySlider.setRange(0.1f, 2000.0f);
    decaySlider.setValue(1.0f);
    decaySlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    addAndMakeVisible(&decaySlider);
    decayVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "decay", decaySlider);
}
Envelope::~Envelope() {}

void Envelope::paint(Graphics& g) {
    //Text
    juce::Rectangle<int> titleArea(0, 20, getWidth(), 20);
    g.setColour(Colours::white);
    g.drawText("Envelope", titleArea, Justification::centredTop);
    g.drawText("Attack", 43, 90, 60, 30, Justification::centredBottom);
    g.drawText("Release", 113, 90, 60, 30, Justification::centredBottom);
    g.drawText("Sustain", 183, 90, 60, 30, Justification::centredBottom);
    g.drawText("Decay", 252, 90, 60, 30, Justification::centredBottom);
}
void Envelope::resized() {
    attackSlider.setBounds(35,40, 75,75);
    releaseSlider.setBounds(105,40, 75,75);
    sustainSlider.setBounds(175,40, 75,75);
    decaySlider.setBounds(245,40, 75,75);
}

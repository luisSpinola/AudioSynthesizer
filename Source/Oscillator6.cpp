#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator6.h"

Oscillator6::Oscillator6(SynthAudioProcessor& p) : processor(p) {
    setSize(200, 140);

    //Wave selection
    oscMenu.addItem("Square", 1);
    oscMenu.addItem("Saw", 2);
    oscMenu.addItem("Sine", 3);
    oscMenu.addItem("Triangle", 4);
    oscMenu.addItem("Noise", 5);
    oscMenu.setJustificationType(Justification::centred);
    addAndMakeVisible(&oscMenu);
    //waveSelection = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "wavetype3", oscMenu);

    //Frequency
    oscFrequency.addItem("x2", 1);
    oscFrequency.addItem("x4", 2);
    oscFrequency.addItem("Normal", 3);
    oscFrequency.addItem("/2", 4);
    oscFrequency.addItem("/4", 5);
    oscFrequency.setJustificationType(Justification::centred);
    addAndMakeVisible(&oscFrequency);

    //Blend slider
    blendSlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    blendSlider.setColour(Slider::trackColourId, Colours::black);
    blendSlider.setColour(Slider::thumbColourId, Colours::black);
    blendSlider.setRange(0.0f, 1.0f, 1);
    blendSlider.setValue(0.0f);
    blendSlider.setTextBoxStyle(Slider::TextBoxRight, false, 30, 20);
    blendSlider.setColour(Slider::textBoxOutlineColourId, Colours::grey);
    addAndMakeVisible(&blendSlider);
    //blendVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "blend3", blendSlider);
}

Oscillator6::~Oscillator6() {}

void Oscillator6::paint(Graphics& g) {
    //Background
    juce::Rectangle <float> area(25, 25, 150, 150);
    g.setColour(Colours::grey);
    g.drawRect(area, 5.0f);
    g.fillRect(area);

    //Text
    juce::Rectangle<int> titleArea(0, 10, getWidth(), 20);
    g.setColour(Colours::white);
    g.drawText("Oscillator 6", titleArea, Justification::centredTop);
    g.drawText("Wave", 40, 28, 100, 20, Justification::centredLeft);
    g.drawText("Frequency", 40, 63, 100, 20, Justification::centredLeft);
    g.drawText("Blend", 40, 98, 100, 20, Justification::centredLeft);
}

void Oscillator6::resized() {
    oscMenu.setBounds(35, 45, 130, 20);
    oscFrequency.setBounds(35, 80, 130, 20);
    blendSlider.setBounds(30, 110, 140, 20);
}
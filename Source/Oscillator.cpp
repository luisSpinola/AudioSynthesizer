#include <JuceHeader.h>
#include "Oscillator.h"

Oscillator::Oscillator(SynthAudioProcessor& p) : processor(p){
    setSize(200, 140);

    //Wave Selection
    oscMenu.addItem("Square", 1);
    oscMenu.addItem("Saw", 2);
    oscMenu.addItem("Sine", 3);
    oscMenu.addItem("Triangle", 4);
    oscMenu.addItem("Noise", 5);
    oscMenu.setJustificationType(Justification::centred);
    addAndMakeVisible(&oscMenu);
    waveSelection = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "wavetype", oscMenu);

    //Frequency
    oscFrequency.addItem("Normal", 1);
    oscFrequency.addItem("/2", 2);
    oscFrequency.addItem("/4", 3);
    oscFrequency.addItem("/8", 4);
    oscFrequency.setJustificationType(Justification::centred);
    addAndMakeVisible(&oscFrequency);
    frequencySelection = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "frequency1", oscFrequency);
}
Oscillator::~Oscillator() {}

void Oscillator::paint(Graphics& g) {
    //Background
    juce::Rectangle<float> area(25, 25, 150, 150);
    g.setColour(Colours::grey);
    g.drawRect(area, 5.0f);
    g.fillRect(area);

    //Text
    juce::Rectangle<int> titleArea(0, 10, getWidth(), 20);
    g.setColour(Colours::white);
    g.drawText("Oscillator 1", titleArea, Justification::centredTop);
    g.drawText("Wave", 40, 28, 100, 20, Justification::centredLeft);
    g.drawText("Frequency", 40, 63, 100, 20, Justification::centredLeft);
}

void Oscillator::resized() {
    oscMenu.setBounds(35, 45, 130, 20);
    oscFrequency.setBounds(35, 80, 130, 20);
}

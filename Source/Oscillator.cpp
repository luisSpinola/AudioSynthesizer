/*
  ==============================================================================

    Oscillator.cpp
    Created: 31 Mar 2020 12:22:16am
    Author:  DaSno

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Oscillator.h"

//==============================================================================
Oscillator::Oscillator(SynthAudioProcessor& p) : processor(p){
    setSize(200, 140);
    oscMenu.addItem("Square", 1);
    oscMenu.addItem("Saw", 2);
    oscMenu.addItem("Sine", 3);
    oscMenu.addItem("Triangle", 4);
    oscMenu.addItem("Noise", 5);
    oscMenu.setJustificationType(Justification::centred);
    addAndMakeVisible(&oscMenu);

    waveSelection = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "wavetype", oscMenu);
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
}

void Oscillator::resized() {
    juce::Rectangle<int> area = getLocalBounds().reduced(40);
    oscMenu.setBounds(area.removeFromTop(20));
}

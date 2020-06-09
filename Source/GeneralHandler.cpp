#include <JuceHeader.h>
#include "GeneralHandler.h"

GeneralHandler::GeneralHandler(SynthAudioProcessor& p) : processor(p) {
    setSize(335, 140);

    //Volume
    mastergainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    mastergainSlider.setColour(Slider::trackColourId, Colours::black);
    mastergainSlider.setColour(Slider::thumbColourId, Colours::black);
    mastergainSlider.setRange(0.0f, 1.0f);
    mastergainSlider.setValue(0.5f);
    mastergainSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    addAndMakeVisible(&mastergainSlider);
    mastergainVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "mastergain", mastergainSlider);

    //Pb up
    pbupSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    pbupSlider.setRange(0.0f, 12.0f, 1.0f);
    pbupSlider.setValue(12.0f);
    pbupSlider.setTextBoxStyle(Slider::TextBoxRight, true, 35, 25);
    addAndMakeVisible(&pbupSlider);
    pbupVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "pbup", pbupSlider);

    //Pb down
    pbdownSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    pbdownSlider.setRange(0, 12, 1.0f);
    pbdownSlider.setValue(12.0f);
    pbdownSlider.setTextBoxStyle(Slider::TextBoxRight, true, 35, 25);
    addAndMakeVisible(&pbdownSlider);
    pbdownVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "pbdown", pbdownSlider);
    
    
    
}
GeneralHandler::~GeneralHandler() {}
void GeneralHandler::paint(Graphics& g) {
    juce::Rectangle<int> titleArea(0, 10, getWidth(), 20);

    //Background
    juce::Rectangle<float> area(25, 25, 550, 150);
    g.setColour(Colours::grey);
    g.drawRect(area, 5.0f);
    g.fillRect(area);

    //Text
    g.setColour(Colours::white);
    g.drawText("Main", titleArea, Justification::centredTop);
    g.drawText("Volume", 35, 110, 60, 20, Justification::centredLeft);
    //g.drawText("PB Up/Down", 53, 90, 90, 20, Justification::centredLeft);
}
void GeneralHandler::resized() {
    mastergainSlider.setBounds(45,30,30,90);
    pbdownSlider.setBounds(95,30,30,90);
    pbupSlider.setBounds(135,30,30,90);
}

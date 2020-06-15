#include <JuceHeader.h>
#include "GeneralHandler.h"

GeneralHandler::GeneralHandler(SynthAudioProcessor& p) : processor(p) {
    setSize(335, 140);

    //Volume
    mastergainSlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    mastergainSlider.setColour(Slider::trackColourId, Colours::floralwhite);
    mastergainSlider.setColour(Slider::thumbColourId, Colours::floralwhite);
    mastergainSlider.setRange(0.0f, 1.0f);
    mastergainSlider.setValue(0.5f);
    mastergainSlider.setTextBoxStyle(Slider::NoTextBox, true, 100, 50);
    addAndMakeVisible(&mastergainSlider);
    mastergainVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "mastergain", mastergainSlider);

    //Pb up
    pbupSlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    pbupSlider.setColour(Slider::trackColourId, Colours::floralwhite);
    pbupSlider.setColour(Slider::thumbColourId, Colours::floralwhite);
    pbupSlider.setRange(-10.0f, 10.0f, 1.0f);
    pbupSlider.setValue(0.0f);
    pbupSlider.setTextBoxStyle(Slider::TextBoxRight, true, 50, 25);
    pbupSlider.setColour(Slider::textBoxOutlineColourId, Colours::grey);
    addAndMakeVisible(&pbupSlider);
    pbupVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "pbup", pbupSlider);
}
GeneralHandler::~GeneralHandler() {}
void GeneralHandler::paint(Graphics& g) {
    //Background
    juce::Rectangle<float> area(25, 25, 550, 150);
    //Text
    g.setColour(Colours::white);
    g.drawText("Volume", 45, 0, 60, 20, Justification::centredLeft);
    g.drawText("Pitch", 45, 30, 90, 20, Justification::centredLeft);
}
void GeneralHandler::resized() {
    //mastergainSlider.setBounds(45,30,30,90);
    mastergainSlider.setBounds(35, 10, 285, 30);
    pbupSlider.setBounds(35, 40, 285, 30);
}

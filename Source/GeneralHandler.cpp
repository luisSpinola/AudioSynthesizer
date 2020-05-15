#include <JuceHeader.h>
#include "GeneralHandler.h"

GeneralHandler::GeneralHandler(SynthAudioProcessor& p) : processor(p) {
    setSize(200, 200);
    //slider initialization values
    mastergainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    mastergainSlider.setColour(Slider::trackColourId, Colours::black);
    mastergainSlider.setColour(Slider::thumbColourId, Colours::black);
    mastergainSlider.setRange(0.0f, 1.0f);
    mastergainSlider.setValue(0.5f);
    mastergainSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    addAndMakeVisible(&mastergainSlider);

    pbupSlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    pbupSlider.setRange(0, 12, 1);
    pbupSlider.setValue(12);
    pbupSlider.setTextBoxStyle(Slider::TextBoxRight, true, 35, 25);
    addAndMakeVisible(&pbupSlider);

    pbdownSlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    pbdownSlider.setRange(0, 12, 1);
    pbdownSlider.setValue(12);
    pbdownSlider.setTextBoxStyle(Slider::TextBoxRight, true, 35, 25);
    addAndMakeVisible(&pbdownSlider);

    mastergainVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "mastergain", mastergainSlider);
    pbupVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "pbup", pbupSlider);
    pbdownVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "pbdown", pbdownSlider);
}
GeneralHandler::~GeneralHandler() {}
void GeneralHandler::paint(Graphics& g) {
    //fancy stuff for the UI background etc
    juce::Rectangle<int> titleArea(0, 10, getWidth(), 20);

    g.fillAll(Colours::black);
    
    juce::Rectangle<float> area(25, 25, 550, 150);
    g.setColour(Colours::grey);
    g.drawRect(area, 5.0f);
    g.fillRect(area);

    g.setColour(Colours::white);
    g.drawText("Main", titleArea, Justification::centredTop);
    //static positioning for now due to time, make dynamic later
    g.drawText("Master", 53, 40, 40, 20, Justification::centredLeft);
    g.drawText("PB Up/Down", 53, 90, 90, 20, Justification::centredLeft);
}
void GeneralHandler::resized() {
    //draws the sliders...we use a rectangle object to dynamically size the UI (if we want to resize for IPad etc without needing to change ALL settings
    juce::Rectangle<int> area = getLocalBounds().reduced(50);

    int sliderWidth = 25;
    int sliderHeight = 75;

    //mastergainSlider.setBounds(45, 20, 120, 100);
    mastergainSlider.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));

    pbdownSlider.setBounds(area.removeFromBottom(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));
    pbupSlider.setBounds(area.removeFromBottom(sliderHeight).removeFromTop(sliderWidth).withTrimmedTop(10));
}

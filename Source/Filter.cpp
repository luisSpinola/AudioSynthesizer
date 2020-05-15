#include <JuceHeader.h>
#include "Filter.h"

Filter::Filter(SynthAudioProcessor& p) : processor(p){
	setSize(320, 140);
	filterMenu.addItem("Low Pass", 1);
	filterMenu.addItem("High Pass", 2);
	filterMenu.addItem("Band Pass", 3);
	filterMenu.setJustificationType(Justification::centred);
	addAndMakeVisible(&filterMenu);

	filterTypeVal = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "filterType", filterMenu);

	//filterCutoff.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	filterCutoff.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
	filterCutoff.setColour(Slider::trackColourId, Colours::black);
	filterCutoff.setColour(Slider::thumbColourId, Colours::black);
	filterCutoff.setRange(20.0, 3000.0);
	filterCutoff.setValue(400.0);
	filterCutoff.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&filterCutoff);
	
	filterVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filterCutoff", filterCutoff);
	

	//filterRes.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	filterRes.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
	filterRes.setColour(Slider::thumbColourId, Colours::black);
	filterRes.setRange(1, 5);
	filterRes.setValue(1);
	filterRes.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&filterRes);
	resVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filterRes", filterRes);

	//filterCutoff.setSkewFactorFromMidPoint(1000.0);
}
Filter::~Filter() {

}
void Filter::paint(Graphics& g) {
	//Image splash = ImageFileFormat::loadFrom(BinaryData::metal_png, (size_t)BinaryData::metal_pngSize);
	//g.drawImageAt(splash, 0, 0);
	juce::Rectangle<float> area(25, 25, 335, 150);
	g.setColour(Colours::grey);
	g.drawRect(area, 5.0f);
	g.fillRect(area);
	
	//Text
	juce::Rectangle<int> titleArea(0, 10, getWidth(), 20);
	g.setColour(Colours::white);
	g.drawText("Filter", titleArea, Justification::centredTop);
	g.drawText("Cutoff", 40, 60, 100, 20, Justification::centredLeft);
	g.drawText("Resonance", 40, 90, 100, 20, Justification::centredLeft);
}
void Filter::resized() {
	juce::Rectangle<int> area = getLocalBounds().reduced(40);
	filterMenu.setBounds(area.removeFromTop(20));
	filterCutoff.setBounds(45, 70, 260, 30);
	filterRes.setBounds(45, 100, 260, 30);
}

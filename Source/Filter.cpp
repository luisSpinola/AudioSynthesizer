#include <JuceHeader.h>
#include "Filter.h"

Filter::Filter(SynthAudioProcessor& p) : processor(p){
	setSize(320, 140);

	//Filter selector
/*	filterMenu.addItem("Low Pass", 1);
	filterMenu.addItem("High Pass", 2);
	filterMenu.addItem("Band Pass", 3);
	filterMenu.setJustificationType(Justification::centred);
	addAndMakeVisible(&filterMenu);
	filterTypeVal = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "filterType", filterMenu);*/

	//Cutoff
	filterCutoff.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
	filterCutoff.setColour(Slider::trackColourId, Colours::floralwhite);
	filterCutoff.setColour(Slider::thumbColourId, Colours::floralwhite);
	filterCutoff.setRange(20.0, 3000.0);
	filterCutoff.setValue(400.0);
	filterCutoff.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&filterCutoff);
	filterVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filterCutoff", filterCutoff);
	
	//Resonance
	filterRes.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
	filterRes.setColour(Slider::thumbColourId, Colours::floralwhite);
	filterRes.setColour(Slider::trackColourId, Colours::floralwhite);
	filterRes.setRange(1, 5);
	filterRes.setValue(1);
	filterRes.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&filterRes);
	resVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filterRes", filterRes);
}
Filter::~Filter() {}
void Filter::paint(Graphics& g) {
	
	//Background
	juce::Rectangle<float> area(25, 25, 335, 150);
	g.setColour(Colours::transparentWhite);
	g.drawRect(area, 5.0f);
	g.fillRect(area);
	
	//Text
	juce::Rectangle<int> titleArea(0, 10, getWidth(), 20);
	g.setColour(Colours::white);
	g.drawText("Filter", titleArea, Justification::centredTop);
	g.drawText("Cutoff", 45, 60, 100, 20, Justification::centredLeft);
	g.drawText("Resonance", 45, 90, 100, 20, Justification::centredLeft);
}
void Filter::resized() {
	//filterMenu.setBounds(40,40, 275, 20);
	filterCutoff.setBounds(35, 70, 285, 30);
	filterRes.setBounds(35, 100, 285, 30);
}

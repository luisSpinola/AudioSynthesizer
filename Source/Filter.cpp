#include <JuceHeader.h>
#include "Filter.h"

Filter::Filter(SynthAudioProcessor& p) : processor(p){
	setSize(600, 200);
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
	juce::Rectangle<int> titleArea(0, 10, getWidth(), 20);
	g.fillAll(Colours::black);
	g.setColour(Colours::white);
	g.drawText("Filter", titleArea, Justification::centredTop);


	//Image splash = ImageFileFormat::loadFrom(BinaryData::Sprit_png, (size_t)BinaryData::Sprit_pngSize);
	
	juce::Rectangle<float> area(25, 25, 550, 150);

	g.setColour(Colours::grey);
	g.drawRect(area, 5.0f);
	g.fillRect(area);
	//g.drawImageAt(splash, 0, 0);
}
void Filter::resized() {

	juce::Rectangle<int> area = getLocalBounds().reduced(40);
	filterMenu.setBounds(area.removeFromTop(20));
	filterCutoff.setBounds(45, 60, 500, 70);
	filterRes.setBounds(45, 100, 500, 70);
}

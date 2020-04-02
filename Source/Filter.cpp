#include <JuceHeader.h>
#include "Filter.h"

Filter::Filter(SynthAudioProcessor& p) : processor(p){
	setSize(200, 200);
	filterMenu.addItem("Low Pass", 1);
	filterMenu.addItem("High Pass", 2);
	filterMenu.addItem("Band Pass", 3);
	filterMenu.setJustificationType(Justification::centred);
	addAndMakeVisible(&filterMenu);

	filterTypeVal = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "filterType", filterMenu);
}
Filter::~Filter() {

}
void Filter::paint(Graphics& g) {
	g.fillAll(Colours::black);
}
void Filter::resized() {

}

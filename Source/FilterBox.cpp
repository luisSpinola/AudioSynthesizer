#include <JuceHeader.h>
#include "FilterBox.h"

FilterBox::FilterBox(SynthAudioProcessor& p) : processor(p) {
	setSize(320, 50);

	//Filter selector
	filterMenu.addItem("Low Pass", 1);
	filterMenu.addItem("High Pass", 2);
	filterMenu.addItem("Band Pass", 3);
	filterMenu.setJustificationType(Justification::centred);
	addAndMakeVisible(&filterMenu);
	filterTypeVal = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "filterType", filterMenu);

}
FilterBox::~FilterBox() {}
void FilterBox::paint(Graphics& g) {
}
void FilterBox::resized() {
	juce::Rectangle<int> area = getLocalBounds().reduced(40);
	filterMenu.setBounds(40,40, 275, 20);
}

#include <JuceHeader.h>
#include "Images.h"

Images::Images(SynthAudioProcessor& p) : processor(p) {
	setSize(320, 140);
}
Images::~Images() {}
void Images::paint(Graphics& g) {
	Image splash = ImageFileFormat::loadFrom(BinaryData::Logo_png, (size_t)BinaryData::Logo_pngSize);
	g.drawImageAt(splash, 0, 0);
}
void Images::resized() {
}

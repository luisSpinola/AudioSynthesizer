#include "PluginProcessor.h"
#include "VisualHandler.h"

VisualHandler::VisualHandler() : AudioVisualiserComponent(1) {
	setBufferSize(128);
	setSamplesPerBlock(32);
	setColours(Colours::black, Colours::grey);
}

VisualHandler::~VisualHandler(){
}
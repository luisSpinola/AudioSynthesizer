/*
  ==============================================================================

    Oscillator.cpp
    Created: 31 Mar 2020 12:22:16am
    Author:  DaSno

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MidiHandler.h"

//==============================================================================
MidiHandler::MidiHandler(SynthAudioProcessor& p) : processor(p) {
    setSize(200, 65);
    addAndMakeVisible(processor.keyboardComponent);
    processor.keyboardComponent.setAvailableRange(24, 95);
    processor.keyboardComponent.setKeyPressBaseOctave(4);
}

MidiHandler::~MidiHandler() {
}

void MidiHandler::paint(Graphics& g) {
}

void MidiHandler::resized() {
    processor.keyboardComponent.setBounds(8, 0, getWidth() - 16, 64);
}
/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthAudioProcessorEditor::SynthAudioProcessorEditor (SynthAudioProcessor& p) : AudioProcessorEditor (&p), processor (p), osc1(p), osc2(p), envGui(p), filterGui(p), midiHandler(p), generalHandler(p), osc3(p), osc4(p), osc5(p), osc6(p), images(p), filterBox(p) {
    setSize (680, 630);

    addAndMakeVisible(&osc1);
    addAndMakeVisible(&osc2);
    addAndMakeVisible(&osc3);
    addAndMakeVisible(&osc4);
    addAndMakeVisible(&osc5);
    addAndMakeVisible(&osc5);
    addAndMakeVisible(&osc6);
    addAndMakeVisible(&filterGui);
    addAndMakeVisible(&envGui);
    
    addAndMakeVisible(processor.visualHandler);
    addAndMakeVisible(&generalHandler);
    
    addAndMakeVisible(&midiHandler);
    addAndMakeVisible(&images);
    addAndMakeVisible(&filterBox);
}

SynthAudioProcessorEditor::~SynthAudioProcessorEditor() {
}

//==============================================================================
void SynthAudioProcessorEditor::paint (Graphics& g) {
    g.fillAll (Colours::black);
    
}

void SynthAudioProcessorEditor::resized() {
    //KEYBOARD
    midiHandler.setBounds(0, 560, 680, 100);

    //OSCs
    osc1.setBounds(0,0,200,140);
    osc2.setBounds(160,0,200,140);
    osc3.setBounds(320, 0, 200, 140);
    osc4.setBounds(480, 0, 200, 140);
    osc5.setBounds(0, 140, 200, 140);
    osc6.setBounds(160, 140, 200, 140);

    //FILTER
    filterBox.setBounds(320, 140, 335, 60);
    filterGui.setBounds(320,140,335,140);
    

    //ENVELOPE + MAIN
    envGui.setBounds(0,280,335,140);
    generalHandler.setBounds(320, 300, 335, 140);
    //VISUALISER
    processor.visualHandler.setBounds(25, 440, 630, 100);
    images.setBounds(200, 440, 630, 100);
}



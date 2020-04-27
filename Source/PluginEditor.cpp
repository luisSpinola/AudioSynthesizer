/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthAudioProcessorEditor::SynthAudioProcessorEditor (SynthAudioProcessor& p) : AudioProcessorEditor (&p), processor (p), oscGui(p), osc2Gui(p), envGui(p), filterGui(p), midiHandler(p) {
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 665);
    addAndMakeVisible(&oscGui);
    addAndMakeVisible(&osc2Gui);
    addAndMakeVisible(&filterGui);
    addAndMakeVisible(&envGui);
    addAndMakeVisible(&midiHandler);
    //ATTACK
    /*attackSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    attackSlider.setRange(0.1f, 5000.0f);
    attackSlider.setValue(0.1f);
    //attackSlider.setTextBoxStyle(Slider::TextBoxLeft, false, 300, 50);
    attackSlider.addListener(this);
    

    //RELEASE
    releaseSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    releaseSlider.setRange(0.1f, 5000.0f);
    releaseSlider.setValue(0.1f);
    releaseSlider.addListener(this);

    //ADD
    addAndMakeVisible(&attackSlider);
    addAndMakeVisible(&releaseSlider);



    attackTree = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "attack", attackSlider);
    releaseTree = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "release", releaseSlider);*/
}

SynthAudioProcessorEditor::~SynthAudioProcessorEditor()
{
}

//==============================================================================
void SynthAudioProcessorEditor::paint (Graphics& g) {
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (Colours::black);

}

void SynthAudioProcessorEditor::resized() {
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    juce::Rectangle<int> area = getLocalBounds();
    const int componentWidth = 200;
    const int componentHeight = 200;
    oscGui.setBounds(0,0,200,200);
    osc2Gui.setBounds(200,0,200,200);

    filterGui.setBounds(0,200,600,200);
    envGui.setBounds(0,400,600,200);
    midiHandler.setBounds(0,600,600,200);
    //cenas.setBounds(0, 550, 800, 520);
    //filterGui.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight));
    //envGui.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight));
}



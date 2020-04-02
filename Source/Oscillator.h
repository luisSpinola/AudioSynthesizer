/*
  ==============================================================================

    Oscillator.h
    Created: 31 Mar 2020 12:22:16am
    Author:  DaSno

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class Oscillator : public Component, private ComboBox::Listener {
public:
    Oscillator(SynthAudioProcessor&);
    ~Oscillator();

    void paint(Graphics&) override;
    void resized() override;

    void comboBoxChanged(ComboBox*) override;

    
private:
    ComboBox oscMenu;
    

    
    ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> waveSelection;
    SynthAudioProcessor& processor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Oscillator)
};

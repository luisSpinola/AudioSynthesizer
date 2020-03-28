/*
  ==============================================================================

    SynthVoice.h
    Created: 27 Mar 2020 2:34:36am
    Author:  DaSno

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SynthSound.h"

class SynthVoice : public SynthesiserVoice {
    public:
        bool canPlaySound(SynthesiserSound* sound) {
            return dynamic_cast<SynthSound*>(sound) != nullptr;
        }
        void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition) {
            frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        }
        void stopNote(float velocity, bool allowTailOff) {
            clearCurrentNote();
        }
        void pitchWheelMoved(int newPitchWheelValue) {}
        void controllerMoved(int controllerNumber, int newControllerValue) {}
        void renderNextBlock(AudioBuffer<float>& outputBuffer, int startSample, int numSamples) {}
    private:
        double level;
        double frequency;



};

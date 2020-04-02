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
#include "maximilian.h"

class SynthVoice : public SynthesiserVoice {
    public:
        bool canPlaySound(SynthesiserSound* sound) {
            return dynamic_cast<SynthSound*>(sound) != nullptr;
        }
        void getParam(float* attack, float* release) {
            env1.setAttack(double(*attack));
            env1.setRelease(double(*release));
        }
        void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition) {
            env1.trigger = 1;
            level = velocity;
            frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        }
        void getOscType(float* selection) {
            theWave = *selection;
        }

        double setOscType() {
            if (theWave == 0) {
                return osc1.sinewave(frequency);
            }
            else if (theWave == 1) {
                return osc1.saw(frequency);
            }
            else if (theWave == 2) {
                return osc1.square(frequency);
            }
            else {
                return osc1.sinewave(frequency);
            }
        }

        void getFilterParams(float* filterType, float* filterCutoff, float* filterRes) {

        }



        void stopNote(float velocity, bool allowTailOff) {
            env1.trigger = 0;
            allowTailOff = true;
            if (velocity == 0) {
                clearCurrentNote();
            }
        }
      
        void renderNextBlock(AudioBuffer<float> &outputBuffer, int startSample, int numSamples) {
            
            env1.setDecay(500);
            env1.setSustain(0.8);
            

            for (int sample = 0; sample < numSamples; ++sample) {
                //double theWave = osc1.saw(frequency);
                double theSound = env1.adsr(setOscType(), env1.trigger) * level;
                double filteredSound = filter1.lores(theSound, 100, 0.1);
                for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel) {
                    outputBuffer.addSample(channel, startSample, theSound);
                }
                ++startSample;
            }
        }
        void pitchWheelMoved(int newPitchWheelValue) {}
        void controllerMoved(int controllerNumber, int newControllerValue) {}
    private:
        double level;
        double frequency;

        int theWave;

        maxiOsc osc1;
        maxiEnv env1;
        maxiFilter filter1;
};

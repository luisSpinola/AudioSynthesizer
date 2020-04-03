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
        bool canPlaySound(SynthesiserSound* sound) override {
            return dynamic_cast<SynthSound*>(sound) != nullptr;
        }
        
        //OSCILLATOR
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

        //ENVELOPE
        void getEnvelopeParam(float* attack, float* release) {
            env1.setAttack(double(*attack));
            env1.setRelease(double(*release));
        }
        double setEnvelope() {
            return env1.adsr(setOscType(), env1.trigger);
        }

        //FILTER
        void getFilterParams(float* filterType, float* filterCutoff, float* filterRes) {
            filterChoice = (double(*filterType));
            cutoff = (double(*filterCutoff));
            resonance = (double(*filterRes));
        }
        double setFilter() {
            if (filterChoice == 0) {
                return filter1.lores(setEnvelope(), cutoff, resonance);
            }
            else if (filterChoice == 1) {
                return filter1.hires(setEnvelope(), cutoff, resonance);
            }
            else if (filterChoice == 2) {
                return filter1.bandpass(setEnvelope(), cutoff, resonance);
            }
            else {
                return filter1.lores(setEnvelope(), cutoff, resonance);
            }
        }

        void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition) override {
            env1.trigger = 1;
            frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
            level = velocity;
        }
        void stopNote(float velocity, bool allowTailOff) override {
            env1.trigger = 0;
            allowTailOff = true;
            if (velocity == 0) {
                clearCurrentNote();
            }
        }
        void pitchWheelMoved(int newPitchWheelValue) override {}
        void controllerMoved(int controllerNumber, int newControllerValue) override {}

        void renderNextBlock(AudioBuffer<float> &outputBuffer, int startSample, int numSamples) override {
            
            env1.setDecay(500);
            env1.setSustain(0.8);
            

            for (int sample = 0; sample < numSamples; ++sample) {
                //double theWave = osc1.saw(frequency);
                //double theSound = setEnvelope();
                //double filteredSound = filter1.lores(theSound, 100, 0.1);
                for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel) {
                    outputBuffer.addSample(channel, startSample, setEnvelope() * 0.3f);
                }
                ++startSample;
            }
        }
        
    private:
        double level;
        double frequency;

        int theWave;

        float filterChoice;
        float cutoff;
        float resonance;


        maxiOsc osc1;
        maxiEnv env1;
        maxiFilter filter1;
};

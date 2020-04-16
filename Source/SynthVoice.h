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
        
        //OSCILLATORS
        void getOscType(float* selection) {
            theWave = *selection;
        }
        void getOsc2Type(float* selection) {
            theWave2 = *selection;
        }

        double setOscType() {
            double sample1, sample2;
            switch (theWave) {
                case 0:
                    sample1 = osc1.square(frequency);
                    break;
                case 1:
                    sample1 = osc1.saw(frequency);
                    break;
                default:
                    sample1 = osc1.sinewave(frequency);
                    break;
            }
            switch (theWave2) {
                case 0:
                    sample2 = osc2.saw(frequency / 2.0);
                    break;
                case 1:
                    sample2 = osc2.square(frequency / 2.0);
                    break;
                default:
                    sample2 = osc2.sinewave(frequency / 2.0);
                    break;
            }
            return sample1 + osc2blend * sample2;
        }

        void getBlendParam(float* blend1) {
            osc2blend = *blend1;
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

        int theWave, theWave2;
        float osc2blend;

        float filterChoice;
        float cutoff;
        float resonance;


        maxiOsc osc1, osc2;
        maxiEnv env1;
        maxiFilter filter1;
};

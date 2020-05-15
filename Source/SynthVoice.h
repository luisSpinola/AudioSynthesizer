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

class SynthVoice : public SynthesiserVoice{
    public:
        bool canPlaySound(SynthesiserSound* sound) override {
            return dynamic_cast<SynthSound*>(sound) != nullptr;
        }

        //Master
        void setMaster(float* gain, float* pbup, float* pbdn) {
            masterGain = *gain;
            pitchBendUpSemitones = *pbup;
            pitchBendDownSemitones = *pbdn;
        }

        //PITCH
        void setPitchBend(int pitchWheelPos) {
            if (pitchWheelPos > 8192) {
                // shifting up
                pitchBend = float(pitchWheelPos - 8192) / (16383 - 8192);
            }
            else {
                // shifting down
                pitchBend = float(8192 - pitchWheelPos) / -8192;    // negative number
            }
        }
        float pitchBendCents() {
            if (pitchBend >= 0.0f) {
                // shifting up
                return pitchBend * pitchBendUpSemitones * 100;
            }
            else {
                // shifting down
                return pitchBend * pitchBendDownSemitones * 100;
            }
        }
        static double noteHz(int midiNoteNumber, double centsOffset) {
            double hertz = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
            hertz *= std::pow(2.0, centsOffset / 1200);
            return hertz;
        }

        //OSCILLATORS
        void getOscType(float* selection) {
            theWave = *selection;
        }
        void getOsc2Type(float* selection) {
            theWave2 = *selection;
        }
        void setOsc3Type(float* selection) {
            theWave3 = *selection;
        }
        double setOscType() {
            double sample1, sample2, sample3, sample4, sample5, sample6;
            switch (theWave) {
                case 0:
                    sample1 = osc1.square(frequency / 2.0);
                    break;
                case 1:
                    sample1 = osc1.saw(frequency / 2.0);
                    break;
                case 2:
                    sample1 = osc1.sinewave(frequency / 2.0);
                    break;
                case 3:
                    sample1 = osc1.triangle(frequency / 2.0);
                    break;
                case 4:
                    sample1 = osc1.noise();
                    break;
                default:
                    sample1 = osc1.sinewave(frequency / 2.0);
                    break;
            }
            switch (theWave2) {
                case 0:
                    sample2 = osc2.saw(frequency / 4.0);
                    break;
                case 1:
                    sample2 = osc2.square(frequency / 4.0);
                    break;
                case 2:
                    sample2 = osc2.sinewave(frequency / 4.0);
                    break;
                case 3:
                    sample2 = osc2.triangle(frequency / 4.0);
                    break;
                case 4:
                    sample2 = osc2.noise();
                    break;
                default:
                    sample2 = osc2.sinewave(frequency / 4.0);
                    break;
            }
            switch (theWave3) {
            case 0:
                sample3 = osc3.saw(frequency);
                break;
            case 1:
                sample3 = osc3.square(frequency);
                break;
            case 2:
                sample3 = osc3.sinewave(frequency);
                break;
            case 3:
                sample3 = osc3.triangle(frequency);
                break;
            case 4:
                sample3 = osc3.noise();
                break;
            default:
                sample3 = osc3.sinewave(frequency);
                break;
            }
            return sample1 + osc2blend * sample2 + osc3blend * sample3;
        }
        void setBlendParam(float* blend2, float* blend3) {
            osc2blend = *blend2;
            osc3blend = *blend3;
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
            noteNumber = midiNoteNumber;
            env1.trigger = 1;
            setPitchBend(currentPitchWheelPosition);
            frequency = noteHz(noteNumber, pitchBendCents());
            level = velocity;
        }
        void stopNote(float velocity, bool allowTailOff) override {
            env1.trigger = 0;
            allowTailOff = true;
            if (velocity == 0) {
                clearCurrentNote();
            }
        }
        void pitchWheelMoved(int newPitchWheelValue) override {
            setPitchBend(newPitchWheelValue);
            frequency = noteHz(noteNumber, pitchBendCents());
        }
        void controllerMoved(int controllerNumber, int newControllerValue) override {}

        void renderNextBlock(AudioBuffer<float> &outputBuffer, int startSample, int numSamples) override {
            env1.setDecay(500);
            env1.setSustain(0.8);
            for (int sample = 0; sample < numSamples; ++sample) {
                //double filteredSound = filter1.lores(theSound, 100, 0.1);
                for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel) {
                    outputBuffer.addSample(channel, startSample, setEnvelope() * masterGain);
                }
                ++startSample;
            }
        }
    private:
        float masterGain;
        float pitchBend = 0.0f;
        float pitchBendUpSemitones = 2.0f;
        float pitchBendDownSemitones = 2.0f;
        int noteNumber;

        double level;
        double frequency;

        int theWave, theWave2, theWave3;
        float osc2blend, osc3blend;

        float filterChoice;
        float cutoff;
        float resonance;

        maxiOsc osc1, osc2, osc3;
        maxiEnv env1;
        maxiFilter filter1;
};

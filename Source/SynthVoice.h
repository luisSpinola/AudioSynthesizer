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
                pitchBend = float(pitchWheelPos - 8192) / (16383 - 8192);
            }
            else {
                pitchBend = float(8192 - pitchWheelPos) / -8192;
            }
        }
        float pitchBendCents() {
            if (pitchBend >= 0.0f) {
                return pitchBend * pitchBendUpSemitones * 100;
            }
            else {
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
        void setOsc4Type(float* selection) {
            theWave4 = *selection;
        }
        void setOsc5Type(float* selection) {
            theWave5 = *selection;
        }
        void setOsc6Type(float* selection) {
            theWave6 = *selection;
        }
        void setFrequency1(float* selection1, float* selection2, float* selection3, float* selection4, float* selection5, float* selection6) {
            frequency1 = *selection1;
            frequency2 = *selection2;
            frequency3 = *selection3;
            frequency4 = *selection4;
            frequency5 = *selection5;
            frequency6 = *selection6;
        }
        double setOscType() {
            double sample1, sample2, sample3, sample4, sample5, sample6;
            double div1 = 1, div2 = 1, div3 = 1, div4 = 1, div5 = 1, div6 = 1;
            switch (frequency1){
                case 0: div1 = 1; break;
                case 1: div1 = 2; break;
                case 2: div1 = 4; break;
                case 3: div1 = 8; break;
                default: div1 = 1; break;
            }
            switch (frequency2) {
                case 0: div2 = 1; break;
                case 1: div2 = 2; break;
                case 2: div2 = 4; break;
                case 3: div2 = 8; break;
                default: div2 = 1; break;
            }
            switch (frequency3) {
                case 0: div3 = 1; break;
                case 1: div3 = 2; break;
                case 2: div3 = 4; break;
                case 3: div3 = 8; break;
                default: div3 = 1; break;
            }
            switch (frequency4) {
                case 0: div4 = 1; break;
                case 1: div4 = 2; break;
                case 2: div4 = 4; break;
                case 3: div4 = 8; break;
                default: div4 = 1; break;
            }
            switch (frequency5) {
                case 0: div5 = 1; break;
                case 1: div5 = 2; break;
                case 2: div5 = 4; break;
                case 3: div5 = 8; break;
                default: div5 = 1; break;
            }
            switch(frequency6) {
                case 0: div6 = 1; break;
                case 1: div6 = 2; break;
                case 2: div6 = 4; break;
                case 3: div6 = 8; break;
                default: div6 = 1; break;
            }
            switch (theWave) {
                case 0: sample1 = osc1.square(frequency / div1); break;
                case 1: sample1 = osc1.saw(frequency / div1); break;
                case 2: sample1 = osc1.sinewave(frequency / div1); break;
                case 3: sample1 = osc1.triangle(frequency / div1); break;
                case 4: sample1 = osc1.noise(); break;
                default: sample1 = osc1.sinewave(frequency / div1); break;
            }
            switch (theWave2) {
                case 0: sample2 = osc2.saw(frequency / div2); break;
                case 1: sample2 = osc2.square(frequency / div2); break;
                case 2: sample2 = osc2.sinewave(frequency / div2); break;
                case 3: sample2 = osc2.triangle(frequency / div2); break;
                case 4: sample2 = osc2.noise(); break;
                default: sample2 = osc2.sinewave(frequency / div2); break;
            }
            switch (theWave3) { 
                case 0: sample3 = osc3.saw(frequency / div3);  break;
                case 1: sample3 = osc3.square(frequency / div3); break;
                case 2: sample3 = osc3.sinewave(frequency / div3); break;
                case 3: sample3 = osc3.triangle(frequency / div3); break;
                case 4: sample3 = osc3.noise(); break;
                default: sample3 = osc3.sinewave(frequency / div3); break;
            }
            switch (theWave4) {
                case 0: sample4 = osc4.saw(frequency / div4);  break;
                case 1: sample4 = osc4.square(frequency / div4); break;
                case 2: sample4 = osc4.sinewave(frequency / div4); break;
                case 3: sample4 = osc4.triangle(frequency / div4); break;
                case 4: sample4 = osc4.noise(); break;
                default: sample4 = osc4.sinewave(frequency / div4); break;
            }
            switch (theWave5) {
                case 0: sample5 = osc5.saw(frequency / div5);  break;
                case 1: sample5 = osc5.square(frequency / div5); break;
                case 2: sample5 = osc5.sinewave(frequency / div5); break;
                case 3: sample5 = osc5.triangle(frequency / div5); break;
                case 4: sample5 = osc5.noise(); break;
                default: sample5 = osc5.sinewave(frequency / div5); break;
            }
            switch (theWave6) {
                case 0: sample6 = osc6.saw(frequency / div6);  break;
                case 1: sample6 = osc6.square(frequency / div6); break;
                case 2: sample6 = osc6.sinewave(frequency / div6); break;
                case 3: sample6 = osc6.triangle(frequency / div6); break;
                case 4: sample6 = osc6.noise(); break;
                default: sample6 = osc6.sinewave(frequency / div6); break;
            }
            return sample1 + (osc2blend * sample2) + (osc3blend * sample3) + (osc4blend * sample4) + (osc5blend * sample5) + (osc6blend * sample6);
        }
        void setBlendParam(float* blend2, float* blend3, float* blend4,float* blend5 ,float* blend6) {
            osc2blend = *blend2;
            osc3blend = *blend3;
            osc4blend = *blend4;
            osc5blend = *blend5;
            osc6blend = *blend6;
        }

        //ENVELOPE
        void getEnvelopeParam(float* attack, float* release, float* sustain, float* decay) {
            env1.setAttack(double(*attack));
            env1.setRelease(double(*release));
            env1.setSustain(double(*sustain));
            env1.setDecay(double(*decay));
        }
        double getEnvelope() {
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
                return filter1.lores(getEnvelope(), cutoff, resonance);
            }
            else if (filterChoice == 1) {
                return filter1.hires(getEnvelope(), cutoff, resonance);
            }
            else if (filterChoice == 2) {
                return filter1.bandpass(getEnvelope(), cutoff, resonance);
            }
            else {
                return filter1.lores(getEnvelope(), cutoff, resonance);
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
            //env1.setDecay(500);
            //env1.setSustain(0.8);
            for (int sample = 0; sample < numSamples; ++sample) {
                //double filteredSound = filter1.lores(theSound, 100, 0.1);
                for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel) {
                    outputBuffer.addSample(channel, startSample, getEnvelope() * masterGain);
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

        int theWave, theWave2, theWave3, theWave4, theWave5, theWave6;
        float osc2blend, osc3blend, osc4blend, osc5blend, osc6blend;
        int frequency1, frequency2, frequency3, frequency4, frequency5, frequency6;

        float filterChoice;
        float cutoff;
        float resonance;

        maxiOsc osc1, osc2, osc3, osc4, osc5, osc6;
        maxiEnv env1;
        maxiFilter filter1;
};

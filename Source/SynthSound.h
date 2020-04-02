/*
  ==============================================================================

    SynthSound.h
    Created: 27 Mar 2020 2:34:13am
    Author:  DaSno

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SynthSound : public SynthesiserSound {
    public:
        bool appliesToNote(int /*midiNoteNumber*/) override { return true; }
        bool appliesToChannel(int /*midiChannel*/) override { return true; }
};

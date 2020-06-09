/*
  ==============================================================================

    NoteAndVelocityTest.h
    Created: 29 May 2020 1:25:51pm
    Author:  Taras A. Palczynski III

  ==============================================================================
*/

#pragma once

#include "MIDIEnviromentTest.h"

class NoteAndVelocityTest : public MIDIEnviromentTest
{
public:
    /// Construct the data needed for the Note and Velocity test.
    /// @param channel Channel is from 1 to 16 (for notes).
    NoteAndVelocityTest(int channel);
};

/*
  ==============================================================================

    TransitionCurve.h
    Created: 13 Apr 2020 4:44:03pm
    Author:  Taras A. Palczynski III

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class TransitionCurve
{
public:
    void setTransition(float transition);
    float evaluate(float xPosition);
    
private:
    int horizontalMargin = 40;
    int verticalMargin = 40;
    
    Path internalPath;
};

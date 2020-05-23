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
    TransitionCurve();
    
    void setTransition(float newTransition);
    void setMidpoint(float newPercentage);
    float evaluate(float xPosition);
    
    Point<float> startPoint;
    Point<float> cubicStartPoint;
    Point<float> cubicWeightLeft;
    Point<float> cubicWeightRight;
    Point<float> cubicEndPoint;
    Point<float> endPoint;
    
private:
    void updateCurve();
    
    float transition;
    float midpoint;
    
    Path internalPath;
    Line<float> evaluationLine;
};

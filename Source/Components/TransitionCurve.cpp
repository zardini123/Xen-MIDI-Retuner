/*
  ==============================================================================

    TransitionCurve.cpp
    Created: 13 Apr 2020 4:44:03pm
    Author:  Taras A. Palczynski III

  ==============================================================================
*/

#include "TransitionCurve.h"

TransitionCurve::TransitionCurve()
{
    setTransition(0.0f);
    setMidpoint(0.5f);
}

void TransitionCurve::setTransition(float newTransition)
{
    transition = newTransition;
    updateCurve();
}

void TransitionCurve::setMidpoint(float newPercentage)
{
    midpoint = newPercentage;
    updateCurve();
}

float TransitionCurve::evaluate(float xPercent)
{
    evaluationLine.setStart(xPercent, 0.0f);
    evaluationLine.setEnd(xPercent, 1.0f);

    PathFlatteningIterator i (internalPath);

    Point<float> intersectionPoint;
    while (i.next())
    {
        const Line<float> line (i.x1, i.y1, i.x2, i.y2);

        bool intersected = line.intersects(evaluationLine, intersectionPoint);

        if (intersected) break;
    }

    // Points origin is top left (0,0), but highest point should return a range of [0,1], not [1,0].
    float evaluation = jmap(intersectionPoint.y, 0.0f, 1.0f, 1.0f, 0.0f);

    return evaluation;
}

void TransitionCurve::updateCurve()
{
    float cubicEnd = 0.75f;
    float transitionCapped = jlimit(0.0f, cubicEnd, transition);
    float transitionToStraight = jlimit(cubicEnd, 1.0f, transition);

    internalPath.clear();
    
    // (0, 0) is top left
    // (0, 1) is bottom left
    startPoint = Point<float>(0.0f, 1.0f);
    internalPath.startNewSubPath(startPoint);

    cubicStartPoint = Point<float>(jmap(transitionCapped, cubicEnd, 0.0f, 0.0f, midpoint), 1.0f);
    internalPath.lineTo(cubicStartPoint);
    
    cubicWeightLeft = Point<float>(jmap(transitionToStraight, cubicEnd, 1.0f, midpoint, 0.0f), 1.0f);
    cubicWeightRight = Point<float>(jmap(transitionToStraight, cubicEnd, 1.0f, midpoint, 1.0f), 0.0f);
    cubicEndPoint = Point<float>(jmap(transitionCapped, cubicEnd, 0.0f, 1.0f, midpoint), 0.0f);
    internalPath.cubicTo(cubicWeightLeft, cubicWeightRight, cubicEndPoint);

    endPoint = Point<float>(1.0f, 0.0f);
    internalPath.lineTo (endPoint);
}

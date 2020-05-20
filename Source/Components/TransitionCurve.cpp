/*
  ==============================================================================

    TransitionCurve.cpp
    Created: 13 Apr 2020 4:44:03pm
    Author:  Taras A. Palczynski III

  ==============================================================================
*/

#include "TransitionCurve.h"

void TransitionCurve::setTransition(float transition)
{
    float cubicEnd = 0.75f;
    float transitionCapped = jlimit(0.0f, cubicEnd, transition);
    float transitionToStraight = jlimit(cubicEnd, 1.0f, transition);

    internalPath.clear();

    // TODO: REVIEW: Does these Point<float>'s get properly deallocated once the function ends?
    Point<float> *startPoint = new Point<float>(horizontalMargin, proportionOfHeight (1.0000f) - verticalMargin);
    internalPath.startNewSubPath(*startPoint);

    Point<float> *cubicStartPoint = new Point<float>(jmap(transitionCapped, cubicEnd, 0.0f, (float)horizontalMargin, (float)proportionOfWidth(0.5f)), proportionOfHeight (1.0000f) - verticalMargin);
    internalPath.lineTo(*cubicStartPoint);

    Point<float> *cubicWeightLeft = new Point<float>(jmap(transitionToStraight, cubicEnd, 1.0f, (float)proportionOfWidth (0.5000f), (float)horizontalMargin), proportionOfHeight (1.0000f) - verticalMargin);
    Point<float> *cubicWeightRight = new Point<float>(jmap(transitionToStraight, cubicEnd, 1.0f, (float)proportionOfWidth (0.5000f), (float)proportionOfWidth(1.0f) - horizontalMargin), verticalMargin);
    Point<float> *lineRightStart = new Point<float>(jmap(transitionCapped, cubicEnd, 0.0f, (float)proportionOfWidth(1.0f) - horizontalMargin, (float)proportionOfWidth(0.5f)), verticalMargin);
    internalPath.cubicTo(*cubicWeightLeft, *cubicWeightRight, *lineRightStart);

    Point<float> *lineRightEnd = new Point<float>(getWidth() - horizontalMargin, verticalMargin);
    internalPath.lineTo (*lineRightEnd);

    repaint();
}

float TransitionCurve::evaluate(float xPercent)
{
    float lineXPoint = jmap(xPercent, 0.0f, 1.0f, (float)horizontalMargin, (float)proportionOfWidth(1.0f) - horizontalMargin);
    evaluationLine.setStart(lineXPoint, verticalMargin);
    evaluationLine.setEnd(lineXPoint, proportionOfHeight(1.0f) - verticalMargin);

    PathFlatteningIterator i (internalPath1);

    Point<float> intersectionPoint;
    while (i.next())
    {
        const Line<float> line (i.x1, i.y1, i.x2, i.y2);

        bool intersected = line.intersects(evaluationLine, intersectionPoint);

        if (intersected) break;
    }

    // Points origin is top left, but highest point should return 1.0f, not 0.0f.
    float evaluation = jmap(intersectionPoint.y, (float)verticalMargin, (float)proportionOfHeight(1.0f) - verticalMargin, 1.0f, 0.0f);

    return evaluation;
}

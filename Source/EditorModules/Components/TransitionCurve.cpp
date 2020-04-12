/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.7

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "TransitionCurve.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TransitionCurve::TransitionCurve ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

TransitionCurve::~TransitionCurve()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TransitionCurve::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    {
        float x = 0, y = 0;
        Colour strokeColour = Colour (0xffa52a8d);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.strokePath (internalPath1, PathStrokeType (5.000f, PathStrokeType::curved, PathStrokeType::rounded), AffineTransform::translation(x, y));
    }
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TransitionCurve::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    setTransition(0.0f);
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void TransitionCurve::setTransition(float transition)
{
    float cubicEnd = 0.75f;
    float transitionCapped = jlimit(0.0f, cubicEnd, transition);
    float transitionToStraight = jlimit(cubicEnd, 1.0f, transition);

    internalPath1.clear();

    // TODO: REVIEW: Does these Point<float>'s get properly deallocated once the function ends?
    Point<float> *startPoint = new Point<float>(horizontalMargin, proportionOfHeight (1.0000f) - verticalMargin);
    internalPath1.startNewSubPath(*startPoint);

    Point<float> *cubicStartPoint = new Point<float>(jmap(transitionCapped, cubicEnd, 0.0f, (float)horizontalMargin, (float)proportionOfWidth(0.5f)), proportionOfHeight (1.0000f) - verticalMargin);
    internalPath1.lineTo(*cubicStartPoint);

    Point<float> *cubicWeightLeft = new Point<float>(jmap(transitionToStraight, cubicEnd, 1.0f, (float)proportionOfWidth (0.5000f), (float)horizontalMargin), proportionOfHeight (1.0000f) - verticalMargin);
    Point<float> *cubicWeightRight = new Point<float>(jmap(transitionToStraight, cubicEnd, 1.0f, (float)proportionOfWidth (0.5000f), (float)proportionOfWidth(1.0f) - horizontalMargin), verticalMargin);
    Point<float> *lineRightStart = new Point<float>(jmap(transitionCapped, cubicEnd, 0.0f, (float)proportionOfWidth(1.0f) - horizontalMargin, (float)proportionOfWidth(0.5f)), verticalMargin);
    internalPath1.cubicTo(*cubicWeightLeft, *cubicWeightRight, *lineRightStart);

    Point<float> *lineRightEnd = new Point<float>(getWidth() - horizontalMargin, verticalMargin);
    internalPath1.lineTo (*lineRightEnd);

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
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TransitionCurve" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="323e44"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


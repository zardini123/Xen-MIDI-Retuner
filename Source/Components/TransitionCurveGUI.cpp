/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "TransitionCurveGUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TransitionCurveGUI::TransitionCurveGUI (TransitionCurve *transitionCurve)
{
    //[Constructor_pre] You can add your own custom stuff here..
    curve = transitionCurve;
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

TransitionCurveGUI::~TransitionCurveGUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TransitionCurveGUI::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    internalPath.clear();

    // (0, 0) is top left
    // (0, 1) is bottom left
    internalPath.startNewSubPath(convertPercentsToPixels(curve->startPoint));
    internalPath.lineTo(convertPercentsToPixels(curve->cubicStartPoint));

    internalPath.cubicTo(convertPercentsToPixels(curve->cubicWeightLeft), convertPercentsToPixels(curve->cubicWeightRight), convertPercentsToPixels(curve->cubicEndPoint));

    internalPath.lineTo (convertPercentsToPixels(curve->endPoint));

    {
        float x = 0, y = 0;
        Colour strokeColour = Colour (0xffa52a8d);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.strokePath (internalPath, PathStrokeType (5.000f, PathStrokeType::curved, PathStrokeType::rounded), AffineTransform::translation(x, y));
    }
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TransitionCurveGUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
Point<float> TransitionCurveGUI::convertPercentsToPixels(Point<float> percentsPoint)
{
    return Point<float>(jmap(percentsPoint.x, 0.0f, 1.0f, (float)horizontalMargin, (float)(getWidth() - horizontalMargin)),
                        jmap(percentsPoint.y, 0.0f, 1.0f, (float)verticalMargin, (float)(getHeight() - verticalMargin)));
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TransitionCurveGUI" componentName=""
                 parentClasses="public Component" constructorParams="TransitionCurve *transitionCurve"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="323e44"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


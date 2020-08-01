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

#include "ActionButtonAndStatus.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
ActionButtonAndStatus::ActionButtonAndStatus(ProcessorData *dataReference, MIDIEnviromentTestType testType, MIDIEnviromentTestOperationType operationType) : ActionButtonAndStatus(dataReference)
{
    testID.testType = testType;
    testID.operationType = operationType;
    testID.midiChannel = 1;

    data->midiEnviromentTestManager.addSubscriberToTestChange(testID, this);
}
//[/MiscUserDefs]

//==============================================================================
ActionButtonAndStatus::ActionButtonAndStatus (ProcessorData *dataReference)
    : ComponentWithReferenceToData (dataReference)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    actionButton.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (actionButton.get());
    actionButton->setButtonText (TRANS("<action name>"));
    actionButton->addListener (this);

    statusBar.reset (new ProgressBar (progress));
    addAndMakeVisible (statusBar.get());
    statusBar->setName ("new component");


    //[UserPreSize]
    statusBar->setTextToDisplay(TRANS("<status>"));
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ActionButtonAndStatus::~ActionButtonAndStatus()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    actionButton = nullptr;
    statusBar = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ActionButtonAndStatus::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ActionButtonAndStatus::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    actionButton->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.0000f), proportionOfWidth (0.5004f), proportionOfHeight (1.0000f));
    statusBar->setBounds (proportionOfWidth (0.5004f), proportionOfHeight (0.0000f), proportionOfWidth (0.5004f), proportionOfHeight (1.0000f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ActionButtonAndStatus::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == actionButton.get())
    {
        //[UserButtonCode_actionButton] -- add your button handler code here..
        MIDIEnviromentTestManager *manager = &data->midiEnviromentTestManager;

        const void * address = static_cast<const void*>(&data->midiEnviromentTestManager.testEntryMap[testID].theTest.allUniqueMessages);
        std::stringstream ss;
        ss << address;
        std::string name = ss.str();

        int ret = manager->addBroadcastingTestToQueueWithListenerDoppelganger(testID);
        //[/UserButtonCode_actionButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ActionButtonAndStatus::changeListenerCallback(ChangeBroadcaster *source)
{
    MIDIEnviromentTestManager *manager = &data->midiEnviromentTestManager;

    {
        const ScopedLock scopedLock (manager->entryMapLock);

        MIDIEnviromentTestEntry *entry = &manager->testEntryMap[testID];
        setStatus(entry->status, entry->progress);
    }
}

void ActionButtonAndStatus::attachListenerToActionButton(Button::Listener *theListener)
{
    actionButton->addListener(theListener);
}

void ActionButtonAndStatus::setActionName(std::string action)
{
    actionButton->setButtonText(TRANS(action));
}

void ActionButtonAndStatus::setStatus(Status status, double percentage)
{
//    statusBar->setTooltip(TRANS(status));

    std::string statusText = "";
    Colour statusColour;
    switch(status)
    {
        case IN_QUEUE:
            statusText = "In Queue";
            break;
        case RUNNING:
            statusText = "Running...";
            break;
        case DONE:
            statusText = "Done";
            break;
        case FAILED:
            statusText = "Failed";
            break;
        case TIMEOUT:
            statusText = "Timeout";
            break;
    }
    statusBar->setTextToDisplay(TRANS(statusText + " " + std::to_string((int)(percentage * 100))));

    actionButton->setButtonText(std::to_string(data->midiEnviromentTestManager.testEntryMap[testID].theTest.allUniqueMessages.size()) + "/" + std::to_string(data->midiEnviromentTestManager.testEntryMap[testID].theTest.initalUniqueMessageCount));

    std::string test = "";
    if (status == TIMEOUT)
    {
        for (auto it = data->midiEnviromentTestManager.testEntryMap[testID].theTest.allUniqueMessages.begin(); it != data->midiEnviromentTestManager.testEntryMap[testID].theTest.allUniqueMessages.end(); ++it )
        {
            test += it->getDescription().toStdString() + " ";
        }
    }

    actionButton->setButtonText(test);

    progress = percentage;

//    statusBar->setColour (Label::backgroundColourId, color);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ActionButtonAndStatus" componentName=""
                 parentClasses="public ComponentWithReferenceToData, public ChangeListener"
                 constructorParams="ProcessorData *dataReference" variableInitialisers="ComponentWithReferenceToData (dataReference)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <TEXTBUTTON name="new button" id="747d04c3852ec15e" memberName="actionButton"
              virtualName="" explicitFocusOrder="0" pos="0% 0% 50.043% 100%"
              buttonText="&lt;action name&gt;" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <GENERICCOMPONENT name="new component" id="ddfbc579fc8ae26b" memberName="statusBar"
                    virtualName="" explicitFocusOrder="0" pos="50.043% 0% 50.043% 100%"
                    class="ProgressBar" params="progress"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


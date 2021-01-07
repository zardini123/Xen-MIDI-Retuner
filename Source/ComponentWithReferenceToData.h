/*
  ==============================================================================

    ComponentWithReferenceToData.h
    Created: 12 Jul 2020 3:12:49pm
    Author:  Taras A. Palczynski III

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "ProcessorData.h"

class ComponentWithReferenceToData : public Component
{
public:
    ComponentWithReferenceToData(ProcessorData *dataReference);
    
protected:
    ProcessorData *data;
};

/*
  ==============================================================================

    ComponentWithReferenceToData.h
    Created: 12 Jul 2020 3:12:49pm
    Author:  Taras A. Palczynski III

  ==============================================================================
*/

#pragma once

#include "ProcessorData.h"

#include <JuceHeader.h>

class ComponentWithReferenceToData : public Component {
public:
  ComponentWithReferenceToData(ProcessorData *dataReference) : data{dataReference} {}

protected:
  ProcessorData *data;
};

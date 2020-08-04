/*
  ==============================================================================

    ComponentWithReferenceToData.cpp
    Created: 12 Jul 2020 3:12:49pm
    Author:  Taras A. Palczynski III

  ==============================================================================
*/

#include "ComponentWithReferenceToData.h"

ComponentWithReferenceToData::ComponentWithReferenceToData(ProcessorData *dataReference)
{
    data = dataReference;
}

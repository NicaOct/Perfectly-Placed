#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "HouseholdObject.h"
#include "ObjectType.h"
#include <memory>


std::shared_ptr<HouseholdObject> makeObjectFactory(ObjectType type);

#endif // OBJECTFACTORY_H

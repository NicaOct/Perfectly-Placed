#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "HouseholdObject.h"
#include "ObjectType.h"
#include <memory>

/**
 * @file ObjectFactory.h
 * @brief Factory design pattern implementation for creating `HouseholdObject` instances.
 */


std::shared_ptr<HouseholdObject> makeObjectFactory(ObjectType type);

#endif // OBJECTFACTORY_H

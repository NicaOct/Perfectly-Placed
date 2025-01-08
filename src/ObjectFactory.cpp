#include "../headers/ObjectFactory.h"
#include "../headers/Painting.h"
#include "../headers/Pencil.h"
std::shared_ptr<HouseholdObject> makeObjectFactory(ObjectType type) {
    if (type == ObjectType::Painting) {
        return std::make_shared<Painting>();
    }
    if (type == ObjectType::Pencil) {
        return std::make_shared<Pencil>();
    }

    return nullptr;
}

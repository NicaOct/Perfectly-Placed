#include "raylib.h"
#include "../headers/Painting.h"
#include "../headers/TextLoadException.h"

Painting::Painting()
    : HouseholdObject({100.0f, 100.0f})
{
    texture = LoadTexture("../resources/textures/Painting.jpg");
}

std::unique_ptr<HouseholdObject> Painting::clone() const {
    return std::make_unique<Painting>(*this);
};

void Painting::LoadText() {
    texture = LoadTexture("../resources/textures/Painting.png");
    if (texture.id == 0) {
        throw TextLoadException("../resources/textures/Painting.png");
    }
}

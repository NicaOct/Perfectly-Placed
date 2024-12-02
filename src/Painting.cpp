#include "raylib.h"
#include "../headers/Painting.h"

Painting::Painting()
    : HouseholdObject({100.0f, 100.0f})
{
    texture = LoadTexture("../resources/textures/Painting.png");
}

std::unique_ptr<HouseholdObject> Painting::clone() const {
    return std::make_unique<Painting>(*this);
};

void Painting::LoadText() {
    texture = LoadTexture("../resources/textures/Painting.png");
}

#include "../headers/Pencil.h"

Pencil::Pencil()
    : HouseholdObject({200.0f, 150.0f})
{
    texture = LoadTexture("../resources/textures/Pencil.png");
}
std::unique_ptr<HouseholdObject> Pencil::clone() const {
    return std::make_unique<Pencil>(*this);
}
void Pencil::LoadText() {
    texture = LoadTexture("../resources/textures/Painting.png");
}

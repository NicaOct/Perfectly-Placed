#include <iostream>
#include "raylib.h"
#include "../headers/HouseholdObject.h"

int HouseholdObject::objectCount = 0;

HouseholdObject::HouseholdObject(Vector2 initPosition)
    : position(initPosition), texture{} {
    objectCount++;
}

HouseholdObject::~HouseholdObject() {
    UnloadTexture(texture);
    objectCount--;
}

void HouseholdObject::Draw() {
    LoadText();
    DrawTexture(texture, static_cast<int>(position.x), static_cast<int>(position.y), WHITE);
}

Rectangle HouseholdObject::GetRect() const {
    return Rectangle{position.x, position.y, static_cast<float>(texture.width), static_cast<float>(texture.height)};
}

void HouseholdObject::DrawHitBox(bool isColliding) const {
    if (isColliding) {
        DrawRectangleLinesEx(GetRect(), 3, RED);
    }
}

int HouseholdObject::GetObjectCount() {
    return objectCount;
}

Vector2 HouseholdObject::GetPosition() const {
    return position;
}

void HouseholdObject::SetPosition(Vector2 newPosition) {
    position = newPosition;
}

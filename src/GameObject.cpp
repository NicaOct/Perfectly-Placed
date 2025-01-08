#include "../headers/GameObject.h"

GameObject::GameObject(Vector2 pos, Vector2 sz, Color clr)
    : position(pos), size(sz), color(clr) {}

void GameObject::Draw() const {
    DrawRectangleV(position, size, color);
}

bool GameObject::IsMouseOver() const {
    Vector2 mouse = GetMousePosition();
    Rectangle rect = { position.x, position.y, size.x, size.y };
    return CheckCollisionPointRec(mouse, rect);
}

bool GameObject::CheckPlacement(Rectangle targetZone) const {
    Rectangle rect = { position.x, position.y, size.x, size.y };
    return CheckCollisionRecs(rect, targetZone);
}

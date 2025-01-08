#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "raylib.h"

class GameObject {
public:
    Vector2 position;
    Vector2 size;
    Color color;

    GameObject(Vector2 pos, Vector2 sz, Color clr);

    void Draw() const;
    bool IsMouseOver() const;
    bool CheckPlacement(Rectangle targetZone) const;
};

#endif //GAMEOBJECT_H
#ifndef HOUSEHOLDOBJECT_H
#define HOUSEHOLDOBJECT_H

#include "raylib.h"
#include <memory>

class HouseholdObject {
public:
    static int objectCount;

    explicit HouseholdObject(Vector2 initPosition);
    virtual ~HouseholdObject();

    [[nodiscard]] virtual std::unique_ptr<HouseholdObject> clone() const = 0;
    void Draw();
    virtual void LoadText() = 0;
    [[nodiscard]] Rectangle GetRect() const;
    void DrawHitBox(bool isColliding) const;
    static int GetObjectCount();

protected:
    static int objecCount;
    Vector2 position;
    Texture2D texture;
};

#endif // HOUSEHOLDOBJECT_H

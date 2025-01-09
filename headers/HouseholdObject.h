#ifndef HOUSEHOLDOBJECT_H
#define HOUSEHOLDOBJECT_H

#include "raylib.h"
#include <memory>

/**
 * @file HouseholdObject.h
 * @brief Defines the abstract base class for household objects in the game.
 */

/**
 * @class HouseholdObject
 * @brief Represents a generic household object with position, texture, and behaviors.
 */

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

    [[nodiscard]] Vector2 GetPosition() const;
    void SetPosition(Vector2 newPosition);

protected:
    Vector2 position;
    Texture2D texture;
};

#endif // HOUSEHOLDOBJECT_H

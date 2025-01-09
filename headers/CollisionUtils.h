#ifndef COLLISIONUTILS_H
#define COLLISIONUTILS_H

#include "HouseholdObject.h"
#include "raylib.h"
#include <type_traits>

template <typename T1, typename T2>
bool CheckCollision(const T1& obj1, const T2& obj2) {
    // Check if the two objects are derived from HouseholdObject
    static_assert(std::is_base_of_v<HouseholdObject, T1>, "T1 must derive from HouseholdObject");
    static_assert(std::is_base_of_v<HouseholdObject, T2>, "T2 must derive from HouseholdObject");

    return CheckCollisionRecs(obj1.GetRect(), obj2.GetRect());
}

#endif // COLLISIONUTILS_H

#ifndef PENCIL_H
#define PENCIL_H

#include "../headers/HouseholdObject.h"

/**
 * @file Pencil.h
 * @brief Defines the Pencil class, which is derived from HouseholdObject.
 *
 * This file contains the class `Pencil`, which represents a type of HouseholdObject.
 */

/**
 * @class Pencil
 * @brief Derived class from HouseholdObject representing what it was initially a pencil.
 *
 * The `Pencil` class extends the `HouseholdObject` class and provides implementations
 * for cloning and loading data specific to pencils.
 */

class Pencil : public HouseholdObject {
public:
    Pencil();
    ~Pencil() override = default;

    [[nodiscard]] std::unique_ptr<HouseholdObject> clone() const override;
    void LoadText() override;
};

#endif //PENCIL_H

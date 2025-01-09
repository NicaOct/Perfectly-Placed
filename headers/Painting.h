#ifndef PAINTING_H
#define PAINTING_H

#include "HouseholdObject.h"

/**
 * @file Painting.h
 * @brief Defines the Painting class, which is derived from HouseholdObject.
 *
 * This file contains the class `Painting`, which represents a type of HouseholdObject.
 */

/**
 * @class Painting
 * @brief Derived class from HouseholdObject representing a painting.
 *
 * The `Painting` class extends the `HouseholdObject` class and provides implementations
 * for cloning and loading data specific to paintings.
 */

class Painting : public HouseholdObject {
public:
    Painting();
    ~Painting() override = default;

    [[nodiscard]] std::unique_ptr<HouseholdObject> clone() const override;
    void LoadText() override;
};

#endif // PAINTING_H

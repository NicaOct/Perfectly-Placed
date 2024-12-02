#ifndef PAINTING_H
#define PAINTING_H

#include "HouseholdObject.h"

class Painting : public HouseholdObject {
public:
    Painting();
    ~Painting() override = default;

    [[nodiscard]] std::unique_ptr<HouseholdObject> clone() const override;
    void LoadText() override;
};

#endif // PAINTING_H

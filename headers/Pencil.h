#ifndef PENCIL_H
#define PENCIL_H

#include "../headers/HouseholdObject.h"

class Pencil : public HouseholdObject {
public:
    Pencil();
    ~Pencil() override = default;

    [[nodiscard]] std::unique_ptr<HouseholdObject> clone() const override;
    void LoadText() override;
};

#endif //PENCIL_H

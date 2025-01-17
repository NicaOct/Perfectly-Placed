//
// Created by Octavian on 12/2/2024.
//

#ifndef OBJECTALIGN_H
#define OBJECTALIGN_H
#include <iostream>
#include <utility>
#include "raylib.h"

class ObjectAlign {
private:
    std::string name;
    std::string description;
    Vector2 position;
    Vector2 correct;
    float tolerance;

public:
    ObjectAlign()
        : position({0, 0}), correct({0, 0}), tolerance(0.0f) {}

    ObjectAlign(std::string name, std::string description,
           float posX, float posY, float correctX, float correctY, float tolerance)
        : name(std::move(name)), description(std::move(description)),
          position({posX, posY}), correct({correctX, correctY}), tolerance(tolerance) {
        std::cout << "ObjectAlign created: " << this->name << "\n";
    }

    ~ObjectAlign() {
        std::cout << "ObjectAlign destroyed: " << this->name << "\n";
    }

    friend std::ostream &operator<<(std::ostream &out, const ObjectAlign &object) {
        out << "Name of the ObjectAlign: " << object.name;
        out << "\nDescription: " << object.description;
        return out;
    }

    [[nodiscard]]std::string getName() const { return this->name; }
    [[nodiscard]]std::string getDescription() const { return this->description; }
    [[nodiscard]] float getPositionX() const { return this->position.x; }
    [[nodiscard]] float getPositionY() const { return this->position.y; }
    [[nodiscard]] float getCorrectX() const { return this->correct.x; }
    [[nodiscard]] float getCorrectY() const { return this->correct.y; }
    [[nodiscard]] float getTolerance() const { return this->tolerance; }

    void setPositionX(float posX) { this->position.x = posX; }
    void setPositionY(float posY) { this->position.y = posY; }
    void setCorrectX(float correctX) { this->correct.x = correctX; }
    void setCorrectY(float correctY) { this->correct.y = correctY; }
    void setTolerance(float tolerance) { this->tolerance = tolerance; }

    ObjectAlign &operator=(const ObjectAlign &object) {
        if (this != &object) {
            this->name = object.name;
            this->description = object.description;
            this->position = object.position;
            this->correct = object.correct;
            this->tolerance = object.tolerance;
        }
        return *this;
    }

    void moveTo(float x, float y);

    [[nodiscard]] bool isInCorrectPosition() const {
        return (std::abs(position.x - correct.x) <= tolerance) &&
               (std::abs(position.y - correct.y) <= tolerance);
    }
    
    friend class Room;
    friend class Hand;
};
#endif //OBJECTALIGN_H

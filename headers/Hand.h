#ifndef HAND_H
#define HAND_H
#include <iostream>
#include "../headers/ObjectAlign.h"
class Hand {
private:
    int positionX;
    int positionY;
    Object* heldObject;
public:
    Hand()=default;
    ~Hand()=default;
    Hand(int positionX, int positionY) {  this->positionX = positionX; this->positionY = positionY; heldObject = nullptr; };
    [[nodiscard]] int getPositionX() const { return this->positionX; };
    [[nodiscard]] int getPositionY() const { return this->positionY; };
    void setPositionX(int m_positionX){this->positionX = m_positionX; };
    void setPositionY(int m_positionY){this->positionY = m_positionY; };
    void moveTo(int newX, int newY) {
        positionX = newX;
        positionY = newY;
        std::cout << "Moved hand to position (" << positionX << ", " << positionY << ")\n";
    }
    void grabObject(Object& obj) {
        if (heldObject == nullptr) {
            heldObject = &obj;
            std::cout << "Grabbed object: " << obj.name << "\n";
        } else {
            std::cout << "Already holding an object: " << heldObject->name << "\n";
        }
    }
    void releaseObject() {
        if (heldObject != nullptr) {
            heldObject->moveTo(positionX, positionY);
            std::cout << "Released object: " << heldObject->name << " at (" << positionX << ", " << positionY << ")\n";
            heldObject = nullptr;
        } else {
            std::cout << "No object to release\n";
        }
    }

};
#endif //HAND_H

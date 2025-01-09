#ifndef GAMENOTIFICATIONS_H
#define GAMENOTIFICATIONS_H

#include "Observer.h"
#include <iostream>

class PlacementNotification : public Observer {
public:
    void onNotify() override {
        std::cout << "Object placed correctly!" << std::endl;
    }
};

#endif // GAMENOTIFICATIONS_H

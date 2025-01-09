#ifndef GAMENOTIFICATIONS_H
#define GAMENOTIFICATIONS_H

#include "Observer.h"
#include <iostream>

/**
 * @file GameNotifications.h
 * @brief Contains notifications for in-game events.
 */

/**
 * @class PlacementNotification
 * @brief Notification class for handling object placement events.
 *
 * This class inherits from the `Observer` interface and provides functionality
 * to notify when an object is placed successfully.
 */

class PlacementNotification : public Observer {
public:
    void onNotify() override {
        std::cout << "Object placed perfectly!" << std::endl;
    }
};

#endif // GAMENOTIFICATIONS_H

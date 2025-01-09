#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>

/**
 * @file Observer.h
 * @brief Defines the Observer design pattern implementation.
 *
 * This file contains the base Observer class and the Subject class.
 */

/**
 * @class Observer
 * @brief Abstract base class for objects that need to be notified.
 *
 * The Observer class is used in the Observer design pattern, where objects (observers)
 * subscribe to a Subject and get notified when an event occurs.
 */

class Observer {
public:
    virtual void onNotify() = 0;
    virtual ~Observer() = default;
};

class Subject {
public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        std::erase(observers, observer);
    }

    void notifyObservers() {
        for (Observer* observer : observers) {
            observer->onNotify();
        }
    }

private:
    std::vector<Observer*> observers;
};

#endif // OBSERVER_H

#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>

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

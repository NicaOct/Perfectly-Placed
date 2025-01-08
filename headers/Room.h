#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <vector>
#include <bits/ranges_algo.h>

class Room {
private:
    std::string name;
    int difficulty;
    std::vector<Object> objects;
public:
    Room() {
        name = "";
        difficulty=0;
    }
    Room(const std::string &name, int difficulty) {
        this->name = name; this->difficulty = difficulty;
        std::cout<<"Room created "<<this->name<<"\n";
    };
    ~Room(){std::cout<<"Room destroyed: "<< this->name<<"\n";};
    std::string getName(){ return this->name; };
    [[nodiscard]] int getDifficulty() const { return this->difficulty; };
    void setName(const std::string &m_name){ this->name = m_name; };
    void setDifficulty(int m_difficulty){ this->difficulty = m_difficulty; };
    friend std::ostream &operator<<(std::ostream &out, const Room &room) {
        out <<"Name of the room: "<<room.name<<"\nDifficulty of the room: "<< room.difficulty<<"\n";
        return out;
    }
    Room &operator=(const Room &room) {
        this->name = room.name;
        this->difficulty = room.difficulty;
        return *this;
    }
    void addObject(const Object& obj) {
        objects.push_back(obj);
    }
    [[nodiscard]] bool isLevelComplete() const {
        return std::ranges::all_of(objects, [](const Object& obj) {
            return obj.isInCorrectPosition();
        });
    }

};

#endif //ROOM_H

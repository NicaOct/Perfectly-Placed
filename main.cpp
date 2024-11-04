#include <iostream>
#include <array>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

#include <Helper.h>

//////////////////////////////////////////////////////////////////////
/// NOTE: this include is needed for environment-specific fixes     //
/// You can remove this include and the call from main              //
/// if you have tested on all environments, and it works without it //
#include "env_fixes.h"                                              //
//////////////////////////////////////////////////////////////////////

#include <vector>


class Object {
    private:
        std::string name;
        std::string description;
        int positionX, positionY;
        int correctX, correctY;
        int tolerance;

    public:
        Object()=default;
        Object(std::string name, std::string description, int positionX, int positionY, int ceorrectX, int correctY, int tolerance){
            this->name=name; this->description=description; this->positionX=positionX; this->positionY=positionY;
            this->correctX=ceorrectX; this->correctY=correctY;this->correctY=correctY; this->tolerance=tolerance;
            std::cout<<"Object created "<< this->name<<"\n";
        };
        ~Object(){ std::cout<<"Object destroyed: "<< this->name<<"\n";};
        friend std::ostream &operator<<(std::ostream &out, const Object &object) {
            out<<"Name of the Object: "<<object.name;
            out<<"\nDescription: "<<object.description;
            return out;
        }
        std::string getName(){ return this->name; };
        std::string getDescription(){ return this->description; };
        int getpositionX(){ return this->positionX; };
        int getpositionY(){ return this->positionY; };
        int getcorrectX(){ return this->correctX; };
        int getcorrectY(){ return this->correctY; };
        int getTolerance(){ return this->tolerance;};
        void setName(std::string name){ this->name = name; };
        void setDescription(std::string description){ this->description = description; };
        void setpositionX(int positionX){this->positionX = positionX; };
        void setpositionY(int positionY){this->positionY = positionY; };
        void setcorrectX(int correctX){this->correctX=correctX;};
        void setcorrectY(int correctY){this->correctY=correctY;};
        void setTolerance(int tolerance){this->tolerance=tolerance;};
        Object &operator=(const Object &object) {
            this->name = object.name;
            this->description = object.description;
            this->positionX = object.positionX;
            this->positionY = object.positionY;
            return *this;
        }
        void moveTo(int x, int y) {
            positionX = x;
            positionY = y;
        }
        bool isInCorrectPosition() const {
            return (abs(positionX - correctX) <= tolerance) &&
                   (abs(positionY - correctY) <= tolerance);
        }
        friend class Room;
        friend class Hand;
    };

class Room {
private:
    std::string name;
    int difficulty;
    std::vector<Object> objects;
public:
    Room()=default;
    Room(std::string name, int difficulty) {
        this->name = name; this->difficulty = difficulty;
        std::cout<<"Room created "<<this->name<<"\n";
    };
    ~Room(){std::cout<<"Room destroyed: "<< this->name<<"\n";};
    const std::string getName(){ return this->name; };
     int getDifficulty(){ return this->difficulty; };
    void setName(std::string name){ this->name = name; };
    void setDifficulty(int difficulty){ this->difficulty = difficulty; };
    friend std::ostream &operator<<(std::ostream &out, const Room &room) {
        out <<"Name of the room: "<<room.name<<"\nDifficulty of the room: "<< room.difficulty<<"\n";
        //"It contains the object: "<<object.name <<"and the dinosaur: "<< dinosaur.species;
        return out;
    }
    Room &operator=(const Room &room) {
        this->name = room.name;
        this->difficulty = room.difficulty;
        return *this;
    }
    void addObject(Object &obj) {
        if(&obj!=nullptr) {
            objects.push_back(obj);
        }
        else std::cout<<"Cannot add null object\n";
    }
    bool isLevelComplete() const {
        for (const Object& obj : objects) {
            if (!obj.isInCorrectPosition()) {
                return false;
            }
        }
    }
};
class Hand {
    private:
    int positionX;
    int positionY;
    Object* heldObject;
    public:
    Hand()=default;
    ~Hand()=default;
    Hand(int positionX, int positionY) {  this->positionX = positionX; this->positionY = positionY; heldObject = nullptr; };
    int getPositionX(){ return this->positionX; };
    int getPositionY(){ return this->positionY; };
    void setPositionX(int positionX){this->positionX = positionX; };
    void setPositionY(int positionY){this->positionY = positionY; };
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

//////////////////////////////////////////////////////////////////////
/// This class is used to test that the memory leak checks work as expected even when using a GUI
class SomeClass {
public:
    explicit SomeClass(int) {}
};

SomeClass *getC() {
    return new SomeClass{2};
}
//////////////////////////////////////////////////////////////////////


int main() {
    ////////////////////////////////////////////////////////////////////////
    /// NOTE: this function call is needed for environment-specific fixes //
    init_threads();                                                       //
    ////////////////////////////////////////////////////////////////////////
    ///
    Room bedroom("Bedroom", 1);
    Object lamp("Lamp","When it is on it keeps the monsters at bay",10,50, 60,100, 20);
    Object diary("Diary","Your secrets won't stay hidden forever",10,10, 10, 10,50);
    bedroom.addObject(lamp);
    bedroom.addObject(diary);
    diary.setpositionX(0);
    diary.setcorrectX(100);
    lamp.setTolerance(5);
    lamp.setpositionY(120);
    if(bedroom.isLevelComplete())
        std::cout<<"Level completed\n";
    else
        std::cout<<"You failed\n";

    //lamp.moveTo(60,70);
    lamp.setpositionX(lamp.getpositionX()+50);
    lamp.setpositionY(lamp.getpositionY()+50);
    if(bedroom.isLevelComplete())
        std::cout<<"Level completed\n";
    else
        std::cout<<"You failed\n";
    Hand hand(0,0);
    hand.setPositionX(hand.getPositionX()+50);
    hand.releaseObject();
    hand.grabObject(lamp);
    hand.grabObject(diary);
    hand.releaseObject();
    ///////////////////////////////////////////////////////////////////////////
    /// Pentru date citite din fișier, NU folosiți tastatura.txt. Creați-vă voi
    /// alt fișier propriu cu ce alt nume doriți.
    /// Exemplu:
    /// std::ifstream fis("date.txt");
    /// for(int i = 0; i < nr2; ++i)
    ///     fis >> v2[i];
    ///
    ///////////////////////////////////////////////////////////////////////////
    ///                Exemplu de utilizare cod generat                     ///
    ///////////////////////////////////////////////////////////////////////////
    Helper helper;
    helper.help();
    ///////////////////////////////////////////////////////////////////////////

    SomeClass *c = getC();
    std::cout << c << "\n";
    delete c;

    sf::RenderWindow window;
    ///////////////////////////////////////////////////////////////////////////
    /// NOTE: sync with env variable APP_WINDOW from .github/workflows/cmake.yml:31
    window.create(sf::VideoMode({800, 700}), "My Window", sf::Style::Default);
    ///////////////////////////////////////////////////////////////////////////
    //
    ///////////////////////////////////////////////////////////////////////////
    /// NOTE: mandatory use one of vsync or FPS limit (not both)            ///
    /// This is needed so we do not burn the GPU                            ///
    window.setVerticalSyncEnabled(true);                                    ///
    /// window.setFramerateLimit(60);                                       ///
    ///////////////////////////////////////////////////////////////////////////

    while(window.isOpen()) {
        bool shouldExit = false;
        sf::Event e{};
        while(window.pollEvent(e)) {
            switch(e.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                std::cout << "New width: " << window.getSize().x << '\n'
                          << "New height: " << window.getSize().y << '\n';
                break;
            case sf::Event::KeyPressed:
                std::cout << "Received key " << (e.key.code == sf::Keyboard::X ? "X" : "(other)") << "\n";
                if(e.key.code == sf::Keyboard::Escape)
                    shouldExit = true;
                break;
            default:
                break;
            }
        }
        if(shouldExit) {
            window.close();
            break;
        }
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(300ms);

        window.clear();
        window.display();
    }
    return 0;
}

#include <iostream>

#include <chrono>

#include <Helper.h>

#include "./headers/Object.h"
#include "./headers/Hand.h"
#include "./headers/Room.h"
#include "./headers/Painting.h"
#include "raylib.h"

class SomeClass {
public:
    explicit SomeClass(int) {}
};

SomeClass *getC() {
    return new SomeClass{2};
}

int main() {
    Room bedroom("Bedroom", 1);
    Object lamp("Lamp","When it is on it keeps the monsters at bay",10,50, 60,100, 20);
    Object diary("Diary","Your secrets won't stay hidden forever",10,10, 10, 10,50);
    bedroom.addObject(lamp);
    bedroom.addObject(diary);
    diary.setPositionX(0);
    diary.setCorrectX(100);
    lamp.setTolerance(5);
    lamp.setPositionY(120);
    if(bedroom.isLevelComplete())
        std::cout<<"Level completed\n";
    else
        std::cout<<"You failed\n";

    //lamp.moveTo(60,70);
    lamp.setPositionX(lamp.getPositionX()+50);
    lamp.setPositionY(lamp.getPositionY()+50);
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

    constexpr int screenWidth = 1600;
    constexpr int screenHeight = 900;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "Start");

    Vector2 startPoint = { 100, 100 };
    Vector2 endPoint = { static_cast<float>(screenWidth) - 100, static_cast<float>(screenHeight) - 100 };
    bool moveStartPoint = false;
    bool moveEndPoint = false;

    SetTargetFPS(60);
    InitAudioDevice();

    Music StartMusic = LoadMusicStream("./resources/sounds/seagull.wav");
    if (!FileExists("./resources/sounds/seagull.wav")) {
        printf("File not found: resources/sounds/seagull.wav\n");
    } else {
        printf("File found! resources/sounds/seagull.wav\n");
    }
    Sound StartLoadSound = LoadSound("./resources/sounds/bee.wav");
    if (!FileExists("./resources/sounds/bee.wav")) {
        printf("File not found: resources/sounds/bee.wav\n");
    } else {
        printf("File found! resources/sounds/bee.wav\n");
    }
    PlayMusicStream(StartMusic);
    // Main game loop

    while (!WindowShouldClose())
    {
        // somewhat choose and pick: update game or use a function in a class regarding collisions with the correct position
        if(IsKeyPressed(KEY_SPACE)) {
            StopMusicStream(StartMusic);
            PlaySound(StartLoadSound);
        }
        Vector2 mouse = GetMousePosition();

        if (CheckCollisionPointCircle(mouse, startPoint, 50.0f) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) moveStartPoint = true;
        else if (CheckCollisionPointCircle(mouse, endPoint, 50.0f) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) moveEndPoint = true;

        if (moveStartPoint)
        {
            startPoint = mouse;
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) moveStartPoint = false;
        }
        if (moveEndPoint)
        {
            endPoint = mouse;
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) moveEndPoint = false;
        }
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("MOVE CIRCLES WITH MOUSE", screenWidth/2-300, screenHeight/2-100, 40, LIME);

            DrawCircleV(startPoint, CheckCollisionPointCircle(mouse, startPoint, 100.0f)? 30.0f : 20.0f, moveStartPoint? RED : BLUE);
            DrawCircleV(endPoint, CheckCollisionPointCircle(mouse, endPoint, 100.0f)? 30.0f : 20.0f, moveEndPoint? RED : BLUE);
            DrawCircleV(endPoint, CheckCollisionPointCircle(mouse, endPoint, 100.0f)? 30.0f : 20.0f, moveEndPoint? RED : BLUE);

        EndDrawing();
    }
    UnloadMusicStream(StartMusic);
    UnloadSound(StartLoadSound);
    CloseWindow();
    Helper helper;
    helper.help();
    return 0;
}

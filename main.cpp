#include <iostream>

#include <chrono>

#include <Helper.h>

//#include "./headers/Object.h"
//#include "./headers/Hand.h"
//#include "./headers/Room.h"
#include "./headers/HouseholdObject.h"
#include "./headers/Painting.h"
#include "./headers/Pencil.h"
#include "./headers/MyException.h"
#include "./headers/CollisionUtils.h"
#include "./headers/Observer.h"
#include "./headers/GameNotifications.h"
//#include "./headers/GameObject.h"
//#include "./headers/TextLoadException.h"
#include "raylib.h"


class SomeClass {
public:
    explicit SomeClass(int) {}
};

SomeClass *getC() {
    return new SomeClass{2};
}

int main() {
/*try {
    Painting painting;
    painting.LoadText();
    painting.Draw();
}
    catch (const TextLoadException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cerr << "Failed: " << e.GetFilePath() << std::endl;
    }*/
    constexpr int screenWidth = 1920;
    constexpr int screenHeight = 1080;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "Start");
    SetTargetFPS(60);

    Rectangle targetZone1 = { 800, 700, 50, 50 }; // Zona unde trebuie plasate obiectele
    Rectangle targetZone2 = { 1200, 500, 50, 50 };
    bool isDraggingPainting = false;
    bool isDraggingPencil = false;

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
    Texture2D background = LoadTexture("D:/githubdesktop/Perfectly-Placed/resources/textures/Background.jpg");
    if (background.id == 0) {
        printf("Failed to load background texture\n");
    }

    Painting painting;
    Pencil pencil;
    Subject placementSubject;

    PlacementNotification notification;
    placementSubject.addObserver(&notification);

    PlayMusicStream(StartMusic);

    while (!WindowShouldClose()) {
        Vector2 mouse = GetMousePosition();

        // Drag logic
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (CheckCollisionPointRec(mouse, painting.GetRect())) {
                isDraggingPainting = true;
            } else if (CheckCollisionPointRec(mouse, pencil.GetRect())) {
                isDraggingPencil = true;
            }
        }

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            isDraggingPainting = false;
            isDraggingPencil = false;
        }

        if (isDraggingPainting) {
            painting.SetPosition({ mouse.x - painting.GetRect().width / 2, mouse.y - painting.GetRect().height / 2 });
        }
        if (isDraggingPencil) {
            pencil.SetPosition({ mouse.x - pencil.GetRect().width / 2, mouse.y - pencil.GetRect().height / 2 });
        }

	if(IsKeyPressed(KEY_SPACE)) {
            StopMusicStream(StartMusic);
            PlaySound(StartLoadSound);
        }
        bool isColliding = CheckCollision(painting, pencil);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(background, 0, 0, WHITE);
        DrawText("Place the paintings where you think they fit best.", 10, 10, 40, BLACK);

        painting.Draw();
        pencil.Draw();

        //Afisez Hitbox pentru obiecte daca se suprapun
        painting.DrawHitBox(isColliding);
        pencil.DrawHitBox(isColliding);

        // Verific plasarea prin coliziune
        if (CheckCollisionRecs(painting.GetRect(), targetZone1) && CheckCollisionRecs(pencil.GetRect(), targetZone2)) {
            DrawText("Paintings placed correctly!", 10, 60, 40, GREEN);
            placementSubject.notifyObservers();
        }
        EndDrawing();
    }

    UnloadMusicStream(StartMusic);
    UnloadSound(StartLoadSound);
    CloseWindow();
    Helper helper;
    helper.help();
    return 0;
}

#include "engine/engine.h"
#include "engine/game_settings.h"
#include "scenes/menu_scene.h"
#include <raylib.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TITLE "osu!"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
    SetTargetFPS(144);

    GameSettings settings;
    Engine engine(settings);

    MenuScene menuScene;

    engine.setScene(&menuScene);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        engine.getScene().render();
        EndDrawing();
        engine.getScene().update(GetFrameTime());
    }
}

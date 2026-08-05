#include "engine/engine.h"
#include "engine/game_settings.h"
#include "scenes/menu_scene.h"
#include <memory>
#include <raylib.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TITLE "raysu!"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
    SetTargetFPS(144);

    GameSettings settings;
    Engine engine(settings);

    engine.setScene(std::make_unique<MenuScene>());

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        engine.getScene().render();
        EndDrawing();
        engine.getScene().update(GetFrameTime());
    }
}

#include "scenes/menu_scene.h"
#include "engine/engine.h"
#include "scenes/game_scene.h"
#include "scenes/settings_scene.h"
#include "ui/button.h"
#include "ui/label.h"
#include <memory>
#include <vector>

MenuScene::MenuScene(std::vector<Button> buttons, std::vector<Label> labels) {
    m_buttons = buttons;
    m_labels = labels;
}

void MenuScene::init(Engine *engine) {
    std::cout << "MENU_SCENE_INIT" << std::endl;
    m_buttons.push_back({Rectangle{0.0f, 0.0f, 100, 100}, RED, Label{"Play"},
                         [engine]() { engine->setScene(std::make_unique<GameScene>()); }});
    m_buttons.push_back(
        {Rectangle{150.0f, 0.0f, 100, 100}, GREEN, Label{"Settings"},
         [engine]() { engine->setScene(std::make_unique<SettingsScene>()); }});
    m_labels.push_back(
        Label{"Menu Scene", {(float)GetScreenWidth() / 2, 150.0f}, 25, BLACK});
}

void MenuScene::render() {
    for (Button button : m_buttons) {
        button.render();
    }
    for (Label label : m_labels) {
        label.render();
    }
}

void MenuScene::update(float deltaTime, Engine *engine) {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        for (Button &button : m_buttons) {
            if (button.collisionDetected(GetMousePosition())) {
                button.click();
            }
        }
    }
}

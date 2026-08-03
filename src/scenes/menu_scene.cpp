#include "scenes/menu_scene.h"
#include "engine/engine.h"
#include "scenes/game_scene.h"
#include "scenes/settings_scene.h"
#include "ui/button.h"
#include "ui/label.h"
#include <vector>

MenuScene::MenuScene(std::vector<Button> buttons, std::vector<Label> labels) {
    m_buttons = buttons;
    m_labels = labels;
}

void MenuScene::init(Engine *engine) {
    std::cout << "MENU_SCENE_INIT" << std::endl;
    m_buttons.push_back({Rectangle{0.0f, 0.0f, 100, 100}, RED,
                         [engine]() { engine->setScene(new GameScene()); }});
    m_buttons.push_back({Rectangle{150.0f, 0.0f, 100, 100}, GREEN, [engine]() {
                             engine->setScene(new SettingsScene());
                         }});
    m_labels.push_back(
        Label{"Menu", {(float)GetScreenWidth() / 2, 150.0f}, 25, BLACK});
}

void MenuScene::render() {
    for (Button button : m_buttons) {
        DrawRectanglePro(button.getGeometry(), {}, 0.0f, button.getBgColor());
    }
    for (Label label : m_labels) {
        DrawText(label.getText().c_str(), label.getPosition().x,
                 label.getPosition().y, label.getFontSize(), label.getColor());
    }
}

void MenuScene::update(float deltaTime) {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        for (Button &button : m_buttons) {
            if (button.collisionDetected(GetMousePosition())) {
                button.click();
            }
        }
    }
}

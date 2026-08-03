#include "scenes/settings_scene.h"
#include "engine/engine.h"
#include "scenes/menu_scene.h"
#include "ui/button.h"
#include "ui/label.h"
#include <vector>

SettingsScene::SettingsScene(std::vector<Button> buttons,
                             std::vector<Label> labels) {
    m_buttons = buttons;
    m_labels = labels;
}

void SettingsScene::init(Engine *engine) {
    std::cout << "SETTINGS_SCENE_INIT" << std::endl;
    m_buttons.push_back({Rectangle{0.0f, 0.0f, 100, 100}, RED,
                         [engine]() { engine->setScene(new MenuScene()); }});
    m_labels.push_back(
        Label{"Settings", {(float)GetScreenWidth() / 2, 150.0f}, 25, BLACK});
}

void SettingsScene::render() {
    for (Button button : m_buttons) {
        DrawRectanglePro(button.getGeometry(), {}, 0.0f, button.getBgColor());
    }
    for (Label label : m_labels) {
        DrawText(label.getText().c_str(), label.getPosition().x,
                 label.getPosition().y, label.getFontSize(), label.getColor());
    }
}

void SettingsScene::update(float deltaTime) {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        for (Button &button : m_buttons) {
            if (button.collisionDetected(GetMousePosition())) {
                button.click();
            }
        }
    }
}

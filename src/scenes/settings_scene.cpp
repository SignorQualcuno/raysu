#include "scenes/settings_scene.h"
#include "engine/engine.h"
#include "scenes/menu_scene.h"
#include "ui/button.h"
#include "ui/label.h"
#include <memory>
#include <vector>

SettingsScene::SettingsScene(std::vector<Button> buttons,
                             std::vector<Label> labels) {
    m_buttons = buttons;
    m_staticLabels = labels;
}

void SettingsScene::init(Engine *engine) {
    std::cout << "SETTINGS_SCENE_INIT" << std::endl;
    m_buttons.push_back(
        {Rectangle{0.0f, 0.0f, 100, 100}, RED, Label{"Back"},
         [engine]() { engine->setScene(std::make_unique<MenuScene>()); }});
    m_staticLabels.push_back(
        Label{"Scene: Settings", {2, (float)GetScreenHeight() - 20}});
}

void SettingsScene::render() {
    for (Button button : m_buttons) {
        button.render();
    }
    for (Label label : m_staticLabels) {
        label.render();
    }
}

void SettingsScene::update(float deltaTime, Engine *engine) {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        for (Button &button : m_buttons) {
            if (button.collisionDetected(GetMousePosition())) {
                button.click();
            }
        }
    }
}

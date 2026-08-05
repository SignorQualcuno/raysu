#ifndef SETTINGS_SCENE_H
#define SETTINGS_SCENE_H

#include "engine/scene.h"
#include "ui/button.h"
#include "ui/label.h"
#include <iostream>
#include <vector>

class SettingsScene : public Scene {
  private:
    std::vector<Button> m_buttons;
    std::vector<Label> m_staticLabels;

  public:
    ~SettingsScene() override = default;
    SettingsScene() = default;
    SettingsScene(std::vector<Button> buttons, std::vector<Label> labels);

    void init(Engine *engine) override;
    void cleanup() override {
        std::cout << "SETTINGS_SCENE_CLEANUP" << std::endl;
    };
    void update(float deltaTime, Engine *engine) override;
    void render() override;
};

#endif // SETTINGS_SCENE_H

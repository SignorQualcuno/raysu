#ifndef MENU_SCENE_H
#define MENU_SCENE_H

#include "engine/scene.h"
#include "ui/button.h"
#include "ui/label.h"
#include <iostream>
#include <vector>

class MenuScene : public Scene {
  private:
    std::vector<Button> m_buttons;
    std::vector<Label> m_labels;

  public:
    ~MenuScene() override = default;
    MenuScene() = default;
    MenuScene(std::vector<Button> buttons, std::vector<Label> labels);

    void init(Engine *engine) override;
    void cleanup() override { std::cout << "MENU_SCENE_CLEANUP" << std::endl; }
    void update(float deltaTime, Engine *engine) override;
    void render() override;
};

#endif // MENU_SCENE_H

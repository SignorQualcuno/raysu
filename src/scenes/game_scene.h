#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "engine/scene.h"
#include "ui/button.h"
#include "ui/label.h"
#include <iostream>
#include <vector>

class GameScene : public Scene {
  private:
    std::vector<Button> m_buttons;
    std::vector<Label> m_labels;

  public:
    ~GameScene() override = default;
    GameScene() = default;
    GameScene(std::vector<Button> buttons, std::vector<Label> labels);

    void init(Engine *engine) override;
    void cleanup() override { std::cout << "GAME_SCENE_CLEANUP" << std::endl; }
    void update(float) override;
    void render() override;
};

#endif // GAME_SCENE_H

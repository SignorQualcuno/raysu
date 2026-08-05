#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "engine/scene.h"
#include "game/node.h"
#include "ui/button.h"
#include "ui/label.h"
#include <iostream>
#include <memory>
#include <raylib.h>
#include <string>
#include <vector>

class GameScene : public Scene {
  private:
    std::vector<Button> m_buttons;
    std::vector<Label> m_staticLabels;
    std::vector<std::unique_ptr<Node>> m_nodes;
    Label m_accuracyLabel = {"Accuracy 100%", {0, 50}};
    int m_maxNodes = 2;
    int m_clicks = 0;
    int m_hits = 0;

  public:
    ~GameScene() override = default;
    GameScene() = default;
    GameScene(std::vector<Button> buttons, std::vector<Label> labels);

    void init(Engine *engine) override;
    void cleanup() override { std::cout << "GAME_SCENE_CLEANUP" << std::endl; }
    void update(float deltaTime, Engine *engine) override;
    void render() override;

    void generateNodeRandomPosition();
    void reloadNodes();
    bool isValidPosition(Vector2 position);
    Node *collisionDetected(Vector2 mousePos);
    void updateNodes();
    std::string getAccuracyLabel();
};

#endif // GAME_SCENE_H

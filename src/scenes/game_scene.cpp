#include "scenes/game_scene.h"
#include "config.h"
#include "engine/engine.h"
#include "scenes/menu_scene.h"
#include "ui/button.h"
#include "ui/label.h"
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <memory>
#include <raylib.h>
#include <sstream>
#include <string>
#include <vector>

GameScene::GameScene(std::vector<Button> buttons, std::vector<Label> labels) {
    m_buttons = buttons;
    m_staticLabels = labels;
}

void GameScene::init(Engine *engine) {
    SetMouseCursor(MOUSE_CURSOR_CROSSHAIR);
    srand(time(NULL));
    std::cout << "GAME_SCENE_INIT" << std::endl;
    m_staticLabels.push_back(
        Label{"Scene: Game", {2, (float)GetScreenHeight() - 20}});
    m_staticLabels.push_back(Label{"Press R to reload scenario", {0, 0}});
    m_staticLabels.push_back(Label{"Press Q to go to menu", {0, 25}});

    reloadNodes();
}

void GameScene::cleanup() {
    std::cout << "GAME_SCENE_CLEANUP" << std::endl;
    SetMouseCursor(MOUSE_CURSOR_DEFAULT);
}

void GameScene::render() {
    for (Button button : m_buttons) {
        button.render();
    }
    for (Label label : m_staticLabels) {
        label.render();
    }
    m_accuracyLabel.render();
    for (const auto &node : m_nodes) {
        node->render();
    }
}

void GameScene::updateNodes() {
    for (const auto &node : m_nodes) {
        node->setOrder(node->getOrder() - 1);
        node->setLabel(std::to_string(node->getOrder()));
    }
    while (m_nodes.size() < m_maxNodes) {
        generateNodeRandomPosition();
    }
}

void GameScene::update(float deltaTime, Engine *engine) {
    if (IsKeyPressed(KEY_R)) {
        reloadNodes();
    }
    if (IsKeyPressed(KEY_Q)) {
        engine->setScene(std::make_unique<MenuScene>());
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        m_clicks++;
        for (Button &button : m_buttons) {
            if (button.collisionDetected(GetMousePosition())) {
                button.click();
            }
        }
        Node *hit = collisionDetected(GetMousePosition());
        if (hit && hit->getOrder() == 1) {
            m_nodes.erase(m_nodes.begin());
            updateNodes();
            m_hits++;
        }
    }
    m_accuracyLabel.setText("Accuracy: " + getAccuracyLabel() + "% (" +
                            std::to_string(m_hits) + "/" +
                            std::to_string(m_clicks) + ")");
}

std::string GameScene::getAccuracyLabel() {
    if (m_clicks == 0) {
        return "100.00";
    }
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2)
           << (float)m_hits / m_clicks * 100;
    return stream.str();
}

Node *GameScene::collisionDetected(Vector2 mousePos) {
    for (const auto &node : m_nodes) {
        if (CheckCollisionPointCircle(mousePos, node->getPosition(),
                                      NODE_RADIUS)) {
            return node.get();
        }
    }
    return nullptr;
}

bool GameScene::isValidPosition(Vector2 position) {
    for (const auto &node : m_nodes) {
        if (CheckCollisionCircles(position, NODE_RADIUS, node->getPosition(),
                                  NODE_RADIUS)) {
            return false;
        }
    }
    return true;
}

void GameScene::generateNodeRandomPosition() {
    float posX = 0;
    float posY = 0;
    do {
        posX = (float)(rand() % (int)(GetScreenWidth() - 2 * NODE_RADIUS)) +
               (float)NODE_RADIUS;
        posY = (float)(rand() % (int)(GetScreenHeight() - 2 * NODE_RADIUS)) +
               (float)NODE_RADIUS;
    } while (!isValidPosition(Vector2{posX, posY}));
    std::unique_ptr<Node> tmpNode =
        std::make_unique<Node>(Vector2{posX, posY}, (int)m_nodes.size() + 1);
    m_nodes.push_back(std::move(tmpNode));
}

void GameScene::reloadNodes() {
    m_clicks = 0;
    m_hits = 0;
    m_nodes.clear();
    for (std::size_t i = 1; i <= m_maxNodes; i++) {
        generateNodeRandomPosition();
    }
}

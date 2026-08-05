#include "scene_manager.h"

void SceneManager::changeScene(std::unique_ptr<Scene> newScene) {
    if (m_currentScene) {
        m_currentScene->cleanup();
    }
    m_currentScene = std::move(newScene);
    if (m_currentScene) {
        m_currentScene->init(m_engine);
    }
}

void SceneManager::update(float deltaTime) {
    if (m_currentScene) {
        m_currentScene->update(deltaTime, m_engine);
    }
}

void SceneManager::render() {
    if (m_currentScene) {
        m_currentScene->render();
    }
}

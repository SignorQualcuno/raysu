#include "scene_manager.h"

void SceneManager::changeScene(Scene *newScene) {
    if (m_currentScene) {
        m_currentScene->cleanup();
    }
    m_currentScene = newScene;
    if (m_currentScene) {
        m_currentScene->init(m_engine);
    }
}

void SceneManager::update(float deltaTime) {
    if (m_currentScene) {
        m_currentScene->update(deltaTime);
    }
}

void SceneManager::render() {
    if (m_currentScene) {
        m_currentScene->render();
    }
}

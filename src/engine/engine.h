#ifndef ENGINE_H
#define ENGINE_H

#include "engine/game_settings.h"
#include "scene_manager.h"

class Engine {
  private:
    GameSettings &m_settings;
    SceneManager m_sceneManager;

  public:
    explicit Engine(GameSettings &settings)
        : m_settings(settings), m_sceneManager() {
        m_sceneManager.setEngine(this);
    }

    SceneManager &getScene() { return m_sceneManager; }
    void setScene(std::unique_ptr<Scene> newScene) { m_sceneManager.changeScene(std::move(newScene)); }
};

#endif // ENGINE_H

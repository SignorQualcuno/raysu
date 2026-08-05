#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "scene.h"
#include <memory>

class Engine;

class SceneManager {
  private:
    std::unique_ptr<Scene> m_currentScene;
    std::unique_ptr<Scene> m_pendingScene;
    Engine *m_engine;

    void applyPendingScene();

  public:
    void changeScene(std::unique_ptr<Scene> newScene);
    void update(float deltaTime);
    void render();

    void setEngine(Engine *engine) { m_engine = engine; }
};

#endif // SCENE_H

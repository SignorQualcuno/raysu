#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "scene.h"

class Engine;

class SceneManager {
  private:
    Scene *m_currentScene;
    Engine *m_engine;

  public:
    void changeScene(Scene *);
    void update(float);
    void render();

    void setEngine(Engine *engine) { m_engine = engine; }
};

#endif // SCENE_H

#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "scene.h"

class SceneManager {
  private:
    std::vector<Scene> scenes;

  public:
    SceneManager();
    ~SceneManager();
};

#endif // SCENE_H

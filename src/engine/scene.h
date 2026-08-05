#ifndef SCENE_H
#define SCENE_H

#include <pthread.h>
#include <raylib.h>

class Engine;

class Scene {
  private:
  public:
    virtual ~Scene() = default;

    virtual void init(Engine *engine) = 0;
    virtual void cleanup() = 0;
    virtual void update(float deltaTime, Engine *engine) = 0;
    virtual void render() = 0;
};

#endif // SCENE_H

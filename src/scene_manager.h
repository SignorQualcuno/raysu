#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#define FONT_SIZE 14

#include <raylib.h>
#include <string>
#include <vector>

struct Label {
    Vector2 position;
    std::string text;
    int font_size = FONT_SIZE;
};

class SceneManager {
  private:
    std::vector<std::string> labels;

  public:
    SceneManager();
    ~SceneManager();

    void update();
    void draw();
};

#endif // SCENE_MANAGER_H

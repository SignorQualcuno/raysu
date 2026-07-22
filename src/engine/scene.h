#ifndef SCENE_H
#define SCENE_H

#define FONT_SIZE 14

#include <raylib.h>
#include <string>
#include <vector>

struct Label {
    std::string text = "";
    int font_size = FONT_SIZE;
};

struct Button {
    Vector2 position;
    Vector2 dimensions;
    Label label;
};

class Scene {
  private:
    std::vector<Label> labels;
    std::vector<Button> buttons;

  public:
    Scene();
    ~Scene();

    void update();
    void draw();
};

#endif // SCENE_MANAGER_H

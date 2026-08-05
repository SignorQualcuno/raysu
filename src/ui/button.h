#ifndef BUTTON_H
#define BUTTON_H

#include "engine/iclickable.h"
#include "ui/label.h"
#include <functional>
#include <raylib.h>

class Button : public IClickable {
  private:
    Color m_color;
    Label m_text;
    std::function<void()> m_onClick;

  public:
    Button() = delete;
    Button(Rectangle geometry, Color color,
           std::function<void()> onClick = nullptr);
    Button(Rectangle geometry, Color color, Label text,
           std::function<void()> onClick = nullptr);

    void render();

    void click();
};

#endif

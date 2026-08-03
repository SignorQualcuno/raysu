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

    void click();

    const Color &getBgColor() const { return m_color; }
    void setBgColor(const Color &bgColor) { this->m_color = bgColor; }
};

#endif

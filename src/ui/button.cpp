#include "ui/button.h"
#include "engine/iclickable.h"
#include <functional>

Button::Button(Rectangle geometry, Color color, std::function<void()> onClick)
    : IClickable(geometry), m_color(color), m_onClick(onClick) {}

void Button::click() {
    if (m_onClick) {
        m_onClick();
    }
}

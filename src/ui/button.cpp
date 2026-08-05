#include "ui/button.h"
#include "engine/iclickable.h"
#include <functional>
#include <raylib.h>

Button::Button(Rectangle geometry, Color color, std::function<void()> onClick)
    : IClickable(geometry), m_color(color), m_onClick(onClick) {}

Button::Button(Rectangle geometry, Color color, Label text,
               std::function<void()> onClick)
    : IClickable(geometry), m_color(color), m_text(text), m_onClick(onClick) {}

void Button::click() {
    if (m_onClick) {
        m_onClick();
    }
}

void Button::render() {
    DrawRectanglePro(getGeometry(), {0.0f, 0.0f}, 0.0f, m_color);
    DrawText(m_text.getText().c_str(), getGeometry().x, getGeometry().y,
             m_text.getFontSize(), m_text.getColor());
}

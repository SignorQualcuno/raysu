#include "ui/button.h"
#include <functional>
#include <raylib.h>

Button::Button(Rectangle geometry, Color color, std::function<void()> onClick)
    : m_geometry(geometry), m_color(color), m_onClick(onClick) {}

Button::Button(Rectangle geometry, Color color, Label text,
               std::function<void()> onClick)
    : m_geometry(geometry), m_color(color), m_text(text), m_onClick(onClick) {}

void Button::click() {
    if (m_onClick) {
        m_onClick();
    }
}

void Button::render() {
    DrawRectanglePro(m_geometry, {0, 0}, 0, m_color);
    DrawText(m_text.getText().c_str(), m_geometry.x, m_geometry.y,
             m_text.getFontSize(), m_text.getColor());
}

Button *Button::collisionDetected(Vector2 mousePos) {
    if (CheckCollisionPointRec(mousePos, m_geometry)) {
        return this;
    }
    return nullptr;
}

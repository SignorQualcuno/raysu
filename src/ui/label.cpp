#include "ui/label.h"

Label::Label(std::string text, Vector2 position, int fontSize, Color color)
    : m_text(text), m_position(position), m_fontSize(fontSize), m_color(color) {
}

Label::Label(std::string text, Vector2 position)
    : m_text(text), m_position(position) {}

Label::Label(std::string text) : m_text(text) {}

void Label::render() {
    DrawText(m_text.c_str(), m_position.x, m_position.y, m_fontSize, m_color);
}

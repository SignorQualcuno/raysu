#include "ui/label.h"
Label::Label(std::string text, Vector2 position, u_int8_t fontSize,
             Color color) {
    this->m_text = text;
    this->m_position = position;
    this->m_fontSize = fontSize;
    this->m_color = color;
}

#ifndef LABEL_H
#define LABEL_H

#include <raylib.h>
#include <string>
#include <sys/types.h>

class Label {
  private:
    std::string m_text;
    Vector2 m_position;
    u_int8_t m_fontSize;
    Color m_color;

  public:
    Label() = default;
    Label(std::string text, Vector2 position, u_int8_t fontSize, Color color);

    const std::string &getText() const { return m_text; }
    void setText(const std::string &m_text) { this->m_text = m_text; }

    const Vector2 &getPosition() const { return m_position; }
    void setPosition(const Vector2 &m_position) {
        this->m_position = m_position;
    }

    const u_int8_t &getFontSize() const { return m_fontSize; }
    void setFontSize(const u_int8_t &m_fontSize) {
        this->m_fontSize = m_fontSize;
    }

    const Color &getColor() const { return m_color; }
    void setColor(const Color &m_color) { this->m_color = m_color; }
};

#endif

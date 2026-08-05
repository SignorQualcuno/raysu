#ifndef LABEL_H
#define LABEL_H

#include <raylib.h>
#include <string>

class Label {
  private:
    std::string m_text;
    Vector2 m_position = {0.0f, 0.0f};
    int m_fontSize = 20;
    Color m_color = BLACK;

  public:
    Label() = default;
    Label(std::string text, Vector2 position, int fontSize, Color color);
    Label(std::string text, Vector2 position);
    Label(std::string text);

    void render();

    const std::string &getText() const { return m_text; }
    void setText(const std::string &m_text) { this->m_text = m_text; }

    const Vector2 &getPosition() const { return m_position; }
    void setPosition(const Vector2 &m_position) {
        this->m_position = m_position;
    }

    const int &getFontSize() const { return m_fontSize; }
    void setFontSize(const int &m_fontSize) { this->m_fontSize = m_fontSize; }

    const Color &getColor() const { return m_color; }
    void setColor(const Color &m_color) { this->m_color = m_color; }
};

#endif

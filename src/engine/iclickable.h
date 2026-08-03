#ifndef I_CLICKABLE_H
#define I_CLICKABLE_H

#include <raylib.h>

class IClickable {
  private:
    Rectangle m_geometry;

  public:
    virtual ~IClickable() = default;

    IClickable(Rectangle m_geometry) : m_geometry(m_geometry) {}

    const Rectangle &getGeometry() const { return m_geometry; }
    void setGeometry(const Rectangle &m_geometry) {
        this->m_geometry = m_geometry;
    }

    IClickable *collisionDetected(Vector2 mousePos);
};

#endif // I_CLICKABLE_H

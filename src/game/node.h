#ifndef NODE_H
#define NODE_H

#include "config.h"
#include "ui/label.h"
#include <raylib.h>

class Node {
  private:
    Vector2 m_position;
    Label m_label;
    Color m_color = RED;
    int m_radius = NODE_RADIUS;
    int m_order;

  public:
    Node() = default;
    Node(Vector2 position, Label label, int order);
    Node(Vector2 position, int order);
    ~Node() = default;

    void render();

    const Vector2 &getPosition() const { return m_position; }
    void setPosition(const Vector2 &position) { this->m_position = position; }

    const Label &getLabel() const { return m_label; }
    void setLabel(const Label &label) { this->m_label = label; }

    const int &getOrder() const { return m_order; }
    void setOrder(const int &order) { this->m_order = order; }
};

#endif // NODE_H

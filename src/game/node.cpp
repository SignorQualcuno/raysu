#include "node.h"
#include "config.h"
#include "ui/label.h"
#include <raylib.h>
#include <string>

Node::Node(Vector2 position, Label label, int order)
    : m_position(position), m_label(label), m_order(order) {}

Node::Node(Vector2 position, int order)
    : m_position(position), m_order(order), m_label(std::to_string(order)) {}

void Node::render() {
    DrawCircleV(m_position, NODE_RADIUS, m_color);
    DrawText(m_label.getText().c_str(), m_position.x, m_position.y,
             m_label.getFontSize(), m_label.getColor());
}

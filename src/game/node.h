#ifndef NODE_H
#define NODE_H

#include <raylib.h>
#include <string>
#include <sys/types.h>

class Node {
  private:
    Vector2 position;
    std::string label;
    u_int8_t order;

  public:
    Node();
    Node(Vector2, std::string, u_int8_t);
    ~Node();

    const Vector2 &getPosition() const { return position; }
    void setPosition(const Vector2 &position) { this->position = position; }

    const std::string &getLabel() const { return label; }
    void setLabel(const std::string &label) { this->label = label; }

    const u_int8_t &getOrder() const { return order; }
    void setOrder(const u_int8_t &order) { this->order = order; }
};

#endif // NODE_H

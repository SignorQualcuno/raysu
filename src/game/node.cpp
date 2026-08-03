#include "node.h"
#include <raylib.h>
#include <sys/types.h>

Node::Node() {
    this->position = {0.0f, 0.0f};
    this->label = "";
    this->order = -1;
}

Node::Node(Vector2 position, std::string label, u_int8_t order) {
    this->position = position;
    this->label = label;
    this->order = order;
}

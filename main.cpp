#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <raylib.h>
#include <string>
#include <sys/types.h>
#include <vector>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TITLE "osu!"

#define START_NODES 5
#define NODE_RADIUS 40.0f
#define NODE_COLOR RED

struct Node {
    Vector2 position;
    std::string label;
    u_int8_t order;
};

Node *generate_random_node_position(std::string label, u_int8_t order) {
    return new Node{(float)(rand() % (int)(SCREEN_WIDTH - 2 * NODE_RADIUS)) +
                        (float)NODE_RADIUS,
                    (float)(rand() % (int)(SCREEN_HEIGHT - 2 * NODE_RADIUS)) +
                        (float)NODE_RADIUS,
                    label, order};
}

void draw_node(Node *node) {
    DrawCircleV(node->position, NODE_RADIUS, NODE_COLOR);
    DrawText(node->label.c_str(), node->position.x, node->position.y, 20,
             BLACK);
}

Node *check_collision(std::vector<Node *> nodes, Vector2 mouse_position) {
    for (Node *node : nodes) {
        if (((mouse_position.x >= node->position.x - NODE_RADIUS) &&
             (mouse_position.x <= node->position.x + NODE_RADIUS)) &&
            ((mouse_position.y >= node->position.y - NODE_RADIUS) &&
             (mouse_position.y <= node->position.y + NODE_RADIUS))) {
            return node;
        }
    }
    return nullptr;
}

void reload_scenario(std::vector<Node *> &nodes) {
    nodes.clear();
    for (int i = 1; i <= START_NODES; i++) {
        nodes.push_back(generate_random_node_position(std::to_string(i), i));
    }
}

int main() {
    srand(time(NULL));
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
    SetTargetFPS(144);

    std::vector<Node *> nodes = {};

    reload_scenario(nodes);

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_R)) {
            reload_scenario(nodes);
        }
        Node *hit = check_collision(nodes, GetMousePosition());
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && hit) {
            nodes.erase(std::remove(nodes.begin(), nodes.end(), hit),
                        nodes.end());
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        for (Node *item : nodes) {
            draw_node(item);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

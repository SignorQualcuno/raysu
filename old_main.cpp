// #include <cstdlib>
// #include <ctime>
// #include <iomanip>
// #include <iostream>
// #include <raylib.h>
// #include <sstream>
// #include <string>
// #include <sys/types.h>

// #include <vector>

// #define SCREEN_WIDTH 800
// #define SCREEN_HEIGHT 600
// #define TITLE "osu!"

// #define START_NODES 2
// #define NODE_RADIUS 40.0f
// #define NODE_DIAMETER 2 * NODE_RADIUS
// #define NODE_COLOR RED

// struct Node {
//     Vector2 position;
//     std::string label;
//     u_int8_t order;
// };

// Node *gen_node_with_random_position(std::string label, u_int8_t order) {
//     return new Node{(float)(rand() % (int)(SCREEN_WIDTH - 2 * NODE_RADIUS)) +
//                         (float)NODE_RADIUS,
//                     (float)(rand() % (int)(SCREEN_HEIGHT - 2 * NODE_RADIUS))
//                     +
//                         (float)NODE_RADIUS,
//                     label, order};
// }

// void draw_node(Node node) {
//     DrawCircleV(node.position, NODE_RADIUS, NODE_COLOR);
//     DrawText(node.label.c_str(), node.position.x, node.position.y, 20,
//     BLACK);
// }

// Node *check_collision(std::vector<Node *> nodes, Vector2 mouse_position) {
//     for (Node *node : nodes) {
//         if (((mouse_position.x >= node->position.x - NODE_RADIUS) &&
//              (mouse_position.x <= node->position.x + NODE_RADIUS)) &&
//             ((mouse_position.y >= node->position.y - NODE_RADIUS) &&
//              (mouse_position.y <= node->position.y + NODE_RADIUS))) {
//             return node;
//         }
//     }
//     return nullptr;
// }

// bool check_draw_node_valid_position(std::vector<Node *> nodes, Node new_node)
// {
//     for (Node *node : nodes) {
//         if (((new_node.position.x >= node->position.x - NODE_DIAMETER) &&
//              (new_node.position.x <= node->position.x + NODE_DIAMETER)) &&
//             ((new_node.position.y >= node->position.y - NODE_DIAMETER) &&
//              (new_node.position.y <= node->position.y + NODE_DIAMETER))) {
//             return false;
//         }
//     }
//     return true;
// }

// void add_nodes_until_full(std::vector<Node *> &nodes) {
//     while (nodes.size() != START_NODES) {
//         Node *tmp_node = gen_node_with_random_position(
//             std::to_string(nodes.size() + 1), nodes.size() + 1);
//         if (check_draw_node_valid_position(nodes, *tmp_node)) {
//             nodes.push_back(tmp_node);
//         }
//     }
// }

// void reload_scenario(std::vector<Node *> &nodes, int &hits, int &clicks) {
//     hits = 0;
//     clicks = 0;
//     nodes.clear();
//     add_nodes_until_full(nodes);
// }

// void reassign_nodes(std::vector<Node *> &nodes) {
//     u_int8_t n = 1;
//     for (Node *node : nodes) {
//         node->order = n;
//         node->label = std::to_string(n);
//         n++;
//     }
//     add_nodes_until_full(nodes);
// }

// std::string get_accuracy_label(int clicks, int hits) {
//     if (clicks == 0) {
//         return "100.00";
//     }
//     std::stringstream stream;
//     stream << std::fixed << std::setprecision(2) << (float)hits / clicks *
//     100; return stream.str();
// }

// int main() {
//     srand(time(NULL));
//     InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
//     SetTargetFPS(144);

//     int hits = 0;
//     int clicks = 0;

//     std::vector<Node *> nodes = {};
//     reload_scenario(nodes, hits, clicks);

//     while (!WindowShouldClose()) {

//         std::string accuracy_label =
//             "Accuracy: " + get_accuracy_label(clicks, hits) + "%";

//         if (IsKeyPressed(KEY_R)) {
//             reload_scenario(nodes, hits, clicks);
//         }
//         if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
//             Node *hit = check_collision(nodes, GetMousePosition());
//             clicks++;
//             if (hit && hit->order == 1) {
//                 hits++;
//                 nodes.erase(nodes.begin());
//                 reassign_nodes(nodes);
//             }
//         }

//         BeginDrawing();
//         ClearBackground(RAYWHITE);
//         DrawText("Press R to reload", 10, 10, 20, BLACK);
//         DrawText(accuracy_label.c_str(), 10, 30, 20, BLACK);
//         for (Node *item : nodes) {
//             draw_node(*item);
//         }
//         EndDrawing();
//     }
//     CloseWindow();
//     return 0;
// }

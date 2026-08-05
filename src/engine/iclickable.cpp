#include "engine/iclickable.h"
#include <raylib.h>

IClickable *IClickable::collisionDetected(Vector2 mousePos) {
    if (CheckCollisionPointRec(mousePos, m_geometry)) {
        return this;
    }
    return nullptr;
}

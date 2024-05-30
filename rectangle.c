#include "rectangle.h"

// Função para verificar se dois retângulos colidem
int collides(Rectangle *a, Rectangle *b) {
    return !(a->x + a->l <= b->x || b->x + b->l <= a->x || a->y + a->h <= b->y || b->y + b->h <= a->y);
}

// Função para aplicar gravidade a um retângulo
void applyGravity(Rectangle *rects, int count, Rectangle *rect) {
    while (1) {
        int canFall = 1;
        for (int i = 0; i < count; ++i) {
            if (&rects[i] != rect && collides(rect, &rects[i])) {
                canFall = 0;
                break;
            }
        }
        if (rect->y == 0 || !canFall) break;
        rect->y--;
    }
}

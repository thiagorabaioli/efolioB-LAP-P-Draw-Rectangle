#include "world.h"
#include "rectangle.h"
#include <stdio.h>

// Função para criar um retângulo no mundo
void createRectangle(World *world, int x, int y, int l, int h) {
    if (world->count >= 100) {
        printf("Error: Maximum number of rectangles reached.\n");
        return;
    }

    Rectangle rect = {x, y, l, h};
    for (int i = 0; i < world->count; ++i) {
        if (collides(&rect, &world->rects[i])) {
            printf("Error: New rectangle collides with an existing one.\n");
            return;
        }
    }

    applyGravity(world->rects, world->count, &rect);
    world->rects[world->count++] = rect;
}

// Função para mover um retângulo no mundo
void moveRectangle(World *world, int x, int y, int p, int direction) {
    Rectangle *rect = findRectangleAt(world, x, y);
    if (rect == NULL) {
        printf("Error: No rectangle at specified coordinates.\n");
        return;
    }

    int newX = rect->x + p * direction;
    if (newX < 0) {
        printf("Error: Rectangle out of bounds to the left.\n");
        return;
    }
    if (newX + rect->l > WIDTH) {
        printf("Error: Rectangle out of bounds to the right.\n");
        return;
    }

    Rectangle newRect = {newX, rect->y, rect->l, rect->h};
    for (int i = 0; i < world->count; ++i) {
        if (&world->rects[i] != rect && collides(&newRect, &world->rects[i])) {
            printf("Error: Rectangle collides with an existing one after movement.\n");
            return;
        }
    }

    *rect = newRect;
    applyGravity(world->rects, world->count, rect);
}

// Função para inicializar o mundo
void initializeWorld(World *world) {
    world->count = 0;
    world->rects = (Rectangle*)malloc(sizeof(Rectangle) * 100);
}

// Função para liberar memória do mundo
void freeWorld(World *world) {
    free(world->rects);
}

// Função para encontrar um retângulo nas coordenadas especificadas
Rectangle* findRectangleAt(World *world, int x, int y) {
    for (int i = 0; i < world->count; ++i) {
        Rectangle *rect = &world->rects[i];
        if (x >= rect->x && x < rect->x + rect->l && y >= rect->y && y < rect->y + rect->h) {
            return rect;
        }
    }
    return NULL;
}

// Função para desenhar o mundo com os retângulos
void drawWorld(World *world) {
    char canvas[HEIGHT][WIDTH + 1];
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            canvas[i][j] = ' ';
        }
        canvas[i][WIDTH] = '\0';
    }

    for (int i = 0; i < world->count; ++i) {
        Rectangle rect = world->rects[i];
        for (int y = rect.y; y < rect.y + rect.h && y < HEIGHT; ++y) {
            for (int x = rect.x; x < rect.x + rect.l && x < WIDTH; ++x) {
                canvas[y][x] = 'x';
            }
        }
    }

    for (int i = HEIGHT - 1; i >= 0; --i) {
        printf("%s\n", canvas[i]);
    }

    // Exibir coordenadas do retângulo após movimento
    printf("Coordenadas do retângulo: (%d, %d)\n", world->rects[0].x, world->rects[0].y); // Supondo que há apenas um retângulo
}

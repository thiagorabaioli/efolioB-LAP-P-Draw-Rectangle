#ifndef WORLD_H
#define WORLD_H

#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 25

typedef struct {
    int x, y, l, h;
} Rectangle;

typedef struct {
    Rectangle *rects;
    int count;
} World;

void initializeWorld(World *world);
void freeWorld(World *world);
void createRectangle(World *world, int x, int y, int l, int h);
void moveRectangle(World *world, int x, int y, int p, int direction);
Rectangle* findRectangleAt(World *world, int x, int y);
void drawWorld(World *world);

#endif

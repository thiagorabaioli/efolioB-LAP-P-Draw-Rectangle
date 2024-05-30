#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "world.h"

int collides(Rectangle *a, Rectangle *b);
void applyGravity(Rectangle *rects, int count, Rectangle *rect);

#endif

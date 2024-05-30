#include <stdio.h>
#include "world.h"
#include "menu.h"

int main() {
    World world;
    initializeWorld(&world);

    displayMenu(&world);

    freeWorld(&world);
    return 0;
}

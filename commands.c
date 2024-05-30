#include "commands.h"
#include <stdio.h>
#include <string.h>

// Função para executar comandos a partir de strings
void executeCommand(World *world, char *command) {
    int x, y, l, h, p;

    if (sscanf(command, "create %d,%d+%d,%d", &x, &y, &l, &h) == 4) {
        createRectangle(world, x, y, l, h);
    } else if (sscanf(command, "moveleft %d,%d+%d", &x, &y, &p) == 3) {
        moveRectangle(world, x, y, p, -1);
    } else if (sscanf(command, "moveright %d,%d+%d", &x, &y, &p) == 3) {
        moveRectangle(world, x, y, p, 1);
    } else {
        printf("Error: Invalid command format.\n");
    }
}

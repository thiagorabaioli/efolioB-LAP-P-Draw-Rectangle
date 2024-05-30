#include <stdio.h>
#include "menu.h"
#include "commands.h"

// Função para exibir o menu principal e processar comandos
void displayMenu(World *world) {
    int choice;
    int x, y, p;

    do {
        printf("\n=== Menu ===\n");
        printf("1. Criar retângulo\n");
        printf("2. Mover retângulo para a esquerda\n");
        printf("3. Mover retângulo para a direita\n");
        printf("4. Mover retângulo para a cima\n");
        printf("5. Mover retângulo para a baixo\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Criar um retângulo automaticamente com valores predefinidos
                executeCommand(world, "create 0,0+5,5");
                drawWorld(world);
                break;
            case 2:
                // Movendo retângulo para a esquerda
                printf("Digite as coordenadas do canto inferior esquerdo do retângulo (x y): ");
                scanf("%d %d", &x, &y);
                printf("Digite a quantidade de unidades para mover para a esquerda: ");
                scanf("%d", &p);
                moveRectangle(world, x, y, p, -1);
                drawWorld(world);
                break;
            case 3:
                // Movendo retângulo para a direita
                printf("Digite as coordenadas do canto inferior esquerdo do retângulo (x y): ");
                scanf("%d %d", &x, &y);
                printf("Digite a quantidade de unidades para mover para a direita: ");
                scanf("%d", &p);
                moveRectangle(world, x, y, p, 1);
                drawWorld(world);
                break;
            case 4:
                // Movendo retângulo para a direita
                printf("Digite as coordenadas do canto inferior esquerdo do retângulo (x y): ");
                scanf("%d %d", &x, &y);
                printf("Digite a quantidade de unidades para mover para a cima: ");
                scanf("%d", &p);
                moveRectangle(world, x, y, p, 1);
                drawWorld(world);
                break;
            case 5:
                // Movendo retângulo para a direita
                printf("Digite as coordenadas do canto inferior esquerdo do retângulo (x y): ");
                scanf("%d %d", &x, &y);
                printf("Digite a quantidade de unidades para mover para a baixo: ");
                scanf("%d", &p);
                moveRectangle(world, x, y, p, 1);
                drawWorld(world);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (choice != 4);
}

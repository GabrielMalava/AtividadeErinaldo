#include <stdio.h>
#include <stdlib.h>

#define MAX_INTERSECTIONS 100

void initializeGraph(int graph[MAX_INTERSECTIONS][MAX_INTERSECTIONS], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            graph[i][j] = 0;
        }
    }
}

void insertStreet(int graph[MAX_INTERSECTIONS][MAX_INTERSECTIONS], int start, int end) {
    if (start >= 0 && start < MAX_INTERSECTIONS && end >= 0 && end < MAX_INTERSECTIONS) {
        graph[start][end] = 1;
        graph[end][start] = 1; 
    } else {
        printf("Interseções inválidas!\n");
    }
}

void printGraph(int graph[MAX_INTERSECTIONS][MAX_INTERSECTIONS], int size) {
    printf("Matriz de Adjacências:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int size;
    printf("Digite o número de interseções: ");
    scanf("%d", &size);

    if (size > MAX_INTERSECTIONS) {
        printf("Número de interseções excede o máximo permitido (%d)!\n", MAX_INTERSECTIONS);
        return 1;
    }

    int graph[MAX_INTERSECTIONS][MAX_INTERSECTIONS];
    initializeGraph(graph, size);

    int option, start, end;
    do {
        printf("\n1. Inserir uma nova rua\n");
        printf("2. Mostrar matriz de adjacências\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Digite a interseção inicial: ");
                scanf("%d", &start);
                printf("Digite a interseção final: ");
                scanf("%d", &end);
                insertStreet(graph, start, end);
                break;
            case 2:
                printGraph(graph, size);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (option != 0);

    return 0;
}

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 9

// Função para encontrar o vértice com a menor distância, que ainda não foi processado
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Função para imprimir o array de distâncias
void printSolution(int dist[], int n) {
    printf("Vértice \t Distância da origem\n");
    for (int i = 0; i < n; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Função que implementa o algoritmo de Dijkstra
void dijkstra(int graph[V][V], int src) {
    int dist[V]; // Array para guardar a menor distância de src a i
    bool sptSet[V]; // sptSet[i] será verdadeiro se o vértice i estiver na árvore de caminho mais curto

    // Inicializar todas as distâncias como INFINITO e sptSet[] como falso
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distância do vértice de origem para ele mesmo é sempre 0
    dist[src] = 0;

    // Encontrar o caminho mais curto para todos os vértices
    for (int count = 0; count < V - 1; count++) {
        // Escolher o vértice de distância mínima da árvore de caminho mais curto
        int u = minDistance(dist, sptSet);

        // Marcar o vértice escolhido como processado
        sptSet[u] = true;

        // Atualizar o valor dist dos vértices adjacentes do vértice escolhido
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Imprimir o array de distâncias
    printSolution(dist, V);
}

int main() {
    // Matriz de adjacências de exemplo
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0);

    return 0;
}

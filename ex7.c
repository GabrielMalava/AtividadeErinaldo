#include <stdio.h>

// Função para trocar dois elementos
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Função para implementar o Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // Mover a fronteira da sublista não ordenada
    for (i = 0; i < n-1; i++) {
        // Encontrar o menor elemento na sublista não ordenada
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Trocar o menor elemento encontrado com o primeiro elemento não ordenado
        swap(&arr[min_idx], &arr[i]);
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array original: \n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Array ordenado: \n");
    printArray(arr, n);

    return 0;
}

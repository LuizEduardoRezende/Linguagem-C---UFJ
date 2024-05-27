#include <stdio.h>
#include <stdlib.h>

// Função para mesclar dois subconjuntos ordenados
void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Criação de arrays temporários
    int L[n1], R[n2];

    // Copia os dados para os arrays temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    // Mescla os arrays temporários de volta ao array original arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver algum
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver algum
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função principal que implementa o Mergesort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Encontra o ponto médio do array
        int middle = left + (right - left) / 2;

        // Ordena a primeira e a segunda metade
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Mescla as metades ordenadas
        merge(arr, left, middle, right);
    }
}

// Função de impressão de um array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função principal
int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, arr_size);

    // Chama a função Mergesort
    mergeSort(arr, 0, arr_size - 1);

    printf("Array ordenado:\n");
    printArray(arr, arr_size);

    return 0;
}

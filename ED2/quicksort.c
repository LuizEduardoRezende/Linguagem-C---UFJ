#include <stdio.h>

// Função para trocar dois elementos de um array
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para escolher o pivô e particionar o array
int particionar(int arr[], int baixo, int alto) {
    int pivô = arr[alto];  // Escolhendo o último elemento como pivô
    int i = (baixo - 1);   // Índice do menor elemento

    for (int j = baixo; j < alto ; j++) {
        // Se o elemento atual é menor ou igual ao pivô
        if (arr[j] <= pivô) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

// Função principal que implementa o QuickSort
void quickSort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        // Obtém o índice de partição
        int indiceParticao = particionar(arr, baixo, alto);

        // Ordena os elementos antes e depois da partição
        quickSort(arr, baixo, indiceParticao - 1);
        quickSort(arr, indiceParticao + 1, alto);
    }
}

// Função para imprimir um array
void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Exemplo de uso
int main() {
    int arr[] = {12, 7, 3, 1, 8, 5, 11, 6};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    imprimirArray(arr, tamanho);

    quickSort(arr, 0, tamanho - 1);

    printf("Array ordenado: ");
    imprimirArray(arr, tamanho);

    return 0;
}
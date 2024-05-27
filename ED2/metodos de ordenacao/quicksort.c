#include <stdio.h>

// Função para trocar dois elementos de um array
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int arr[], int baixo, int alto) {

    int pivo = arr[alto];  // Escolhendo o último elemento como pivô
    int i = (baixo - 1);   // Índice do menor elemento

    for (int j = baixo; j <= alto - 1; j++) {
        // Se o elemento atual é menor ou igual ao pivô
        if(arr[j] <= pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

// Função para escolher o pivô e particionar o array
int particionar_dec(int arr[], int baixo, int alto) {
    int pivo = arr[alto];  // Escolhendo o último elemento como pivô
    int i = (baixo - 1);   // Índice do menor elemento

    for (int j = baixo; j <= alto - 1; j++) {
        // Se o elemento atual é maior ou igual ao pivô (alteração para ordenação decrescente)
        if (arr[j] >= pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

// Função principal que implementa o QuickSort
void quicksort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        // Obtém o índice de partição
        int indiceParticao = particionar(arr, baixo, alto);

        // Ordena os elementos antes e depois da partição
        quicksort(arr, baixo, indiceParticao - 1);
        quicksort(arr, indiceParticao + 1, alto);
    }
}

void quicksort_dec(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        // Obtém o índice de partição
        int pi = particionar_dec(arr, baixo, alto);

        // Ordena os elementos antes e depois da partição (alteração para ordenação decrescente)
        quicksort_dec(arr, baixo, pi - 1);
        quicksort_dec(arr, pi + 1, alto);
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

    quicksort_dec(arr, 0, tamanho - 1);

    printf("Array ordenado decrescentemente: ");
    imprimirArray(arr, tamanho);

    return 0;
}

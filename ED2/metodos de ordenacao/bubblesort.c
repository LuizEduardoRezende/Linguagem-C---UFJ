#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 500000

int main() {
    double num[TAM];
    double aux;
    int i, j;

    // Inicia o cronômetro
    clock_t start_time = clock();

    srand(time(NULL));

    // Preenche o vetor com números aleatórios entre 0 e 1
    for (i = 0; i < TAM; i++) {
        num[i] = ((double)rand() / RAND_MAX);
    }

    // Algoritmo de ordenação (Bubblesort)
    for (i = 0; i < TAM; i++) {
        for (j = i + 1; j < TAM; j++) {
            if (num[j] < num[i]) {
                aux = num[j];
                num[j] = num[i];
                num[i] = aux;
            }
        }
    }

    // Para o cronômetro
    clock_t end_time = clock();

    // Calcula o tempo de execução em segundos
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Exibe o tempo de execução
    printf("\n\nTempo de execucao: %.6f segundos\n\n", elapsed_time);

    // Exibe os primeiros e últimos elementos do vetor ordenado
    printf("Vetor ordenado (primeiros e ultimos elementos):\n");
    for (int i = 0; i < 5; i++) {
        printf("%f\t", num[i]);
    }
    printf("...\t");
    for (int i = TAM - 5; i < TAM; i++) {
        printf("%f\t", num[i]);
    }

    return 0;
}

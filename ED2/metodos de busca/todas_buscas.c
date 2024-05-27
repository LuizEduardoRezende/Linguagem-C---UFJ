#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Função para realizar busca sequencial em um vetor
int buscaSequencial(int vetor[], int tamanho, int elemento) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == elemento) {
            return i; // Elemento encontrado, retorna a posição
        }
    }
    return -1; // Elemento não encontrado
}

// Função para realizar ordenação do vetor usando Bubble Sort
void bubbleSort(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                // Troca os elementos se estiverem fora de ordem
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

// Função para realizar busca binária em um vetor ordenado
int buscaBinaria(int vetor[], int inicio, int fim, int elemento) {
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (vetor[meio] == elemento) {
            return meio; // Elemento encontrado, retorna a posição
        }

        if (vetor[meio] < elemento) {
            inicio = meio + 1; // Descarta a metade inferior
        } else {
            fim = meio - 1; // Descarta a metade superior
        }
    }

    return -1; // Elemento não encontrado
}

int main() {
    int vetor[20] = {10, 5, 8, 15, 20, 7, 12, 3, 18, 1, 6, 11, 17, 2, 9, 4, 19, 13, 16, 14};
    int tamanho = 20;
    int elemento, posicao;

    // Ordena o vetor usando Bubble Sort
    bubbleSort(vetor, tamanho);

    // Solicita ao usuário o número a ser procurado
    printf("Digite o numero a ser procurado: ");
    scanf("%d", &elemento);

    // Realiza a busca sequencial no vetor
    posicao = buscaSequencial(vetor, tamanho, elemento);

    // Verifica se o elemento foi encontrado ou não usando busca sequencial
    if (posicao != -1) {
        printf("Elemento encontrado na posicao %d (usando busca sequencial).\n", posicao);
    } else {
        printf("Elemento nao encontrado no vetor (usando busca sequencial).\n");
    }

    // Realiza a busca binária no vetor
    posicao = buscaBinaria(vetor, 0, tamanho - 1, elemento);

    // Verifica se o elemento foi encontrado ou não usando busca binária
    if (posicao != -1) {
        printf("Elemento encontrado na posicao %d (usando busca binaria).\n", posicao);
    } else {
        printf("Elemento nao encontrado no vetor (usando busca binaria).\n");
    }

    return 0;
}

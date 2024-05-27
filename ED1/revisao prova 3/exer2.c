#include <stdio.h>
#include <stdlib.h>

typedef struct NOH {
    int data;
    struct NOH* next;
} NOH;

typedef NOH* Lista;

void inserirNoFinal(Lista* lista, int valor) {
    NOH* novoNoh = (NOH*)malloc(sizeof(NOH));
    if (novoNoh == NULL) {
        fprintf(stderr, "Erro: Falha na alocacao de memoria.\n");
        exit(1);
    }
    novoNoh->data = valor;
    novoNoh->next = NULL;

    if (*lista == NULL) {
        *lista = novoNoh;
    } else {
        NOH* atual = *lista;
        while (atual->next != NULL) {
            atual = atual->next;
        }
        atual->next = novoNoh;
    }
}

void concatenarListas(Lista* terceira, Lista primeira, Lista segunda) {
    NOH* atual = primeira;
    while (atual != NULL) {
        inserirNoFinal(terceira, atual->data);
        atual = atual->next;
    }

    atual = segunda;
    while (atual != NULL) {
        inserirNoFinal(terceira, atual->data);
        atual = atual->next;
    }
}

void imprimirLista(Lista lista) {
    NOH* atual = lista;
    while (atual != NULL) {
        printf("%d ", atual->data);
        atual = atual->next;
    }
    printf("\n");
}

int main() {
    Lista primeira = NULL;
    Lista segunda = NULL;
    Lista terceira = NULL;

    inserirNoFinal(&primeira, 1);
    inserirNoFinal(&primeira, 7);

    inserirNoFinal(&segunda, 3);
    inserirNoFinal(&segunda, 4);
    inserirNoFinal(&segunda, 8);

    concatenarListas(&terceira, primeira, segunda);

    printf("Primeira lista: ");
    imprimirLista(primeira);

    printf("Segunda lista: ");
    imprimirLista(segunda);

    printf("Terceira lista (concatenada): ");
    imprimirLista(terceira);

    // Liberando memória
    while (terceira != NULL) {
        NOH* temp = terceira->next;
        free(terceira);
        terceira = temp;
    }

    return 0;
}

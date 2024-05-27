#include <stdio.h>
#include <stdlib.h>

typedef struct NOH {
    int data;
    struct NOH* proximo;
} NOH;

typedef NOH* Lista;

void inserirNoInicio(Lista* lista, int valor) {
    NOH* novoNoh = (NOH*)malloc(sizeof(NOH));
    if (novoNoh == NULL) {
        fprintf(stderr, "Erro: Falha na alocacao de memoria.\n");
        exit(1);
    }
    novoNoh->data = valor;
    novoNoh->proximo = *lista;
    *lista = novoNoh;
}

void imprimirLista(Lista lista) {
    NOH* atual = lista;
    while (atual != NULL) {
        printf("%d ", atual->data);
        atual = atual->proximo;
    }
    printf("\n");
}

void inverterLista(Lista* lista) {
    NOH* atual = *lista;
    NOH* anterior = NULL;
    NOH* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }

    *lista = anterior; // O último nó se torna o novo primeiro nó
}

void liberarLista(Lista* lista) {
    NOH* atual = *lista;
    while (atual != NULL) {
        NOH* temp = atual->proximo;
        free(atual);
        atual = temp;
    }
    *lista = NULL;
}

int main() {
    Lista lista = NULL;

    inserirNoInicio(&lista, 1);
    inserirNoInicio(&lista, 2);
    inserirNoInicio(&lista, 3);
    inserirNoInicio(&lista, 4);

    printf("Lista original: ");
    imprimirLista(lista);

    inverterLista(&lista);

    printf("Lista invertida: ");
    imprimirLista(lista);

    liberarLista(&lista); // Liberar memória alocada para a lista

    return 0;
}

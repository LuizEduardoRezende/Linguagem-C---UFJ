#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
typedef struct NOH {
    int data;
    struct NOH* proximo;
} NOH;

typedef NOH* Lista;

// Função para criar um novo nó
NOH* criarNoh(int valor) {
    NOH* novoNoh = (NOH*)malloc(sizeof(NOH));
    if (novoNoh == NULL) {
        fprintf(stderr, "Erro: Falha na alocacao de memoria.\n");
        exit(1);
    }
    novoNoh->data = valor;
    novoNoh->proximo = NULL;
    return novoNoh;
}

// Função para inserir um nó ordenadamente na lista
void inserirOrdenado(Lista* lista, int valor) {
    NOH* novoNoh = criarNoh(valor);

    if (*lista == NULL || valor < (*lista)->data) {
        novoNoh->proximo = *lista;
        *lista = novoNoh;
    } else {
        NOH* atual = *lista;
        while (atual->proximo != NULL && valor >= atual->proximo->data) {
            atual = atual->proximo;
        }
        novoNoh->proximo = atual->proximo;
        atual->proximo = novoNoh;
    }
}

// Função para imprimir a lista
void imprimirLista(Lista lista) {
    NOH* atual = lista;
    while (atual != NULL) {
        printf("%d ", atual->data);
        atual = atual->proximo;
    }
    printf("\n");
}

// Função para liberar a memória alocada para a lista
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
    int elementos, valor;

    printf("Quantos elementos deseja inserir na lista? ");
    scanf("%d", &elementos);

    printf("Insira os elementos:\n");
    for (int i = 0; i < elementos; i++) {
        scanf("%d", &valor);
        inserirOrdenado(&lista, valor);
    }

    printf("Lista ordenada: ");
    imprimirLista(lista);

    liberarLista(&lista); // Liberar memória alocada para a lista

    return 0;
}

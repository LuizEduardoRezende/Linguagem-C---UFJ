#include <stdio.h>
#include <stdlib.h>

typedef struct NOH {
    int item;
    struct NOH* anterior;
    struct NOH* proximo;
} NOH;

typedef NOH* tipoLista;

tipoLista criarNoh(int valor) {
    tipoLista novoNoh = (tipoLista)malloc(sizeof(NOH));
    if (novoNoh == NULL) {
        fprintf(stderr, "Erro: Falha na alocacao de memoria.\n");
        exit(1);
    }
    novoNoh->item = valor;
    novoNoh->anterior = NULL;
    novoNoh->proximo = NULL;
    return novoNoh;
}

int numero(tipoLista L) {
    int count = 0;
    tipoLista atual = L;
    while (atual != NULL) {
        count++;
        atual = atual->proximo;
    }
    return count;
}

void troca(tipoLista L, int K, int v) {
    tipoLista atual = L;
    int indice = 1;
    while (atual != NULL && indice < K) {
        atual = atual->proximo;
        indice++;
    }
    if (atual != NULL) {
        atual->item = v;
    }
}

void insereEsq(tipoLista* L, int K, int v) {
    tipoLista novoNoh = criarNoh(v);
    if (*L == NULL) {
        *L = novoNoh;
    } else if (K == 1) {
        novoNoh->proximo = *L;
        (*L)->anterior = novoNoh;
        *L = novoNoh;
    } else {
        tipoLista atual = *L;
        int indice = 1;
        while (atual != NULL && indice < K) {
            atual = atual->proximo;
            indice++;
        }
        if (atual != NULL) {
            novoNoh->anterior = atual->anterior;
            novoNoh->proximo = atual;
            atual->anterior->proximo = novoNoh;
            atual->anterior = novoNoh;
        }
    }
}

void insereDir(tipoLista L, int K, int v) {
    tipoLista novoNoh = criarNoh(v);
    tipoLista atual = L;
    int indice = 1;
    while (atual != NULL && indice < K) {
        atual = atual->proximo;
        indice++;
    }
    if (atual != NULL) {
        novoNoh->anterior = atual;
        novoNoh->proximo = atual->proximo;
        if (atual->proximo != NULL) {
            atual->proximo->anterior = novoNoh;
        }
        atual->proximo = novoNoh;
    }
}

void banir(tipoLista* L, int v) {
    tipoLista atual = *L;
    while (atual != NULL) {
        tipoLista temp = atual->proximo;
        if (atual->item == v) {
            if (atual->anterior != NULL) {
                atual->anterior->proximo = atual->proximo;
            }
            if (atual->proximo != NULL) {
                atual->proximo->anterior = atual->anterior;
            }
            free(atual);
        }
        atual = temp;
    }
}

void imprimirLista(tipoLista L) {
    tipoLista atual = L;
    while (atual != NULL) {
        printf("%d ", atual->item);
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    tipoLista lista = NULL;

    for (int i = 1; i <= 5; i++) {
        insereEsq(&lista, 1, i);
    }

    printf("Lista inicial: ");
    imprimirLista(lista);

    int numElementos = numero(lista);
    printf("Numero de elementos na lista: %d\n", numElementos);

    troca(lista, 2, 10);
    printf("Apos a troca: ");
    imprimirLista(lista);

    insereEsq(&lista, 3, 7);
    printf("Apos a insercao a esquerda: ");
    imprimirLista(lista);

    insereDir(lista, 4, 8);
    printf("Apos a insercao a direita: ");
    imprimirLista(lista);

    banir(&lista, 3);
    printf("Apos banir o elemento 3: ");
    imprimirLista(lista);

    while (lista != NULL) {
        tipoLista temp = lista->proximo;
        free(lista);
        lista = temp;
    }

    return 0;
}

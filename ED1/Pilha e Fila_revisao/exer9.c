#include <stdio.h>

#define MAX_QUEUE_SIZE 100

struct Fila {
    int data[MAX_QUEUE_SIZE];
    int inicio, fim;
};

void inicializar(struct Fila *fila) {
    fila->inicio = -1;
    fila->fim = -1;
}

int estaVazia(struct Fila *fila) {
    return fila->inicio == -1;
}

int estaCheia(struct Fila *fila) {
    return (fila->fim + 1) % MAX_QUEUE_SIZE == fila->inicio;
}

void enfileirar(struct Fila *fila, int valor) {
    if (!estaCheia(fila)) {
        if (estaVazia(fila)) {
            fila->inicio = 0;
        }
        fila->fim = (fila->fim + 1) % MAX_QUEUE_SIZE;
        fila->data[fila->fim] = valor;
    } else {
        printf("Fila cheia. Nao e possivel adicionar mais elementos.\n");
    }
}

void intercalaFila(struct Fila *f1, struct Fila *f2, struct Fila *f3) {
    if (f1->fim - f1->inicio != f2->fim - f2->inicio) {
        printf("As filas nao possuem o mesmo tamanho.\n");
        return;
    }

    inicializar(f3);

    for (int i = f1->inicio, j = f2->inicio; i <= f1->fim && j <= f2->fim; i++, j++) {
        enfileirar(f3, f1->data[i]);
        enfileirar(f3, f2->data[j]);
    }
}

void imprimirFila(struct Fila *fila) {
    printf("Conteudo da fila:\n");
    if (!estaVazia(fila)) {
        int indice = fila->inicio;
        while (indice != fila->fim) {
            printf("%d\n", fila->data[indice]);
            indice = (indice + 1) % MAX_QUEUE_SIZE;
        }
        printf("%d\n", fila->data[fila->fim]);
    } else {
        printf("A fila esta vazia.\n");
    }
}

int main() {
    struct Fila fila1, fila2, fila3;
    inicializar(&fila1);
    inicializar(&fila2);
    inicializar(&fila3);

    // Exemplo de inserção nas filas
    enfileirar(&fila1, 1);
    enfileirar(&fila1, 3);
    enfileirar(&fila1, 5);

    enfileirar(&fila2, 2);
    enfileirar(&fila2, 4);
    enfileirar(&fila2, 6);

    intercalaFila(&fila1, &fila2, &fila3);

    imprimirFila(&fila3);

    return 0;
}

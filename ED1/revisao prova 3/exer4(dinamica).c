#include <stdio.h>
#include <stdlib.h>

typedef struct NOH {
    int data;
    struct NOH* proximo;
    struct NOH* anterior;
} NOH;

typedef struct Deque {
    NOH* frente;
    NOH* tras;
} Deque;

void inicializarDeque(Deque* deque) {
    deque->frente = NULL;
    deque->tras = NULL;
}

int estaVazio(Deque* deque) {
    return (deque->frente == NULL);
}

void inserirFrente(Deque* deque, int valor) {
    NOH* novoNoh = (NOH*)malloc(sizeof(NOH));
    if (novoNoh == NULL) {
        fprintf(stderr, "Erro: Falha na alocacao de memoria.\n");
        exit(1);
    }
    novoNoh->data = valor;
    novoNoh->proximo = NULL;
    novoNoh->anterior = NULL;

    if (estaVazio(deque)) {
        deque->frente = novoNoh;
        deque->tras = novoNoh;
    } else {
        novoNoh->proximo = deque->frente;
        deque->frente->anterior = novoNoh;
        deque->frente = novoNoh;
    }
}

void inserirTras(Deque* deque, int valor) {
    NOH* novoNoh = (NOH*)malloc(sizeof(NOH));
    if (novoNoh == NULL) {
        fprintf(stderr, "Erro: Falha na alocacao de memoria.\n");
        exit(1);
    }
    novoNoh->data = valor;
    novoNoh->proximo = NULL;
    novoNoh->anterior = NULL;

    if (estaVazio(deque)) {
        deque->frente = novoNoh;
        deque->tras = novoNoh;
    } else {
        novoNoh->anterior = deque->tras;
        deque->tras->proximo = novoNoh;
        deque->tras = novoNoh;
    }
}

int removerFrente(Deque* deque) {
    if (estaVazio(deque)) {
        printf("Erro: O deque esta vazio.\n");
        exit(1);
    }

    int valor = deque->frente->data;
    NOH* temp = deque->frente;

    if (deque->frente == deque->tras) {
        deque->frente = NULL;
        deque->tras = NULL;
    } else {
        deque->frente = deque->frente->proximo;
        deque->frente->anterior = NULL;
    }

    free(temp);
    return valor;
}

int removerTras(Deque* deque) {
    if (estaVazio(deque)) {
        printf("Erro: O deque esta vazio.\n");
        exit(1);
    }

    int valor = deque->tras->data;
    NOH* temp = deque->tras;

    if (deque->frente == deque->tras) {
        deque->frente = NULL;
        deque->tras = NULL;
    } else {
        deque->tras = deque->tras->anterior;
        deque->tras->proximo = NULL;
    }

    free(temp);
    return valor;
}

void imprimirDeque(Deque* deque) {
    NOH* atual = deque->frente;
    while (atual != NULL) {
        printf("%d ", atual->data);
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    Deque deque;
    inicializarDeque(&deque);

    inserirFrente(&deque, 1);
    inserirTras(&deque, 2);
    inserirFrente(&deque, 3);
    inserirTras(&deque, 4);

    printf("Deque: ");
    imprimirDeque(&deque);

    printf("Removido da frente: %d\n", removerFrente(&deque));
    printf("Removido de tras: %d\n", removerTras(&deque));
    inserirTras(&deque, 99);

    printf("Deque apos remocoes: ");
    imprimirDeque(&deque);

    // Liberar memória alocada para o deque
    while (!estaVazio(&deque)) {
        removerFrente(&deque);
    }

    return 0;
}

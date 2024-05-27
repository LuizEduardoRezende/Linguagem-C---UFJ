//aluno Luiz Eduardo Rezende Moraes
//matrícula: 202200162
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        printf("Erro: Falha na alocacao de memoria.\n");
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
        printf("Erro: Falha na alocacao de memoria.\n");
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

    int escolha;
    int valor;

    while (escolha != 6) {
        printf("\nMenu:\n");
        printf("1. Inserir na frente\n");
        printf("2. Inserir na tras\n");
        printf("3. Remover da frente\n");
        printf("4. Remover de tras\n");
        printf("5. Imprimir deque\n");
        printf("6. Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o valor a ser inserido na frente: ");
                scanf("%d", &valor);
                inserirFrente(&deque, valor);
                break;
            case 2:
                printf("Digite o valor a ser inserido na tras: ");
                scanf("%d", &valor);
                inserirTras(&deque, valor);
                break;
            case 3:
                printf("Removido da frente: %d\n", removerFrente(&deque));
                break;
            case 4:
                printf("Removido de tras: %d\n", removerTras(&deque));
                break;
            case 5:
                printf("Deque: ");
                imprimirDeque(&deque);
                break;
            case 6:
                // Liberar memória alocada
                while (!estaVazio(&deque)) {
                    removerFrente(&deque);
                }
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}

//aluno Luiz Eduardo Rezende Moraes
//matrícula: 202200162
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Deque {
    int data[MAX_SIZE];
    int frente;
    int tras;
} Deque;

void inicializarDeque(Deque *deque) {
    deque->frente = -1;
    deque->tras = -1;
}

int estaVazio(Deque *deque) {
    return (deque->frente == -1);
}

int estaCheio(Deque *deque) {
    return ((deque->frente == 0 && deque->tras == MAX_SIZE - 1) || (deque->frente == deque->tras + 1));
}

void inserirFrente(Deque *deque, int valor) {
    if (estaCheio(deque)) {
        printf("Erro: O deque esta cheio.\n");
        return;
    }

    if (deque->frente == -1) {
        deque->frente = 0;
        deque->tras = 0;
    } else if (deque->frente == 0) {
        deque->frente = MAX_SIZE - 1;
    } else {
        deque->frente--;
    }

    deque->data[deque->frente] = valor;
}

void inserirTras(Deque *deque, int valor) {
    if (estaCheio(deque)) {
        printf("Erro: O deque esta cheio.\n");
        return;
    }

    if (deque->frente == -1) {
        deque->frente = 0;
        deque->tras = 0;
    } else if (deque->tras == MAX_SIZE - 1) {
        deque->tras = 0;
    } else {
        deque->tras++;
    }

    deque->data[deque->tras] = valor;
}

int removerFrente(Deque *deque) {
    if (estaVazio(deque)) {
        printf("Erro: O deque esta vazio.\n");
        exit(1);
    }

    int valor = deque->data[deque->frente];

    if (deque->frente == deque->tras) {
        deque->frente = -1;
        deque->tras = -1;
    } else if (deque->frente == MAX_SIZE - 1) {
        deque->frente = 0;
    } else {
        deque->frente++;
    }

    return valor;
}

int removerTras(Deque *deque) {
    if (estaVazio(deque)) {
        printf("Erro: O deque esta vazio.\n");
        exit(1);
    }

    int valor = deque->data[deque->tras];

    if (deque->frente == deque->tras) {
        deque->frente = -1;
        deque->tras = -1;
    } else if (deque->tras == 0) {
        deque->tras = MAX_SIZE - 1;
    } else {
        deque->tras--;
    }

    return valor;
}

void imprimirDeque(Deque *deque) {
    if (estaVazio(deque)) {
        printf("Deque vazio.\n");
        return;
    }

    int i = deque->frente;

    while (1) {
        printf("%d ", deque->data[i]);

        if (i == deque->tras) {
            break;
        }

        if (i == MAX_SIZE - 1) {
            i = 0;
        } else {
            i++;
        }
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
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}

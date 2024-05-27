#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int chave;
    char nome[50];
    struct Node* next;
};

struct FilaDinamica {
    struct Node* inicio;
    struct Node* fim;
};

void inicializar(struct FilaDinamica* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

int estaVazia(struct FilaDinamica* fila) {
    return fila->inicio == NULL;
}

void enfileirar(struct FilaDinamica* fila, int chave, const char* nome) {
    struct Node* novoNode = (struct Node*)malloc(sizeof(struct Node));
    novoNode->chave = chave;
    strcpy(novoNode->nome, nome);
    novoNode->next = NULL;

    if (estaVazia(fila)) {
        fila->inicio = novoNode;
        fila->fim = novoNode;
    } else {
        fila->fim->next = novoNode;
        fila->fim = novoNode;
    }
}

void desenfileirar(struct FilaDinamica* fila) {
    if (!estaVazia(fila)) {
        struct Node* temp = fila->inicio;
        fila->inicio = fila->inicio->next;
        free(temp);
    }
}

void imprimirFila(struct FilaDinamica* fila) {
    printf("Conteudo da fila dinamica:\n");
    struct Node* current = fila->inicio;
    while (current != NULL) {
        printf("Chave: %d, Nome: %s\n", current->chave, current->nome);
        current = current->next;
    }
}

int buscarNomePorChave(struct FilaDinamica* fila, int chave, char* nomeEncontrado) {
    struct Node* current = fila->inicio;
    while (current != NULL) {
        if (current->chave == chave) {
            strcpy(nomeEncontrado, current->nome);
            return 1; // Nome encontrado
        }
        current = current->next;
    }
    return 0; // Nome não encontrado
}

void copiarFila(struct FilaDinamica* origem, struct FilaDinamica* destino) {
    inicializar(destino);

    struct Node* current = origem->inicio;
    while (current != NULL) {
        enfileirar(destino, current->chave, current->nome);
        current = current->next;
    }
}

int main() {
    struct FilaDinamica fila;
    inicializar(&fila);

    while (1) {
        printf("Opcoes:\n");
        printf("1. Inserir novo elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Imprimir fila\n");
        printf("4. Buscar nome por chave\n");
        printf("5. Copiar fila\n");
        printf("6. Sair\n");

        int escolha;
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: {
                int chave;
                char nome[50];
                printf("Digite a chave: ");
                scanf("%d", &chave);
                printf("Digite o nome: ");
                scanf("%s", nome);
                enfileirar(&fila, chave, nome);
                break;
            }
            case 2:
                desenfileirar(&fila);
                break;
            case 3:
                imprimirFila(&fila);
                break;
            case 4: {
                int chave;
                printf("Digite a chave para buscar o nome: ");
                scanf("%d", &chave);
                char nomeEncontrado[50];
                if (buscarNomePorChave(&fila, chave, nomeEncontrado)) {
                    printf("Nome encontrado: %s\n", nomeEncontrado);
                } else {
                    printf("Nome nao encontrado.\n");
                }
                break;
            }
            case 5: {
                struct FilaDinamica filaCopia;
                inicializar(&filaCopia);
                copiarFila(&fila, &filaCopia);
                printf("Fila copiada.\n");
                break;
            }
            case 6:
                return 0;
            default:
                printf("Opcao invalida. Escolha uma opcao valida.\n");
                break;
        }
    }

    // Liberar memória alocada para os nós
    while (!estaVazia(&fila)) {
        desenfileirar(&fila);
    }

    return 0;
}

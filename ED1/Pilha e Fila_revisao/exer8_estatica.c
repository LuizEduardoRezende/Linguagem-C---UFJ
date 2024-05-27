#include <stdio.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

struct Node {
    int chave;
    char nome[50];
};

struct FilaCircular {
    struct Node data[MAX_QUEUE_SIZE];
    int inicio, fim;
};

void inicializar(struct FilaCircular *fila) {
    fila->inicio = -1;
    fila->fim = -1;
}

int estaVazia(struct FilaCircular *fila) {
    return fila->inicio == -1;
}

int estaCheia(struct FilaCircular *fila) {
    return (fila->fim + 1) % MAX_QUEUE_SIZE == fila->inicio;
}

void enfileirar(struct FilaCircular *fila, int chave, const char *nome) {
    if (!estaCheia(fila)) {
        if (estaVazia(fila)) {
            fila->inicio = 0;
        }
        fila->fim = (fila->fim + 1) % MAX_QUEUE_SIZE;
        fila->data[fila->fim].chave = chave;
        strcpy(fila->data[fila->fim].nome, nome);
    } else {
        printf("Fila cheia. Nao e possivel adicionar mais elementos.\n");
    }
}

void desenfileirar(struct FilaCircular *fila) {
    if (!estaVazia(fila)) {
        if (fila->inicio == fila->fim) {
            fila->inicio = -1;
            fila->fim = -1;
        } else {
            fila->inicio = (fila->inicio + 1) % MAX_QUEUE_SIZE;
        }
    } else {
        printf("Fila vazia. Nao e possivel remover elementos.\n");
    }
}

void imprimirFila(struct FilaCircular *fila) {
    printf("Conteudo da fila circular:\n");
    if (!estaVazia(fila)) {
        int indice = fila->inicio;
        while (indice != fila->fim) {
            printf("Chave: %d, Nome: %s\n", fila->data[indice].chave, fila->data[indice].nome);
            indice = (indice + 1) % MAX_QUEUE_SIZE;
        }
        printf("Chave: %d, Nome: %s\n", fila->data[fila->fim].chave, fila->data[fila->fim].nome);
    } else {
        printf("A fila esta vazia.\n");
    }
}

int buscarNomePorChave(struct FilaCircular *fila, int chave, char *nomeEncontrado) {
    if (!estaVazia(fila)) {
        int indice = fila->inicio;
        while (indice != fila->fim) {
            if (fila->data[indice].chave == chave) {
                strcpy(nomeEncontrado, fila->data[indice].nome);
                return 1; // Nome encontrado
            }
            indice = (indice + 1) % MAX_QUEUE_SIZE;
        }
        if (fila->data[fila->fim].chave == chave) {
            strcpy(nomeEncontrado, fila->data[fila->fim].nome);
            return 1; // Nome encontrado
        }
    }
    return 0; // Nome nao encontrado
}

void copiarFila(struct FilaCircular *origem, struct FilaCircular *destino) {
    inicializar(destino);

    if (!estaVazia(origem)) {
        int indice = origem->inicio;
        while (indice != origem->fim) {
            enfileirar(destino, origem->data[indice].chave, origem->data[indice].nome);
            indice = (indice + 1) % MAX_QUEUE_SIZE;
        }
        enfileirar(destino, origem->data[origem->fim].chave, origem->data[origem->fim].nome);
    }
}

int main() {
    struct FilaCircular fila;
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
                struct FilaCircular filaCopia;
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

    return 0;
}

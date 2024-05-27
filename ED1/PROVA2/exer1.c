#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//aluno Luiz Eduardo Rezende Prova2 ED1

typedef struct No {
    char link[100];
    struct No* proximo;
} No;

typedef struct {
    No* topo;
} Pilha;

void inicializarPilha(Pilha* pilha) {
    pilha->topo = NULL;
}

int pilhaVazia(Pilha* pilha){
    if(pilha->topo == NULL)
        return 1;
    else
        return 0;
}

void empilhar(Pilha* pilha, const char* link) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }

    strcpy(novoNo->link, link);
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
}

void desempilhar(Pilha* pilha) {
    if (pilhaVazia(pilha) == 0) {
        No* temp = pilha->topo;
        pilha->topo = pilha->topo->proximo;
        free(temp);
    }
}

void moverParaTopo(Pilha* pilha, const char* link) {
    No* anterior = NULL;
    No* atual = pilha->topo;

    // Procurar o link e sua posição anterior
    while (atual != NULL && strcmp(atual->link, link) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Link nao encontrado na pilha.\n");
        return;
    }

    // Remover o link da sua posição original
    if (anterior != NULL) {
        anterior->proximo = atual->proximo;
    } else {
        pilha->topo = atual->proximo;
    }

    // Mover o link para o topo
    atual->proximo = pilha->topo;
    pilha->topo = atual;
}

void imprimirPilha(Pilha* pilha) {
    No* atual = pilha->topo;
    while (atual != NULL) {
        printf("%s\n", atual->link);
        atual = atual->proximo;
    }
}

void liberarPilha(Pilha* pilha) {
    while (!pilhaVazia(pilha)) {
        desempilhar(pilha);
    }
}

int main() {
    Pilha pilha;
    inicializarPilha(&pilha);

    int escolha;
    char link[100];

    do {
        printf("\nMenu:\n");
        printf("1. Empilhar link\n");
        printf("2. Mover link para o topo\n");
        printf("3. Imprimir pilha\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o link a ser empilhado: ");
                scanf("%s", link);
                fflush(stdin);
                empilhar(&pilha, link);
                break;
            case 2:
                printf("Digite o link a ser movido para o topo: ");
                scanf("%s", link);
                fflush(stdin);
                moverParaTopo(&pilha, link);
                break;
            case 3:
                printf("Conteudo da pilha:\n");
                imprimirPilha(&pilha);
                break;
            case 4:
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (escolha != 4);

    liberarPilha(&pilha);

    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define tamanhoDoEspaco 10

typedef struct ITEM {
    char palavra[30];
} tipoItem;

typedef struct NOH {
    tipoItem item;
    struct NOH *esquerda;
    struct NOH *direita;
} tipoNoh;

tipoItem criarItem(char palavra[]) {
    tipoItem item;
    strncpy(item.palavra, palavra, 30);
    return item;
}

tipoNoh *alocar() {
    tipoNoh *novoNoh = (tipoNoh*) malloc(sizeof(tipoNoh));
    if (novoNoh != NULL) {
        return novoNoh;
    } else {
        printf("Erro ao criar novo nó\n");
        exit(1); // interrompe o programa
    }
}

tipoNoh *inicializar() {
    return NULL;
}

tipoNoh *minimo(tipoNoh *raiz) {
    if (raiz != NULL) {
        tipoNoh *nohAuxiliar = raiz;
        while(nohAuxiliar->esquerda != NULL){
            nohAuxiliar = nohAuxiliar->esquerda;
        }
        return nohAuxiliar;
    }
    return NULL;
}

tipoNoh *rotacaoDireita(tipoNoh *raiz) {
    tipoNoh *nohAuxiliar = raiz->esquerda;
    raiz->esquerda = nohAuxiliar->direita;
    nohAuxiliar->direita = raiz;
    return nohAuxiliar;
}

tipoNoh *rotacaoEsquerda(tipoNoh *raiz) {
    tipoNoh *nohAuxiliar = raiz->direita;
    raiz->direita = nohAuxiliar->esquerda;
    nohAuxiliar->esquerda = raiz;
    return nohAuxiliar;
}

tipoNoh *splay(tipoNoh *raiz, char palavra[]) {
    if (raiz == NULL || strcmp(raiz->item.palavra, palavra) == 0) {
        return raiz;
    }

    if (strcmp(raiz->item.palavra, palavra) > 0) {
        if (raiz->esquerda == NULL) {
            return raiz;
        }

        if (strcmp(raiz->esquerda->item.palavra, palavra) > 0) {
            raiz->esquerda->esquerda = splay(raiz->esquerda->esquerda, palavra);
            raiz = rotacaoDireita(raiz);
        } else if (strcmp(raiz->esquerda->item.palavra, palavra) < 0) {
            raiz->esquerda->direita = splay(raiz->esquerda->direita, palavra);
            if (raiz->esquerda->direita != NULL) {
                raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
            }
        }

        return (raiz->esquerda == NULL) ? raiz : rotacaoDireita(raiz);
    } else {
        if (raiz->direita == NULL) {
            return raiz;
        }

        if (strcmp(raiz->direita->item.palavra, palavra) > 0) {
            raiz->direita->esquerda = splay(raiz->direita->esquerda, palavra);
            if (raiz->direita->esquerda != NULL) {
                raiz->direita = rotacaoDireita(raiz->direita);
            }
        } else if (strcmp(raiz->direita->item.palavra, palavra) < 0) {
            raiz->direita->direita = splay(raiz->direita->direita, palavra);
            raiz = rotacaoEsquerda(raiz);
        }

        return (raiz->direita == NULL) ? raiz : rotacaoEsquerda(raiz);
    }
}

tipoNoh *pesquisar(tipoNoh *raiz, char palavra[]) {
    return splay(raiz, palavra);
}

tipoNoh *inserir(tipoNoh *raiz, tipoItem item) {
    if (raiz == NULL) {
        tipoNoh *novoNoh = alocar();
        novoNoh->item = item;
        novoNoh->esquerda = NULL;
        novoNoh->direita = NULL;
        return novoNoh;
    } else {
        if (strcmp(item.palavra, raiz->item.palavra) > 0) {
            raiz->direita = inserir(raiz->direita, item);
        } else if (strcmp(item.palavra, raiz->item.palavra) < 0) {
            raiz->esquerda = inserir(raiz->esquerda, item);
        }
    }
    return raiz;
}

tipoNoh *remover(tipoNoh *raiz, char palavra[]) {
    if (raiz != NULL) {
        if (strcmp(palavra, raiz->item.palavra) > 0) {
            raiz->direita = remover(raiz->direita, palavra);
        } else if (strcmp(palavra, raiz->item.palavra) < 0) {
            raiz->esquerda = remover(raiz->esquerda, palavra);
        } else {
            if (raiz->esquerda == NULL && raiz->direita == NULL) {
                free(raiz);
                raiz = NULL;
                return NULL;
            } else if (raiz->esquerda == NULL && raiz->direita != NULL) {
                tipoNoh *nohAuxiliar = raiz->direita;
                free(raiz);
                raiz = NULL;
                return nohAuxiliar;
            } else if (raiz->esquerda != NULL && raiz->direita == NULL) {
                tipoNoh *nohAuxiliar = raiz->esquerda;
                free(raiz);
                raiz = NULL;
                return nohAuxiliar;
            } else {
                tipoNoh *nohAuxiliar = minimo(raiz->direita);
                tipoItem itemAuxiliar = nohAuxiliar->item;
                raiz = remover(raiz, itemAuxiliar.palavra);
                raiz->item = itemAuxiliar;
            }
        }
        return raiz;
    } else {
        return NULL;
    }
}

void imprimir(tipoNoh *raiz, int espaco) {
    if (raiz == NULL) {
        return;
    } else {
        espaco += tamanhoDoEspaco;
        imprimir(raiz->direita, espaco);
        printf("\n");
        for (int i = tamanhoDoEspaco; i < espaco; i++) {
            printf(" ");
        }
        printf("%s\n", raiz->item.palavra);
        imprimir(raiz->esquerda, espaco);
    }
}

void apagarArvore(tipoNoh *raiz) {
    if (raiz != NULL) {
        apagarArvore(raiz->esquerda);
        apagarArvore(raiz->direita);
        free(raiz);
        raiz = NULL;
    }
}

int main() {
    tipoNoh *raiz = inicializar();
    int opcao = -1;
    char palavra[30];

    while (opcao != 0) {
        printf("\n---Arvore atual---\n");
        imprimir(raiz, tamanhoDoEspaco);

        printf("\n---------------MENU---------------\n");
        printf("1: Inserir \n");
        printf("2: Remover \n");
        printf("3: Pesquisar \n");
        printf("0: SAIR \n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("\n------INSERINDO------\n");
                printf("Digite uma palavra (até 30 caracteres):\n");
                scanf("%s", palavra);
                raiz = inserir(raiz, criarItem(palavra));
                raiz = splay(raiz, palavra);
                break;

            case 2:
                printf("\n------REMOVENDO------\n");
                printf("Digite uma palavra para remover:\n");
                scanf("%s", palavra);
                raiz = splay(raiz, palavra);
                raiz = remover(raiz, palavra);
                break;

            case 3:
                printf("\n------PESQUISANDO------\n");
                printf("Digite uma palavra para pesquisar:\n");
                scanf("%s", palavra);
                raiz = pesquisar(raiz, palavra);
                if (strcmp(raiz->item.palavra, palavra) == 0) {
                    printf("\nElemento encontrado com sucesso!\n");
                } else {
                    printf("\nElemento não encontrado! \n");
                }
                break;

            case 0:
                printf("\nTchau! Até a próxima\n");
                break;

            default:
                printf("\nOpção inválida! \n");
                break;
        }
    }

    apagarArvore(raiz);

    return 0;
}

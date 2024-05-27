//aluno Luiz Eduardo Rezende Moraes
//matrícula: 202200162
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NOH {
    int data;
    struct NOH* proximo;
} NOH;

typedef NOH* Lista;

void inserirNoInicio(Lista* lista, int valor) {
    NOH* novoNoh = (NOH*)malloc(sizeof(NOH));
    if (novoNoh == NULL) {
        printf("Erro: Falha na alocacao de memoria.\n");
        exit(1);
    }
    novoNoh->data = valor;
    novoNoh->proximo = *lista;
    *lista = novoNoh;
}

void inserirNoMeio(Lista* lista, int valor, int posicao) {
    if (posicao < 1) {
        printf("Erro: Posicao invalida. A posicao deve ser maior ou igual a 1.\n");
        return;
    }

    NOH* novoNoh = (NOH*)malloc(sizeof(NOH));
    if (novoNoh == NULL) {
        printf("Erro: Falha na alocacao de memoria.\n");
        exit(1);
    }
    novoNoh->data = valor;

    if (posicao == 1 || *lista == NULL) {
        // Inserir no início ou se a lista estiver vazia
        novoNoh->proximo = *lista;
        *lista = novoNoh;
    } else {
        NOH* atual = *lista;
        int i;
        for (i = 1; i < posicao - 1 && atual->proximo != NULL; i++) {
            atual = atual->proximo;
        }
        novoNoh->proximo = atual->proximo;
        atual->proximo = novoNoh;
    }
}

void inserirNoFinal(Lista* lista, int valor) {
    NOH* novoNoh = (NOH*)malloc(sizeof(NOH));
    if (novoNoh == NULL) {
        printf("Erro: Falha na alocacao de memoria.\n");
        exit(1);
    }
    novoNoh->data = valor;
    novoNoh->proximo = NULL;

    if (*lista == NULL) {
        // Inserir no início se a lista estiver vazia
        *lista = novoNoh;
    } else {
        NOH* atual = *lista;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoNoh;
    }
}

void removerDoMeio(Lista* lista, int posicao) {
    if (posicao < 1) {
        printf("Erro: Posicao invalida. A posicao deve ser maior ou igual a 1.\n");
        return;
    }

    if (*lista == NULL) {
        printf("Erro: A lista esta vazia.\n");
        return;
    }

    if (posicao == 1) {
        // Remover o primeiro elemento
        NOH* temp = *lista;
        *lista = (*lista)->proximo;
        free(temp);
    } else {
        NOH* atual = *lista;
        NOH* anterior = NULL;
        int i;
        for (i = 1; i < posicao && atual != NULL; i++) {
            anterior = atual;
            atual = atual->proximo;
        }

        if (atual == NULL) {
            printf("Erro: Posicao nao encontrada.\n");
            return;
        }

        anterior->proximo = atual->proximo;
        free(atual);
    }
}

void removerDoInicio(Lista* lista) {
    if (*lista == NULL) {
        printf("Erro: A lista esta vazia.\n");
        exit(1);
    }

    NOH* temp = *lista;
    *lista = (*lista)->proximo;
    free(temp);
}

void removerDoFinal(Lista* lista) {
    if (*lista == NULL) {
        printf("Erro: A lista esta vazia.\n");
        exit(1);
    }

    if ((*lista)->proximo == NULL) {
        // Lista possui apenas um elemento
        free(*lista);
        *lista = NULL;
    } else {
        NOH* atual = *lista;
        NOH* anterior = NULL;
        while (atual->proximo != NULL) {
            anterior = atual;
            atual = atual->proximo;
        }
        anterior->proximo = NULL;
        free(atual);
    }
}

void imprimirLista(Lista lista) {
    NOH* atual = lista;
    while (atual != NULL) {
        printf("%d ", atual->data);
        atual = atual->proximo;
    }
    printf("\n");
}

void inverterLista(Lista* lista) {
    NOH* atual = *lista;
    NOH* anterior = NULL;
    NOH* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }

    *lista = anterior; // O último nó se torna o novo primeiro nó
}

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
    int escolha;
    int valor;
    int posicao;

    while (escolha != 9) {
        printf("\nMenu:\n");
        printf("1. Inserir no inicio\n");
        printf("2. Inserir no meio\n");
        printf("3. Inserir no final\n");
        printf("4. Remover do inicio\n");
        printf("5. Remover do meio\n");
        printf("6. Remover do final\n");
        printf("7. Imprimir lista\n");
        printf("8. Inverter lista\n");
        printf("9. Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o valor a ser inserido no inicio: ");
                scanf("%d", &valor);
                inserirNoInicio(&lista, valor);
                break;
            case 2:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                printf("Digite a posicao: ");
                scanf("%d", &posicao);
                inserirNoMeio(&lista, valor, posicao);
                break;
            case 3:
                printf("Digite o valor a ser inserido no final: ");
                scanf("%d", &valor);
                inserirNoFinal(&lista, valor);
                break;
            case 4:
                removerDoInicio(&lista);
                printf("Removido do inicio.\n");
                break;
            case 5:
                printf("Digite a posicao a ser removida: ");
                scanf("%d", &posicao);
                removerDoMeio(&lista, posicao);
                printf("Removido do meio.\n");
                break;
            case 6:
                removerDoFinal(&lista);
                printf("Removido do final.\n");
                break;
            case 7:
                printf("Lista: ");
                imprimirLista(lista);
                break;
            case 8:
                inverterLista(&lista);
                printf("Lista invertida: ");
                imprimirLista(lista);
                break;
            case 9:
                liberarLista(&lista);
                printf("Saindo do programa.\n");
                return 0;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    }

    return 0;
}

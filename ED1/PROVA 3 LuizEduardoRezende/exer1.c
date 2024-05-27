//aluno Luiz Eduardo Rezende Moraes
//matrícula: 202200162
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
    char nome[100];
    int matricula;
} tipoAluno;

typedef struct NOH {
    tipoAluno Aluno;
    struct NOH* proximo;
} NOH;

typedef NOH* ListaAlunos;

void inserirNoInicio(ListaAlunos* lista, char nome[], int matricula) {
    NOH* novoNoh = (NOH*)malloc(sizeof(NOH));
    if (novoNoh == NULL) {
        printf("Erro: Falha na alocacao de memoria.\n");
        exit(1);
    }
    strcpy(novoNoh->Aluno.nome, nome);
    novoNoh->Aluno.matricula = matricula;
    novoNoh->proximo = *lista;
    *lista = novoNoh;
}

void inserirNoMeio(ListaAlunos* lista, char nome[], int matricula, int posicao) {
    if (posicao < 1) {
        printf("Erro: Posicao invalida. A posicao deve ser maior ou igual a 1.\n");
        return;
    }

    NOH* novoNoh = (NOH*)malloc(sizeof(NOH));
    if (novoNoh == NULL) {
        printf("Erro: Falha na alocacao de memoria.\n");
        exit(1);
    }
    strcpy(novoNoh->Aluno.nome, nome);
    novoNoh->Aluno.matricula = matricula;

    if (posicao == 1 || *lista == NULL) {
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

void inserirNoFinal(ListaAlunos* lista, char nome[], int matricula) {
    NOH* novoNoh = (NOH*)malloc(sizeof(NOH));
    if (novoNoh == NULL) {
        printf("Erro: Falha na alocacao de memoria.\n");
        exit(1);
    }
    strcpy(novoNoh->Aluno.nome, nome);
    novoNoh->Aluno.matricula = matricula;
    novoNoh->proximo = NULL;

    if (*lista == NULL) {
        *lista = novoNoh;
    } else {
        NOH* atual = *lista;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoNoh;
    }
}

void removerNoInicio(ListaAlunos* lista) {
    if (*lista == NULL) {
        printf("Erro: A lista esta vazia.\n");
        return;
    }

    NOH* temp = *lista;
    *lista = (*lista)->proximo;
    free(temp);
}

void removerNoMeio(ListaAlunos* lista, int posicao) {
    if (posicao < 1) {
        printf("Erro: Posicao invalida. A posicao deve ser maior ou igual a 1.\n");
        return;
    }

    if (*lista == NULL) {
        printf("Erro: A lista esta vazia.\n");
        return;
    }

    if (posicao == 1) {
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

void removerNoFinal(ListaAlunos* lista) {
    if (*lista == NULL) {
        printf("Erro: A lista esta vazia.\n");
        return;
    }

    if ((*lista)->proximo == NULL) {
        // A lista tem apenas um elemento
        free(*lista);
        *lista = NULL;
        return;
    }

    NOH* atual = *lista;
    NOH* anterior = NULL;
    while (atual->proximo != NULL) {
        anterior = atual;
        atual = atual->proximo;
    }

    anterior->proximo = NULL;
    free(atual);
}

void imprimirLista(ListaAlunos lista) {
    NOH* atual = lista;
    int posicao = 1;
    while (atual != NULL) {
        printf("Posicao %d: Nome: %s, Matricula: %d\n", posicao, atual->Aluno.nome, atual->Aluno.matricula);
        atual = atual->proximo;
        posicao++;
    }
    printf("\n");
}

void liberarLista(ListaAlunos* lista) {
    while (*lista != NULL) {
        NOH* temp = *lista;
        *lista = (*lista)->proximo;
        free(temp);
    }
}

void ordenarListaPorNome(ListaAlunos* lista) {
    if (*lista == NULL || (*lista)->proximo == NULL) {
        return; // Lista vazia ou com apenas um elemento, já está ordenada
    }

    ListaAlunos listaOrdenada = NULL;

    while (*lista != NULL) {
        NOH* atual = *lista;
        *lista = (*lista)->proximo;

        if (listaOrdenada == NULL || strcmp(atual->Aluno.nome, listaOrdenada->Aluno.nome) < 0) {
            // Inserir no início da lista ordenada
            atual->proximo = listaOrdenada;
            listaOrdenada = atual;
        } else {
            // Encontrar o local de inserção na lista ordenada
            NOH* temp = listaOrdenada;
            while (temp->proximo != NULL && strcmp(atual->Aluno.nome, temp->proximo->Aluno.nome) >= 0) {
                temp = temp->proximo;
            }
            atual->proximo = temp->proximo;
            temp->proximo = atual;
        }
    }

    *lista = listaOrdenada; // Atualiza a lista original com a lista ordenada
}

int main() {
    ListaAlunos lista = NULL;
    int escolha;
    char nome[100];
    int matricula;
    int posicao;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Inserir Aluno no Inicio\n");
        printf("2. Inserir Aluno no Meio\n");
        printf("3. Inserir Aluno no Final\n");
        printf("4. Remover Aluno no Inicio\n");
        printf("5. Remover Aluno no Meio\n");
        printf("6. Remover Aluno no Final\n");
        printf("7. Imprimir lista\n");
        printf("8. Ordenar lista por nome.\n");
        printf("9. Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o nome do Aluno: ");
                scanf("%s", nome);
                printf("Digite a matricula do Aluno: ");
                scanf("%d", &matricula);
                inserirNoInicio(&lista, nome, matricula);
                break;
            case 2:
                printf("Digite o nome do Aluno: ");
                scanf("%s", nome);
                printf("Digite a matricula do Aluno: ");
                scanf("%d", &matricula);
                printf("Digite a posicao (1 em diante): ");
                scanf("%d", &posicao);
                inserirNoMeio(&lista, nome, matricula, posicao);
                break;
            case 3:
                printf("Digite o nome do Aluno: ");
                scanf("%s", nome);
                printf("Digite a matricula do Aluno: ");
                scanf("%d", &matricula);
                inserirNoFinal(&lista, nome, matricula);
                break;
            case 4:
                removerNoInicio(&lista);
                break;
            case 5:
                printf("Digite a posicao a ser removida (1 em diante): ");
                scanf("%d", &posicao);
                removerNoMeio(&lista, posicao);
                break;
            case 6:
                removerNoFinal(&lista);
                break;
            case 7:
                imprimirLista(lista);
                break;
            case 8:
                ordenarListaPorNome(&lista);
                break;
            case 9:
                printf("Saindo do programa.\n");
                liberarLista(&lista);
                return 0;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}

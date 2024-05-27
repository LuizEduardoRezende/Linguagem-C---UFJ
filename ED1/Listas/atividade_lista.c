#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//aluno: Luiz Eduardo Rezende Moraes
typedef struct aluno {
    int cpf;
    char nome[50];
} tipo_aluno;

typedef struct NOH {
    tipo_aluno aluno;
    struct NOH* proximo;
} * tipo_lista;

tipo_lista criarNOH(tipo_aluno novoAluno) {
    tipo_lista novoNOH = (tipo_lista)malloc(sizeof(struct NOH));

    if (novoNOH == NULL) {
        printf("\nErro ao alocar memória.\n");
        return NULL;
    } else {
        novoNOH->aluno = novoAluno;
        novoNOH->proximo = NULL;
        return novoNOH;
    }
}

tipo_lista inserirInico(tipo_aluno novoAluno, tipo_lista inicio) {
    tipo_lista novoNOH = criarNOH(novoAluno);

    if (inicio == NULL) {
        return novoNOH;
    } else {
        novoNOH->proximo = inicio;
        return novoNOH;
    }
}

tipo_lista inserirFinal(tipo_aluno novoAluno, tipo_lista lista) {
    tipo_lista novoNOH = criarNOH(novoAluno);

    if (lista == NULL) {
        return novoNOH;
    } else {
        tipo_lista listaAuxiliar = lista;

        while (listaAuxiliar->proximo != NULL) {
            listaAuxiliar = listaAuxiliar->proximo;
        }

        listaAuxiliar->proximo = novoNOH;
        return lista;
    }
}

tipo_lista removerInicio(tipo_lista lista) {
    if (lista == NULL) {
        printf("A lista esta vazia.\n");
        return NULL;
    } else {
        tipo_lista novoInicio = lista->proximo;
        free(lista);
        return novoInicio;
    }
}

tipo_lista removerFinal(tipo_lista lista) {
    if (lista == NULL) {
        printf("A lista esta vazia.\n");
        return NULL;
    } else if (lista->proximo == NULL) {
        // Se houver apenas um nó na lista, libere-o e retorne NULL
        free(lista);
        return NULL;
    } else {
        tipo_lista listaAuxiliar = lista;
        while (listaAuxiliar->proximo->proximo != NULL) {
            listaAuxiliar = listaAuxiliar->proximo;
        }
        free(listaAuxiliar->proximo);
        listaAuxiliar->proximo = NULL;
        return lista;
    }
}

void exibir(tipo_lista lista) {
    printf("\n---- LISTA ----\n");

    if (lista == NULL) {
        printf("Vazia\n");
    } else {
        tipo_lista listaAuxiliar = lista;

        while (listaAuxiliar != NULL) {
            printf("[%s - %d] ", listaAuxiliar->aluno.nome, listaAuxiliar->aluno.cpf);
            listaAuxiliar = listaAuxiliar->proximo;
        }
        printf("\n");
    }
}

int main() {
    tipo_lista lista = NULL;
    tipo_aluno novoAluno1;
    int opcao = -1;

    do {
        printf("\nEscolha uma opcao:\n");
        printf("1- Adicionar aluno no inicio da lista.\n");
        printf("2- Adicionar aluno no final da lista.\n");
        printf("3- Remover aluno do inicio da lista.\n");
        printf("4- Remover aluno do final da lista.\n");
        printf("5- Exibir lista.\n");
        printf("6- Sair do menu.\n");
        printf("Digite a opcao escolhida: ");
        scanf("%d", &opcao);
        getchar(); // Consumir o caractere de nova linha

        switch (opcao) {
            case 1:
                printf("Digite o nome do aluno: ");
                fgets(novoAluno1.nome, sizeof(novoAluno1.nome), stdin);
                novoAluno1.nome[strcspn(novoAluno1.nome, "\n")] = '\0'; // Remover o caractere de nova linha

                printf("Digite a cpf do aluno: ");
                scanf("%d", &novoAluno1.cpf);
                getchar(); // Consumir o caractere de nova linha

                lista = inserirInico(novoAluno1, lista);
                break;

            case 2:
                printf("Digite o nome do aluno: ");
                fgets(novoAluno1.nome, sizeof(novoAluno1.nome), stdin);
                novoAluno1.nome[strcspn(novoAluno1.nome, "\n")] = '\0'; // Remover o caractere de nova linha

                printf("Digite a cpf do aluno: ");
                scanf("%d", &novoAluno1.cpf);
                getchar(); // Consumir o caractere de nova linha

                lista = inserirFinal(novoAluno1, lista);
                break;

            case 3:
                lista = removerInicio(lista);
                break;

            case 4:
                lista = removerFinal(lista);
                break;

            case 5:
                exibir(lista);
                break;

            case 6:
                printf("Menu encerrado.\n");
                break;

            default:
                printf("Digite uma opcao valida.\n");
                break;
        }
    } while (opcao != 6);

    // Libere a memória alocada para os nós da lista antes de sair do programa
    while (lista != NULL) {
        tipo_lista proximo = lista->proximo;
        free(lista);
        lista = proximo;
    }

    return 0;
}

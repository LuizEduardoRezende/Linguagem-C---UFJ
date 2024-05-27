//aluno Luiz Eduardo Rezende Moraes
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct aluno
{
    char nome[50];
    int cpf;
} tipoAluno;

typedef struct ITEM
{
    tipoAluno aluno;
    struct ITEM *anterior;
    struct ITEM *proximo;
} *tipoLista;

tipoLista criarItem(tipoAluno novoAluno)
{
    tipoLista novoItem = (tipoLista)malloc(sizeof(struct ITEM));

    if (novoItem == NULL)
    {
        printf("\nErro ao criar item!\n");
        return NULL;
    }
    else
    {
        novoItem->aluno = novoAluno;
        novoItem->proximo = NULL;
        novoItem->anterior = NULL;
        return novoItem;
    }
}


tipoLista inserirInicio(tipoAluno novoAluno, tipoLista lista)
{
    tipoLista novoItem = criarItem(novoAluno);

    if (lista == NULL)
    {
        return novoItem;
    }
    else
    {
        lista->anterior = novoItem;
        novoItem->proximo = lista;
        return novoItem;
    }
}

tipoLista inserirFinal(tipoAluno novoAluno, tipoLista lista)
{
    tipoLista novoItem = criarItem(novoAluno);

    if (lista == NULL)
    {
        return novoItem;
    }
    else
    {
        tipoLista listaAuxiliar = lista;

        while (listaAuxiliar->proximo != NULL)
        {
            listaAuxiliar = listaAuxiliar->proximo;
        }

        listaAuxiliar->proximo = novoItem;
        novoItem->anterior = listaAuxiliar;
        return lista;
    }
}

tipoLista inserirMeio(tipoAluno novoAluno, char nomeAlvo[], tipoLista lista)
{
    tipoLista novoItem = criarItem(novoAluno);

    if (lista == NULL)
    {
        return novoItem;
    }
    else
    {
        tipoLista listaAuxiliar = lista;

        while (listaAuxiliar != NULL)
        {
            if (strcmp(nomeAlvo, listaAuxiliar->aluno.nome) == 0)
            {
                if (listaAuxiliar->proximo != NULL)
                {
                    novoItem->proximo = listaAuxiliar->proximo;
                    listaAuxiliar->proximo->anterior = novoItem;
                }

                listaAuxiliar->proximo = novoItem;
                novoItem->anterior = listaAuxiliar;
                return lista;
            }
            listaAuxiliar = listaAuxiliar->proximo;
        }

        // Se o nomeAlvo não for encontrado, apenas insira no final.
        lista = inserirFinal(novoAluno, lista);
        return lista;
    }
}

tipoLista removerInicio(tipoLista lista)
{
    tipoLista listaAuxiliar = lista;

    if (listaAuxiliar == NULL)
    {
        printf("\nVazia!\n");
    }
    else
    {
        if (listaAuxiliar->proximo == NULL)
        {
            free(listaAuxiliar);
            listaAuxiliar = NULL;
        }
        else
        {
            listaAuxiliar = lista->proximo;
            listaAuxiliar->anterior = NULL;
            free(lista);
            lista = NULL;
        }
    }
    return listaAuxiliar;
}

tipoLista removerMeio(char nomeAlunoRemover[], tipoLista lista)
{
    if (lista == NULL)
    {
        printf("\nLista vazia!\n");
    }
    else
    {
        tipoLista listaAuxiliar = lista;

        while (listaAuxiliar != NULL)
        {
            if (strcmp(nomeAlunoRemover, listaAuxiliar->aluno.nome) == 0)
            {
                tipoLista itemDescartar = listaAuxiliar;

                if (listaAuxiliar->anterior != NULL)
                {
                    listaAuxiliar->anterior->proximo = listaAuxiliar->proximo;
                }

                if (listaAuxiliar->proximo != NULL)
                {
                    listaAuxiliar->proximo->anterior = listaAuxiliar->anterior;
                }

                if (lista == itemDescartar)
                {
                    lista = lista->proximo;
                }

                free(itemDescartar);
                itemDescartar = NULL;

                return lista;
            }
            listaAuxiliar = listaAuxiliar->proximo;
        }

        printf("\nAluno com o nome \"%s\" nao encontrado na lista!\n", nomeAlunoRemover);
    }

    return lista;
}

tipoLista removerFinal(tipoLista lista)
{
    tipoLista listaAuxiliar = lista;

    if (listaAuxiliar == NULL)
    {
        printf("\nVazia!\n");
    }
    else
    {
        if (listaAuxiliar->proximo == NULL)
        {
            free(listaAuxiliar);
            listaAuxiliar = NULL;
        }
        else
        {
            while (listaAuxiliar->proximo != NULL)
            {
                listaAuxiliar = listaAuxiliar->proximo;
            }

            tipoLista itemDescartar;
            itemDescartar = listaAuxiliar;

            listaAuxiliar->anterior->proximo = NULL;
            itemDescartar->anterior = NULL;

            free(itemDescartar);
            itemDescartar = NULL;

            return lista;
        }
    }

    return listaAuxiliar;
}

void exibir(tipoLista lista)
{
    printf("\n---Lista atual---\n");

    if (lista == NULL)
    {
        printf("\nVazia!\n");
    }
    else
    {
        tipoLista listaAuxiliar = lista;

        while (listaAuxiliar != NULL)
        {
            printf("[%s - %d] ", listaAuxiliar->aluno.nome, listaAuxiliar->aluno.cpf);
            listaAuxiliar = listaAuxiliar->proximo;
        }
    }
}

void pesquisar(char nome[], tipoLista lista)
{
    int contador = 0;
    tipoLista listaAuxiliar = lista;

    while (listaAuxiliar != NULL)
    {
        if (strcmp(nome, listaAuxiliar->aluno.nome) == 0)
        {
            contador++;
        }
        listaAuxiliar = listaAuxiliar->proximo;
    }

    printf("\nHouve %d ocorrencia(s) do nome %s\n", contador, nome);
}

int main()
{
    int opcao = -1;
    tipoAluno aluno;
    tipoLista lista = NULL;
    char nomeBuscado[50];

    do
    {
        exibir(lista);

        printf("\nDIGITE 0 PARA SAIR\n");
        printf("1: Inserir no inicio\n");
        printf("2: Inserir no final\n");
        printf("3: Remover no inicio\n");
        printf("4: Remover no final\n");
        printf("5: Inerir no meio\n");
        printf("6: Remover no meio\n");
        printf("7: Pesquisar\n");

        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 0:
            printf("Menu encerrado.\n");
            break;
        case 1:
            printf("Digite o nome do aluno: ");
            fgets(aluno.nome, sizeof(aluno.nome), stdin);
            aluno.nome[strcspn(aluno.nome, "\n")] = '\0';

            printf("Digite o numero de cpf: ");
            scanf("%d", &aluno.cpf);
            getchar();

            lista = inserirInicio(aluno, lista);
            break;

        case 2:
            printf("Digite o nome do aluno: ");
            fgets(aluno.nome, sizeof(aluno.nome), stdin);
            aluno.nome[strcspn(aluno.nome, "\n")] = '\0';

            printf("Digite o numero de cpf: ");
            scanf("%d", &aluno.cpf);
            getchar();

            lista = inserirFinal(aluno, lista);
            break;

        case 3:
            lista = removerInicio(lista);
            break;

        case 4:
            lista = removerFinal(lista);
            break;

        case 5:
            printf("Digite o nome do aluno: ");
            fgets(aluno.nome, sizeof(aluno.nome), stdin);
            aluno.nome[strcspn(aluno.nome, "\n")] = '\0';

            printf("Digite o numero de cpf: ");
            scanf("%d", &aluno.cpf);
            getchar();

            printf("Digite o nome que sera o anterior desse aluno.\n");
            fgets(nomeBuscado, sizeof(nomeBuscado), stdin);
            nomeBuscado[strcspn(nomeBuscado, "\n")] = '\0';

            lista = inserirMeio(aluno, nomeBuscado, lista);
            break;

        case 6:
            printf("Digite o nome do aluno que sera removido.\n");
            fgets(nomeBuscado, sizeof(nomeBuscado), stdin);
            nomeBuscado[strcspn(nomeBuscado, "\n")] = '\0';

            lista = removerMeio(nomeBuscado, lista);
            break;
        case 7:
            printf("Digite um nome\n");
            fgets(nomeBuscado, sizeof(nomeBuscado), stdin);
            nomeBuscado[strcspn(nomeBuscado, "\n")] = '\0';
            pesquisar(nomeBuscado, lista);
            break;

        default:
            printf("Opcao invalida!\n");
            break;
        }

    } while (opcao != 0);

    while (lista != NULL)
    {
        tipoLista proximo = lista->proximo;
        free(lista);
        lista = proximo;
    }
    return 0;
}

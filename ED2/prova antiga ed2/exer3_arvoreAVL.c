#include <stdio.h>
#include <stdlib.h>

#define tamanhoDoEspaco 10

typedef struct ITEM
{
    int valor;
} tipoItem;

typedef struct NOH
{
    tipoItem item;
    struct NOH *esquerda;
    struct NOH *direita;
    int fatorBalanceamento;
    int altura;
} tipoNoh;

tipoNoh *inicializar()
{
    return NULL;
}

void imprimirComFatorBalanceamento(tipoNoh *raiz, int espaco)
{
    if (raiz == NULL)
    {
        return;
    }
    else
    {
        espaco += tamanhoDoEspaco;

        imprimirComFatorBalanceamento(raiz->direita, espaco);

        printf("\n");
        for (int i = tamanhoDoEspaco; i < espaco; i++)
        {
            printf(" ");
        }

        printf("%d (%d)", raiz->item.valor, raiz->fatorBalanceamento);

        imprimirComFatorBalanceamento(raiz->esquerda, espaco);
    }
}

int alturaNoh(tipoNoh *raiz)
{
    if (raiz == NULL)
        return -1;
    else
        return raiz->altura;
}

int fatorBalanceamento(tipoNoh *raiz)
{
    return labs(alturaNoh(raiz->esquerda) - alturaNoh(raiz->direita));
}

int maior(int x, int y)
{
    return (x > y) ? x : y;
}

void rotacaoDireita(tipoNoh **raiz)
{
    tipoNoh *nohAuxiliar;

    nohAuxiliar = (*raiz)->esquerda;
    (*raiz)->esquerda = nohAuxiliar->direita;
    nohAuxiliar->direita = *raiz;

    (*raiz)->altura = maior(alturaNoh((*raiz)->esquerda), alturaNoh((*raiz)->direita)) + 1;
    nohAuxiliar->altura = maior(alturaNoh(nohAuxiliar->esquerda), (*raiz)->altura) + 1;

    *raiz = nohAuxiliar;
}

void rotacaoEsquerda(tipoNoh **raiz)
{
    tipoNoh *nohAuxiliar;

    nohAuxiliar = (*raiz)->direita;
    (*raiz)->direita = nohAuxiliar->esquerda;
    nohAuxiliar->esquerda = *raiz;

    (*raiz)->altura = maior(alturaNoh((*raiz)->esquerda), alturaNoh((*raiz)->direita)) + 1;
    nohAuxiliar->altura = maior(alturaNoh(nohAuxiliar->esquerda), (*raiz)->altura) + 1;

    *raiz = nohAuxiliar;
}

void rotacaoEsquerdaDireita(tipoNoh **raiz)
{
    rotacaoEsquerda(&(*raiz)->esquerda);
    rotacaoDireita(raiz);
}

void rotacaoDireitaEsquerda(tipoNoh **raiz)
{
    rotacaoDireita(&(*raiz)->direita);
    rotacaoEsquerda(raiz);
}

int inserir(tipoNoh **raiz, int valor, int *rotacoes)
{
    int controle;

    if (*raiz == NULL)
    {
        tipoNoh *nohAuxiliar = (tipoNoh *)malloc(sizeof(tipoNoh));
        if (nohAuxiliar != NULL)
        {
            nohAuxiliar->item.valor = valor;
            nohAuxiliar->altura = 0;
            nohAuxiliar->esquerda = NULL;
            nohAuxiliar->direita = NULL;
            *raiz = nohAuxiliar;
            return 1;
        }
        else
        {
            printf("Erro ao criar novo nó\n");
            exit(1);
        }
    }

    tipoNoh *nohAtual;
    nohAtual = *raiz;

    if (valor < nohAtual->item.valor)
    {
        if ((controle = inserir(&(nohAtual->esquerda), valor, rotacoes)) == 1)
        {
            if (fatorBalanceamento(nohAtual) >= 2)
            {
                if (valor < (*raiz)->esquerda->item.valor)
                {
                    rotacaoDireita(raiz);
                    (*rotacoes)++;
                }
                else
                {
                    rotacaoEsquerdaDireita(raiz);
                    (*rotacoes)++;
                }
            }
        }
    }
    else
    {
        if (valor > nohAtual->item.valor)
        {
            if ((controle = inserir(&(nohAtual->direita), valor, rotacoes)) == 1)
            {
                if (fatorBalanceamento(nohAtual) >= 2)
                {
                    if (valor > (*raiz)->direita->item.valor)
                    {
                        rotacaoEsquerda(raiz);
                        (*rotacoes)++;
                    }
                    else
                    {
                        rotacaoDireitaEsquerda(raiz);
                        (*rotacoes)++;
                    }
                }
            }
        }
        else
        {
            printf("\nValor Duplicado!\n");
            return 0;
        }
    }

    nohAtual->altura = maior(alturaNoh(nohAtual->esquerda), alturaNoh(nohAtual->direita)) + 1;
    return controle;
}

int main()
{
    tipoNoh *raiz = inicializar();
    int opcao = -1;
    int valor = 0;
    int rotacoes = 0;

    while (opcao != 0)
    {
        printf("\n---Árvore Atual---\n");
        imprimirComFatorBalanceamento(raiz, tamanhoDoEspaco);
        printf("\nNúmero total de rotações: %d\n", rotacoes);

        valor = 0;
        printf("\n---------------MENU---------------\n");
        printf("1: Inserir \n");
        printf("0: SAIR \n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n------INSERINDO------\n");
            printf("Digite um valor\n");
            scanf("%d", &valor);
            inserir(&raiz, valor, &rotacoes);
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

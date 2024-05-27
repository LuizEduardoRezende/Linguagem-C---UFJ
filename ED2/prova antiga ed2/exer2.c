#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAMANHO 500

int vetor[TAMANHO];

void inserir()
{
    for (int i = 0; i < TAMANHO; i++)
    {
        vetor[i] = rand() % 500;
    }
}

int busca(int *vetor, int valor, int tamanho)
{
    for (int indice = 0; indice < tamanho; indice++)
    {
        if (vetor[indice] == valor)
        {
            return indice;
        }
    }
    return -1;
}

int main()
{
    int caso;

    inserir();

    printf("Vetor gerado:\n");
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n\nEscolha uma das opçoes:\n");
    printf("1- Buscar um valor do vetor pela posicao dele\n");
    printf("0- Sair e fechar o programa\n");
    scanf("%d", &caso);

    switch (caso)
    {
    case 1:
    {
        printf("\nDigite o numero desejado para identificar sua posicao: ");
        int escolha;
        scanf("%d", &escolha);
        int posicao = busca(vetor, escolha, TAMANHO);

        if (posicao != -1)
        {
            printf("O numero %d esta na posicao %d do vetor.\n", escolha, posicao);
        }
        else
        {
            printf("O numero %d nao foi encontrado no vetor.\n", escolha);
        }
        break;
    }

    case 0:
        printf("\nAte logo!\n");
        exit(0);
        break;

    default:
        printf("\nNuMERO ERRADO!\n");
        break;
    }

    return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
typedef struct aluno                                   // variáveis exer 9
{
    char nome[50];
    int matricula;
    float n1, n2, n3, media;
}tipoaluno;
tipoaluno aluno;

#include "exercicios.h"

int main()
{
    int esc;
    int a, b, c;                                        // variáveis exer 2 e 3
    int vetor[8] = {0, 0, 0, 0, 0, 0, 0, 0}, i = 0;     // variáveis exer 4
    char string[40], v; int tamanho = 0;                // variáveis exer 5
    char frase[40]; tamanho = 0;                        // variáveis exer 6
    int A[3] = {0, 0, 0};                               // variáveis exer 7
    int matriz[2][3] = {{0, 0, 0}, {0, 0, 0}}, j = 0;   // variáveis exer 8



    setlocale(LC_ALL, "Portuguese");
    do
    {
        printf("\nEscolha qual exercício deseja escolher de 2 até 9: \n");
        scanf("%d", &esc);
        fflush(stdin);
        switch (esc)
        {
        case 0:
            printf("Menu encerrado.\n");
            break;
        case 2:
            printf("Digite 3 valores para ordenar de forma decrescente.\n");
            scanf("%d", &a);
            fflush(stdin);
            scanf("%d", &b);
            fflush(stdin);
            scanf("%d", &c);
            fflush(stdin);

            ordena(&a, &b, &c);
            printf("%d  %d  %d", a, b, c);

            break;
        case 3:
            printf("Digite 2 números. O primeiro será decrementado e o segundo incrementado.\n");
            scanf("%d", &a);
            fflush(stdin);
            scanf("%d", &b);
            fflush(stdin);
            encremento(&a, &b);
            printf("Número 1:%d   Número 2:%d", a, b);
            break;
        case 4:
            for (i = 0; i < 8; i++)
            {
                printf("Digite o valor da posição %d.\n", i + 1);
                scanf("%d", &vetor[i]);
                fflush(stdin);
            }

            elementos(vetor);

            printf("Vetor: ");
            for (i = 0; i < 8; i++)
            {
                printf("%d\t", vetor[i]);
            }
            printf("\n");
            break;
        case 5:
            printf("Digite uma string para ser criptografada.\n");
            scanf("%[^\n]s", string);
            fflush(stdin);
            printf("Digite o caractere que será usado na criptografia.\n");
            scanf("%c", &v);
            fflush(stdin);
            tamanho = strlen(string);

            criptografia(string, v, tamanho);

            printf("String criptografada: %s", string);
            break;
        case 6:
            printf("Digite sua string para colocar em maiúsculas.\n");
            scanf("%[^\n]s", frase);
            fflush(stdin);
            tamanho = strlen(frase);
            maiusculas(frase, tamanho);

            printf("%s", frase);
            break;
        case 7:
            crescente(A);
            printf("%d\t%d\t%d", A[0], A[1], A[2]);

            break;
        case 8:
            matriz_par(matriz);
            for (i = 0; i < 2; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    printf("%d\t", matriz[i][j]);
                }
                printf("\n");
            }
            break;
        case 9:
            printf("Digite o nome do aluno:\n");
            scanf("%[^\n]s", aluno.nome);
            fflush(stdin);
            printf("Digite o número de matrícula:\n");
            scanf("%d", &aluno.matricula);
            fflush(stdin);
            printf("Digite as notas 1, 2 e 3:\n");
            scanf("%f\n%f\n%f", &aluno.n1, &aluno.n2, &aluno.n3);
            fflush(stdin);
            media(&aluno);
            printf("A média do aluno %s foi: %f\n", aluno.nome, aluno.media);

            break;
        default:
            printf("Exercício inválido.\n");
            break;
        }
    } while (esc != 0);
    return 0;
}
#ifndef exercicios_h
#define exercicios_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void ordena(int *x, int *y, int *z)
{
    int menor, medio, maior;

    if ( (*x >= *y) && (*x >= *z) && (*z >= *y))
    {
        maior = *x;
        medio = *z;
        menor = *y;
    }

    if( (*x >= *y) && (*x >= *z) && (*z <= *y))
    {
        maior = *x;
        medio = *y;
        menor = *z;
    }

    if( (*x >= *y) && (*x <=*z) )
    {
        maior= *z;
        medio =*x;
        menor=*y;
    }

    if( (*x<= *y) && (*x>=*z) )
    {
        maior = *y;
        medio = *x;
        menor = *z;
    }

    if( (*x <= *y) && (*x<=*z) && (*y >= *z))
    {
        maior = *y;
        medio = *z;
        menor = *x;
    }

    if( (*x <= *y) && (*x <= *z) && (*z >= *y))
    {
        maior = *z;
        medio = *y;
        menor = *x;
    }

    if ( (*x == *y) && (*y == *z))
    {
        maior = *x;
        menor = *y;
        medio = *z;
    }

    *x = maior;
    *y = medio;
    *z = menor;
}

void encremento( int *x, int *y)
{
    *x = *x - 1;
    *y = *y + 1;
}

void elementos ( int *vetor)
{
    int i;
    for( i = 0; i < 8; i++)
    {
        if(vetor[i] >= 15 && vetor[i] <=20)
        vetor[i] = 0;
    }
}

void criptografia( char *p, char v, int tamanho)
{
    int i;
    for(i = 0; i< tamanho; i++)
    {
        if( (p[i] == 'a') || (p[i] == 'e') || (p[i] == 'i') || (p[i] == 'o') || (p[i] == 'u'))
        {
            p[i] = v;
        }
    }
}

void maiusculas(char *p, int tamanho)
{
    int i = 0;
    for(i = 0; i< tamanho; i++)
    {
        if( p[i] >= 97 && p[i] <= 122 )
        {
            p[i] -= 32;
        }
    }
}

void crescente( int *A)
{
    setlocale(LC_ALL, "Portuguese");
    int maior, medio, menor, i;

    for( i = 0; i<3; i++)
    {
        printf("Digite o número para posição %d\n", i+1);
        scanf("%d", &A[i]);
    }
    if ( (A[0] >= A[1]) && (A[0] >= A[2]) && (A[2] >= A[1]))
    {
        maior = A[0];
        medio = A[2];
        menor = A[1];
    }

    if( (A[0] >= A[2]) && (A[0] >= A[2]) && (A[2] <= A[1]))
    {
        maior = A[0];
        medio = A[1];
        menor = A[2];
    }

    if( (A[0] >= A[1]) && (A[0] <= A[2]) )
    {
        maior = A[2];
        medio = A[0];
        menor = A[1];
    }

    if( (A[0]<= A[1]) && (A[0] >= A[2]) )
    {
        maior = A[1];
        medio = A[0];
        menor = A[2];
    }

    if( (A[0] <= A[1]) && (A[0] <= A[2]) && (A[1] >= A[2]))
    {
        maior = A[1];
        medio = A[2];
        menor = A[0];
    }

    if( (A[0] <= A[1]) && (A[0] <= A[2]) && (A[2] >= A[1]))
    {
        maior = A[2];
        medio = A[1];
        menor = A[0];
    }

    A[0] = menor;
    A[1] = medio;
    A[2] = maior;
}

void matriz_par( int matriz[][3])
{
    setlocale(LC_ALL, "Portuguese");
    int i,j, posicao = 1;
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("Digite o valor número %d\n", posicao);
            scanf("%d", &matriz[i][j]);
            fflush(stdin);
            if(matriz[i][j] % 2 == 0)
            matriz[i][j] = 1000;
            posicao++;
        }
    }
}

void media( tipoaluno *aluno)
{
    aluno->media = (aluno->n1 + aluno->n2 + aluno->n3) / 3;

}

#endif

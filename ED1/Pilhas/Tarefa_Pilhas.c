#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
//aluno Luiz Eduardo Rezende Moraes

typedef struct pillhaitem{
    int item;

}tipo_pilhaitem;

int topo = -1;
int tamanho = 5;

void push(tipo_pilhaitem P[], int valor)
{
    if(verifica_pilha_cheia() == 1)
    {
        printf("Pilha cheia.\n");
    }
    else
    {
        topo++;
        P[topo].item = valor;
    }
}

void pop(tipo_pilhaitem P[])
{
    if(verifica_pilha_vazia() == 1)
    {
        printf("Pilha vazia.\n");
    }
    else
    {
        P[topo].item = NULL;
        topo--;
    }
}

void consultaPilha(tipo_pilhaitem P[])
{
    printf("O item do topo e: %d\n", P[topo].item);
}


int verifica_pilha_cheia()
{
    if(topo == tamanho - 1)
        return 1;
    else
        return 0;

}

int verifica_pilha_vazia()
{
    if(topo == -1)
        return 1;
    else 
        return 0;
}

int main()
{
    tipo_pilhaitem P[tamanho];
    push(P, 5);
    push(P, 30);
    push(P, 30);
    push(P, 30);
    push(P, 10);
    push(P, 30);

    consultaPilha(P);

    pop(P);
    pop(P);
    pop(P);
    pop(P);

    consultaPilha(P);

    return 0;
}
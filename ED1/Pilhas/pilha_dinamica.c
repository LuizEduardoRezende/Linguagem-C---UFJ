#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
//aluno Luiz Eduardo Rezende Moraes

typedef struct node{
    int item;
    struct node *prox;
}tipo_pilha;

tipo_pilha *topo;

void inicializa(){
    topo = NULL;
}

void push(int valor){
        tipo_pilha *novoNoh = (tipo_pilha*)malloc(sizeof(tipo_pilha));
        if(novoNoh == NULL)
        {
            printf("Alocação de memoria falhou.\n");
            return;
        }

        novoNoh->item = valor;

        novoNoh->prox = topo;
        topo = novoNoh;
}

int main()
{
    inicializa();
    push(10);
    push(20);
    push(30);

    printf("Valor do topo: %d", topo->item);


    return 0;
}
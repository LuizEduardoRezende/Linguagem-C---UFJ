#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
//aluno Luiz Eduardo Rezende Moraes

typedef struct item{
    int item;

}tipo_item;

int inicio = 0;
int fim = 0;
int tamanho = 10;

int filaVazia(){
    if(fim == inicio)
        return 1;
    else
        return 0;
}

int filaCheia(){
    if(fim == tamanho - 1)
        return 1;
    else 
        return 0;
}

void queue(tipo_item I[]){
    if(filaCheia() == 0)
    {
        printf("Diite o item para ser adicionado: ");
        scanf("%d", &I[fim].item);
        fflush(stdin);
        fim++;
    }
    else
    {
        printf("Fila cheia, nao e possivel adicionar.\n");
    }
    
}

void dequeue(tipo_item I[]){
    if(filaVazia() == 0)
    {
        I[inicio].item = NULL;
        inicio++;
        printf("Elemento do comeco retirado.\n");
    }
    else
    {
        printf("Fila vazia.\n");
    }
}


void consultaFila(tipo_item I[]){
    if(filaVazia() == 0)
    {
        printf("O elemento do inico da fila e: %d\n", I[inicio].item);
        dequeue(I);
    }
    else
    {
        printf("Fila vazia.\n");
    }
}

void excluiFila(tipo_item I[]){
    for(int i = 0; i< tamanho; i++){
        I[i].item = 0;
    }

    inicio = 0;
    fim = 0;
    printf("Fila resetada.\n");
}

int main()
{
    tipo_item I[tamanho];
    int esc = -1;

    do{

        printf("Digite sua escolha:\n");
        printf("1- Adicionar.\n2- Retirar.\n3- Consultar o primeiro elemento e depois retira-lo.\n4- Excluir fila.\n0- Encerrar o menu.\n");
        scanf("%d", &esc);
        fflush(stdin);

        switch (esc)
        {
        case 0:
            system("cls");
            printf("Menu encerrado.\n");
            break;

        case 1:
            system("cls");
            queue(I);
            break;

        case 2:
            system("cls");
            dequeue(I);
            break;

        case 3:
            system("cls");
            consultaFila(I);
            break;

        case 4:
            system("cls");
            excluiFila(I);
            break;

        default:
            printf("Digite uma opcao valida.\n");
            break;
        } 
    }while(esc != 0);











    return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
//aluno Luiz Eduardo Rezende Moraes

typedef struct node{
    char data;
    struct node *prox;
}tipo_stack;

tipo_stack *topo;


void initialize(){
    topo = NULL;
}

int isFull(){

}

int isEmpty(){

}

void push(char item){
    tipo_stack *newNode = (tipo_stack*)malloc(sizeof(tipo_stack));
    if(newNode == NULL)
    {
        printf("Alocação de memoria falhou.\n");
        return;
    }

    newNode->data = item;

    newNode->prox = topo;
    topo = newNode;
}

char pop(){
    if (topo != NULL) 
    {
        char item = topo->data;
        tipo_stack* temp = topo;
        topo = topo->prox;
        free(temp);
        return item;
    }
    return '\0';
}

int checkForm(char str[]){
    initialize();

    int tamanho = strlen(str);
    int i = 0;
    while (str[i] != 'c' && i < tamanho) {
        push(str[i]);
        i++;
    }

    i++; // Pular o caractere 'c'

    while (str[i] != '\0' && i < tamanho) {
        char top = pop();
        if (top != str[i]) {
            return 0;
        }
        i++;
    }

    return 1;
}

int main()
{
    char string[100];
    printf("Digite a string: ");
    scanf("%s", string);

    if (checkForm(string) == 1) {
        printf("A string pertence a forma WcM.\n");
    } else {
        printf("A string nao pertence a forma WcM.\n");
    }

    return 0;
}
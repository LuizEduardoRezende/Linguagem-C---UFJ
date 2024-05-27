#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome[30];

    printf("Qual seu nome ?\n");
    gets(nome);
    printf("Bem vindo ao Desenrola ");
    puts(nome);
    printf("desejamos bons estudos para você!!\n");

    return 0;
}
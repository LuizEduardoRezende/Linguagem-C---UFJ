#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char nome_arq[30];
    printf("Digite o nome do arquivo teste:");
    scanf("%[^\n^]s", nome_arq);
    fflush(stdin);

    FILE *arq = fopen(nome_arq, "w+");




    if(arq == NULL)
        printf("Erro.\n");
    else
        fprintf(arq,"Teste bem sucedido.\n");





    return 0;
}
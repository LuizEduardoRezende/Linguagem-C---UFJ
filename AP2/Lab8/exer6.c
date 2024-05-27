#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char nome[30];
    float salario = 0;
    char url[]={"b.txt"};
    
    FILE *arq;
    arq = fopen(url, "w");
    FILE *arq2;
    arq2 = fopen("a.txt", "r");

    fscanf(arq2, "%s %f\n", nome, &salario);   
    fprintf(arq, "%s %f\n", nome, salario);

    fclose(arq);
    fclose(arq2);
    return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char i;

    char url[] = {"exer5_2.0.txt"};
    FILE *arq;
    arq = fopen("exer5.txt", "r");
    FILE *arq2;
    arq2 = fopen(url, "w");

    if( (arq == NULL) || (arq2 == NULL) )
    {
        printf("Erro em algum dos arquivos.\n");
    }
    else
    {
        while( fscanf(arq, "%c", &i) != EOF)
        fprintf(arq2, "%c", i);

    }

    fclose(arq2);
    fclose(arq);
    return 0;
}
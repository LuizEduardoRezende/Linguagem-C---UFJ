#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int i = 0;
    FILE *arq;
    arq = fopen("dados.txt", "w");

    if(arq == NULL)
    {
        printf("Erro.\n");
    }
    else
    {
        for( i=1; i<=10; i++)
        {
            fprintf(arq, "%d \n", i * 10);
        }
    }

    fclose (arq);
    return 0;
}
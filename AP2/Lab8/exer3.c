#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int linhas = 0;
    char count;
    FILE *arq;
    arq = fopen ("Quantas_Linhas.txt", "r");
    if( arq == NULL)
    {
        printf("Erro.\n");
    }
    else
    {
        
        while( fscanf(arq, "%c", &count) != EOF)
        {
            if(count == '\n')
            linhas++; 
        }

        printf("O programa tem %d linhas.", linhas+1);
    }

    fclose(arq);
    return 0;
}
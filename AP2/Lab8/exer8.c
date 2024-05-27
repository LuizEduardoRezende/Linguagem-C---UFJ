#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    int palavras = 0;
    char i;
    FILE *arq;
    arq = fopen("exer8.txt", "r");

    if( (arq == NULL) )
    {
        printf("Erro.\n");
    }
    else
    {   
        while( fscanf(arq, "%c", &i) != EOF)
        {
            printf("%c", i);
            if(i == ' ')
            {
                palavras++;
            }
        }
    }

    printf("O arquivo tem %d palavras.\n", palavras);

    fclose(arq);
    return 0;
}
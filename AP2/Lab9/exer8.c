#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>

char reverse(char palavra[], int tamanho)
{
    if(tamanho < 0)
    {
        return 1;
    }
    else
    {
        printf("%c", palavra[tamanho]), reverse(palavra, tamanho - 1);
        return 0;
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char palavra[40];
    int tamanho = 0;
    printf("Digite a palavra para ser invertida:");
    scanf("%s", palavra);
    tamanho = strlen(palavra);

    reverse(palavra, tamanho);

    return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>

char palavra[50];

char reverse(char word[], int tam, int i)
{

    if (tam < 0 && i > tam)
    {
        return 1;
    }
    else
    {
        palavra[i] = word[tam];
        reverse(word, tam - 1, i + 1);
        return 0;
    }
}

int main()
{
    char word[50];
    int tam, i = 0;

    printf("digite a palavra\n");
    scanf("%[^\n]s", word);
    tam = strlen(word) - 1;

    reverse(word, tam, i);
    printf("%s\n", palavra);

    if (strcmp(palavra, word) == 0)
    {
        printf("E palindromo\n");
    }
    else
    {
        printf("Nao e Palindromo\n");
    }

    return 0;
}
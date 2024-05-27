#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char s1[20] = "", s2[20] = "";
    int i = 0, j = 0;
    int letras_ig = 0;

    printf("Digite uma palavra sem acentos para verificar se ela é um palíndromo.\n");
    fflush(stdin);
    scanf("%[^\n]s", s1);
    strcpy(s2, s1);

    j = strlen(s1) - 1;
    for (i = 0; i < strlen(s1); i++)
    {

        if (s1[i] == s2[j])
        {
            letras_ig++;
        }

        j--;
    }

    if (letras_ig == strlen(s1))
    {
        printf("Essa palavra é um palíndromo.\n");
    }
    else
    {
        printf("Essa palavra não é um palíndromo.\n");
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char s1[50] = "", s2[50] = "", s3[50] = "";
    int i = 0, j = 0, letras_ig = 0;

    printf("Digite uma frase sem pontuação e acentos para verificar se ela é um palíndromo.\n");
    fflush(stdin);
    scanf("%[^\n]s", s1);

    for (i = strlen(s1) - 1; i >= 0; i--) // tirando os espaços e invertendo a S1 e colocando na S2.   S2 = S1 inertida sem espaços
    {
        if (s1[i] != 32)
        {
            s2[j] = s1[i];
            j++;
        }
    }

    j = 0;
    for (i = strlen(s2) - 1; i >= 0; i--) // invertendo a S2 e colocando na S3.  S3 = S1(sem espaços)
    {
        s3[j] = s2[i];
        j++;
    }

    for (i = 0; i < strlen(s2) ; i++) // comparando a S2 com a S3 para verificar se são palíndromos.
    {
        if (s2[i] == s3[i])
        {
            letras_ig++;
        }
    }

    if (strlen(s3) == letras_ig)
    {
        printf("Essa frase forma um palíndromo.\n");
    }
    else
    {
        printf("Essa frase não forma um palíndromo.\n");
    }

    return 0;
}
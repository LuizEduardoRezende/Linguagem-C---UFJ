#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    char frase[50] = {""}, frase2[50] = {""}, frase_inver[50] = {""};
    int i = 0, j = 0, posicao = 0;

    printf("Digite a frase:\n");
    scanf("%[^\n]s", frase);
    fflush(stdin);

    for( i = 0; i < strlen(frase); i++){

        if(frase[i] != ' ')
        {
            frase2[posicao] = frase[i];
            posicao++;
        }
    }

    printf("%s\n", frase2);

    for( i = strlen(frase2) - 1; i >= 0; i --){
        frase_inver[j] = frase2[i];
        j++;
    }

    printf("%s\n", frase_inver);

    if(strcmp(frase2,frase_inver) == 0)
        printf("A frase e um palindromo.\n");
    else
        printf("A frase nao e um palindromo.\n");

    
    return 0;
}

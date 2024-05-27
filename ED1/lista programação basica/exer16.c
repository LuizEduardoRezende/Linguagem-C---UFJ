#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    char frase[50] = {""}, frase_inver[50] = {""};
    int i = 0, j = 0;

    printf("Digite a frase:\n");
    scanf("%[^\n]s", frase);
    fflush(stdin);

    for( i = strlen(frase) - 1; i >= 0; i --){
        frase_inver[j] = frase[i];
        j++;
    }

    printf("Frase invertida : %s", frase_inver);






    return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>


int main(){
    char frase[60] = {""};
    char *ptr_frase;
    ptr_frase = frase;

    printf("Digite a frase:\n");
    scanf("%[^\n]s", ptr_frase);
    fflush(stdin);

    for(int i = 0; i<60; i++)
    {
        if( *ptr_frase == ' ')
        {
            printf("\n");
        }
        else
        {
            printf("%c", *ptr_frase);
        }
        
        ptr_frase++;
    }

    return 0;
}

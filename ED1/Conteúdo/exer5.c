#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>


int main(){
    char frase[50]={""};
    char *ptr_frase;
    ptr_frase = frase;
    int flag = 0;

    printf("Digite uma frase:\n");
    scanf("%[^\n]s", ptr_frase);
    fflush(stdin);

    for(int i = 0; i<strlen(frase); i++)
    {
        if((*ptr_frase == "\n") || (*ptr_frase == "\0")){
            break;
        }
        
        if( *ptr_frase != ' ')
            flag++;
        
        ptr_frase++;
    }

    printf("A quantidade de caracteres e: %d\n", flag);

    return 0;
}

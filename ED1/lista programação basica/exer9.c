#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>


int main(){
    int anos = 0, dias = 0;
    char nome[50];

    printf("Qual seu nome ?\n");
    scanf("%[^\n]s", nome);
    fflush(stdin);
    printf("Qual sua idade em anos ?\n");
    scanf("%d", &anos);
    fflush(stdin);

    dias = anos * 365;
    printf("%s voce ja viveu %d dias.\n", nome, dias);




    return 0;
}

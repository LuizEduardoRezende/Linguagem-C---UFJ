#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>


int main(){
    int n = 0, soma = 0;

    printf("Digite um numero n para saber a soma de todos numeros inteiros positivos ate n.\n");
    scanf("%d", &n);
    fflush(stdin);

    for(int i = 0; i<= n; i++)
        soma += i;

    printf("A soma e: %d\n", soma);

    

    return 0;
}

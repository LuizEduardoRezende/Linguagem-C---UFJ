#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>


int main(){
    int a;
    int b;
    int *pta;
    int *ptb;

    pta = &a;
    ptb = &b;

    printf("Digite o valor de A:\n");
    scanf("%d", pta);
    fflush(stdin);
    printf("Digite o valor de B:\n");
    scanf("%d", ptb);
    fflush(stdin);

    *pta += *ptb;
    *pta *= 2;

    *ptb += 100;
    *ptb /= 2;

    printf("Valor de (A + B)*2: %d\n", *pta);
    printf("Valor de (B + 100)/2: %d\n", *ptb);

    return 0;
}

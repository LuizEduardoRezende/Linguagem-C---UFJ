#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>


int main(){
    int a;
    int b;
    int c;
    int menor, meio, maior;
    int *menor_end, *meio_end, *maior_end;
    int *pta;
    int *ptb;
    int *ptc;

    pta = &a;
    ptb = &b;
    ptc = &c;

    printf("Digite o valor de A:\n");
    scanf("%d", pta);
    fflush(stdin);
    printf("Digite o valor de B:\n");
    scanf("%d", ptb);
    fflush(stdin);
    printf("Digite o valor de C:\n");
    scanf("%d", ptc);
    fflush(stdin);

    if( *pta > *ptb)
    {
        if( *ptb > *ptc)
        {
            maior = *pta;
            maior_end = pta;
            meio = *ptb;
            meio_end = ptb;
            menor = *ptc;
            menor_end = ptc;
        }
        else
        {
            if(*pta > *ptc)
            {
                maior = *pta;
                maior_end = pta;
                meio = *ptc;
                meio_end = ptc;
                menor = *ptb;
                menor_end = ptb;
            }
            else
            {
                maior = *ptc;
                meio = *pta;
                menor = *ptb;
            }
        }
    }
    else
    {
        if( *ptb > *ptc)
        {
            if( *pta > *ptc)
            {
                maior = *ptb;
                meio = *pta;
                menor = *ptc;
            }
            else
            {
                maior = *ptb;
                meio = *ptc;
                menor = *pta;
            }
        }
        else
        {
            maior = *ptc;
            meio = *ptb;
            menor = *pta;
        }
    }

    printf("Maior valor: %d\n", maior);
    printf("Valor do meio: %d\n", meio);
    printf("Menor valor: %d\n", menor);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int i = 0;
    typedef struct ficha
    {
        int x;
    }tipoficha;

    tipoficha ficha[5];

    for(i = 0; i <5;i++)
    {
        printf("Digite o x da ficha %d: ", i+1);
        scanf("%d", &ficha[i].x);
    }
    
    for(i = 0; i <5;i++)
    {
        printf("X da ficha %d: %d\n", i+1, ficha[i].x);
    }

    return 0;
}
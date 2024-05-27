#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    float distancia = 0;
    typedef struct ponto
    {
        float x,y;
    }tipoponto;
    tipoponto ponto;
    tipoponto *ptrponto = &ponto;

    printf("Digite o valor de x:\n");
    scanf("%f", &(*ptrponto).x);
    fflush(stdin);
    printf("Digite o valor de y:\n");
    scanf("%f", &(*ptrponto).y);
    fflush(stdin);

    distancia = sqrt( (ptrponto->x*ptrponto->x) + (ptrponto->y*ptrponto->y));

    printf("Distância desse ponto até a origem: %f\n", distancia);

    return 0;
}
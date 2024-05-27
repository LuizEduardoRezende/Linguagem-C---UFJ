#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(){

    int min = 0, max = 0;
    float estoque_medio = 0;

    printf("Digite o estoque minimo:\n");
    scanf("%d", &min);
    fflush(stdin);

    printf("Digite o estoque maximo:\n");
    scanf("%d", &max);
    fflush(stdin);

    estoque_medio = ((float)min + (float)max) / 2;

    printf("Estoque medio = %.2f", estoque_medio);

    return 0;
}

#ifndef exer6_h
#define exer6_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

float notas[3], media_ari = 0, media_pond = 0;

int medias()
{
    setlocale(LC_ALL, "Portuguese");
    printf("Informe suas notas nas 3 provas.\n");
    fflush(stdin);
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        printf("Digite a nota %d:", i + 1);
        scanf("%f", &notas[i]);
    }

    media_ari = (notas[0] + notas[1] + notas[2]) / 3;
    media_pond = (notas[0] * 5 + notas[1] * 3 + notas[2] * 2) / 10;
    printf("Média Aritmética: %.2f \nMédia Ponderada: %.2f\n", media_ari, media_pond);
    return 0;
}
#endif
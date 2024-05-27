#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    struct vetor
    {
        float x, y, z;
    };

    struct vetor vetores[3];

    printf("Digite x(1):\n");
    scanf("%f", &vetores[0].x);
    fflush(stdin);
    printf("Digite y(1):\n");
    scanf("%f", &vetores[0].y);
    fflush(stdin);
    printf("Digite z(1):\n");
    scanf("%f", &vetores[0].z);
    fflush(stdin);
    printf("\n");

    printf("Digite x(2):\n");
    scanf("%f", &vetores[1].x);
    fflush(stdin);
    printf("Digite y(2):\n");
    scanf("%f", &vetores[1].y);
    fflush(stdin);
    printf("Digite z(2):\n");
    scanf("%f", &vetores[1].z);
    fflush(stdin);

    vetores[2].x = vetores[0].x + vetores[1].x;
    vetores[2].y = vetores[0].y + vetores[1].y;
    vetores[2].z = vetores[0].z + vetores[1].z;

    printf("\nVetor 3:\nx(3) = %.2f\ny(3) = %.2f\nz(3) = %.2f", vetores[2].x, vetores[2].y, vetores[2].z);

    return 0;
}
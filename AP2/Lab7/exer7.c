#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int i=3, j=5;
    int *p, *q;
    p = &i;
    q = &j;
    float resultado = 0;

    printf("p: %d\n", p);
    printf("&i: %d\n", &i);
    printf("*&p: %d\n", *&p);

    resultado = 3* - (float)*p/(float)(*q)+7;

    printf("expressao: %f", resultado);

    return 0;
}
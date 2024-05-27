#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>

int pot(int x, int n)
{
    if(n == 0)
        return 1;
    else
        return x * pot( x, n - 1);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int x, n;
    printf ("Digite x e n para saber x elevado a n.\n");
    printf("x:");
    scanf("%d", &x);
    printf("n:");
    scanf("%d", &n);
    printf("Resultado : %d", pot(x, n));

    return 0;
}
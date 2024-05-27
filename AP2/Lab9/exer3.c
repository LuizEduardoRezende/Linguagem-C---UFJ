#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>

int mdc(int x, int y)
{
    if(x%y == 0)
    {
        return y;
    }
    else
    {
        return mdc(y, x%y);
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int x, y, aux;
    printf ("Digite x e y para saber o MDC.\n");
    printf("x:");
    scanf("%d", &x);
    printf("y:");
    scanf("%d", &y);
    if ( x < y)
    {
        aux = x;
        x = y;
        y = aux;
    }
    printf("MDC: %d", mdc(x,y));


    return 0;
}
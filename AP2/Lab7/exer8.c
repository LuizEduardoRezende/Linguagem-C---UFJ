#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int x, *ptrx;
    ptrx = &x;
    *ptrx = 39;
    printf("x: %d", x);

    return 0;
}
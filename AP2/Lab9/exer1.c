#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int rec(int n)
{
    if(n == 1)
        return 1;
    else
        return n + rec(n-1);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int x;
    printf ("Digite um número para saber a soma de 1 até esse número:");
    scanf("%d", &x);
    printf("Resultado : %d", rec(x));

    return 0;
}
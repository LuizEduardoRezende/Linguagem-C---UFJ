#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int fat(int n)
{
    if(n == 1)
        return 1;
    else
        return n * fat(n -1);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int x;
    printf ("Digite um n�mero para saber seu fatorial:");
    scanf("%d", &x);
    printf("O fatorial de %d � : %d", x, fat(x));

    return 0;
}
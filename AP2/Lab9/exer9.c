#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>

int comb(int n, int k)
{
    if( k == 1)
    return n;

    if( k == n)
    return 1;

    return comb( n - 1, k - 1) + comb(n - 1, k);    
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int n, k;
    printf("Digite o k e n para fazer a combinação, sendo n o número total de pessoas.\n");
    printf("n:");
    scanf("%d", &n);
    printf("k:");
    scanf("%d", &k);

    printf("O resultado da combinação é: %d",comb(n, k));
    return 0;
}
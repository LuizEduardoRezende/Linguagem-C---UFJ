#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>

int somatorio(int n)
{
    if(n == 1)
        return 0;
    else
        return (n-1 + somatorio(n-1));
    
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int n;
    printf("Digite N para saber o resultado do somatório:");
    scanf("%d", &n);
    printf("O resultado do somatório é: %d", 2*somatorio(n));

    return 0;
}
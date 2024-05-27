#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>

int fib(int n)
{
    if(n == 1)
        return 1;
    if(n == 2)
        return 1;
    
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int n;
    printf("Digite N para saber o N termo da sequência de fibonnaci:");
    scanf("%d", &n);
    printf("O termo n de da sequência de fibonnaci é: %d", fib(n));

    return 0;
}
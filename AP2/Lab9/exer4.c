#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>

int fat(int x)
{
    if(x == 1)
        return 1;
    else
        return x * fat(x-1);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int n;
    printf("Digite N para caclular o fatorial quádruplo de N.\n");
    scanf("%d", &n);
    printf("O fatorial quádruplo de N é: %d", fat(2*n)/ fat(n));

    return 0;
}
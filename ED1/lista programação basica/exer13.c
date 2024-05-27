#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int fatorial(int x)
{
    if(x == 1)
        return 1;
    else
        return x * fatorial(x-1);
}

int main(){
    int num = 0, fat = 1;
    int num2 = 0;
    printf("Digite um numero para calcular o fatorial:\n");
    scanf("%d", &num);
    fflush(stdin);

    for(int i = num; i>0; i--)
    {
        fat *= i;
    }
    printf("O fatorial de %d e: %d\n", num, fat);

    printf("Digite um numero para calcular o fatorial novamente:\n");
    scanf("%d", &num2);
    fflush(stdin);
    printf("O fatorial de %d e: %d", num2, fatorial(num2));




    return 0;
}

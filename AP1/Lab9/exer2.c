#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, j, i = 1;
    printf("Digite um numero para sabe a ordem crescente e decrescente.\n");
    scanf("%d", &num);
    j = num;

    for (i = 1; i <= num; i++)
    {
        printf("%d  %d\n", i, j);
        j--;
    }
    
    system("pause");
    return 0;
}
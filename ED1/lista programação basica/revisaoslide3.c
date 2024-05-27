#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{

    int n1 = 0, n2 = 0, n3 = 0, n4 = 0, quad1 = 0, quad2 = 0, quad3 = 0, quad4 = 0;

    printf("Digite quatro numeros:\n");
    scanf("%d %d %d %d", &n1, &n2, &n3, &n4);

    quad1 = n1 * n1;
    quad2 = n2 * n2;
    quad3 = n3 * n3;
    quad4 = n4 * n4;
    if (quad3 >= 1000)
    {
        printf("%d", quad3);
        return 0;
    }
    else
    {
        printf("O quadrado do 1:%d\n", quad1);
        printf("O quadrado do 2:%d\n", quad2);
        printf("O quadrado do 3:%d\n", quad3);
        printf("O quadrado do 4:%d\n", quad4);
    }
    return 0;
}

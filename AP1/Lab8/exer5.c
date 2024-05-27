#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 0;
    printf("Tabela ASCII.\n");
    printf("Decimal       Hexadecimal       Caracter.\n");
    do
    {
        printf("%d              %x                 %c\n", num, num, num);
        num++;

    } while (num <= 127);

    system("pause");
    return 0;
}
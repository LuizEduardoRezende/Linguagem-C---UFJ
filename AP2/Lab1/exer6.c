#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;

    printf("Tabela ASCII\n");
    printf("Decimal            Hexadecimal         Caractere\n");
    for(i=0; i<128; i++)
    {
        printf("%d                  %x                   %c\n",i,i,i);
    }

    return 0;
}
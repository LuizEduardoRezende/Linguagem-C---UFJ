#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int v[4], *ptrv = v;
    int i;
    for(i = 0; i<4; i++)
    {
        printf("Digite a posi��o %d do vetor:\n", i+1);
        scanf("%d", &v[i]);
    }

    printf("Seu vetor �:   ");
    while( ptrv <= &v[3])
    {
        printf("%d\t", *ptrv++);
    }

    return 0;
}
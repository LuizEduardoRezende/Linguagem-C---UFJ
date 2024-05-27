#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    FILE *arq;
    fopen("testelab8.txt", "w+");

    if (arq == NULL)
    return 1;

    fclose(arq);
    return 0;
}
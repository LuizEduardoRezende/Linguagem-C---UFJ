#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int i = 234;
    float f = 89.6;
    char nome[] = {"Maria Jose"};
    char url[] = {"nao_binarie.txt"};
    char url2[] = {"binarie.txt"};
    FILE *arq;
    arq = fopen( url, "w");
    
    if(arq == NULL)
    {
        printf("Erro.\n");
    }
    else
    {
        fprintf(arq, "%d\n", i);
        fprintf(arq, "%f\n", f);
        fprintf(arq, "%s\n", nome);
    }

    FILE *arq2;
    arq2 = fopen(url2, "wb");

    if(arq2 == NULL)
    {
        printf("Erro.\n");
    }
    else
    {
        fwrite(&i, sizeof(i), 1, arq2);
        fwrite(&f, sizeof(f), 1, arq2);
        fwrite(&nome, sizeof(nome), 10, arq2);
    }


    fclose(arq2);
    fclose(arq);
    return 0;
}
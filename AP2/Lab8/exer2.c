#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    rename ("dados.txt", "MATRICULADOS.txt");

    return 0;
}
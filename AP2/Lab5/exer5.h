#ifndef exer5_h
#define exer5_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int fatorial(int valor)
{
    int resul = 1;
    while(valor > 1)
    {
        resul = resul * valor;
        valor--;
    }

    return resul;
}
#endif
#ifndef exer3_h
#define exer3_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int divisor(int x, int y)
{
    int resto;
    if (x > y)
    {
        do
        {
            resto = x % y;
            x = y;
            y = resto;

        } while (resto != 0);
        return x;
    }
    else
    {
        do{
        resto=y%x;
        y=x;
        x=resto;
        }while(resto!=0);
        return y;
    }
}
#endif
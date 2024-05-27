#ifndef exer6_h
#define exer6_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

float calculataxa(float horas)
{
    if (horas <= 3)
    {
        if (horas <= 0)
        {
            return 0.0;
        }
        else
        {
            return 2.0;
        }
    }
    else
    {
        if( horas >= 19)
        {
            return 10.0;
        }
        else
        {
            return 2 + ((horas-3)*0.5);
        }
    }
}
#endif
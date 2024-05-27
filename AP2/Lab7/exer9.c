#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    char string[30];
    char *ptrstring;
    ptrstring = string;

    scanf("%[^\n]s", string);
    fflush(stdin);
    
    while( *ptrstring != '\0')
    {
        if((97 <= *ptrstring)  && (*ptrstring <= 122))
        {
            *ptrstring = *ptrstring - 32;
        }
        *ptrstring++;
    }
    printf("%c", string);
    
    return 0;
}
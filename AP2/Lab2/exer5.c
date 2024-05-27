#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char string[50] = "";
    int i = 0, flag_a = 0;

    printf("Digite sua string para verificar quantos caracteres 'a' existem:\n");
    fflush(stdin);
    scanf("%[^\n]S", string);

    for(i = 0; i <= strlen(string); i++)
    {
        if(string[i] == 'a')
        flag_a++;
    }
    
    printf("Letras a = %d", flag_a);
    
    return 0;
}
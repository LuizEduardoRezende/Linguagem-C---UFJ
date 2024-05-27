#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>


int main(){
    int dia = 0, mes = 0, dias_passados = 0;

    do
    {
        printf("Informe o dia:\n");
        scanf("%d", &dia);
        fflush(stdin);
        if((dia <= 0) || (dia > 30))
            printf("Entrada invalida.\n");
        
    }while((dia <= 0) || (dia > 30));

    do
    {
        printf("Informe o mes:\n");
        scanf("%d", &mes);
        fflush(stdin);
        if((mes <= 0) || (mes > 12))
            printf("Entrada invalida.\n");
    }while((mes <= 0) || (mes > 12));

    dias_passados += dia + mes*30;
    printf("Dias passados: %d\n", dias_passados);






    return 0;
}

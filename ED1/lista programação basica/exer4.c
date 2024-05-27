#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>


int main(){
    float capital = 0, juros = 0;
    
    printf("Digite o Capital Inicial:\n");
    scanf("%f", &capital);
    fflush(stdin);

    printf("Digite o juros mensal em porcentagem:\n");
    scanf("%f", &juros);
    fflush(stdin);
    juros = (juros/100)+1;

    for( int i = 0; i<12; i++)
    {   
        capital *= juros; 
        printf("Montante do mes %d: %f\n", i + 1, capital);
    }

    

    return 0;
}

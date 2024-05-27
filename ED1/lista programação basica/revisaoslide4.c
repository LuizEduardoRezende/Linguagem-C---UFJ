#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>


int main(){
    int idade = 0;
    
    printf("Digite a idade do nadador:\n");
    scanf("%d", &idade);
    fflush(stdin);

    if(idade < 5)
    {
        printf("Nenhuma categoria.\n");
        return 0;
    }
    
    if((idade >= 5) && (idade <= 7))
    {
        printf("Categoria: Infatil A.\n");
        return 0;
    }

    if((idade >= 8) && (idade <= 11))
    {
        printf("Categoria: Infantil B.\n");
        return 0;
    }

    if((idade == 13) || (idade == 14))
    {
        printf("Categoria: Juvenil A.\n");
        return 0;
    }

    if((idade >= 14) && (idade <= 17))
    {
        printf("Categoria: Juvenil B.\n");
        return 0;
    }

    if(idade >= 18)
    {
        printf("Categoria: Maiores de 18.\n");
        return 0;
    }

    return 0;
}

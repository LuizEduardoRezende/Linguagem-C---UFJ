#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>


int main(){
    int vet[6]={0,0,0,0,0,0};
    int *ptr_vet;
    ptr_vet = vet;

    for(int i = 0; i<6; i++)
    {
        printf("Digite o valor numero %d:\n", i+1);
        scanf("%d", ptr_vet++);
        fflush(stdin);
    }

    ptr_vet = vet;
    for(int i = 0; i<6; i++)
    {
        printf("Valor numero %d: %d\t", i+1, *ptr_vet);
        printf("Endereco: %p\n", ptr_vet++);
    }

    return 0;
}

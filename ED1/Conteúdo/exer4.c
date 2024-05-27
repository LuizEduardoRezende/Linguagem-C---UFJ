#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>


int main(){
    int vet[4]={0,0,0,0};
    int *ptr_vet;
    ptr_vet = &vet;
    int maior = 0, menor = 0;

    for(int i = 0; i<4; i++)
    {
        printf("Digite o valor numero %d:\n", i+1);
        scanf("%d", ptr_vet++);
        fflush(stdin);
    }

    ptr_vet = vet;
    for(int i = 0; i<4; i++)
    {
        printf("Valor numero %d: %d\t", i+1, *ptr_vet);
        printf("Endereco: %p\n", ptr_vet++);
    }

    ptr_vet = vet;
    maior = *ptr_vet;
    for(int i = 0; i<4; i++)
    {
        if (maior <= *ptr_vet)
            maior = *ptr_vet;
        ptr_vet++;
    }

    ptr_vet = vet;
    menor = *ptr_vet;
    for(int i = 0; i<4; i++)
    {
        if( menor >= *ptr_vet)
            menor = *ptr_vet;
        ptr_vet++;
    }

    printf("\nO maior numero do vetor e: %d\n", maior);
    printf("O menor numero do vetor e: %d\n", menor);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define TAM 6

int flag_ordenado(int vet[]){
    int i,j;

    for( i = 1; i< TAM; i++){
        j = i - 1;

        if(vet[j] > vet[i])
            return 1;
    }

    return 0;
}

int main() {

    int num[TAM] = {1,2,3,4,6,7};

    if (flag_ordenado(num) == 1)
        printf("Vetor nao e ordenado.\n");
    else
        printf("Vetor e ordenado.\n");
   

    return 0;
}

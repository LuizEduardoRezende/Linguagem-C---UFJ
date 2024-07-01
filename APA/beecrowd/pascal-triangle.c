#include <stdio.h>

int main() {
    int t; //quantidade t de entradas
    scanf("%d", &t); 

    int N[100];
    //scanear as t entradas
    for(int i = 0; i < t; i++){
        scanf("%d", &N[i]);
    }

    int soma;
    for(int i = 0; i < t; i++){
        soma = 0;
        for(int j = 0; j < N[i]; j++){
            soma += (1 << j); 
        }
        printf("%d\n", soma);
    }

    return 0;
}

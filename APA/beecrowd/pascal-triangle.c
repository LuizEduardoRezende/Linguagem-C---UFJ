#include <stdio.h>
#include <math.h>

int main() {
    int t; //quantidade t de entradas
    scanf("%d", &t); 

    int N[10];
    //scanear as t entradas
    for(int i = 0; i < t; i++){
        scanf("%d", &N[i]);
    }

    long int sum_N;
    //printar saida para as t entradas
    for(int i = 0; i < t; i++){
        sum_N = (1ULL << N[i]) - 1; // 2^n - 1
        printf("%ld\n", sum_N);
    }

    return 0;
}

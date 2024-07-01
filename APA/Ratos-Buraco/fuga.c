#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 2147483647

int Calcula_Dist(int R, int B) {
    return abs(R - B);
}

int Fuga(int R[], int B[], int P[], int tamanho){
    int menor = INT_MAX;
    int dist = 0;
    int dist_total = 0;
    int q = 0;

    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            dist = Calcula_Dist(R[i], B[j]);
            if( (dist < menor) && (B[j] != INT_MAX)){
                menor = dist;
                q = j;
            }
        }

        dist_total += menor;
        P[i] = B[q];
        B[q] = INT_MAX;
        menor = INT_MAX;
    }

    return dist_total;
}

int main()
{
    int B[3] = {-5, 4, -1};
    int R[3] = {1, 6, -2};
    int P[3] = {0, 0, 0};
    int tamanho = sizeof(R) / sizeof(R[0]);

    printf("Distancia total percorrida: %d\n", Fuga(R, B, P, tamanho));

    for(int i = 0; i < 3; i++)
        printf("Posicao final dos rato %d: %d\n", i+1, P[i]);


	return 0;
}
#include <stdio.h>
#include <stdlib.h>


//busca binaria iterativa
int busca_binaria(int A[],int v, int inicio,int fim){
    int meio;
    while( inicio <= fim){
        meio = (inicio + fim) / 2;
        if(v == A[meio])
            return meio;
        if(v < A[meio])
            fim = meio - 1;
        else
            inicio = meio + 1;
    }
    return -1;
}

int main()
{
    #define TAM 6

    int A[TAM] = {1,3,5,7,8,10};

    printf("%d", busca_binaria(A,1,0,5));

	return 0;
}
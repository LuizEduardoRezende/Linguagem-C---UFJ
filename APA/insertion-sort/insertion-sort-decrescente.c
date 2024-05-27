#include <stdio.h>
#include <stdlib.h>

int main()
{
    #define TAM 10

    int A[TAM] = {5,2,9,8,5,12,1,3,7,4};
    int key;
    int i;

    for(int j=1; j < TAM; j++)
    {
        key = A[j];
        i = j - 1;

        while( i >= 0 && A[i] < key){
            A[i + 1] = A[i];
            i--;
        }

        A[i+1] = key;
    }

    for(i=0; i < TAM; i++){
        printf("%d\n", A[i]);
    }

	return 0;
}
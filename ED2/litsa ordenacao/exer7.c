#include <stdio.h>

void bubbleSortDecrescente(int array[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (array[j] < array[j+1]) {
                
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main() {
    int array_numeros[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(array_numeros) / sizeof(array_numeros[0]);

    bubbleSortDecrescente(array_numeros, n);

    printf("Array ordenado de maneira decrescente: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array_numeros[i]);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Aluno: Luiz Eduardo Rezende Moraes


// Função para intercalar dois subarrays ordenados
void intercalar(int v[], int inicio, int centro, int fim) {
    int vAux[10], tamanho, i, j, k;
    int fim1 = 0; int fim2 = 0;
    tamanho = fim - inicio + 1;
    int p1 = inicio;
    int p2 = centro + 1;

    // Intercala os dois subarrays ordenados em um array temporário
    for (i = 0; i < tamanho; i++) {
        if (!fim1 && !fim2) {
            if (v[p1] < v[p2])
                vAux[i] = v[p1++];
            else
                vAux[i] = v[p2++];

            // Verifica se algum dos subarrays chegou ao fim
            if (p1 > centro) fim1 = 1;
            if (p2 > fim) fim2 = 1;
        }
        else {
            // Copia os elementos restantes do subarray que não chegou ao fim
            if (!fim1)
                vAux[i] = v[p1++];
            else
                vAux[i] = v[p2++];
        }
    }

    // Copia os elementos intercalados de volta para o array original
    j = 0;
    for (k = inicio; k <= fim; k++) {
        v[k] = vAux[j];
        j++;
    }
}

void mergesort(int v[], int esq, int dir) {
    int centro;
    if (esq < dir) {
        
        centro = (esq + dir) / 2;

        // Recursivamente ordena as duas metades do array
        mergesort(v, esq, centro);
        mergesort(v, centro + 1, dir);

        // Combina as duas metades ordenadas usando a função intercalar
        intercalar(v, esq, centro, dir);
    }
}

int main() {
    
    int vet[10] = {9, 4, 3, 5, 6, 7, 1, 2, 8, 10};

    
    mergesort(vet, 0, 9);

    
    printf("Array Ordenado: ");
    for (int i = 0; i < 10; i++)
        printf("%d\t", vet[i]);

    return 0;
}

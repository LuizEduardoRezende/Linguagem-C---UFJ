/*Aluno: Luiz Eduardo Rezende Moraes
Para responder essa questão número 4 escolhi utilizar a Busca Binária.
Inicialmente preencho os valores dos id's com 500 numeros aleatórios, depois eu ordeno utilizando a função
selection_sort() e por fim uso a função buscaBbinaria() para buscar o valor no vetor ordenado.
Escolhi a busca binária por ser o metodo mais eficaz para fazer uma busca em um vetor.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 500 

typedef struct ITEM
{
	int id;
    char nome[30];

} tipoItem;

//vetor com 500 registros 
tipoItem item[TAM];
int aux;

void selection_sort()
{
    int i, j, min_idx;
    for (i = 0; i < TAM - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < TAM; j++)
        {
            if (item[j].id < item[min_idx].id)
            {
                min_idx = j;
            }
        }
        // Troca o menor elemento encontrado com o primeiro elemento não ordenado
        aux = item[min_idx].id;
        item[min_idx].id = item[i].id;
        item[i].id = aux;
    }
}

void insertion_sort()
{
    int i, j;
    for (i = 1; i < TAM; i++)
    {
        j = i - 1;
        aux = item[i].id;
        while (j >= 0 && aux < item[j].id)
        {
            item[j + 1].id = item[j].id;
            j--;
        }
        item[j + 1].id = aux; // Move o valor de aux para a posição correta
    }
}


void bubble_sort()
{
    int i, j;

    for (i = 0; i < TAM; i++)
    {
        for (j = i + 1; j < TAM; j++)
        {
            if (item[j].id < item[i].id)
            {
                aux = item[j].id;
                item[j].id = item[i].id;
                item[i].id = aux;
            }
        }
    }
}

// Função para realizar busca binária em um vetor ordenado
int buscaBinaria(tipoItem vetor[], int inicio, int fim, int elemento) {
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (vetor[meio].id == elemento) {
            return meio; // Elemento encontrado, retorna a posição
        }

        if (vetor[meio].id < elemento) {
            inicio = meio + 1; // Descarta a metade inferior
        } else {
            fim = meio - 1; // Descarta a metade superior
        }
    }

    return -1; // Elemento não encontrado
}

int main()
{
    int i = 0;
    int valor;

    for (i = 0; i < TAM; i++)
    {
        item[i].id = rand();
    }

    selection_sort();

    for (i = 0; i < TAM; i++)
    {
        printf("%d\t",item[i].id);
    }

    printf("\nDigite um ID para ser buscado nos 500 registros.\n");
    scanf("%d", &valor);
    fflush(stdin);

    if( buscaBinaria(item, 0, 499, valor) == -1)
        printf("Valor nao encontrado nos registros.\n");
    else
        printf("A posicao desse id no vetor e: %d\n",buscaBinaria(item, 0, 499, valor));

    return 0;
}

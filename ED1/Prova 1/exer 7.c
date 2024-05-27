#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
//aluno Luiz Eduardo Rezende Moraes

typedef struct vetor{
    int vet[3];

}tipo_vetor;
int topo = -1;

void cria(tipo_vetor V[], int valor1, int valor2, int valor3)
{
    topo++;
    V[topo].vet[0] = valor1;
    V[topo].vet[1] = valor2;
    V[topo].vet[2] = valor3;
}

void libera(tipo_vetor V[])
{
    V[topo].vet[0] = NULL;
    V[topo].vet[1] = NULL;
    V[topo].vet[2] = NULL;
    topo--;
}

void soma(tipo_vetor V[], int a , int b)
{
    int valor1, valor2, valor3;
    valor1 = V[a].vet[0] + V[b].vet[0];
    valor2 = V[a].vet[1] + V[b].vet[1];
    valor3 = V[a].vet[2] + V[b].vet[2];

    cria(V, valor1, valor2, valor3);
}

int prodint(tipo_vetor V[], int a, int b)
{
    int soma = 0;
    soma += V[a].vet[0] * V[b].vet[0];
    soma += V[a].vet[1] * V[b].vet[1];
    soma += V[a].vet[2] * V[b].vet[2];

    return soma;
}

void prodvet(tipo_vetor V[], int a, int b)
{
    int valor1, valor2, valor3;
    valor1 = V[a].vet[1] * V[b].vet[2] - V[a].vet[2] * V[b].vet[1];
    valor2 = V[a].vet[2] * V[b].vet[0] - V[a].vet[0] * V[b].vet[2];
    valor3 = V[a].vet[0] * V[b].vet[1] - V[a].vet[1] * V[b].vet[0];

    cria(V, valor1, valor2, valor3);
}

void consulta(tipo_vetor V[])
{
    printf("Vetor do topo: ");
    for(int i = 0; i<3;i++)
    {
        printf("%d\t", V[topo].vet[i]);
    }
    printf("\n");

} 

int main()
{
    tipo_vetor V[12];
    int opcao;
    int a = 0, b = 0;

    do
    {
        printf("\n\nO que deseja fazer ?\n");
        printf("1- Criar um vetor.\n2- Liberar um vetor.\n3- Soma de 2 vetores.\n4- Produto interno.\n");
        printf("5- Produto vetorial.\n6- Mostrar ultimo vetor.\n0- Sair do menu.\n");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao)
        {
        case 0:
            printf("Menu encerrado.\n");
            break;
        case 1:
            system("cls");
            int valor1 = 0, valor2 = 0, valor3 = 0;
            printf("Digite o valor 1: ");
            scanf("%d", &valor1);
            fflush(stdin);

            printf("Digite o valor 2: ");
            scanf("%d", &valor2);
            fflush(stdin);

            printf("Digite o valor 3: ");
            scanf("%d", &valor3);
            fflush(stdin);

            cria(V, valor1, valor2, valor3);

            break;
        case 2:
            system("cls");
            libera(V);
            printf("Vetor do topo liberado com sucesso.\n");

            break;
        case 3:
            system("cls");
            a = 0; b = 0;

            printf("Informe os vetores que serao somados:\n");
            scanf("%d", &a);
            fflush(stdin);
            scanf("%d", &b);
            fflush(stdin);

            if( (a > topo || a < 0) || (b > topo || b < 0))
                printf("Digite apenas vetores que já existem.\n");
            else
            {
                soma(V, a, b);
                printf("Vetores resultante armazenado no topo.\n");
            }
            break; 
        case 4:
            system("cls");
            a = 0; b = 0;

            printf("Informe os vetores que serao utilizados:\n");
            scanf("%d", &a);
            fflush(stdin);
            scanf("%d", &b);
            fflush(stdin);

            if( (a > topo || a < 0) || (b > topo || b < 0))
                printf("Digite apenas vetores que já existem.\n");
            else
                printf("Produto interno desses vetores: %d", prodint(V, a, b));


            break;
        case 5:
            system("cls");
            a = 0; b = 0;

            printf("Informe os vetores que serao utilizados:\n");
            scanf("%d", &a);
            fflush(stdin);
            scanf("%d", &b);
            fflush(stdin);

            if( (a > topo || a < 0) || (b > topo || b < 0))
                printf("Digite apenas vetores que já existem.\n");
            else
            {
                prodvet(V, a, b);
                printf("Vetores resultante armazenado no topo.\n");
            }

            break;
        case 6:
            system("cls");
            consulta(V);

            break;                      
        default:
            break;
        }

    }while(opcao != 0);


    return 0;
}
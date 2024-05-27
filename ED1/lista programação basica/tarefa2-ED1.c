#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

// Aluno / Autor: Luiz Eduardo Rezende Moraes
// Matricula : 202200162

typedef struct contabancaria
{
    char nome[30];
    int conta;
    float saldo;
} tipoConta;
tipoConta cb[10];

int CONT = 0;

void inicarConta(tipoConta cb[])
{
    printf("Digite o nome do titular:\n");
    scanf("%[^\n]s", cb[CONT].nome);
    fflush(stdin);
    printf("Digite o numero da conta bancaria:\n");
    scanf("%d", &cb[CONT].conta);
    fflush(stdin);
    printf("Digite o saldo inicial da conta:\n");
    scanf("%f", &cb[CONT].saldo);
    fflush(stdin);
    CONT++;
}

void depositarConta(tipoConta cb[])
{
    int conta = 0, flag = 0;
    float deposito = 0;
    printf("Digite o numero da conta:\n");
    scanf("%d", &conta);
    fflush(stdin);
    for (int i = 0; i < 11; i++)
    {
        if (conta == cb[i].conta)
        {
            printf("Digite o valor a ser depositado:\n");
            scanf("%f", &deposito);
            fflush(stdin);
            cb[i].saldo += deposito;
            flag = 1;
            break;
        }
        
    }
    if( flag == 0)
        printf("Conta inexistente.\n\n");
}

void sacarConta(tipoConta cb[])
{
    int conta = 0, flag = 0;
    float saque = 0;
    printf("Digite o numero da conta:");
    scanf("%d", &conta);
    fflush(stdin);
    for (int i = 0; i < 11; i++)
    {
        if (conta == cb[i].conta)
        {
            printf("Digite o valor a ser sacado:\n");
            scanf("%f", &saque);
            fflush(stdin);
            cb[i].saldo -= saque;
            flag = 1;
            break;
        }
    }
    if( flag == 0)
        printf("Conta inexistente.\n\n");

}

void imprimiConta(tipoConta cb[]){
    int conta = 0, flag = 0;
    printf("Digite o numero da conta:\n");
    scanf("%d", &conta);
    fflush(stdin);

    for(int i = 0; i<11; i++)
    {
        if(conta == cb[i].conta){
            printf("Conta numero: %d\n", cb[i].conta);
            printf("Nome do titular: %s\n", cb[i].nome);
            printf("Saldo: %f\n", cb[i].saldo);
            flag = 1;
            break;
        }  
    }
    if( flag == 0)
        printf("Conta inexistente.\n\n");
}

int main()
{
    int opcao = -1;

    do
    {
        printf("\n\nDigite a opcao que deseja:\n1- Iniciar conta\n2- Depositar um valor\n");
        printf("3- Sacar um valor\n4- Imprimir o saldo.\n0- Encerrar o Menu.\n");
        scanf("%d", &opcao);
        fflush(stdin);
        switch (opcao)
        {
        case 0:
            printf("Menu encerrado.\n");
            break;
        case 1:
            inicarConta(cb);
            break;

        case 2:
            depositarConta(cb);
            break;

        case 3:
            sacarConta(cb);
            break;

        case 4:
            imprimiConta(cb);
            break;

        default:
            printf("Digite uma opcao valida.\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
//aluno Luiz Eduardo Rezende Moraes

typedef struct produto {
    int codigo;
    char nome[100];
    int quantidade;
    int preco;
}tipo_produto;

int topo = -1;

void insert(tipo_produto P[])
{
    topo++;

    printf("\nCodigo do produto: ");
    scanf("%d", &P[topo].codigo);
    fflush(stdin);
    printf("\nNome do produto: ");
    scanf("%[^\n]s", P[topo].nome);
    fflush(stdin);
    printf("\nQuantidade em estoque: ");
    scanf("%d", &P[topo].quantidade);
    fflush(stdin);
    printf("\nPreco do produto: ");
    scanf("%d", &P[topo].preco);
    fflush(stdin);

}

void search(tipo_produto P[])
{
    int cod = 0;
    printf("Informe o codigo do produto: ");
    scanf("%d", &cod);
    fflush(stdin);

    for(int i = 0; i <= topo; i++)
    {
        if( cod == P[i].codigo)
        {
            printf("Codigo: %d\n", P[i].codigo);
            printf("Nome: %s\n", P[i].nome);
            printf("Quantidade: %d\n", P[i].quantidade);
            printf("Preco: %d\n", P[i].preco);
            return ;
        }
    }
    printf("Produto nao encontrado.\n");
}

void delete(tipo_produto P[])
{
    int cod = 0;
    printf("Informe o codigo do produto: ");
    scanf("%d", &cod);
    fflush(stdin);

    for(int i = 0; i <= topo; i++)
    {
        if( cod == P[i].codigo)
        {
            P[i].codigo = 0;
            strcpy(P[i].nome, " "); 
            P[i].quantidade = 0;
            P[i].preco = 0;
            printf("Produto deletado com sucesso.\n");
            return ;
        }
    }
    printf("Produto nao encontrado.\n");

}


int main()
{
    tipo_produto P[20];
    int opcao;

    do
    {
        printf("\n\nO que deseja fazer ?\n");
        printf("1- Inserir produto.\n2- Procurar produto.\n3- Deletar produto.\n0- Encerrar o menu.\n");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao)
        {
        case 0:
            printf("Menu encerrado.\n");
            break;
        case 1:
            system("cls");
            insert(P);
            printf("Produto inserido com sucesso.\n");

            break;
        case 2:
            system("cls");
            search(P);

            break;
        case 3:
            system("cls");
            delete(P);

            break;                                
        default:
            break;
        }

    }while(opcao != 0);


    return 0;
}
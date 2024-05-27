//Aluno: Luiz Eduardo Rezende Moraes
#include<stdio.h> 
#include<stdlib.h> 
typedef struct ITEM
{
    int lab;
	int preco;
    int nome;
    int codigo;

}tipoItem;

tipoItem v[20];

int buscaBinaria(tipoItem *vetor, int valor, int inicio, int fim) {
    if (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (vetor[meio].codigo == valor) {
            return meio;
        } else if (vetor[meio].codigo < valor) {
            return buscaBinaria(vetor, valor, meio + 1, fim);
        } else {
            return buscaBinaria(vetor, valor, inicio, meio - 1);
        }
    } else {
        return -1;
    }
}

int buscaSequencial(tipoItem *vetor,int valor, int tamanho)
{

    int i = 0;
    int contador = 0;
    for(i=0; i < tamanho;i++)
    {
        
        if(vetor[i].codigo == valor){
            return contador;
        }
        contador++;
    }

    return -1;

}

void bubbleSort(tipoItem *vetor, int tamanho) {
    int atual=0;
    int proximo=0;
    tipoItem auxiliar;

    for (atual=1; atual < tamanho; atual++) {

    for (proximo=0; proximo < tamanho-1; proximo++) {

    if (vetor[proximo].codigo > vetor[proximo+1].codigo) {


        auxiliar.preco = vetor[proximo].preco;
        auxiliar.nome = vetor[proximo].nome;
        auxiliar.codigo = vetor[proximo].codigo;
        auxiliar.lab = vetor[proximo].lab;

        vetor[proximo].preco = vetor[proximo+1].preco;
        vetor[proximo].nome = vetor[proximo+1].nome;
        vetor[proximo].codigo = vetor[proximo+1].codigo;
        vetor[proximo].lab = vetor[proximo+1].lab;


        vetor[proximo+1].preco = auxiliar.preco;
        vetor[proximo+1].nome = auxiliar.nome;
        vetor[proximo+1].codigo = auxiliar.codigo;
        vetor[proximo+1].lab = auxiliar.lab;
    }
    }
}
}

int main() 
{ 
    int esc = -1;
    int i = 0;
    int posicao = 0;
    int num_busca = 0;

    do{
        printf("Digite:\n");
        printf("1 para cadastrar novo item.\n");
        printf("2 para fazer a busca sequencial\n");
        printf("3 para fazer a busca binaria.\n");
        printf("0 para sair.\n");
        scanf("%d", &esc);

        switch (esc)
        {
        case 0:
            printf("Encerrando.\n");
            break;
        case 1:
            printf("Digite o nome: ( numero) \n");
            scanf("%d", &v[i].nome);
            fflush(stdin);

            printf("Digite o preco:\n");
            scanf("%d", &v[i].preco);
            fflush(stdin);

            printf("Digite o codigo:\n");
            scanf("%d", &v[i].codigo);
            fflush(stdin);

            printf("Digite o nome do laboratorio.\n");
            scanf("%d", &v[i].lab);
            fflush(stdin);

            i++;
            break;

        case 2:
            printf("\nDigite o numero para ser buscado.\n\n");
            scanf("%d", &num_busca);
            fflush(stdin);

            posicao = buscaSequencial(v,num_busca,20);
            printf("Posicao no vetor: %d\n",posicao + 1);
            printf("Nome: %d\n", v[posicao].nome);
            printf("Preco: %d\n", v[posicao].preco);
            printf("Codigo: %d\n", v[posicao].codigo);
            printf("Nome do lab: %d\n", v[posicao].lab);

            break;
        case 3:
            bubbleSort(v,20);
            for(int j = 0; j<20; j++){
                printf("Nome: %d\n", v[j].nome);
                printf("Preco: %d\n", v[j].preco);
                printf("Codigo: %d\n", v[j].codigo);
                printf("Nome do lab: %d\n", v[j].lab);
            }

            printf("\nDigite o numero para ser buscado.\n\n");
            scanf("%d", &num_busca);
            fflush(stdin);
            posicao = buscaBinaria(v, num_busca, 0, 19);
            printf("Posicao no vetor: %d\n",posicao + 1);
            printf("Nome: %d\n", v[posicao].nome);
            printf("Preco: %d\n", v[posicao].preco);
            printf("Codigo: %d\n", v[posicao].codigo);
            printf("Nome do lab: %d\n", v[posicao].lab);


            break;
        default:
            break;
        }

    }while(esc != 0);


	return 0; 
}
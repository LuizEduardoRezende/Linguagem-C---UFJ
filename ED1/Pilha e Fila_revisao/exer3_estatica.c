#include <stdio.h>

#define MAX_QUEUE_SIZE 6

typedef struct
{
    int numero;
    char nome[50];
} tipo_aviao;

typedef struct
{
    tipo_aviao data[MAX_QUEUE_SIZE];
    int inicio, topo, count;
} tipo_fila;

void inicializarFila(tipo_fila *fila)
{
    fila->inicio = 0;
    fila->topo = -1;
    fila->count = 0;
}

int cheia(tipo_fila *fila)
{
    if (fila->count == MAX_QUEUE_SIZE)
        return 1;
    else
        return 0;
}

int vazia(tipo_fila *fila)
{
    if (fila->count == 0)
        return 1;
    else
        return 0;
}

void enfileirar(tipo_fila *fila, tipo_aviao aviao)
{
    if (cheia(fila) == 1)
    {
        printf("Fila esta cheia. Nao e possível adicionar mais avioes.\n");
        return;
    }
    fila->topo = (fila->topo + 1);
    fila->data[fila->topo] = aviao;
    fila->count++;

}

tipo_aviao desenfileirar(tipo_fila *fila)
{
    tipo_aviao aviaoVazio = {-1, ""};
    if (vazia(fila))
    {
        printf("Fila esta vazia.\n");
        return aviaoVazio;
    }
    tipo_aviao aviaoDesenfileirado = fila->data[fila->inicio];
    fila->inicio = (fila->inicio + 1);
    fila->count--;
    return aviaoDesenfileirado;
}

void checharPrimeiroAviao(tipo_fila *fila)
{
    tipo_aviao primeiroAviao = fila->data[fila->inicio];
    if (vazia(fila) == 1)
    {
        printf("Fila de avioes vazia.\n");
        return;
    }

    printf("Pirmeiro Aviao da fila:\n");
    printf("Compania Aerea: %s\n", primeiroAviao.nome);
    printf("Codigo do voo: %d\n", primeiroAviao.numero);
}

void listarAguardo(tipo_fila *fila)
{
    printf("Numero de avioes aguardando na fila: %d\n", fila->count);
}

void autorizarDecolagem(tipo_fila *fila)
{
    if (vazia(fila))
    {
        printf("Nenhum aviao na fila.\n");
        return;
    }
    tipo_aviao aviaoPartindo = desenfileirar(fila);
    printf("Autorizada decolagem do voo %d (%s)\n", aviaoPartindo.numero, aviaoPartindo.nome);
}

void adicionarAviaoFila(tipo_fila *fila)
{
    if (cheia(fila))
    {
        printf("Fila esta cheia. Nao e possivel adicionar mais avioes.\n");
        return;
    }
    tipo_aviao novoAviao;
    printf("Digite o numero do voo: ");
    scanf("%d", &novoAviao.numero);
    fflush(stdin);
    printf("Digite o nome da companhia aerea: ");
    scanf("%s", novoAviao.nome);
    fflush(stdin);
    enfileirar(fila, novoAviao);
}

void inverterFila(tipo_fila *fila) {
    if (vazia(fila)) {
        printf("Fila esta vazia. Nada para inverter.\n");
        return;
    }

    tipo_aviao temp[MAX_QUEUE_SIZE];
    int i, j;

    for (i = 0, j = fila->inicio + fila->count - 1; i < fila->count; i++, j--) {
        temp[i] = fila->data[j];
    }

    for (i = 0; i < fila->count; i++) {
        fila->data[(fila->inicio + i)] = temp[i];
    }

    printf("Fila invertida com sucesso.\n");

}

int main()
{
    tipo_fila filaDecolagem;
    inicializarFila(&filaDecolagem);
    int escolha = 0;
    do
    {
        printf("\n==== Controle de Decolagem no Aeroporto ====\n");
        printf("1. Listar numero de avioes aguardando\n");
        printf("2. Autorizar decolagem\n");
        printf("3. Adicionar aviao a fila\n");
        printf("4. Inverter Fila.\n");
        printf("5. Listar caracteristicas do primeiro aviao.\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &escolha);
        fflush(stdin);

        switch (escolha)
        {
        case 1:
            listarAguardo(&filaDecolagem);
            break;
        case 2:
            autorizarDecolagem(&filaDecolagem);
            break;
        case 3:
            adicionarAviaoFila(&filaDecolagem);
            break;
        case 4:
            inverterFila(&filaDecolagem);
            break;
        case 5:
            checharPrimeiroAviao(&filaDecolagem);
            break;
        case 6:
            printf("Encerrando o programa.\n");
            return 0;
        default:
            printf("Escolha invalida. Por favor, escolha uma opcao valida.\n");
        }

    } while (escolha != 6);

    return 0;
}

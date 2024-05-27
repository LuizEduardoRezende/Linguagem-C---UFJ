#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int numero;
    char nome[50];
} tipo_aviao;

typedef struct nodo {
    tipo_aviao aviao;
    struct nodo *prox;
} tipo_nodo;

typedef struct {
    tipo_nodo *inicio;
    tipo_nodo *fim;
    int count;
} tipo_fila;

void inicializarFila(tipo_fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->count = 0;
}

bool vazia(tipo_fila *fila) {
    return fila->count == 0;
}

void enfileirar(tipo_fila *fila, tipo_aviao aviao) {
    tipo_nodo *novoNodo = (tipo_nodo *)malloc(sizeof(tipo_nodo));
    if (!novoNodo) {
        printf("Erro ao alocar memoria.\n");
        return;
    }
    novoNodo->aviao = aviao;
    novoNodo->prox = NULL;

    if (vazia(fila)) {
        fila->inicio = novoNodo;
        fila->fim = novoNodo;
    } else {
        fila->fim->prox = novoNodo;
        fila->fim = novoNodo;
    }
    fila->count++;
}

tipo_aviao desenfileirar(tipo_fila *fila) {
    tipo_aviao aviaoVazio = {-1, ""};
    if (vazia(fila)) {
        printf("Fila esta vazia.\n");
        return aviaoVazio;
    }
    tipo_nodo *nodoRemovido = fila->inicio;
    tipo_aviao aviaoDesenfileirado = nodoRemovido->aviao;

    fila->inicio = fila->inicio->prox;
    free(nodoRemovido);
    fila->count--;

    return aviaoDesenfileirado;
}

void listarAguardo(tipo_fila *fila) {
    printf("Numero de avioes aguardando na fila: %d\n", fila->count);
}

void autorizarDecolagem(tipo_fila *fila) {
    if (vazia(fila)) {
        printf("Nenhum aviao na fila.\n");
        return;
    }
    tipo_aviao aviaoPartindo = desenfileirar(fila);
    printf("Autorizada decolagem do voo %d (%s)\n", aviaoPartindo.numero, aviaoPartindo.nome);
}

void adicionarAviaoFila(tipo_fila *fila) {
    tipo_aviao novoAviao;
    printf("Digite o numero do voo: ");
    scanf("%d", &novoAviao.numero);
    printf("Digite o nome da companhia aerea: ");
    scanf("%s", novoAviao.nome);
    enfileirar(fila, novoAviao);
}

int main() {
    tipo_fila filaDecolagem;
    inicializarFila(&filaDecolagem);

    int escolha;
    do
    {
        printf("\n==== Controle de Decolagem no Aeroporto ====\n");
        printf("1. Listar numero de avioes aguardando\n");
        printf("2. Autorizar decolagem\n");
        printf("3. Adicionar aviao a fila\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        
        scanf("%d", &escolha);

        switch (escolha) {
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
                printf("Encerrando o programa.\n");
                return 0;
            default:
                printf("Escolha invalida. Por favor, escolha uma opcao valida.\n");
        }
    }while(escolha != 4);

    return 0;
}

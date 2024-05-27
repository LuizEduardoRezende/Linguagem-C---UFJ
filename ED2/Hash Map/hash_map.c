//Luiz Eduardo Rezende Moraes
#include<stdio.h> 
#include<stdlib.h> 
#define TAM 5

// Estrutura para representar um item
typedef struct {
    int chave;
    int valor;
} tipo_item;

// Estrutura para representar um nó na lista encadeada
typedef struct NOH {
    tipo_item item;
    struct NOH* proximo;
} * tipo_lista;

// Estrutura para representar um item na tabela hash
typedef struct {
    tipo_lista lista;
} tipo_hash;

// Função para criar um novo nó na lista encadeada
tipo_lista criarNOH(tipo_item novoitem) {
    tipo_lista novoNOH = (tipo_lista)malloc(sizeof(struct NOH));

    if (novoNOH == NULL) {
        printf("\nErro ao alocar memória.\n");
        return NULL;
    } else {
        novoNOH->item = novoitem;
        novoNOH->proximo = NULL;
        return novoNOH;
    }
}

// Função para inserir um item no início da lista encadeada
tipo_lista inserirInicio(tipo_item novoItem, tipo_lista inicio) {
    tipo_lista novoNOH = criarNOH(novoItem);

    if (inicio == NULL) {
        return novoNOH;
    } else {
        novoNOH->proximo = inicio;
        return novoNOH;
    }
}

// Função para inserir um item no final da lista encadeada
tipo_lista inserirFinal(tipo_item novoItem, tipo_lista lista) {
    tipo_lista novoNOH = criarNOH(novoItem);

    if (lista == NULL) {
        return novoNOH;
    } else {
        tipo_lista listaAuxiliar = lista;

        while (listaAuxiliar->proximo != NULL) {
            listaAuxiliar = listaAuxiliar->proximo;
        }

        listaAuxiliar->proximo = novoNOH;
        return lista;
    }
}

// Função para remover o primeiro item da lista encadeada
tipo_lista removerInicio(tipo_lista lista) {
    if (lista == NULL) {
        printf("A lista está vazia.\n");
        return NULL;
    } else {
        tipo_lista novoInicio = lista->proximo;
        free(lista);
        return novoInicio;
    }
}

// Função para remover o último item da lista encadeada
tipo_lista removerFinal(tipo_lista lista) {
    if (lista == NULL) {
        printf("A lista está vazia.\n");
        return NULL;
    } else if (lista->proximo == NULL) {
        free(lista);
        return NULL;
    } else {
        tipo_lista listaAuxiliar = lista;
        while (listaAuxiliar->proximo->proximo != NULL) {
            listaAuxiliar = listaAuxiliar->proximo;
        }
        free(listaAuxiliar->proximo);
        listaAuxiliar->proximo = NULL;
        return lista;
    }
}

// Função para exibir os itens da lista encadeada
void exibir(tipo_lista lista) {
    printf("\n---- LISTA ----\n");

    if (lista == NULL) {
        printf("Vazia\n");
    } else {
        tipo_lista listaAuxiliar = lista;

        while (listaAuxiliar != NULL) {
            printf("\n[Chave: %d\tValor:%d] ", listaAuxiliar->item.chave, listaAuxiliar->item.valor);
            listaAuxiliar = listaAuxiliar->proximo;
        }
        printf("\n");
    }
}

// Função para buscar a chave na tabela hash
tipo_lista buscar_chave(int chave, tipo_hash vet[]) {
    int hash = chave % TAM;
    return vet[hash].lista;
}

// Função para criar o hash da chave
int criar_hash(int chave) {
    return chave % TAM;
}

int main() { 
    int val;
    int chave;
    int hash;
    int i;

    // Inicializando a tabela hash com listas vazias
    tipo_hash vet[TAM];
    for (i = 0; i < TAM; i++) {
        vet[i].lista = NULL;
    }

    tipo_item novoItem1;
    int opcao = -1;

    do {
        printf("\nEscolha uma opcao:\n");
        printf("1- Adicionar item com alguma chave.\n");
        printf("2- Exibir itens de uma determinada chave.\n");
        printf("3- Sair do menu.\n");
        printf("Digite a opcao escolhida: ");
        scanf("%d", &opcao);
        getchar(); // Consumir o caractere de nova linha

        switch (opcao) {
            case 1:
                printf("Digite o valor do item:\n");
                scanf("%d", &val);
                fflush(stdin);

                printf("Digite a chave:\n");
                scanf("%d", &chave);
                fflush(stdin);

                hash = criar_hash(chave);

                novoItem1.chave = chave;
                novoItem1.valor = val;
                vet[hash].lista = inserirFinal(novoItem1, vet[hash].lista);
                break;

            case 2:
                printf("Digite a chave:\n");
                scanf("%d", &chave);
                fflush(stdin);

                hash = criar_hash(chave);

                tipo_lista listaEncontrada = buscar_chave(chave, vet);
                if (listaEncontrada == NULL) {
                    printf("Chave não encontrada.\n");
                } else {
                    exibir(listaEncontrada);
                }
                break;

            case 3:
                printf("Menu encerrado.\n");
                break;

            default:
                printf("Digite uma opcao valida.\n");
                break;
        }
    } while (opcao != 3);

    // Libere a memória alocada para os nós da lista antes de sair do programa
    for (i = 0; i < TAM; i++) {
        tipo_lista lista = vet[i].lista;
        
        while (lista != NULL) {
            tipo_lista proximo = lista->proximo;
            free(lista);
            lista = proximo;
        }
        
        vet[i].lista = NULL;  
    }

    return 0; 
}

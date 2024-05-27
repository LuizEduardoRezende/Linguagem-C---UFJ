#include <stdio.h>
#include <stdlib.h>

typedef struct NOH {
    int data;
    struct NOH* proximo;
} NOH;

typedef NOH* ListaCircular;

// Função para criar um novo nó
NOH* criarNoh(int valor) {
    NOH* novoNoh = (NOH*)malloc(sizeof(NOH));
    if (novoNoh == NULL) {
        fprintf(stderr, "Erro: Falha na alocacao de memoria.\n");
        exit(1);
    }
    novoNoh->data = valor;
    novoNoh->proximo = NULL;
    return novoNoh;
}

// Função para contar o número de elementos na lista circular
int contarElementos(ListaCircular lista) {
    if (lista == NULL) {
        return 0;
    }

    int contador = 1; // Inicializado com 1 para incluir o próprio cabeçalho
    NOH* atual = lista->proximo;

    while (atual != lista) {
        contador++;
        atual = atual->proximo;
    }

    return contador;
}

// Função para inserir um elemento à esquerda do cabeçalho da lista
void inserirEsquerda(ListaCircular* lista, int valor) {
    NOH* novoNoh = criarNoh(valor);

    if (*lista == NULL) {
        *lista = novoNoh;
        novoNoh->proximo = novoNoh; // Lista com um único nó apontando para si mesmo
    } else {
        novoNoh->proximo = (*lista)->proximo;
        (*lista)->proximo = novoNoh;
    }
}

// Função para eliminar o elemento de valor x
void eliminarElemento(ListaCircular* lista, int valor) {
    if (*lista == NULL) {
        return;
    }

    NOH* atual = *lista;
    NOH* anterior = NULL;

    do {
        if (atual->data == valor) {
            if (anterior != NULL) {
                anterior->proximo = atual->proximo;
                free(atual);
                if (atual == *lista) {
                    *lista = anterior->proximo;
                }
                return;
            } else {
                // Caso especial: o elemento a ser excluído é o próprio cabeçalho
                NOH* ultimo = atual;
                while (ultimo->proximo != *lista) {
                    ultimo = ultimo->proximo;
                }
                *lista = atual->proximo;
                ultimo->proximo = *lista;
                free(atual);
                return;
            }
        }
        anterior = atual;
        atual = atual->proximo;
    } while (atual != *lista);
}

// Função para concatenar duas listas circulares
void concatenarListas(ListaCircular* lista1, ListaCircular* lista2) {
    if (*lista2 == NULL) {
        return;
    }

    if (*lista1 == NULL) {
        *lista1 = *lista2;
        return;
    }

    NOH* ultimoLista1 = (*lista1)->proximo;
    while (ultimoLista1->proximo != *lista1) {
        ultimoLista1 = ultimoLista1->proximo;
    }

    NOH* primeiroLista2 = (*lista2)->proximo;

    ultimoLista1->proximo = primeiroLista2;
    free(*lista2);
    *lista2 = NULL;
}

// Função para intercalar duas listas ordenadas
ListaCircular intercalarListasOrdenadas(ListaCircular lista1, ListaCircular lista2) {
    if (lista1 == NULL) {
        return lista2;
    }

    if (lista2 == NULL) {
        return lista1;
    }

    NOH* novaLista = NULL;
    NOH* atual1 = lista1;
    NOH* atual2 = lista2;

    do {
        if (atual1->data < atual2->data) {
            inserirEsquerda(&novaLista, atual1->data);
            atual1 = atual1->proximo;
        } else {
            inserirEsquerda(&novaLista, atual2->data);
            atual2 = atual2->proximo;
        }
    } while (atual1 != lista1 && atual2 != lista2);

    // Se algum dos nós ainda tiver elementos, adicionamos os restantes
    while (atual1 != lista1) {
        inserirEsquerda(&novaLista, atual1->data);
        atual1 = atual1->proximo;
    }

    while (atual2 != lista2) {
        inserirEsquerda(&novaLista, atual2->data);
        atual2 = atual2->proximo;
    }

    return novaLista;
}

// Função para fazer uma cópia da lista
ListaCircular copiarLista(ListaCircular lista) {
    if (lista == NULL) {
        return NULL;
    }

    ListaCircular novaLista = NULL;
    NOH* atual = lista;

    do {
        inserirEsquerda(&novaLista, atual->data);
        atual = atual->proximo;
    } while (atual != lista);

    return novaLista;
}

// Função para imprimir a lista circular
void imprimirListaCircular(ListaCircular lista) {
    if (lista == NULL) {
        return;
    }

    NOH* atual = lista;
    do {
        printf("%d ", atual->data);
        atual = atual->proximo;
    } while (atual != lista);

    printf("\n");
}

// Função para liberar a memória alocada para a lista circular
void liberarListaCircular(ListaCircular* lista) {
    if (*lista == NULL) {
        return;
    }

    NOH* atual = (*lista)->proximo;
    while (atual != *lista) {
        NOH* temp = atual->proximo;
        free(atual);
        atual = temp;
    }
    free(*lista);
    *lista = NULL;
}

int main() {
    ListaCircular lista = NULL;
    ListaCircular lista2 = NULL;

    // Inserção de elementos na lista
    inserirEsquerda(&lista, 1);
    inserirEsquerda(&lista, 2);
    inserirEsquerda(&lista, 3);

    printf("Lista 1: ");
    imprimirListaCircular(lista);

    // Contar o número de elementos na lista
    int tamanho = contarElementos(lista);
    printf("Numero de elementos na lista 1: %d\n", tamanho);

    // Inserir elemento à esquerda do cabeçalho
    inserirEsquerda(&lista, 0);
    printf("Lista 1 apos insercao: ");
    imprimirListaCircular(lista);

    // Eliminar elemento de valor x
    eliminarElemento(&lista, 2);
    printf("Lista 1 apos eliminar o elemento 2: ");
    imprimirListaCircular(lista);

    /* Concatenar duas listas
    inserirEsquerda(&lista2, 4);
    inserirEsquerda(&lista2, 5);
    printf("Lista 2: ");
    imprimirListaCircular(lista2);

    concatenarListas(&lista, &lista2);
    printf("Lista 1 apos concatenacao com Lista 2: ");
    imprimirListaCircular(lista);*/

    // Intercalar duas listas ordenadas
    ListaCircular listaOrdenada1 = NULL;
    ListaCircular listaOrdenada2 = NULL;
    inserirEsquerda(&listaOrdenada1, 1);
    inserirEsquerda(&listaOrdenada1, 3);
    inserirEsquerda(&listaOrdenada2, 2);
    inserirEsquerda(&listaOrdenada2, 4);

    printf("Lista Ordenada 1: ");
    imprimirListaCircular(listaOrdenada1);
    printf("Lista Ordenada 2: ");
    imprimirListaCircular(listaOrdenada2);

    ListaCircular listaIntercalada = intercalarListasOrdenadas(listaOrdenada1, listaOrdenada2);
    printf("Lista Intercalada: ");
    imprimirListaCircular(listaIntercalada);

    // Fazer uma cópia da lista
    ListaCircular copia = copiarLista(lista);
    printf("Copia da Lista 1: ");
    imprimirListaCircular(copia);

    // Liberar memória alocada para as listas
    liberarListaCircular(&lista);
    liberarListaCircular(&lista2);
    liberarListaCircular(&listaOrdenada1);
    liberarListaCircular(&listaOrdenada2);
    liberarListaCircular(&listaIntercalada);
    liberarListaCircular(&copia);

    return 0;
}

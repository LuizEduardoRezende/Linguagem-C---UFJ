#include <stdio.h>
#include <stdlib.h>

// Definição de uma estrutura para um nó da lista
struct Node {
    int data;
    struct Node* next;
};

// Definição de um tipo Lista como um ponteiro para o nó
typedef struct Node* Lista;

// Função para criar um novo nó
struct Node* criarNo(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um nó no início da lista
void inserirNoInicio(Lista* lista, int data) {
    struct Node* newNode = criarNo(data);
    newNode->next = *lista;
    *lista = newNode;
}

// Função para encontrar o menor elemento e movê-lo para o início
void MoveMenor(Lista* lista) {
    if (*lista == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    struct Node* current = *lista;
    struct Node* prev = NULL;
    struct Node* minNode = *lista;
    struct Node* prevMin = NULL;

    while (current != NULL) {
        if (current->data < minNode->data) {
            prevMin = prev;
            minNode = current;
        }
        prev = current;
        current = current->next;
    }

    if (minNode != *lista) {
        // Se o menor elemento não está no início, remova-o da sua posição atual
        prevMin->next = minNode->next;
        // Mova o nó para o início da lista
        minNode->next = *lista;
        *lista = minNode;
    }
}

// Função para imprimir a lista
void imprimirLista(Lista lista) {
    struct Node* current = lista;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Função principal
int main() {
    Lista lista = NULL;

    // Exemplo de inserção de elementos na lista
    inserirNoInicio(&lista, 5);
    inserirNoInicio(&lista, 2);
    inserirNoInicio(&lista, 9);
    inserirNoInicio(&lista, 1);

    printf("Lista original:\n");
    imprimirLista(lista);

    MoveMenor(&lista);

    printf("\nLista após MoveMenor:\n");
    imprimirLista(lista);

    return 0;
}

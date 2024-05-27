#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da lista
struct Noh {
    int data;
    struct Noh* next;
};

// Função para adicionar um novo nó no início da lista
void push(struct Noh** head, int data) {
    struct Noh* newNode = (struct Noh*)malloc(sizeof(struct Noh));
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
}

// Função para imprimir uma lista
void printList(struct Noh* head) {
    struct Noh* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Função para separar a lista em duas listas, uma para pares e outra para ímpares
void splitList(struct Noh* original, struct Noh** even, struct Noh** odd) {
    struct Noh* current = original;
    while (current != NULL) {
        if (current->data % 2 == 0) {
            push(even, current->data);
        } else {
            push(odd, current->data);
        }
        current = current->next;
    }
}

int main() {
    struct Noh* inicio = NULL;
    struct Noh* impar = NULL;
    struct Noh* par = NULL;

    // Exemplo: Construir a lista original
    push(&inicio, 8);
    push(&inicio, 7);
    push(&inicio, 6);
    push(&inicio, 2);
    push(&inicio, 1);

    printf("Lista Original:\n");
    printList(inicio);

    // Dividir a lista em listas de pares e ímpares
    splitList(inicio, &par, &impar);

    printf("\nLista de Ímpares:\n");
    printList(impar);

    printf("\nLista de Pares:\n");
    printList(par);

    return 0;
}

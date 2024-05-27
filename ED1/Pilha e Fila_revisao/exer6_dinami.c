#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Pilha {
    struct Node* top;
};

void initialize(struct Pilha* p) {
    p->top = NULL;
}

int isEmpty(struct Pilha* p) {
    return p->top == NULL;
}

void push(struct Pilha* p, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = p->top;
    p->top = newNode;
}

int pop(struct Pilha* p) {
    if (!isEmpty(p)) {
        struct Node* temp = p->top;
        int value = temp->data;
        p->top = temp->next;
        free(temp);
        return value;
    }
    return 0;  // Retornamos 0 se a pilha estiver vazia
}

int main() {
    struct Pilha pilhaA, pilhaB;
    initialize(&pilhaA);
    initialize(&pilhaB);

    printf("Digite 6 numeros inteiros:\n");
    for (int i = 0; i < 6; i++) {
        int num;
        scanf("%d", &num);

        if (num % 2 == 0) {
            push(&pilhaA, num);  // Empilhar número par na pilha A
        } else {
            push(&pilhaB, num);  // Empilhar número ímpar na pilha B
        }
    }

    printf("Numeros pares na pilha A:\n");
    while (!isEmpty(&pilhaA)) {
        printf("%d\n", pop(&pilhaA));
    }

    printf("Numeros impares na pilha B:\n");
    while (!isEmpty(&pilhaB)) {
        printf("%d\n", pop(&pilhaB));
    }

    return 0;
}

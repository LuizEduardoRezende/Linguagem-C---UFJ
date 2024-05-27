#include <stdio.h>

#define MAX_SIZE 6

struct Pilha {
    int data[MAX_SIZE];
    int top;
};

void initialize(struct Pilha* p) {
    p->top = -1;
}

int isFull(struct Pilha* p) {
    return p->top == MAX_SIZE - 1;
}

int isEmpty(struct Pilha* p) {
    return p->top == -1;
}

void push(struct Pilha* p, int value) {
    if (!isFull(p)) {
        p->data[++p->top] = value;
    }
}

int pop(struct Pilha* p) {
    if (!isEmpty(p)) {
        return p->data[p->top--];
    }
    return 0;  // Retornamos 0 se a pilha estiver vazia
}

int main() {
    struct Pilha pilhaA, pilhaB;
    initialize(&pilhaA);
    initialize(&pilhaB);

    printf("Digite 6 numeros inteiros:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
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

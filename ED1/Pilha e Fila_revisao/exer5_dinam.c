#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 50

struct Node {
    char data;
    struct Node* proximo;
};

struct Pilha {
    struct Node* topo;
};

void initialize(struct Pilha* p) {
    p->topo = NULL;
}

int isEmpty(struct Pilha* p) {
    return p->topo == NULL;
}

void push(struct Pilha* p, char value) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    if (novoNo == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }

    novoNo->data = value;
    novoNo->proximo = p->topo;
    p->topo = novoNo;
}

char pop(struct Pilha* p) {
    if (!isEmpty(p)) {
        struct Node* temp = p->topo;
        char value = temp->data;
        p->topo = temp->proximo;
        free(temp);
        return value;
    }
    return '\0';
}

int main() {
    struct Pilha pilha;
    initialize(&pilha);

    char palavra[MAX_SIZE];
    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    int length = strlen(palavra);

    for (int i = 0; i < length; i++) {
        push(&pilha, palavra[i]);
    }

    int isPalindrome = 1;
    for (int i = 0; i < length; i++) {
        char c = pop(&pilha);
        if (c != palavra[i]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome) {
        printf("A palavra \"%s\" eh um palindromo.\n", palavra);
    } else {
        printf("A palavra \"%s\" nao eh um palindromo.\n", palavra);
    }

    // Liberar memória da pilha
    while (!isEmpty(&pilha)) {
        pop(&pilha);
    }

    return 0;
}

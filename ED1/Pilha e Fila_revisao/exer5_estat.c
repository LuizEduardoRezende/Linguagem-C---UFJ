#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

struct Pilha {
    char data[MAX_SIZE];
    int top;
};

void initialize(struct Pilha *p) {
    p->top = -1;
}

int isFull(struct Pilha *p) {
    return p->top == MAX_SIZE - 1;
}

int isEmpty(struct Pilha *p) {
    return p->top == -1;
}

void push(struct Pilha *p, char value) {
    if (!isFull(p)) {
        p->data[++p->top] = value;
    }
}

char pop(struct Pilha *p) {
    if (!isEmpty(p)) {
        return p->data[p->top--];
    }
    return '\0';
}

int main() {
    struct Pilha pilha;
    initialize(&pilha);
    
    char palavra[MAX_SIZE];
    printf("Digite uma cadeia de caracteres: ");
    scanf("%s", palavra);
    fflush(stdin);
    
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
    
    if (isPalindrome == 1) {
        printf("A cadeia \"%s\" eh um palindromo.\n", palavra);
    } else {
        printf("A cadeia \"%s\" nao eh um palindromo.\n", palavra);
    }
    
    return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

struct Pessoa {
    char nome[50];
    int idade;
};

typedef struct Stack {
    struct Pessoa pessoas[MAX_SIZE];
    int topo;
} tipo_stack;

tipo_stack stack;
tipo_stack auxiliar;

void initialize(tipo_stack *S) {
    S->topo = -1;
}

int isFull(tipo_stack *S) {
    return (S->topo >= MAX_SIZE - 1);
}

int isEmpty(tipo_stack *S) {
    return (S->topo < 0);
}

void push(tipo_stack *S, struct Pessoa pessoa) {
    if (!isFull(S)) {
        S->topo++;
        S->pessoas[S->topo] = pessoa;
    } else {
        printf("Pilha cheia.\n");
    }
}

void pop(tipo_stack *S) {
    if (!isEmpty(S)) {
        S->topo--;
    } else {
        printf("Pilha vazia.\n");
    }
}

void removerPessoa(char nomeRemover[50]) {
    initialize(&auxiliar);

    while (!isEmpty(&stack)) {
        if (strcmp(stack.pessoas[stack.topo].nome, nomeRemover) == 0) {
            pop(&stack);
        } else {
            push(&auxiliar, stack.pessoas[stack.topo]);
            pop(&stack);
        }
    }
}

int main() {
    initialize(&stack);

    int n;
    printf("Quantas pessoas deseja inserir na pilha? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        struct Pessoa pessoa;
        printf("Digite o nome da pessoa %d: \n", i + 1);
        scanf("%s", pessoa.nome);
        printf("Digite a idade da pessoa %d: \n", i + 1);
        scanf("%d", &pessoa.idade);
        push(&stack, pessoa);
    }

    char nomeRemover[50];
    printf("Digite o nome da pessoa que deseja remover: ");
    scanf("%s", nomeRemover);

    removerPessoa(nomeRemover);

    printf("\nPilha apos remocao:\n");
    while (!isEmpty(&auxiliar)) {
        printf("Nome: %s, Idade: %d\n", auxiliar.pessoas[auxiliar.topo].nome, auxiliar.pessoas[auxiliar.topo].idade);
        pop(&auxiliar);
    }

    return 0;
}

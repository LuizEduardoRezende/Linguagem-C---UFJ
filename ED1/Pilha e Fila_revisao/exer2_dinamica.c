#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//nao funciona

struct Pessoa {
    char nome[50];
    int idade;
    struct Pessoa *prox;
};

struct Pilha {
    struct Pessoa *topo;
};

void inicializarPilha(struct Pilha *p) {
    p->topo = NULL;
}

int pilhaVazia(struct Pilha *p) {
    return p->topo == NULL;
}

void push(struct Pilha *p, struct Pessoa *pessoa) {
    pessoa->prox = p->topo;
    p->topo = pessoa;
}

void pop(struct Pilha *p) {
    if (!pilhaVazia(p)) {
        struct Pessoa *temp = p->topo;
        p->topo = p->topo->prox;
        free(temp);
    }
}

void removerPessoa(struct Pilha *p, char nomeRemover[50]) {
    struct Pilha auxiliar;
    inicializarPilha(&auxiliar);

    while (!pilhaVazia(p)) {
        if (strcmp(p->topo->nome, nomeRemover) == 0) {
            pop(p);
        } else {
            push(&auxiliar, p->topo);
            pop(p);
        }
    }

    while (!pilhaVazia(&auxiliar)) {
        push(p, auxiliar.topo);
        pop(&auxiliar);
    }
}

int main() {
    struct Pilha pilha;
    inicializarPilha(&pilha);

    int n;
    printf("Quantas pessoas deseja inserir na pilha? ");
    scanf("%d", &n);
    getchar(); // Captura o newline após o número

    for (int i = 0; i < n; i++) {
        struct Pessoa *pessoa = (struct Pessoa *)malloc(sizeof(struct Pessoa));
        printf("Digite o nome da pessoa %d: ", i + 1);
        fgets(pessoa->nome, sizeof(pessoa->nome), stdin);
        pessoa->nome[strlen(pessoa->nome) - 1] = '\0'; // Remove o newline
        printf("Digite a idade da pessoa %d: ", i + 1);
        scanf("%d", &pessoa->idade);
        getchar(); // Captura o newline após o número
        push(&pilha, pessoa);
    }

    char nomeRemover[50];
    printf("Digite o nome da pessoa que deseja remover: ");
    fgets(nomeRemover, sizeof(nomeRemover), stdin);
    nomeRemover[strlen(nomeRemover) - 1] = '\0'; // Remove o newline

    removerPessoa(&pilha, nomeRemover);

    printf("\nPilha após remoção:\n");
    
    struct Pessoa *atual = pilha.topo;
    while (atual) {
        printf("Nome: %s, Idade: %d\n", atual->nome, atual->idade);
        atual = atual->prox;
    }

    // Libera a memória alocada para as pessoas na pilha
    while (!pilhaVazia(&pilha)) {
        pop(&pilha);
    }

    return 0;
}

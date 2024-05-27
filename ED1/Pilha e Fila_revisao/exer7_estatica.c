#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

struct Process {
    int id;
    int tempoEspera;
};

struct Queue {
    struct Process data[MAX_QUEUE_SIZE];
    int inicio, topo;
};

void initialize(struct Queue *q) {
    q->inicio = -1;
    q->topo = -1;
}

int isEmpty(struct Queue *q) {
    return q->inicio == -1;
}

int isFull(struct Queue *q) {
    return (q->topo + 1) % MAX_QUEUE_SIZE == q->inicio;
}

void enqueue(struct Queue *q, struct Process process) {
    if (!isFull(q)) {
        if (isEmpty(q)) {
            q->inicio = 0;
            q->topo = 0;
        } else {
            q->topo = (q->topo + 1) % MAX_QUEUE_SIZE;
        }
        q->data[q->topo] = process;
    } else {
        printf("Fila cheia. Nao e possivel adicionar mais processos.\n");
    }
}

struct Process dequeue(struct Queue *q) {
    struct Process emptyProcess = {-1, -1};
    if (!isEmpty(q)) {
        struct Process removedProcess = q->data[q->inicio];
        if (q->inicio == q->topo) {
            q->inicio = -1;
            q->topo = -1;
        } else {
            q->inicio = (q->inicio + 1) % MAX_QUEUE_SIZE;
        }
        return removedProcess;
    }
    printf("Fila vazia. Nao e possivel remover processos.\n");
    return emptyProcess;
}

void printQueue(struct Queue *q) {
    printf("Conteudo da fila de processos:\n");
    if (!isEmpty(q)) {
        int index = q->inicio;
        while (index != q->topo) {
            printf("ID: %d, Tempo de Espera: %d\n", q->data[index].id, q->data[index].tempoEspera);
            index = (index + 1) % MAX_QUEUE_SIZE;
        }
        printf("ID: %d, Tempo de Espera: %d\n", q->data[q->topo].id, q->data[q->topo].tempoEspera);
    } else {
        printf("A fila esta vazia.\n");
    }
}

int main() {
    struct Queue processQueue;
    initialize(&processQueue);

    while (1) {
        printf("Opcoes:\n");
        printf("1. Incluir novo processo\n");
        printf("2. Retirar processo com maior tempo de espera\n");
        printf("3. Imprimir lista de processos\n");
        printf("4. Sair\n");
        
        int choice;
        scanf("%d", &choice);
        
        if (choice == 1) {
            struct Process newProcess;
            printf("Digite o ID do processo: ");
            scanf("%d", &newProcess.id);
            printf("Digite o tempo de espera do processo: ");
            scanf("%d", &newProcess.tempoEspera);
            enqueue(&processQueue, newProcess);
        } else if (choice == 2) {
            struct Process removedProcess = dequeue(&processQueue);
            if (removedProcess.id != -1) {
                printf("Processo removido: ID: %d, Tempo de Espera: %d\n", removedProcess.id, removedProcess.tempoEspera);
            }
        } else if (choice == 3) {
            printQueue(&processQueue);
        } else if (choice == 4) {
            break;
        } else {
            printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
        }
    }

    return 0;
}

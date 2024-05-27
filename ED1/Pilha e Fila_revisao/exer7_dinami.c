#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;
    int tempoEspera;
    struct Process* next;
};

struct Queue {
    struct Process* inicio;
    struct Process* topo;
};

void initialize(struct Queue* q) {
    q->inicio = NULL;
    q->topo = NULL;
}

int isEmpty(struct Queue* q) {
    return q->inicio == NULL;
}

void enqueue(struct Queue* q, struct Process* process) {
    process->next = NULL;

    if (isEmpty(q)) {
        q->inicio = process;
        q->topo = process;
    } else {
        q->topo->next = process;
        q->topo = process;
    }
}

struct Process* dequeue(struct Queue* q) {
    if (!isEmpty(q)) {
        struct Process* removedProcess = q->inicio;
        q->inicio = q->inicio->next;
        removedProcess->next = NULL;
        return removedProcess;
    }
    return NULL;
}

void printQueue(struct Queue* q) {
    printf("Conteudo da fila de processos:\n");
    struct Process* current = q->inicio;
    while (current != NULL) {
        printf("ID: %d, Tempo de Espera: %d\n", current->id, current->tempoEspera);
        current = current->next;
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

        switch (choice) {
            case 1: {
                struct Process* newProcess = (struct Process*)malloc(sizeof(struct Process));
                printf("Digite o ID do processo: ");
                scanf("%d", &newProcess->id);
                printf("Digite o tempo de espera do processo: ");
                scanf("%d", &newProcess->tempoEspera);
                enqueue(&processQueue, newProcess);
                break;
            }
            case 2: {
                struct Process* removedProcess = dequeue(&processQueue);
                if (removedProcess != NULL) {
                    printf("Processo removido: ID: %d, Tempo de Espera: %d\n", removedProcess->id, removedProcess->tempoEspera);
                    free(removedProcess);
                }
                break;
            }
            case 3:
                printQueue(&processQueue);
                break;
            case 4: {
                // Liberar memória de processos restantes na fila
                while (!isEmpty(&processQueue)) {
                    struct Process* process = dequeue(&processQueue);
                    free(process);
                }
                return 0;
            }
            default:
                printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
                break;
        }
    }

    return 0;
}

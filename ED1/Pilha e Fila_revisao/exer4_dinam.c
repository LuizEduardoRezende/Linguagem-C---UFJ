#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Paciente {
    char nome[50];
    int idade;
    struct Paciente *prox;
} Paciente;

typedef struct {
    Paciente *inicio;
    Paciente *fim;
} FilaEspera;

void inicializarFila(FilaEspera *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

int filaVazia(FilaEspera *fila) {
    return fila->inicio == NULL;
}

void inserirPaciente(FilaEspera *fila, Paciente paciente) {
    Paciente *novoPaciente = (Paciente *)malloc(sizeof(Paciente));
    if (novoPaciente == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    *novoPaciente = paciente;
    novoPaciente->prox = NULL;

    if (filaVazia(fila)) {
        fila->inicio = novoPaciente;
        fila->fim = novoPaciente;
    } else {
        fila->fim->prox = novoPaciente;
        fila->fim = novoPaciente;
    }

    printf("Paciente %s inserido na fila.\n", paciente.nome);
}

Paciente chamarProximoPaciente(FilaEspera *fila) {
    if (!filaVazia(fila)) {
        Paciente pacienteChamado = *(fila->inicio);
        Paciente *temp = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(temp);
        return pacienteChamado;
    } else {
        Paciente pacienteVazio = {"", 0, NULL};
        return pacienteVazio;
    }
}

Paciente proximoPaciente(FilaEspera *fila) {
    if (!filaVazia(fila)) {
        return *(fila->inicio);
    } else {
        Paciente pacienteVazio = {"", 0, NULL};
        return pacienteVazio;
    }
}

int contarPacientes(FilaEspera *fila) {
    int count = 0;
    Paciente *atual = fila->inicio;
    while (atual != NULL) {
        count++;
        atual = atual->prox;
    }
    return count;
}

/*void atendimentoPrioritario(FilaEspera *fila) {
    if (!filaVazia(fila)) {
        Paciente *atual = fila->inicio;
        while (atual != NULL) {
            Paciente *proximo = atual->prox;
            while (proximo != NULL) {
                if (proximo->idade > atual->idade) {
                    Paciente temp = *atual;
                    *atual = *proximo;
                    *proximo = temp;
                }
                proximo = proximo->prox;
            }
            atual = atual->prox;
        }
    }
}*/

int main() {
    FilaEspera fila;
    inicializarFila(&fila);
    Paciente novoPaciente;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Inserir paciente\n");
        printf("2. Chamar proximo paciente\n");
        printf("3. Verificar se a fila esta vazia\n");
        printf("4. Verificar proximo paciente a ser atendido\n");
        printf("5. Informar quantidade de pacientes na fila\n");
        printf("6. Atendimento prioritario\n");
        printf("7. Sair\n");

        int opcao;
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Nome do paciente: ");
                scanf("%s", novoPaciente.nome);
                printf("Idade do paciente: ");
                scanf("%d", &novoPaciente.idade);
                inserirPaciente(&fila, novoPaciente);
                break;

            case 2:
                if (!filaVazia(&fila)) {
                    Paciente pacienteChamado = chamarProximoPaciente(&fila);
                    printf("Chamando paciente: %s\n", pacienteChamado.nome);
                } else {
                    printf("A fila de espera esta vazia.\n");
                }
                break;

            case 3:
                if (filaVazia(&fila)) {
                    printf("A fila de espera esta vazia.\n");
                } else {
                    printf("A fila de espera nao esta vazia.\n");
                }
                break;

            case 4:
                if (!filaVazia(&fila)) {
                    Paciente pacienteProximo = proximoPaciente(&fila);
                    printf("Proximo paciente a ser atendido: %s\n", pacienteProximo.nome);
                } else {
                    printf("A fila de espera esta vazia.\n");
                }
                break;

            case 5:
                printf("Quantidade de pacientes na fila: %d\n", contarPacientes(&fila));
                break;

            /*case 6:
                if (!filaVazia(&fila)) {
                    atendimentoPrioritario(&fila);
                    printf("Fila reorganizada por atendimento prioritario.\n");
                } else {
                    printf("A fila de espera esta vazia.\n");
                }
                break;*/

            case 7:
                printf("Encerrando o programa.\n");
                exit(0);

            default:
                printf("Opcao invalida.\n");
                break;
        }
    }

    return 0;
}

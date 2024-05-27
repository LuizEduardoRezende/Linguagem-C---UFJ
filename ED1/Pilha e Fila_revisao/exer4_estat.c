#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILA 100

typedef struct {
    char nome[50];
    int idade;
} Paciente;

typedef struct {
    Paciente pacientes[MAX_FILA];
    int tamanho;
} FilaEspera;

void inicializarFila(FilaEspera *fila) {
    fila->tamanho = 0;
}

int filaCheia(FilaEspera *fila) {
    return fila->tamanho >= MAX_FILA;
}

int filaVazia(FilaEspera *fila) {
    return fila->tamanho == 0;
}

void inserirPaciente(FilaEspera *fila, Paciente paciente) {
    if (!filaCheia(fila)) {
        fila->pacientes[fila->tamanho] = paciente;
        fila->tamanho++;
        printf("Paciente %s inserido na fila.\n", paciente.nome);
    } else {
        printf("A fila de espera esta cheia.\n");
    }
}

Paciente chamarProximoPaciente(FilaEspera *fila) {
    if (!filaVazia(fila)) {
        Paciente pacienteChamado = fila->pacientes[0];
        for (int i = 0; i < fila->tamanho - 1; i++) {
            fila->pacientes[i] = fila->pacientes[i + 1];
        }
        fila->tamanho--;
        return pacienteChamado;
    } else {
        Paciente pacienteVazio = {"", 0};
        return pacienteVazio;
    }
}

Paciente proximoPaciente(FilaEspera *fila) {
    if (!filaVazia(fila)) {
        return fila->pacientes[0];
    } else {
        Paciente pacienteVazio = {"", 0};
        return pacienteVazio;
    }
}

int contarPacientes(FilaEspera *fila) {
    return fila->tamanho;
}

void atendimentoPrioritario(FilaEspera *fila) {
    for (int i = 0; i < fila->tamanho - 1; i++) {
        for (int j = 0; j < fila->tamanho - i - 1; j++) {
            if (fila->pacientes[j].idade < fila->pacientes[j + 1].idade) {
                Paciente temp = fila->pacientes[j];
                fila->pacientes[j] = fila->pacientes[j + 1];
                fila->pacientes[j + 1] = temp;
            }
        }
    }
}

int main() {
    FilaEspera fila;
    inicializarFila(&fila);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Inserir paciente\n");
        printf("2. Chamar proximo paciente\n");
        printf("3. Verificar se a fila esta cheia ou vazia\n");
        printf("4. Verificar proximo paciente a ser atendido\n");
        printf("5. Informar quantidade de pacientes na fila\n");
        printf("6. Atendimento prioritario\n");
        printf("7. Sair\n");

        int opcao;
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (!filaCheia(&fila)) {
                    Paciente novoPaciente;
                    printf("Nome do paciente: ");
                    scanf("%s", novoPaciente.nome);
                    fflush(stdin);

                    printf("Idade do paciente: ");
                    scanf("%d", &novoPaciente.idade);
                    fflush(stdin);
                    
                    inserirPaciente(&fila, novoPaciente);
                } else {
                    printf("A fila de espera esta cheia.\n");
                }
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
                if (filaCheia(&fila)) {
                    printf("A fila de espera esta cheia.\n");
                } else if (filaVazia(&fila)) {
                    printf("A fila de espera esta vazia.\n");
                } else {
                    printf("A fila de espera nao esta cheia nem vazia.\n");
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

            case 6:
                if (!filaVazia(&fila)) {
                    atendimentoPrioritario(&fila);
                    printf("Fila reorganizada por atendimento prioritario.\n");
                } else {
                    printf("A fila de espera esta vazia.\n");
                }
                break;

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

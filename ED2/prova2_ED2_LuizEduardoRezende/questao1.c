#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

typedef struct pessoa {
    int chave;
    int CPF;
    char nome[40];
    char info[40];
} tipo_pessoa;

tipo_pessoa tabela_hash[TAM];

// Função para criar o hash da chave
int criar_hash(int chave) {
    return chave % TAM;
}

void inicializar_tabela() {
    for (int i = 0; i < TAM; i++) {
        tabela_hash[i].chave = -1; // Valor que indica posição vazia
    }
}

void inserir_registro(int chave, int CPF, const char* nome, const char* info) {
    int indice = criar_hash(chave);
    int tentativa = 0;

    // Encontra a próxima posição vazia na tabela usando sondagem linear
    while (tabela_hash[indice].chave != -1) {
        if(tentativa >= TAM){
            printf("Tabela cheia.\n");
            return;
        }
        indice = (indice + 1) % TAM;
        tentativa++;
    }

    // Insere o registro na posição encontrada
    tabela_hash[indice].chave = chave;
    tabela_hash[indice].CPF = CPF;
    strcpy(tabela_hash[indice].nome, nome);
    strcpy(tabela_hash[indice].info, info);
}

void escrever_em_arquivo() {
    FILE *arquivo;
    arquivo = fopen("registros.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    for (int i = 0; i < TAM; i++) {
        if (tabela_hash[i].chave != -1) { // Verifica se a posição está ocupada
            fprintf(arquivo, "%d;%d;%s;%s\n", tabela_hash[i].chave, tabela_hash[i].CPF, tabela_hash[i].nome, tabela_hash[i].info);
        }
    }

    fclose(arquivo);
}

tipo_pessoa* buscar_registro(int chave) {
    FILE *arquivo;
    arquivo = fopen("registros.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    char linha[100]; // Assumindo que cada linha do arquivo tem no máximo 100 caracteres
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        int chave_arquivo;
        int CPF;
        char nome[40];
        char info[40];

        // Lê os valores da linha
        sscanf(linha, "%d;%d;%[^;];%[^\n]", &chave_arquivo, &CPF, nome, info);

        // Verifica se a chave lida é igual à chave buscada
        if (chave_arquivo == chave) {
            tipo_pessoa* encontrado = (tipo_pessoa*)malloc(sizeof(tipo_pessoa));
            encontrado->chave = chave_arquivo;
            encontrado->CPF = CPF;
            strcpy(encontrado->nome, nome);
            strcpy(encontrado->info, info);
            fclose(arquivo);
            return encontrado;
        }
    }

    fclose(arquivo);
    return NULL;
}

void imprimir_tabela() {
    for (int i = 0; i < TAM; i++) {
        if (tabela_hash[i].chave != -1) { // Verifica se a posição está ocupada
            printf("Entrada %d: (%d, %d, %s, %s)\n", i, tabela_hash[i].chave, tabela_hash[i].CPF, tabela_hash[i].nome, tabela_hash[i].info);
        } else {
            printf("Entrada %d: NULL\n", i);
        }
    }
}

int main() {
    inicializar_tabela();
    int opcao = -1;
    int chave;
    int CPF;
    char nome[40];
    char info[40];

    do {
        printf("\nEscolha uma opcao:\n");
        printf("1- Fazer um registro de pessoa.\n");
        printf("2- Pesquisar registro pela chave.\n");
        printf("3- Imprimir Tabela.\n");
        printf("4- Sair do menu.\n");
        printf("Digite a opcao escolhida: ");
        scanf("%d", &opcao);
        getchar(); // Consumir o caractere de nova linha

        switch (opcao) {
            case 1:
                printf("Informe o nome da pessoa:\n");
                fgets(nome, 40, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf("Informe o CPF da pessoa:\n");
                scanf("%d", &CPF);
                getchar();

                printf("Informe alguma informacao adicional sobre a pessoa:\n");
                fgets(info, 40, stdin);
                info[strcspn(info, "\n")] = '\0';

                printf("Informe a chave que deseja vincular a essa pessoa:\n");
                scanf("%d", &chave);
                getchar();

                inserir_registro(chave, CPF, nome, info);
                escrever_em_arquivo();
                break;

            case 2:
                printf("Digite a chave do registro que deseja pesquisar: ");
                scanf("%d", &chave);
                getchar();

                tipo_pessoa* encontrado = buscar_registro(chave);
                if (encontrado != NULL) {
                    printf("Registro encontrado: \nChave: %d \nCPF: %d \nNome: %s \nInformacao adicional: %s\n", encontrado->chave, encontrado->CPF, encontrado->nome, encontrado->info);
                } else {
                    printf("Registro nao encontrado no arquivo de dados.\n");
                }
                break;

            case 3:
                imprimir_tabela();
                break;

            case 4:
                printf("Menu encerrado.\n");
                break;

            default:
                printf("Digite uma opcao valida.\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}

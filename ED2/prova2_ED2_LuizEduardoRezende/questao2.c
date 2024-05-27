#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

typedef struct pessoa {
    int chave;

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

int sondagem_linear(int chave) {
    int indice = criar_hash(chave);
    int tentativa = 0;

    // Encontra a próxima posição vazia na tabela usando sondagem linear
    while (tabela_hash[indice].chave != -1) {
        if(tentativa >= TAM)
            return -1;
        indice = (indice + 1) % TAM;
        tentativa++;
    }

    // Retorna o indice que está disponivel
    return indice;
}

int sondagem_quadratica(int chave) {
    int tentativa = 0;
    int hash_original = criar_hash(chave);
    int indice = (hash_original + tentativa * tentativa) % TAM;

    while (tabela_hash[indice].chave != -1){ // Verifica se o indice atual está vazio
        if(tentativa >= TAM)
            return -1;

        tentativa++;
        indice = (hash_original + tentativa * tentativa) % TAM;
    }

    return indice;
}

int hash_duplo(int chave) {
    int tentativa = 0;
    int hash1 = chave % TAM;
    int hash2 = 7 - (chave % 7); 
    int indice = (hash1 + tentativa * hash2) % TAM;

    while (tabela_hash[indice].chave != -1){ // Verifica se o indice atual está vazio
        if(tentativa >= TAM)
            return -1;

        tentativa++;
        indice = (hash1 + tentativa * hash2) % TAM;
    }

    return indice;
}

int sondagem_quadratica_2(int chave) {
    int tentativa = 0;
    int indice = (chave + 2 * tentativa + tentativa * tentativa) % TAM;

    while (tabela_hash[indice].chave != -1){ // Verifica se o indice atual está vazio
        if(tentativa >= TAM)
            return -1;

        tentativa++;
        indice = (chave + 2 * tentativa + tentativa * tentativa) % TAM;
    }

    return indice;
}

void imprimir_tabela() {
    for (int i = 0; i < TAM; i++) {
        if (tabela_hash[i].chave != -1) { // Verifica se a posição está ocupada
            printf("Entrada %d: (%d)\n", i, tabela_hash[i].chave);
        } else {
            printf("Entrada %d: NULL\n", i);
        }
    }
}

int main() {
    inicializar_tabela();
    int opcao = -1;
    int chave;
    int indice;

    do {
        printf("\nEscolha uma opcao:\n");
        printf("1- Fazer um registro usando soldagem linear\n");
        printf("2- Fazer um registro usando soldagem quadratica\n");
        printf("3- Fazer um registro usando soldagem quadratica (2.0)\n");
        printf("4- Fazer um registro usando hash duplo\n");
        printf("5- Imprimir tabela.\n");
        printf("6- Sair do menu.\n");
        printf("Digite a opcao escolhida: ");
        scanf("%d", &opcao);
        getchar(); // Consumir o caractere de nova linha

        switch (opcao) {
            case 1:
                printf("Informe a chave que deseja armazenar:\n");
                scanf("%d", &chave);
                getchar();

                indice = sondagem_linear(chave);
                if(indice != -1)
                    tabela_hash[indice].chave = chave;
                else
                    printf("Tabela cheia.\n");

                break;
            
            case 2:
                printf("Informe a chave que deseja armazenar:\n");
                scanf("%d", &chave);
                getchar();

                indice = sondagem_quadratica(chave);
                if(indice != -1)
                    tabela_hash[indice].chave = chave;
                else
                    printf("Tabela cheia.\n");

                break;

            case 3:
                printf("Informe a chave que deseja armazenar:\n");
                scanf("%d", &chave);
                getchar();

                indice = sondagem_quadratica_2(chave);
                if(indice != -1)
                    tabela_hash[indice].chave = chave;
                else
                    printf("Tabela cheia.\n");
                
                break;

            case 4:
                printf("Informe a chave que deseja armazenar:\n");
                scanf("%d", &chave);
                getchar();

                indice = hash_duplo(chave);
                if(indice != -1)
                    tabela_hash[indice].chave = chave;
                else
                    printf("Tabela cheia.\n");
 
                break;

            case 5:
                imprimir_tabela();
                break;

            case 6:
                printf("Menu encerrado.\n");
                break;

            default:
                printf("Digite uma opcao valida.\n");
                break;
        }

    } while (opcao != 6);

    return 0;
}

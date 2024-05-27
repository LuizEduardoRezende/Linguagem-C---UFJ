#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10000

// Função para ler o conteúdo de um arquivo e armazená-lo em uma str
char *lerArquivo(char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    char *conteudo = (char *)malloc(MAX_SIZE * sizeof(char));
    if (conteudo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    int tamanho = 0;
    char c;
    while ((c = fgetc(arquivo)) != EOF) {
        conteudo[tamanho++] = c;
    }
    conteudo[tamanho] = '\0'; // Adiciona o caractere nulo ao final da str

    fclose(arquivo);
    return conteudo;
}

int forca_bruta(char texto[], char padrao[], int tamanho_padrao, int *posicao) {
    int j = 0;
    int i;
    int flag = 0;
    int tamanho_texto = strlen(texto);
    int indice_posicao = 0;

    for (i = 0; i < tamanho_texto; i++) {
        if (texto[i] == padrao[j]) {
            j++;
            if (j == tamanho_padrao) {
                flag++;
                posicao[indice_posicao] = i - tamanho_padrao + 1;
                indice_posicao++;
            }
        } else {
            j = 0;
        }
    }

    return flag;
}

int bmh(char texto[], char padrao[], int *posicao) {
    int tabela[256]; // Tabela de deslocamento
    int m = strlen(padrao);
    int n = strlen(texto);
    int i, j, k;
    int vezes = 0; // Variável para contar o número de ocorrências

    for (i = 0; i < 256; i++) {
        tabela[i] = m; // Inicializa a tabela com o tamanho do padrão
    }

    for (i = 0; i < m - 1; i++) {
        tabela[(unsigned char) padrao[i]] = m - 1 - i; // Atualiza a tabela com os deslocamentos
    }

    i = m - 1;
    while (i < n) {
        k = i;
        j = m - 1;

        while (j >= 0 && texto[k] == padrao[j]) {
            k--;
            j--;
        }

        if (j == -1) {
            // Encontrou uma ocorrência do padrão
            posicao[vezes++] = i - m + 1;

            // Desloca o padrão para a próxima posição possível
            i += m;
        } else {
            // Desloca o padrão de acordo com a tabela de deslocamento
            i += tabela[texto[i]];
        }
    }
    return vezes;
}

int knuthMorrisPratt(char *texto, char *palavra, int *posicao) {
    int vezes = 0;
    int tamanhoTexto = strlen(texto);
    int tamanhoPalavra = strlen(palavra);

    // Array para armazenar o índice da próxima melhor correspondência
    int proximos[tamanhoPalavra + 1];

    // Inicializa o array proximos com zeros
    for (int i = 0; i < tamanhoPalavra + 1; i++) {
        proximos[i] = 0;
    }

    // Pré-processamento do padrão
    for (int i = 1; i < tamanhoPalavra; i++) {
        int j = proximos[i + 1];

        // Encontra a próxima melhor correspondência
        while (j > 0 && palavra[j] != palavra[i]) {
            j = proximos[j];
        }

        // Se houver correspondência, atualiza o valor no array proximos
        if (j > 0 || palavra[j] == palavra[i]) {
            proximos[i + 1] = j + 1;
        }
    }

    // Comparação do padrão com o texto
    int indicePosicao = 0; // Índice para armazenar a posição no vetor posicao
    for (int i = 0, j = 0; i < tamanhoTexto; i++) {
        if (*(texto + i) == *(palavra + j)) {
            if (++j == tamanhoPalavra) {
                vezes++; // Ocorrência da palavra encontrada
                posicao[indicePosicao++] = i - tamanhoPalavra + 1; // Armazena a posição da ocorrência
            }
        } else if (j > 0) {
            j = proximos[j];
            i--;    // Volta no texto para continuar a busca
        }
    }

    return vezes;
}

int main() {
    int opcao = -1;
    char str[40];
    int vezes = 0;
    int posicao[strlen(lerArquivo("texto.txt"))];

    do {
        printf("\nEscolha uma opcao:\n");
        printf("1- Fazer a busca de uma string com forca bruta.\n");
        printf("2- Fazer a busca de uma string com o algoritmo BMH.\n");
        printf("3- Fazer a busca de uma string com o algoritmo KMP.\n");
        printf("4- Sair do menu.\n");
        printf("Digite a opcao escolhida: ");
        scanf("%d", &opcao);
        getchar(); // Consumir o caractere de nova linha

        switch (opcao) {
            case 1:
                printf("Digite a str que quer buscar:\n");
                fgets(str, 40, stdin);
                str[strcspn(str, "\n")] = '\0';

                vezes = forca_bruta(lerArquivo("texto.txt"), str, strlen(str), posicao);
                printf("A sua str foi encontra %d vezes.\n", vezes);

                for (int i = 0; i < vezes; i++) {
                    printf("A str aparece na posicao: %d\n", posicao[i]);
                }

                break;
            
            case 2:
                printf("Digite a str que quer buscar:\n");
                fgets(str, 40, stdin);
                str[strcspn(str, "\n")] = '\0';

                vezes = bmh(lerArquivo("texto.txt"), str, posicao);
                printf("A sua str foi encontra %d vezes.\n", vezes);

                for (int i = 0; i < vezes; i++) {
                    printf("A str aparece na posicao: %d\n", posicao[i]);
                }

                break;

            case 3:
                printf("Digite a str que quer buscar:\n");
                fgets(str, 40, stdin);
                str[strcspn(str, "\n")] = '\0';

                vezes = knuthMorrisPratt(lerArquivo("texto.txt"), str, posicao);
                printf("A sua str foi encontra %d vezes.\n", vezes);

                for (int i = 0; i < vezes; i++) {
                    printf("A str aparece na posicao: %d\n", posicao[i]);
                }
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

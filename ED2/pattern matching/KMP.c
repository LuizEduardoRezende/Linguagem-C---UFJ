#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void knuthMorrisPratt(char *texto, char *palavra, int tamanhoTexto, int tamanhoPalavra)
{
    int contador = 0;

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
    for (int i = 0, j = 0; i < tamanhoTexto; i++) {
        if (*(texto + i) == *(palavra + j)) {
            if (++j == tamanhoPalavra) {
                contador++; // Ocorrência da palavra encontrada
            }
        } else if (j > 0) {
            j = proximos[j];
            i--;    // Volta no texto para continuar a busca
        }
    }

    // Impressão do resultado
    printf("\nHouve %d ocorrencia(s) do padrao %s\n", contador, palavra);
}

int main()
{
    char texto[] = "ABC JP JV ABC JP JV ABA C";
    char palavra[10];

    // Solicita ao usuário que digite a palavra a ser buscada
    printf("Digite a palavra que deseja buscar.\n");
    fgets(palavra, sizeof(palavra), stdin);
    palavra[strcspn(palavra, "\n")] = 0; // Remove o \n do final da string

    int tamanhoTexto = strlen(texto);
    int tamanhoPalavra = strlen(palavra);

    // Chama a função knuthMorrisPratt para buscar a palavra no texto
    knuthMorrisPratt(texto, palavra, tamanhoTexto, tamanhoPalavra);
    return 0;
}

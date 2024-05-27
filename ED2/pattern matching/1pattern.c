#include <stdio.h>
#include <string.h>

int casamento_exato(char texto[], char padrao[], int tamanho_padrao, int *posicao) {
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

int main() {
    char padrao[10];
    char texto[100] = "cleiton rasta 012345 cleiton rasta 097 cleiton rasta 999";

    int tamanho;
    int vezes;
    int posicao[100];

    printf("Escreva o padrao a ser buscado:\n");
    scanf("%[^\n]s", padrao);
    getchar();  // Consumindo o caractere de nova linha restante no buffer

    tamanho = strlen(padrao);
    vezes = casamento_exato(texto, padrao, tamanho, posicao);

    printf("O padrao aparece %d vezes.\n", vezes);

    for (int i = 0; i < vezes; i++) {
        printf("O padrao aparece na posicao: %d\n", posicao[i]);
    }

    return 0;
}

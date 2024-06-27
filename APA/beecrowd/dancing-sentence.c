#include <stdio.h>
#include <string.h>
#define T 3

int main() {
    char frase[T][51];
    int tamanho[T];

    for (int i = 0; i < T; i++) {
        fgets(frase[i], sizeof(frase[i]), stdin);
        frase[i][strcspn(frase[i], "\n")] = '\0';
        tamanho[i] = strlen(frase[i]);
    }

    int pos = 0; // primeira pos = 0
    // posicao par -> upper
    // posicao impar -> lower

    for (int i = 0; i < T; i++) {
        pos = 0;
        for (int j = 0; j < tamanho[i]; j++) {
            if (frase[i][j] != ' ') { // Ignorar espaços

                if ((pos % 2) == 0) { // posicao par
                    if (frase[i][j] >= 'a' && frase[i][j] <= 'z') // Letra em minúscula
                        frase[i][j] -= 32; // Converter para maiúscula
                } 
                else { // posicao impar
                    if (frase[i][j] >= 'A' && frase[i][j] <= 'Z') // Letra em maiúscula
                        frase[i][j] += 32; // Converter para minúscula
                }
                pos++;

            }
        }
        printf("%s\n", frase[i]);
    }

    return 0;
}

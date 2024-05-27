#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main() {
    
    int maximo = 1000;
    char arquivo_nome[maximo];
    char palavra_antiga[maximo];
    char palavra_nova[maximo];
    char buffer[maximo];

    printf("Digite o nome do arquivo: ");
    scanf("%s", arquivo_nome);

    printf("Digite a palavra antiga: ");
    scanf("%s", palavra_antiga);
    printf("Digite a palavra nova: ");
    scanf("%s", palavra_nova);

    FILE* arquivo = fopen(arquivo_nome, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", arquivo_nome);
        return 1;
    }

    FILE* arquivo_temp = fopen("temp.txt", "w");
    if (arquivo_temp == NULL) {
        printf("Erro ao criar arquivo temporário\n");
        fclose(arquivo);
        return 1;
    }

    while (fgets(buffer, maximo, arquivo)) {
        char *pos = buffer;

        while ((pos = strstr(pos, palavra_antiga)) != NULL) {
            int offset = pos - buffer;
            fwrite(buffer, 1, offset, arquivo_temp);
            fwrite(palavra_nova, 1, strlen(palavra_nova), arquivo_temp);
            pos += strlen(palavra_antiga);
            buffer[offset] = '\0';
        }

        fputs(buffer, arquivo_temp);
    }

    fclose(arquivo);
    fclose(arquivo_temp);

    remove(arquivo_nome);
    rename("temp.txt", arquivo_nome);

    printf("Substituição realizada com sucesso!\n");
    
    return 0;
}
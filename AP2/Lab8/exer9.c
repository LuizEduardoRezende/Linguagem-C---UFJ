#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main() {

    char file_name[50];
    char keyword[20];
    char line[100];

    // pede ao usuário o nome do arquivo e a palavra-chave
    printf("Digite o nome do arquivo: ");
    scanf("%[^\n]s", file_name);
    fflush(stdin);
    printf("Digite a palavra-chave: ");
    scanf("%[^\n]s", keyword);
    fflush(stdin);

    // abre o arquivo para leitura
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    // lê cada linha do arquivo e imprime as que contêm a palavra-chave
    while (fgets(line, 100, file) != NULL) 
    {
        if (strstr(line, keyword) != NULL)
            printf("%s", line);
    }

    // fecha o arquivo
    fclose(file);

    return 0;
}
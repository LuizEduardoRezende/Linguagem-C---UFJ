#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[50];
    int escolha = -1;
    int tamanho = 0;
    int i = 0;

    printf("Digite o conteudo da string de no maximo 50 caracteres:\n\n");
    fflush(stdin);
    scanf("%[^\n]s",string);

    while (escolha != 0)
    {
        printf("Digite 1 para receber o tamanho da string ou 2 para receber a string ao contrario. Digite 0 para encerrar o menu.\n");
        fflush(stdin);
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 0:
            printf("Fim do menu.\n");
            break;
        case 1:
            tamanho = strlen(string);
            printf("O tamanho da string e: %d\n", tamanho);
            break;
        case 2:
            for(i = strlen(string); i>=0; i--)
            {
                printf("%c", string[i]);
            }
            printf("\n\n");
            break;
        default:
            printf("Opcao invalida.");
            break;
        }
    }

    return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    typedef struct pessoa
    {
        char rua[30], cidade[30];
        int numero;

    }tipopessoa;
    tipopessoa pessoa;
    tipopessoa *ptrpessoa = &pessoa;

    printf("Digite o nome da rua de sua casa:\n");
    scanf("%[^\n]s", (*ptrpessoa).rua);
    fflush(stdin);
    printf("Digite o nome da sua cidade:\n");
    scanf("%[^\n]s", ptrpessoa->cidade);
    fflush(stdin);
    printf("Digite o número de sua casa:\n");
    scanf("%d", &ptrpessoa->numero);

    printf("Rua: %s\n", (*ptrpessoa).rua);
    printf("Cidade: %s\n", ptrpessoa->cidade);
    printf("Número: %d\n", (*ptrpessoa).numero);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    struct dados
    {
        char rua[30], CEP[9];
        int numero;
    };
    typedef struct dados tipodados;

    struct cliente
    {
        char nome[30];
        float saldo;

        tipodados endereco;
    };

    struct cliente c = {"Luiz Eduardo", 400, {"Rua Anhanguera", "75300062", 629}};

    printf("\nFICHA DO CLIENTE:\n\n");
    printf("Nome: %s\n", c.nome);
    printf("Saldo: %.4f\n", c.saldo);
    printf("Rua: %s\n", c.endereco.rua);
    printf("Número: %d\n", c.endereco.numero);
    printf("CEP: %s\n", c.endereco.CEP);

    return 0;
}
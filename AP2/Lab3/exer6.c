#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    struct ficha_cliente
    {
        int idade, dia, mes, ano;
        float altura, peso, IMC;
        char nome[50], endereco[50], email[50], CPF[11], sexo[12], ID[50];

    } ficha;

    printf("Informe seu nome:\n");
    fgets(ficha.nome, sizeof(ficha.nome), stdin);
    fflush(stdin);
    printf("Informe seu endereço:\n");
    fgets(ficha.endereco, sizeof(ficha.endereco), stdin);
    fflush(stdin);
    printf("Informe seu E-mail:\n");
    fgets(ficha.email, sizeof(ficha.email), stdin);
    fflush(stdin);

    do
    {
        printf("Informe sua idade:\n");
        scanf("%d", &ficha.idade);
        fflush(stdin);
    } while (ficha.idade <= 0);

    printf("Informe seu CPF:\n");
    fgets(ficha.CPF, sizeof(ficha.CPF), stdin);
    fflush(stdin);

    do
    {
        printf("Informe seu sexo(feminino, masculino ou outro):\n");
        fgets(ficha.sexo, sizeof(ficha.sexo), stdin);
        fflush(stdin);
    } while ((strcmp(ficha.sexo, "masculino\n") != 0) && (strcmp(ficha.sexo, "feminino\n") != 0) && (strcmp(ficha.sexo, "outro\n") != 0));

    do
    {
        printf("Informe o ano de nascimento:\n");
        scanf("%d", &ficha.ano);
        fflush(stdin);
    } while (ficha.ano < 0 || ficha.ano > 2023);
    do
    {
        printf("Informe o mês de nascimento:\n");
        scanf("%d", &ficha.mes);
        fflush(stdin);
    } while (ficha.mes <= 0 || ficha.mes > 12);
    do
    {
        printf("Informe o dia de nascimento:\n");
        scanf("%d", &ficha.dia);
        fflush(stdin);
    } while (ficha.dia <= 0 || ficha.dia > 31);
    do
    {
        printf("Informe a sua altura em metros:\n");
        scanf("%f", &ficha.altura);
        fflush(stdin);
    } while (ficha.altura <= 0);
    do
    {
        printf("Informe o seu peso em KG:\n");
        scanf("%f", &ficha.peso);
        fflush(stdin);
    } while (ficha.peso <= 0);
    ficha.IMC = (ficha.peso / (ficha.altura * ficha.altura));

    printf("\nFICHA DO CLIENTE:\n\n");
    printf("Nome: %s", ficha.nome);
    printf("Endereço: %s", ficha.endereco);
    printf("E-mail: %s", ficha.email);
    printf("Idade: %d\n", ficha.idade);
    printf("CPF: %s", ficha.CPF);
    printf("Sexo: %s", ficha.sexo);
    printf("Data de nascimento: %d/%d/%d\n", ficha.dia, ficha.mes, ficha.ano);
    printf("Altura: %.2f\n", ficha.altura);
    printf("Peso: %.2f\n", ficha.peso);
    printf("IMC: %.2f\n", ficha.IMC);

    system("pause");
    system("cls");
    printf("Informe seu ID(nome) para confirmar a identidade.\n");
    fgets(ficha.ID, sizeof(ficha.ID), stdin);
    fflush(stdin);

    if (strcmp(ficha.ID, ficha.nome) == 0)
    {
        printf("Identidade validada. O ID e o nome são iguais.\n");
    }
    else
    {
        printf("Identidade invalidada. O ID e o nome são diferentes.\n");
    }

    return 0;
}
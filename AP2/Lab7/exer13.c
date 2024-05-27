#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    typedef struct
    {
        char nome[30];
        int idade;
        float nota;
    }tipoaluno;

    tipoaluno aluno;
    tipoaluno *ptraluno = &aluno;

    printf("Digite o nome do aluno:\n");
    scanf("%[^\n]s", (*ptraluno).nome);
    fflush(stdin);
    printf("Digite a idade do aluno:\n");
    scanf("%d", &(*ptraluno).idade);
    fflush(stdin);
    printf("Digite a nota desse aluno:\n");
    scanf("%f", &(*ptraluno).nota);
    fflush(stdin);

    printf("Aluno: %s\n", ptraluno->nome);
    printf("Idade: %d\n", (*ptraluno).idade);
    printf("Nota: %f\n", ptraluno->nota);

    return 0;
}
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
        float media;
    }tipoaluno;

    tipoaluno aluno;
    tipoaluno *ptraluno = &aluno;

    strcpy(ptraluno->nome, "Luiz Eduardo");
    (*ptraluno).idade = 18;
    ptraluno->media = 9.1;

    printf("Aluno: %s\n", ptraluno->nome);
    printf("Idade: %d\n", (*ptraluno).idade);
    printf("Média: %f\n", ptraluno->media);

    return 0;
}
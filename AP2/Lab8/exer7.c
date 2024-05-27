#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int i;
    float media;
    typedef struct alunos
    {
        char nome[30], curso[30];
        float nota;
    }tipoalunos;

    tipoalunos a[5];

    char url[] = {"ALUNOS.TXT"}; //criando o arquivo
    FILE *arq;
    arq = fopen(url, "w");

    for( i = 0; i<5; i++)
    {
        printf("Nome aluno %d:", i+1);
        scanf("%[^\n]s", a[i].nome);
        fflush(stdin);

        printf("Curso aluno %d:", i+1);
        scanf("%[^\n]s", a[i].curso);
        fflush(stdin);

        printf("Nota aluno %d:", i+1);
        scanf("%f", &a[i].nota);
        fflush(stdin);
        media = media + a[i].nota;
    }

    media = media/(float)5;

    for( i = 0; i< 5; i++)
    {
        fprintf(arq, "NOME: %s\t", a[i].nome);
        fprintf(arq, "CURSO: %s\t", a[i].curso);
        fprintf(arq, "NOTA: %f\n\n", a[i].nota);
    }
    fprintf(arq, "MEDIA DA TURMA: %f", media);

    fclose(arq);
    return 0;
}
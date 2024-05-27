#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include <ctype.h>

typedef struct aluno  // struct global com dados do usuario
{
    char nome[40], CPF[11];
    int idade;

} tipoaluno;

#include "logica.h" //biblioteca com todas funcoes do programa

int main()
{
    setlocale(LC_ALL, "Portuguese");

    tipoaluno *usuario = (tipoaluno *)malloc(sizeof(tipoaluno)); // aloca memória dinamicamente
    if (usuario == NULL)
    {
        printf("Erro na alocação de memória\n");
        return 1;
    }
    int tema = 4, flag_tema1 = 0, flag_tema2 = 0, flag_tema3 = 0;
    int nota[3] = {0, 0, 0};                          // nota nos 3 temas
    int acertos[3][9] = {{2, 2, 2, 2, 2, 2, 2, 2, 2}, // matriz de erros e acertos nas questoes
        {2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2}
    };

    interface(); // funcao da interface inicial do programa

    dados_usuario(usuario); // funcao que coleta os dados do usuario

    while (tema != 0) // menu interativo para escolha do tema
    {
        printf("Escolha um tema ler um resumo e dar ínico a um questionário.\n");
        printf("Digite 1 para : Lógica proposicional.\n");
        printf("Digite 2 para : Lógica de predicados.\n");
        printf("Digite 3 para : Métodos de validação da lógica proposicional.\n");
        printf("Digite 0 para encerrar o menu de questionários.\n");
        scanf("%d", &tema);
        fflush(stdin);
        printf("\n\n");

        switch (tema)
        {
        case 0:
            printf("Menu de questionórios encerrados.\n");
            system("pause");
            system("cls");
            break;

        case 1:
            printf("A seguir será apresentado um resumo breve sobre o conteúdo escolhido.\n\n");
            cont_tema1();  //função com o conteúdo do tema
            tema1(flag_tema1, nota, acertos); // funcao com os exercicios do tema 1
            flag_tema1 = 1;
            break;

        case 2:
            printf("A seguir será apresentado um resumo breve sobre o conteúdo escolhido.\n\n");
            cont_tema2();  //função com o conteúdo do tema
            tema2(flag_tema2, nota, acertos); // funcao com os exercicios do tema 2
            flag_tema2 = 1;
            break;

        case 3:
            printf("A seguir será apresentado um resumo breve sobre o conteúdo escolhido.\n\n");
            cont_tema3();  //função com o conteúdo do tema
            tema3(flag_tema3, nota, acertos); // funcao com os exercicios do tema 3
            flag_tema3 = 1;
            break;

        default:
            printf("Tema inválido. Por favor escolha uma opção válida.\n");
            break;
        }
    }

    printf("A seguir será exibido seus acertos(C) e erros(E) em cada tema.\n");
    matrizAcerto(acertos); // função que printa a matriz de acertos e erros

    printf("\n\nSua nota no tema 1 foi: %d\n", nota[0]);
    printf("Sua nota no tema 2 foi: %d\n", nota[1]);
    printf("Sua nota no tema 3 foi: %d\n\n", nota[2]);
    printf("A seguir será criado um arquivo com todos seus dados pessoais e seu desempenho nos questionários.\n");
    system("pause");
    system("cls");

    //criando aquivo com os dados do aluno
    char url[]="Dados.txt";
    FILE *arq;
    arq=fopen(url,"w");
    if (arq == NULL)
    {
        printf("Erro ao criar/abrir o arquivo");
    }
    else
    {
        fprintf(arq,"Nome: %s\n",usuario->nome);
        fprintf(arq,"Idade: %d\n",usuario->idade);
        fprintf(arq,"CPF: %s\n",usuario->CPF);
        fprintf(arq,"Nota no tema 1: %d\n",nota[0]);
        fprintf(arq,"Nota no tema 2: %d\n",nota[1]);
        fprintf(arq,"Nota no tema 3: %d\n",nota[2]);
        printf("Arquivo criado com sucesso.\n");
    }

    fclose(arq);

    return 0;
}

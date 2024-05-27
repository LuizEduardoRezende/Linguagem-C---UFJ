#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int flag_tela_cheia = 0;

    do
    {
        printf("AVISO IMPORTANTE : Digite somente números nas respostas para obter o bom funcionamento do programa e evitar erros e bugs.\n\n");
        printf("Utilize o prompt em tela cheia para obter a experiência correta.\nDigite 1 para confirmar que o prompt está em tela cheia.\n");
        scanf("%d", &flag_tela_cheia);
        printf("\n");
    } while ((flag_tela_cheia != 1));

    
    int tema = 4, flag_tema1 = 0, flag_tema2 = 0, flag_tema3 = 0;
    int i = 0, j = 0;
    int resposta_1[9] = {0, 0, 0, 0, 0, -1, 0, 0, 0};
    int resposta_2[6] = {0, 0, 0, 0, 0, 0};
    int resposta_3[3] = {0, 0, 0};
    int streak = 0;
    int nota[3] = {0, 0, 0};
    int acertos[3][9] = {2, 2, 2, 2, 2, 2, 2, 2, 2,
                         2, 2, 2, 2, 2, 2, 2, 2, 2,
                         2, 2, 2, 2, 2, 2, 2, 2, 2};

    system("cls");
    printf("———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————       \n");
    printf("#   ########    #######   ##        ##             ##              ##   ###   ###      ##   ########      ########                  ###           ########    #       \n");
    printf("#   ##     ##   #######   ###      ###              ##            ##    ###   ####     ##   ##      ##   ##      ##                ## ##         ##      ##   #       \n");
    printf("#   ##     ##   ##        ###      ###               ##          ##     ###   ## ##    ##   ##      ##   ##      ##               ##   ##        ##      ##   #       \n");
    printf("#   #########   #######   ## ##  ## ##     ######     ##        ##      ###   ##  ##   ##   ##      ##   ##      ##              ##     ##       ##      ##   #       \n");
    printf("#   #########   #######   ##   ##   ##     ######      ##      ##       ###   ##   ##  ##   ##      ##   ##      ##             ###########      ##      ##   #       \n");
    printf("#   ##     ##   ##        ##        ##                  ##    ##        ###   ##    ## ##   ##      ##   ##      ##            ##         ##     ##      ##   #       \n");
    printf("#   ##     ##   #######   ##        ##                   ##  ##         ###   ##     ####   ##      ##   ##      ##           ##           ##    ##      ##   #       \n");
    printf("#   ########    #######   ##        ##                     ##           ###   ##      ###   ########      ########           ##             ##    ########    #       \n");
    printf("#                                                                                                                                                             #       \n");
    printf("#                                                                                                                                                             #       \n");
    printf("#   ########     #######   #######   #######   ###      ##   ########      ########    ##              ###                                                    #       \n");
    printf("#   ##      ##   #######   #######   #######   ####     ##   ##      ##   ##      ##   ##             ## ##                                                   #       \n");
    printf("#   ##      ##   ##        ##        ##        ## ##    ##   ##      ##   ##      ##   ##            ##   ##                                                  #       \n");
    printf("#   ##      ##   #######   #######   #######   ##  ##   ##   ##########   ##      ##   ##           ##     ##                                                 #       \n");
    printf("#   ##      ##   #######   #######   #######   ##   ##  ##   ########     ##      ##   ##          ###########                                                #       \n");
    printf("#   ##      ##   ##             ##   ##        ##    ## ##   ##      ##   ##      ##   ##         ##         ##                                               #       \n");
    printf("#   ##      ##   #######   #######   #######   ##     ####   ##      ##   ##      ##   ######    ##           ##                                              #       \n");
    printf("#   ########     #######   #######   #######   ##      ###   ##      ##    ########    ######   ##             ##                                             #       \n");
    printf("———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————       \n");
    printf("\n\n");

    printf("Nesta plataforma você poderá testar seus conhecimentos em Lógica Computacional por meio de questionários sobre diferentes temas.\n");
    printf("É importante ressaltar que o conteúdo de Lógica Computacional apresentado no Desenrola é baseado nas produções do autor João Nunes de Souza.\n");
    printf("Funcionará da seguinte forma: A cada resposta certa você receberá 10 pontos porém, caso acerte respostas em sequência, seu streak aumentará.\n");
    printf("A cada acerto seu streak aumenta em 1 e a questão sempre valerá : (10 x streak).\n\n\n");

    while (tema != 0)
    {
        printf("Escolha um tema para dar ínico a um questionário.\n");
        printf("Digite 1 para : Lógica proposicional.\n");
        printf("Digite 2 para : Lógica de predicados.\n");
        printf("Digite 3 para : Métodos de validação da lógica proposicional.\n");
        printf("Digite 0 para encerrar o menu de questionários.\n");
        scanf("%d", &tema);
        printf("\n");

        switch (tema)
        {
        case 0:
            printf("Menu de questionários encerrados.\n");
            system("pause");
            system("cls");
            break;

        case 1: // exercícios do tema 1

            if (flag_tema1 == 0)
            {
                system("cls");
                printf("A seguir serão apresentados os exercícios de Lógica proposicional:\n\n");

                while (resposta_1[0] != 1 && resposta_1[0] != 2)
                {
                    printf("Exercício 1.1: As proposições da Lógica proposicional podem ser representados pelas letras minúsculas p,q,r,s,p1... VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_1[0]);
                    if (resposta_1[0] != 1 && resposta_1[0] != 2)
                    {
                        printf("Resposta inválida. Por favor escolha uma opção válida para sua resposta.\n\n");
                    }
                }

                if (resposta_1[0] == 1)
                {
                    printf("Resposta Incorreta. Os símbolos para proposições são representados por letras maiúsculas.\n\n");
                    acertos[0][0] = 0;
                    streak = 0;
                }
                else
                {
                    printf("Resposta Correta. Os símbolos para proposições são representados por letras maiúsculas.\n\n");
                    acertos[0][0] = 1;
                    streak++;
                    nota[0] = nota[0] + 10 * streak;
                }

                while (resposta_1[1] != 1 && resposta_1[1] != 2)
                {
                    printf("Exercício 1.2: Uma proposição da Lógica proposicional não pode ser encerrada com ponto de interrogação. VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_1[1]);
                    if (resposta_1[1] != 1 && resposta_1[1] != 2)
                    {
                        printf("Resposta inválida. Por favor escolha uma opção válida para sua resposta.\n\n");
                    }
                }

                if (resposta_1[1] == 1)
                {
                    printf("Resposta Correta. Uma proposição em forma de sentença não pode terminar com ponto de interrogação, uma vez que ela deve ter um valor lógico TRUE ou FALSE.\n\n");
                    acertos[0][1] = 1;
                    streak++;
                    nota[0] = nota[0] + 10 * streak;
                }
                else
                {
                    printf("Resposta Incorreta. Uma proposição em forma de sentença não pode terminar com ponto de interrogação, uma vez que ela deve ter um valor lógico TRUE ou FALSE.\n\n");
                    acertos[0][1] = 0;
                    streak = 0;
                }

                while (resposta_1[2] < 1)
                {
                    printf("Exercício 1.3: No total quantos tipos de símbolos existem na Lógica proposicional.\n");
                    scanf("%d", &resposta_1[2]);
                    if (resposta_1[2] < 1)
                    {
                        printf("Por favor digite uma resposta válida: um número posítivo diferente de 0.\n\n");
                    }
                }

                if (resposta_1[2] == 4)
                {
                    printf("Resposta Correta. Existem 4 tipos de símbolos sendo eles : símbolos de pontuação (), símbolos de verdade( T, F ), símbolos proposicionais( P, Q, R, S...), conectivos proposicionais(¬, v, ^, ->, <->). \n\n");
                    acertos[0][2] = 1;
                    streak++;
                    nota[0] = nota[0] + 10 * streak;
                }
                else
                {
                    printf("Resposta Incorreta. Existem 4 tipos de símbolos sendo eles : símbolos de pontuação (), símbolos de verdade( T, F ), símbolos proposicionais( P, Q, R, S...), conectivos proposicionais(¬, v, ^, ->, <->). \n\n");
                    acertos[0][2] = 0;
                    streak = 0;
                }

                while (resposta_1[3] != 1 && resposta_1[3] != 2)
                {
                    printf("Exercício 1.4: Todo símbolo de verdade é uma fórmula. VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_1[3]);
                    if (resposta_1[3] != 1 && resposta_1[3] != 2)
                    {
                        printf("Resposta inválida. Por favor escolha uma opção válida para sua resposta.\n\n");
                    }
                }

                if (resposta_1[3] == 1)
                {
                    printf("Resposta Correta. Todo símbolo de verdade é uma fórmula e todo símbolo proposicional é uma fórmula.\n\n");
                    acertos[0][3] = 1;
                    streak++;
                    nota[0] = nota[0] + 10 * streak;
                }
                else
                {
                    printf("Resposta Incorreta. Todo símbolo de verdade é uma fórmula e todo símbolo proposicional é uma fórmula.\n\n");
                    acertos[0][3] = 0;
                    streak = 0;
                }

                while (resposta_1[4] != 1 && resposta_1[4] != 2)
                {
                    printf("Exercício 1.5: O comprimento de uma fórmula funciona da seguinte maneira: símbolo de verdade = +1 comprimento, símbolo proposicional = +1 comprimento, conectivo proposicional = +1 comprimento, símbolos de pontuação = +1 comprimento.\n");
                    printf("VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_1[4]);
                    if (resposta_1[4] != 1 && resposta_1[4] != 2)
                    {
                        printf("Resposta inválida. Por favor escolha uma opção válida para sua resposta.\n\n");
                    }
                }

                if (resposta_1[4] == 1)
                {
                    printf("Resposta Incorreta. Os símbolos de verdade, símbolos proposicionais e conectivos proposicionais possuem +1 de comprimento, porém os símbolos de pontuação não mudam o comprimento de uma fórmula.\n\n");
                    acertos[0][4] = 0;
                    streak = 0;
                }
                else
                {
                    printf("Resposta Correta. Os símbolos de verdade, símbolos proposicionais e conectivos proposicionais possuem +1 de comprimento, porém os símbolos de pontuação não mudam o comprimento de uma fórmula.\n\n");
                    acertos[0][4] = 1;
                    nota[0] = nota[0] + 10 * streak;
                }

                while (resposta_1[5] < 0)
                {
                    printf("Exercício 1.6: Em uma fórmula com duas proposições distintas e um conectivo implica as ligando, quantas possibilidades existem para a interpretação dessa fórmula ser FALSA ?\n");
                    scanf("%d", &resposta_1[5]);
                    if (resposta_1[5] < 0)
                    {
                        printf("Resposta inválida. Por favor digite um valor positivo ou zero.\n\n");
                    }
                }

                if (resposta_1[5] == 1)
                {
                    printf("Resposta Correta. A única possíbilidade para a fórmula ser falsa é a primeira proposição sendo VERDADEIRA e a segunda proposição sendo FALSA.\n");
                    printf("Exemplo: H = (P -> Q), para H ser FALSO P deve ser VERDADEIRO e Q deve ser FALSO.\n\n");
                    acertos[0][5] = 1;
                    streak++;
                    nota[0] = nota[0] + 10 * streak;
                }
                else
                {
                    printf("Resposta Incorreta. A única possíbilidade para a fórmula ser falsa é a primeira proposição sendo VERDADEIRA e a segunda proposição sendo FALSA.\n");
                    printf("Exemplo: H = (P -> Q), para H ser FALSO P deve ser VERDADEIRO e Q deve ser FALSO.\n\n");
                    acertos[0][5] = 0;
                    streak = 0;
                }

                while (resposta_1[6] != 1 && resposta_1[6] != 2)
                {
                    printf("Exercício 1.7: Uma fórmula H é tautologia se existe pelo menos uma interpretação VERDADEIRA para ela. VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_1[6]);
                    if (resposta_1[6] != 1 && resposta_1[6] != 2)
                    {
                        printf("Resposta inválida. Por favor escolha uma opção válida para sua resposta.\n\n");
                    }
                }

                if (resposta_1[6] == 1)
                {
                    printf("Resposta Incorreta. H é uma tautologia se, e somente se, todas suas interpretações são VERDADEIRAS.\n");
                    printf("Se existe pelo menos uma interpretação VERDADEIRA para H então H é satisfatível, logo toda tautologia é uma fórmula satisfatível.\n\n");
                    acertos[0][6] = 0;
                    streak = 0;
                }
                else
                {
                    printf("Resposta Correta. H é uma tautologia se, e somente se, todas suas interpretações são VERDADEIRAS.\n");
                    printf("Se existe pelo menos uma interpretação VERDADEIRA para H então H é satisfatível, logo toda tautologia é uma fórmula satisfatível.\n\n");
                    acertos[0][6] = 1;
                    streak++;
                    nota[0] = nota[0] + 10 * streak;
                }

                while (resposta_1[7] != 1 && resposta_1[7] != 2)
                {
                    printf("Exercício 1.8: Considerando as fórmulsa H = (P v Q), G = P, é correto dizer que H |= P . VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_1[7]);
                    if (resposta_1[7] != 1 && resposta_1[7] != 2)
                    {
                        printf("Resposta inválida. Por favor escolha uma opção válida para sua resposta.\n\n");
                    }
                }

                if (resposta_1[7] == 1)
                {
                    printf("Resposta Incorreta. H não implica semanticamente G pois (P v Q) -> P não é uma tautologia. Existe uma interpretação falsa para essa implicação, quando I[P]=FALSO e I[Q]=VERDADEIRO.\n\n");
                    acertos[0][7] = 0;
                    streak = 0;
                }
                else
                {
                    printf("Resposta Correta. H não implica semanticamente G pois (P v Q) -> P não é uma tautologia. Existe uma interpretação falsa para essa implicação, quando I[P]=FALSO e I[Q]=VERDADEIRO.\n\n");
                    acertos[0][7] = 1;
                    streak++;
                    nota[0] = nota[0] + 10 * streak;
                }

                while (resposta_1[8] != 1 && resposta_1[8] != 2)
                {
                    printf("Exercício 1.9: Uma fórmula H não é satisfatível se, e somente se, H for contraditória. VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_1[8]);
                    if (resposta_1[8] != 1 && resposta_1[8] != 2)
                    {
                        printf("Resposta inválida. Por favor escolha uma opção válida para sua resposta.\n\n");
                    }
                }

                if (resposta_1[8] == 1)
                {
                    printf("Resposta Correta. Uma fórmula não satisfatível só possui interpretações FALSAS, logo ela também é uma fórmula contraditória.\n\n");
                    acertos[0][8] = 1;
                    streak++;
                    nota[0] = nota[0] + 10 * streak;
                }
                else
                {
                    printf("Resposta Incorreta. Uma fórmula não satisfatível só possui interpretações FALSAS, logo ela também é uma fórmula contraditória.\n\n");
                    acertos[0][8] = 0;
                    streak = 0;
                }

                printf("Questionário do tema 1 encerrado.\n");
                system("pause");
                system("cls");
            }
            else
            {
                printf("Este tema já foi respondido. Por favor escolha outro tema ou encerre os questionários.\n\n");
            }

            streak = 0;
            flag_tema1 = 1;
            break;

        case 2: // exercícios do tema 2

            if (flag_tema2 == 0)
            {
                system("cls");
                printf("A seguir serão apresentados os exercícios sobre lógica de predicados:\n\n");

                while (resposta_2[0] <= 0)
                {
                    printf("Exercício 2.1: Na lógica de predicados existem quantos tipos de símbolos ?\n");
                    scanf("%d", &resposta_2[0]);
                    if (resposta_2[0] <= 0)
                    {
                        printf("Resposta inválida. Por favor digite um número maior que zero.\n\n");
                    }
                }

                if (resposta_2[0] == 6)
                {
                    printf("Resposta Correta. Existem 6 tipos sendo eles: símbolos de pontuação:( ), símbolos de verdade: (false), símbolos para variáveis: x,y,z,w,x1..., \nsímbolos para funções: f,g,h,f1..., símbolos para predicados: p,q,r,p1..., símbolos para conectivos: ¬, v, A(de cabeça para baixo), 3 .\n\n");
                    acertos[1][0] = 1;
                    streak++;
                    nota[1] = nota[1] + 10 * streak;
                }
                else
                {
                    printf("Resposta Incorreta. Existem 6 tipos sendo eles: símbolos de pontuação:( ), símbolos de verdade: (false), símbolos para variáveis: x,y,z,w,x1..., \nsímbolos para funções: f,g,h,f1..., símbolos para predicados: p,q,r,p1..., símbolos para conectivos: ¬, v, A(de cabeça para baixo), 3 .\n\n");
                    acertos[1][0] = 0;
                    streak = 0;
                }

                while (resposta_2[1] != 1 && resposta_2[1] != 2)
                {
                    printf("Exercício 2.2: Um predicado de argumento zero(K = 0), ou seja, aridade nula, é considerado uma proposição. VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_2[1]);
                    if (resposta_2[1] != 1 && resposta_2[1] != 2)
                    {
                        printf("Resposta inválida. Por favor escolha uma opção válida para sua resposta.\n\n");
                    }
                }

                if (resposta_2[1] == 1)
                {
                    printf("Resposta Correta. Todo predicado de argumento zero é uma proposição.\n\n");
                    acertos[1][1] = 1;
                    streak++;
                    nota[1] = nota[1] + 10 * streak;
                }
                else
                {
                    printf("Resposta Incorreta. Todo predicado de argumento zero é uma proposição.\n\n");
                    acertos[1][1] = 0;
                    streak = 0;
                }

                while (resposta_2[2] != 1 && resposta_2[2] != 2)
                {
                    printf("Exercício 2.3: Uma função de argumento zero(K = 0), ou seja, aridade nula, continua sendo considerada uma função. VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_2[2]);
                    if (resposta_2[2] != 1 && resposta_2[2] != 2)
                    {
                        printf("Resposta inválida. Por favor escolha uma opção válida para sua resposta.\n\n");
                    }
                }

                if (resposta_2[2] == 1)
                {
                    printf("Resposta Incorreta. Toda função zero-ária (argumento zero) é considerada uma constante.\n\n");
                    acertos[1][2] = 0;
                    streak = 0;
                }
                else
                {
                    printf("Resposta Correta. Toda função zero-ária (argumento zero) é considerada uma constante.\n\n");
                    acertos[1][2] = 1;
                    streak++;
                    nota[1] = nota[1] + 10 * streak;
                }

                while (resposta_2[3] != 1 && resposta_2[3] != 2)
                {
                    printf("Exercício 2.4: Variáveis, constantes e funções são consideradas átomos. VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_2[3]);
                    if (resposta_2[3] != 1 && resposta_2[3] != 2)
                    {
                        printf("Resposta inválida. Por favor escolha uma opção válida para sua resposta.\n\n");
                    }
                }

                if (resposta_2[3] == 1)
                {
                    printf("Resposta Incorreta. Variáveis, constantes e funções são consideradas como Termos e não átomos.\n\n");
                    acertos[1][3] = 0;
                    streak = 0;
                }
                else
                {
                    printf("Resposta Correta. Variáveis, constantes e funções são consideradas como Termos e não átomos.\n\n");
                    acertos[1][3] = 1;
                    streak++;
                    nota[1] = nota[1] + 10 * streak;
                }

                while (resposta_2[4] != 1 && resposta_2[4] != 2)
                {
                    printf("Exercício 2.5: Todo átomo é fórmula. VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_2[4]);
                    if (resposta_2[4] != 1 && resposta_2[4] != 2)
                    {
                        printf("Resposta inválida. Por favor escolha uma opção válida para sua resposta.\n\n");
                    }
                }

                if (resposta_2[4] == 1)
                {
                    printf("Resposta Correta. Todo átomo(símbolo verdade, predicado ou proposição) é uma fórmula.\n\n");
                    acertos[1][4] = 1;
                    streak++;
                    nota[1] = nota[1] + 10 * streak;
                }
                else
                {
                    printf("Resposta Incorreta. Todo átomo(símbolo verdade, predicado ou proposição) é uma fórmula.\n\n");
                    acertos[1][4] = 0;
                    streak = 0;
                }

                while (resposta_2[5] != 1 && resposta_2[5] != 2)
                {
                    printf("Exercício 2.6: Considerando a sentença a seguir: Nenhum leão é manso. \nEla pode ser escrita na lógica de predicados da seguinte maneira:   Ax ( p(x) -> ¬q(x) )      Sendo p= é leão, q= é manso\n");
                    printf("VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_2[5]);
                    if (resposta_2[5] != 1 && resposta_2[5] != 2)
                    {
                        printf("Resposta inválida. Por favor escolha uma opção válida para sua resposta.\n\n");
                    }
                }

                if (resposta_2[5] == 1)
                {
                    printf("Resposta Correta. A sentença foi trancrita para lógica de predicados perfeitamente.\n\n");
                    acertos[1][5] = 1;
                    streak++;
                    nota[1] = nota[1] + 10 * streak;
                }
                else
                {
                    printf("Resposta Incorreta. A sentença foi trancrita para lógica de predicados perfeitamente.\n\n");
                    acertos[1][5] = 0;
                    streak = 0;
                }

                printf("Questionário do tema 2 encerrado.\n");
                system("pause");
                system("cls");
            }
            else
            {
                printf("Este tema já foi respondido. Por favor escolha outro tema ou encerre os questionários.\n\n");
            }

            streak = 0;
            flag_tema2 = 1;
            break;

        case 3: // exercícios do tema 3

            if (flag_tema3 == 0)
            {
                system("cls");
                printf("A seguir serão apresentados os exercícios sobre métodos de validação da lógica proposicional:\n\n");

                while (resposta_3[0] != 1 && resposta_3[0] != 2)
                {
                    printf("Exercício 3.1: No método de validação da tabela-verdade a quantidade de linhas é igual a 3 elevado a N, sendo N o número de subfórmulas atômicas. VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_3[0]);
                    if (resposta_3[0] != 1 && resposta_3[0] != 2)
                    {
                        printf("Resposta inválida. Por favor escolha uma opção válida para sua resposta.\n\n");
                    }
                }

                if (resposta_3[0] == 1)
                {
                    printf("Resposta Incorreta. A quantidade de linhas de uma tabela-verdade é igual a 2 eleveado a N, pois as subfórmulas atômicas só possuem 2 tipos de resultados: VERDADEIRO ou FALSO, e não 3.\n\n");
                    acertos[2][0] = 0;
                    streak = 0;
                }
                else
                {
                    printf("Resposta Correta. A quantidade de linhas de uma tabela-verdade é igual a 2 eleveado a N, pois as subfórmulas atômicas só possuem 2 tipos de resultados: VERDADEIRO ou FALSO, e não 3.\n\n");
                    acertos[2][0] = 1;
                    streak++;
                    nota[2] = nota[2] + 10 * streak;
                }

                while (resposta_3[1] != 1 && resposta_3[1] != 2)
                {
                    printf("Exercício 3.2: Caso alguém utilize o método da negação em uma fórmula e na primeira possibilidade encontre um absurdo, ela poderá afirmar que aquela fórmula é uma tautologia. VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_3[1]);
                    if (resposta_3[1] != 1 && resposta_3[1] != 2)
                    {
                        printf("Resposta inválida. Por favor escolha uma opção válida para sua resposta.\n\n");
                    }
                }

                if (resposta_3[1] == 1)
                {
                    printf("Resposta Incorreta. A ánalise de somente 1 possibilidade no método da negação não é o suficiente para provar que uma fórmula é tautologia.\n\n");
                    acertos[2][1] = 0;
                    streak = 0;
                }
                else
                {
                    printf("Resposta Correta. A ánalise de somente 1 possibilidade no método da negação não é o suficiente para provar que uma fórmula é tautologia.\n\n");
                    acertos[2][1] = 1;
                    streak++;
                    nota[2] = nota[2] + 10 * streak;
                }

                while (resposta_3[2] != 1 && resposta_3[2] != 2)
                {
                    printf("Exercício 3.3: Se as folhas de uma árvorede semântica estiverem todas rotuladas com F, então a fórmula que está sendo analisada é contraditória. VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_3[2]);
                    if (resposta_3[2] != 1 && resposta_3[2] != 2)
                    {
                        printf("Resposta inválida. Por favor escolha uma opção válida para sua resposta.\n\n");
                    }
                }

                if (resposta_3[2] == 1)
                {
                    printf("Resposta Correta. Quando todas folhas da árvore semântica estiverem rotuladas com F todas as interpretações para aquela fórmula são FALSAS, o que configura esta fórmula como contraditória.\n\n");
                    acertos[2][2] = 1;
                    streak++;
                    nota[2] = nota[2] + 10 * streak;
                }
                else
                {
                    printf("Resposta Incorreta. Quando todas folhas da árvore semântica estiverem rotuladas com F todas as interpretações para aquela fórmula são FALSAS, o que configura esta fórmula como contraditória.\n\n");
                    acertos[2][2] = 0;
                    streak = 0;
                }

                printf("Questionário do tema 3 encerrado.\n");
                system("pause");
                system("cls");
            }
            else
            {
                printf("Este tema já foi respondido. Por favor escolha outro tema ou encerre os questionários.\n\n");
            }

            printf("Questionário do tema 3 encerrado.\n");
            streak = 0;
            flag_tema3 = 1;
            break;
        default:

            printf("Tema inválido. Por favor escolha uma opção válida.\n");
            break;
        }
    }

    printf("A seguir você consegue observar quais questões acertou e errou por meio desta tabela.\n");
    printf("A letra C representa as questões respondidas certas e a letra E representa as questões respondidas erradas.\n\n");

    for (i = 0; i < 3; i++)
    {
        printf("Tema %d: ", i + 1);
        for (j = 0; j < 9; j++)
        {
            if (acertos[i][j] == 2)
            {
                printf("\0\t");
            }
            if (acertos[i][j] == 1)
            {
                printf("C\t");
            }
            if (acertos[i][j] == 0)
            {
                printf("E\t");
            }
        }
        printf("\n\n");
    }

    printf("Essa é a parte final do aplicativo e você poderá verificar sua pontuação em cada tema a seguir.\n\n");

    if (flag_tema1 == 1)
    {
        system("pause");
        printf("\nSua pontuação no tema 1 foi: %d pontos.\n", nota[0]);
        if (nota[0] == 400)
        {
            printf("Parabéns !!! Você conseguiu a pontuação máxima nesse tema. Continue assim!\n\n");
        }
        if (nota[0] >= 140 && nota[0] != 400)
        {
            printf("Parabéns !! Sua pontuação foi altíssima nesse tema. Continue assim!\n\n");
        }
        if (nota[0] < 140 && nota[0] >= 80)
        {
            printf("Você atingiu uma ponutação mediana nesse tema. Estude e pratique um pouco mais.\n\n");
        }
        if(nota[0] < 80)
        {
            printf("Você atingiu uma pontuação muito baixa nesse tema. É preciso reforçar mais esse conteúdo.\n\n");
        }
    }

    if (flag_tema2 == 1)
    {
        system("pause");
        printf("\nSua pontuação no tema 2 foi: %d pontos.\n", nota[1]);
        if(nota[1] == 210)
        {
            printf("Parabéns !!! Você conseguiu a pontuação máxima nesse tema. Continue assim!\n\n");
        }
        if(nota[1] >= 150 && nota[1] != 210)
        {
            printf("Parabéns !! Sua pontuação foi altíssima nesse tema. Continue assim!\n\n");
        }
        if(nota[1] > 40 && nota[1] <= 100)
        {
            printf("Você atingiu uma ponutação mediana nesse tema. Estude e pratique um pouco mais.\n\n");
        }
        if(nota[1] <= 40)
        {
            printf("Você atingiu uma pontuação muito baixa nesse tema. É preciso reforçar mais esse conteúdo.\n\n");
        }
    }

    if (flag_tema3 == 1)
    {
        system("pause");
        printf("\nSua pontuação no tema 3 foi: %d pontos.\n", nota[2]);
        if (nota[2] == 60)
        {
            printf("Parabéns!!! Você conseguiu a ponutação máxima nesse tema. Continue assim!\n\n");
        }
        if (nota[2] == 30)
        {
            printf("Parabéns! Sua pontuação foi alta nesse tema. Continue assim!\n\n");
        }
        if (nota[2] == 20)
        {
            printf("Você atingiu uma ponutação mediana nesse tema. Estude e pratique um pouco mais.\n\n");
        }
        if (nota[2] <= 10)
        {
            printf("Você atingiu uma pontuação muito baixa nesse tema. É preciso reforçar mais esse conteúdo.\n\n");
        }
    }

    system("pause");
    printf("\nObrigado por utilizar o Desenrola. Volte sempre.\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int flag_tela_cheia = 0;

    do
    {
        printf("AVISO IMPORTANTE : Digite somente n�meros nas respostas para obter o bom funcionamento do programa e evitar erros e bugs.\n\n");
        printf("Utilize o prompt em tela cheia para obter a experi�ncia correta.\nDigite 1 para confirmar que o prompt est� em tela cheia.\n");
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
    printf("���������������������������������������������������������������������������������������������������������������������������������������������������������������       \n");
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
    printf("���������������������������������������������������������������������������������������������������������������������������������������������������������������       \n");
    printf("\n\n");

    printf("Nesta plataforma voc� poder� testar seus conhecimentos em L�gica Computacional por meio de question�rios sobre diferentes temas.\n");
    printf("� importante ressaltar que o conte�do de L�gica Computacional apresentado no Desenrola � baseado nas produ��es do autor Jo�o Nunes de Souza.\n");
    printf("Funcionar� da seguinte forma: A cada resposta certa voc� receber� 10 pontos por�m, caso acerte respostas em sequ�ncia, seu streak aumentar�.\n");
    printf("A cada acerto seu streak aumenta em 1 e a quest�o sempre valer� : (10 x streak).\n\n\n");

    while (tema != 0)
    {
        printf("Escolha um tema para dar �nico a um question�rio.\n");
        printf("Digite 1 para : L�gica proposicional.\n");
        printf("Digite 2 para : L�gica de predicados.\n");
        printf("Digite 3 para : M�todos de valida��o da l�gica proposicional.\n");
        printf("Digite 0 para encerrar o menu de question�rios.\n");
        scanf("%d", &tema);
        printf("\n");

        switch (tema)
        {
        case 0:
            printf("Menu de question�rios encerrados.\n");
            system("pause");
            system("cls");
            break;

        case 1: // exerc�cios do tema 1

            if (flag_tema1 == 0)
            {
                system("cls");
                printf("A seguir ser�o apresentados os exerc�cios de L�gica proposicional:\n\n");

                while (resposta_1[0] != 1 && resposta_1[0] != 2)
                {
                    printf("Exerc�cio 1.1: As proposi��es da L�gica proposicional podem ser representados pelas letras min�sculas p,q,r,s,p1... VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_1[0]);
                    if (resposta_1[0] != 1 && resposta_1[0] != 2)
                    {
                        printf("Resposta inv�lida. Por favor escolha uma op��o v�lida para sua resposta.\n\n");
                    }
                }

                if (resposta_1[0] == 1)
                {
                    printf("Resposta Incorreta. Os s�mbolos para proposi��es s�o representados por letras mai�sculas.\n\n");
                    acertos[0][0] = 0;
                    streak = 0;
                }
                else
                {
                    printf("Resposta Correta. Os s�mbolos para proposi��es s�o representados por letras mai�sculas.\n\n");
                    acertos[0][0] = 1;
                    streak++;
                    nota[0] = nota[0] + 10 * streak;
                }

                while (resposta_1[1] != 1 && resposta_1[1] != 2)
                {
                    printf("Exerc�cio 1.2: Uma proposi��o da L�gica proposicional n�o pode ser encerrada com ponto de interroga��o. VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_1[1]);
                    if (resposta_1[1] != 1 && resposta_1[1] != 2)
                    {
                        printf("Resposta inv�lida. Por favor escolha uma op��o v�lida para sua resposta.\n\n");
                    }
                }

                if (resposta_1[1] == 1)
                {
                    printf("Resposta Correta. Uma proposi��o em forma de senten�a n�o pode terminar com ponto de interroga��o, uma vez que ela deve ter um valor l�gico TRUE ou FALSE.\n\n");
                    acertos[0][1] = 1;
                    streak++;
                    nota[0] = nota[0] + 10 * streak;
                }
                else
                {
                    printf("Resposta Incorreta. Uma proposi��o em forma de senten�a n�o pode terminar com ponto de interroga��o, uma vez que ela deve ter um valor l�gico TRUE ou FALSE.\n\n");
                    acertos[0][1] = 0;
                    streak = 0;
                }

                while (resposta_1[2] < 1)
                {
                    printf("Exerc�cio 1.3: No total quantos tipos de s�mbolos existem na L�gica proposicional.\n");
                    scanf("%d", &resposta_1[2]);
                    if (resposta_1[2] < 1)
                    {
                        printf("Por favor digite uma resposta v�lida: um n�mero pos�tivo diferente de 0.\n\n");
                    }
                }

                if (resposta_1[2] == 4)
                {
                    printf("Resposta Correta. Existem 4 tipos de s�mbolos sendo eles : s�mbolos de pontua��o (), s�mbolos de verdade( T, F ), s�mbolos proposicionais( P, Q, R, S...), conectivos proposicionais(�, v, ^, ->, <->). \n\n");
                    acertos[0][2] = 1;
                    streak++;
                    nota[0] = nota[0] + 10 * streak;
                }
                else
                {
                    printf("Resposta Incorreta. Existem 4 tipos de s�mbolos sendo eles : s�mbolos de pontua��o (), s�mbolos de verdade( T, F ), s�mbolos proposicionais( P, Q, R, S...), conectivos proposicionais(�, v, ^, ->, <->). \n\n");
                    acertos[0][2] = 0;
                    streak = 0;
                }

                while (resposta_1[3] != 1 && resposta_1[3] != 2)
                {
                    printf("Exerc�cio 1.4: Todo s�mbolo de verdade � uma f�rmula. VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_1[3]);
                    if (resposta_1[3] != 1 && resposta_1[3] != 2)
                    {
                        printf("Resposta inv�lida. Por favor escolha uma op��o v�lida para sua resposta.\n\n");
                    }
                }

                if (resposta_1[3] == 1)
                {
                    printf("Resposta Correta. Todo s�mbolo de verdade � uma f�rmula e todo s�mbolo proposicional � uma f�rmula.\n\n");
                    acertos[0][3] = 1;
                    streak++;
                    nota[0] = nota[0] + 10 * streak;
                }
                else
                {
                    printf("Resposta Incorreta. Todo s�mbolo de verdade � uma f�rmula e todo s�mbolo proposicional � uma f�rmula.\n\n");
                    acertos[0][3] = 0;
                    streak = 0;
                }

                while (resposta_1[4] != 1 && resposta_1[4] != 2)
                {
                    printf("Exerc�cio 1.5: O comprimento de uma f�rmula funciona da seguinte maneira: s�mbolo de verdade = +1 comprimento, s�mbolo proposicional = +1 comprimento, conectivo proposicional = +1 comprimento, s�mbolos de pontua��o = +1 comprimento.\n");
                    printf("VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_1[4]);
                    if (resposta_1[4] != 1 && resposta_1[4] != 2)
                    {
                        printf("Resposta inv�lida. Por favor escolha uma op��o v�lida para sua resposta.\n\n");
                    }
                }

                if (resposta_1[4] == 1)
                {
                    printf("Resposta Incorreta. Os s�mbolos de verdade, s�mbolos proposicionais e conectivos proposicionais possuem +1 de comprimento, por�m os s�mbolos de pontua��o n�o mudam o comprimento de uma f�rmula.\n\n");
                    acertos[0][4] = 0;
                    streak = 0;
                }
                else
                {
                    printf("Resposta Correta. Os s�mbolos de verdade, s�mbolos proposicionais e conectivos proposicionais possuem +1 de comprimento, por�m os s�mbolos de pontua��o n�o mudam o comprimento de uma f�rmula.\n\n");
                    acertos[0][4] = 1;
                    nota[0] = nota[0] + 10 * streak;
                }

                while (resposta_1[5] < 0)
                {
                    printf("Exerc�cio 1.6: Em uma f�rmula com duas proposi��es distintas e um conectivo implica as ligando, quantas possibilidades existem para a interpreta��o dessa f�rmula ser FALSA ?\n");
                    scanf("%d", &resposta_1[5]);
                    if (resposta_1[5] < 0)
                    {
                        printf("Resposta inv�lida. Por favor digite um valor positivo ou zero.\n\n");
                    }
                }

                if (resposta_1[5] == 1)
                {
                    printf("Resposta Correta. A �nica poss�bilidade para a f�rmula ser falsa � a primeira proposi��o sendo VERDADEIRA e a segunda proposi��o sendo FALSA.\n");
                    printf("Exemplo: H = (P -> Q), para H ser FALSO P deve ser VERDADEIRO e Q deve ser FALSO.\n\n");
                    acertos[0][5] = 1;
                    streak++;
                    nota[0] = nota[0] + 10 * streak;
                }
                else
                {
                    printf("Resposta Incorreta. A �nica poss�bilidade para a f�rmula ser falsa � a primeira proposi��o sendo VERDADEIRA e a segunda proposi��o sendo FALSA.\n");
                    printf("Exemplo: H = (P -> Q), para H ser FALSO P deve ser VERDADEIRO e Q deve ser FALSO.\n\n");
                    acertos[0][5] = 0;
                    streak = 0;
                }

                while (resposta_1[6] != 1 && resposta_1[6] != 2)
                {
                    printf("Exerc�cio 1.7: Uma f�rmula H � tautologia se existe pelo menos uma interpreta��o VERDADEIRA para ela. VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_1[6]);
                    if (resposta_1[6] != 1 && resposta_1[6] != 2)
                    {
                        printf("Resposta inv�lida. Por favor escolha uma op��o v�lida para sua resposta.\n\n");
                    }
                }

                if (resposta_1[6] == 1)
                {
                    printf("Resposta Incorreta. H � uma tautologia se, e somente se, todas suas interpreta��es s�o VERDADEIRAS.\n");
                    printf("Se existe pelo menos uma interpreta��o VERDADEIRA para H ent�o H � satisfat�vel, logo toda tautologia � uma f�rmula satisfat�vel.\n\n");
                    acertos[0][6] = 0;
                    streak = 0;
                }
                else
                {
                    printf("Resposta Correta. H � uma tautologia se, e somente se, todas suas interpreta��es s�o VERDADEIRAS.\n");
                    printf("Se existe pelo menos uma interpreta��o VERDADEIRA para H ent�o H � satisfat�vel, logo toda tautologia � uma f�rmula satisfat�vel.\n\n");
                    acertos[0][6] = 1;
                    streak++;
                    nota[0] = nota[0] + 10 * streak;
                }

                while (resposta_1[7] != 1 && resposta_1[7] != 2)
                {
                    printf("Exerc�cio 1.8: Considerando as f�rmulsa H = (P v Q), G = P, � correto dizer que H |= P . VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_1[7]);
                    if (resposta_1[7] != 1 && resposta_1[7] != 2)
                    {
                        printf("Resposta inv�lida. Por favor escolha uma op��o v�lida para sua resposta.\n\n");
                    }
                }

                if (resposta_1[7] == 1)
                {
                    printf("Resposta Incorreta. H n�o implica semanticamente G pois (P v Q) -> P n�o � uma tautologia. Existe uma interpreta��o falsa para essa implica��o, quando I[P]=FALSO e I[Q]=VERDADEIRO.\n\n");
                    acertos[0][7] = 0;
                    streak = 0;
                }
                else
                {
                    printf("Resposta Correta. H n�o implica semanticamente G pois (P v Q) -> P n�o � uma tautologia. Existe uma interpreta��o falsa para essa implica��o, quando I[P]=FALSO e I[Q]=VERDADEIRO.\n\n");
                    acertos[0][7] = 1;
                    streak++;
                    nota[0] = nota[0] + 10 * streak;
                }

                while (resposta_1[8] != 1 && resposta_1[8] != 2)
                {
                    printf("Exerc�cio 1.9: Uma f�rmula H n�o � satisfat�vel se, e somente se, H for contradit�ria. VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_1[8]);
                    if (resposta_1[8] != 1 && resposta_1[8] != 2)
                    {
                        printf("Resposta inv�lida. Por favor escolha uma op��o v�lida para sua resposta.\n\n");
                    }
                }

                if (resposta_1[8] == 1)
                {
                    printf("Resposta Correta. Uma f�rmula n�o satisfat�vel s� possui interpreta��es FALSAS, logo ela tamb�m � uma f�rmula contradit�ria.\n\n");
                    acertos[0][8] = 1;
                    streak++;
                    nota[0] = nota[0] + 10 * streak;
                }
                else
                {
                    printf("Resposta Incorreta. Uma f�rmula n�o satisfat�vel s� possui interpreta��es FALSAS, logo ela tamb�m � uma f�rmula contradit�ria.\n\n");
                    acertos[0][8] = 0;
                    streak = 0;
                }

                printf("Question�rio do tema 1 encerrado.\n");
                system("pause");
                system("cls");
            }
            else
            {
                printf("Este tema j� foi respondido. Por favor escolha outro tema ou encerre os question�rios.\n\n");
            }

            streak = 0;
            flag_tema1 = 1;
            break;

        case 2: // exerc�cios do tema 2

            if (flag_tema2 == 0)
            {
                system("cls");
                printf("A seguir ser�o apresentados os exerc�cios sobre l�gica de predicados:\n\n");

                while (resposta_2[0] <= 0)
                {
                    printf("Exerc�cio 2.1: Na l�gica de predicados existem quantos tipos de s�mbolos ?\n");
                    scanf("%d", &resposta_2[0]);
                    if (resposta_2[0] <= 0)
                    {
                        printf("Resposta inv�lida. Por favor digite um n�mero maior que zero.\n\n");
                    }
                }

                if (resposta_2[0] == 6)
                {
                    printf("Resposta Correta. Existem 6 tipos sendo eles: s�mbolos de pontua��o:( ), s�mbolos de verdade: (false), s�mbolos para vari�veis: x,y,z,w,x1..., \ns�mbolos para fun��es: f,g,h,f1..., s�mbolos para predicados: p,q,r,p1..., s�mbolos para conectivos: �, v, A(de cabe�a para baixo), 3 .\n\n");
                    acertos[1][0] = 1;
                    streak++;
                    nota[1] = nota[1] + 10 * streak;
                }
                else
                {
                    printf("Resposta Incorreta. Existem 6 tipos sendo eles: s�mbolos de pontua��o:( ), s�mbolos de verdade: (false), s�mbolos para vari�veis: x,y,z,w,x1..., \ns�mbolos para fun��es: f,g,h,f1..., s�mbolos para predicados: p,q,r,p1..., s�mbolos para conectivos: �, v, A(de cabe�a para baixo), 3 .\n\n");
                    acertos[1][0] = 0;
                    streak = 0;
                }

                while (resposta_2[1] != 1 && resposta_2[1] != 2)
                {
                    printf("Exerc�cio 2.2: Um predicado de argumento zero(K = 0), ou seja, aridade nula, � considerado uma proposi��o. VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_2[1]);
                    if (resposta_2[1] != 1 && resposta_2[1] != 2)
                    {
                        printf("Resposta inv�lida. Por favor escolha uma op��o v�lida para sua resposta.\n\n");
                    }
                }

                if (resposta_2[1] == 1)
                {
                    printf("Resposta Correta. Todo predicado de argumento zero � uma proposi��o.\n\n");
                    acertos[1][1] = 1;
                    streak++;
                    nota[1] = nota[1] + 10 * streak;
                }
                else
                {
                    printf("Resposta Incorreta. Todo predicado de argumento zero � uma proposi��o.\n\n");
                    acertos[1][1] = 0;
                    streak = 0;
                }

                while (resposta_2[2] != 1 && resposta_2[2] != 2)
                {
                    printf("Exerc�cio 2.3: Uma fun��o de argumento zero(K = 0), ou seja, aridade nula, continua sendo considerada uma fun��o. VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_2[2]);
                    if (resposta_2[2] != 1 && resposta_2[2] != 2)
                    {
                        printf("Resposta inv�lida. Por favor escolha uma op��o v�lida para sua resposta.\n\n");
                    }
                }

                if (resposta_2[2] == 1)
                {
                    printf("Resposta Incorreta. Toda fun��o zero-�ria (argumento zero) � considerada uma constante.\n\n");
                    acertos[1][2] = 0;
                    streak = 0;
                }
                else
                {
                    printf("Resposta Correta. Toda fun��o zero-�ria (argumento zero) � considerada uma constante.\n\n");
                    acertos[1][2] = 1;
                    streak++;
                    nota[1] = nota[1] + 10 * streak;
                }

                while (resposta_2[3] != 1 && resposta_2[3] != 2)
                {
                    printf("Exerc�cio 2.4: Vari�veis, constantes e fun��es s�o consideradas �tomos. VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_2[3]);
                    if (resposta_2[3] != 1 && resposta_2[3] != 2)
                    {
                        printf("Resposta inv�lida. Por favor escolha uma op��o v�lida para sua resposta.\n\n");
                    }
                }

                if (resposta_2[3] == 1)
                {
                    printf("Resposta Incorreta. Vari�veis, constantes e fun��es s�o consideradas como Termos e n�o �tomos.\n\n");
                    acertos[1][3] = 0;
                    streak = 0;
                }
                else
                {
                    printf("Resposta Correta. Vari�veis, constantes e fun��es s�o consideradas como Termos e n�o �tomos.\n\n");
                    acertos[1][3] = 1;
                    streak++;
                    nota[1] = nota[1] + 10 * streak;
                }

                while (resposta_2[4] != 1 && resposta_2[4] != 2)
                {
                    printf("Exerc�cio 2.5: Todo �tomo � f�rmula. VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_2[4]);
                    if (resposta_2[4] != 1 && resposta_2[4] != 2)
                    {
                        printf("Resposta inv�lida. Por favor escolha uma op��o v�lida para sua resposta.\n\n");
                    }
                }

                if (resposta_2[4] == 1)
                {
                    printf("Resposta Correta. Todo �tomo(s�mbolo verdade, predicado ou proposi��o) � uma f�rmula.\n\n");
                    acertos[1][4] = 1;
                    streak++;
                    nota[1] = nota[1] + 10 * streak;
                }
                else
                {
                    printf("Resposta Incorreta. Todo �tomo(s�mbolo verdade, predicado ou proposi��o) � uma f�rmula.\n\n");
                    acertos[1][4] = 0;
                    streak = 0;
                }

                while (resposta_2[5] != 1 && resposta_2[5] != 2)
                {
                    printf("Exerc�cio 2.6: Considerando a senten�a a seguir: Nenhum le�o � manso. \nEla pode ser escrita na l�gica de predicados da seguinte maneira:   Ax ( p(x) -> �q(x) )      Sendo p= � le�o, q= � manso\n");
                    printf("VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_2[5]);
                    if (resposta_2[5] != 1 && resposta_2[5] != 2)
                    {
                        printf("Resposta inv�lida. Por favor escolha uma op��o v�lida para sua resposta.\n\n");
                    }
                }

                if (resposta_2[5] == 1)
                {
                    printf("Resposta Correta. A senten�a foi trancrita para l�gica de predicados perfeitamente.\n\n");
                    acertos[1][5] = 1;
                    streak++;
                    nota[1] = nota[1] + 10 * streak;
                }
                else
                {
                    printf("Resposta Incorreta. A senten�a foi trancrita para l�gica de predicados perfeitamente.\n\n");
                    acertos[1][5] = 0;
                    streak = 0;
                }

                printf("Question�rio do tema 2 encerrado.\n");
                system("pause");
                system("cls");
            }
            else
            {
                printf("Este tema j� foi respondido. Por favor escolha outro tema ou encerre os question�rios.\n\n");
            }

            streak = 0;
            flag_tema2 = 1;
            break;

        case 3: // exerc�cios do tema 3

            if (flag_tema3 == 0)
            {
                system("cls");
                printf("A seguir ser�o apresentados os exerc�cios sobre m�todos de valida��o da l�gica proposicional:\n\n");

                while (resposta_3[0] != 1 && resposta_3[0] != 2)
                {
                    printf("Exerc�cio 3.1: No m�todo de valida��o da tabela-verdade a quantidade de linhas � igual a 3 elevado a N, sendo N o n�mero de subf�rmulas at�micas. VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_3[0]);
                    if (resposta_3[0] != 1 && resposta_3[0] != 2)
                    {
                        printf("Resposta inv�lida. Por favor escolha uma op��o v�lida para sua resposta.\n\n");
                    }
                }

                if (resposta_3[0] == 1)
                {
                    printf("Resposta Incorreta. A quantidade de linhas de uma tabela-verdade � igual a 2 eleveado a N, pois as subf�rmulas at�micas s� possuem 2 tipos de resultados: VERDADEIRO ou FALSO, e n�o 3.\n\n");
                    acertos[2][0] = 0;
                    streak = 0;
                }
                else
                {
                    printf("Resposta Correta. A quantidade de linhas de uma tabela-verdade � igual a 2 eleveado a N, pois as subf�rmulas at�micas s� possuem 2 tipos de resultados: VERDADEIRO ou FALSO, e n�o 3.\n\n");
                    acertos[2][0] = 1;
                    streak++;
                    nota[2] = nota[2] + 10 * streak;
                }

                while (resposta_3[1] != 1 && resposta_3[1] != 2)
                {
                    printf("Exerc�cio 3.2: Caso algu�m utilize o m�todo da nega��o em uma f�rmula e na primeira possibilidade encontre um absurdo, ela poder� afirmar que aquela f�rmula � uma tautologia. VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_3[1]);
                    if (resposta_3[1] != 1 && resposta_3[1] != 2)
                    {
                        printf("Resposta inv�lida. Por favor escolha uma op��o v�lida para sua resposta.\n\n");
                    }
                }

                if (resposta_3[1] == 1)
                {
                    printf("Resposta Incorreta. A �nalise de somente 1 possibilidade no m�todo da nega��o n�o � o suficiente para provar que uma f�rmula � tautologia.\n\n");
                    acertos[2][1] = 0;
                    streak = 0;
                }
                else
                {
                    printf("Resposta Correta. A �nalise de somente 1 possibilidade no m�todo da nega��o n�o � o suficiente para provar que uma f�rmula � tautologia.\n\n");
                    acertos[2][1] = 1;
                    streak++;
                    nota[2] = nota[2] + 10 * streak;
                }

                while (resposta_3[2] != 1 && resposta_3[2] != 2)
                {
                    printf("Exerc�cio 3.3: Se as folhas de uma �rvorede sem�ntica estiverem todas rotuladas com F, ent�o a f�rmula que est� sendo analisada � contradit�ria. VERDADEIRO ou FALSO ?\n");
                    printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
                    scanf("%d", &resposta_3[2]);
                    if (resposta_3[2] != 1 && resposta_3[2] != 2)
                    {
                        printf("Resposta inv�lida. Por favor escolha uma op��o v�lida para sua resposta.\n\n");
                    }
                }

                if (resposta_3[2] == 1)
                {
                    printf("Resposta Correta. Quando todas folhas da �rvore sem�ntica estiverem rotuladas com F todas as interpreta��es para aquela f�rmula s�o FALSAS, o que configura esta f�rmula como contradit�ria.\n\n");
                    acertos[2][2] = 1;
                    streak++;
                    nota[2] = nota[2] + 10 * streak;
                }
                else
                {
                    printf("Resposta Incorreta. Quando todas folhas da �rvore sem�ntica estiverem rotuladas com F todas as interpreta��es para aquela f�rmula s�o FALSAS, o que configura esta f�rmula como contradit�ria.\n\n");
                    acertos[2][2] = 0;
                    streak = 0;
                }

                printf("Question�rio do tema 3 encerrado.\n");
                system("pause");
                system("cls");
            }
            else
            {
                printf("Este tema j� foi respondido. Por favor escolha outro tema ou encerre os question�rios.\n\n");
            }

            printf("Question�rio do tema 3 encerrado.\n");
            streak = 0;
            flag_tema3 = 1;
            break;
        default:

            printf("Tema inv�lido. Por favor escolha uma op��o v�lida.\n");
            break;
        }
    }

    printf("A seguir voc� consegue observar quais quest�es acertou e errou por meio desta tabela.\n");
    printf("A letra C representa as quest�es respondidas certas e a letra E representa as quest�es respondidas erradas.\n\n");

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

    printf("Essa � a parte final do aplicativo e voc� poder� verificar sua pontua��o em cada tema a seguir.\n\n");

    if (flag_tema1 == 1)
    {
        system("pause");
        printf("\nSua pontua��o no tema 1 foi: %d pontos.\n", nota[0]);
        if (nota[0] == 400)
        {
            printf("Parab�ns !!! Voc� conseguiu a pontua��o m�xima nesse tema. Continue assim!\n\n");
        }
        if (nota[0] >= 140 && nota[0] != 400)
        {
            printf("Parab�ns !! Sua pontua��o foi alt�ssima nesse tema. Continue assim!\n\n");
        }
        if (nota[0] < 140 && nota[0] >= 80)
        {
            printf("Voc� atingiu uma ponuta��o mediana nesse tema. Estude e pratique um pouco mais.\n\n");
        }
        if(nota[0] < 80)
        {
            printf("Voc� atingiu uma pontua��o muito baixa nesse tema. � preciso refor�ar mais esse conte�do.\n\n");
        }
    }

    if (flag_tema2 == 1)
    {
        system("pause");
        printf("\nSua pontua��o no tema 2 foi: %d pontos.\n", nota[1]);
        if(nota[1] == 210)
        {
            printf("Parab�ns !!! Voc� conseguiu a pontua��o m�xima nesse tema. Continue assim!\n\n");
        }
        if(nota[1] >= 150 && nota[1] != 210)
        {
            printf("Parab�ns !! Sua pontua��o foi alt�ssima nesse tema. Continue assim!\n\n");
        }
        if(nota[1] > 40 && nota[1] <= 100)
        {
            printf("Voc� atingiu uma ponuta��o mediana nesse tema. Estude e pratique um pouco mais.\n\n");
        }
        if(nota[1] <= 40)
        {
            printf("Voc� atingiu uma pontua��o muito baixa nesse tema. � preciso refor�ar mais esse conte�do.\n\n");
        }
    }

    if (flag_tema3 == 1)
    {
        system("pause");
        printf("\nSua pontua��o no tema 3 foi: %d pontos.\n", nota[2]);
        if (nota[2] == 60)
        {
            printf("Parab�ns!!! Voc� conseguiu a ponuta��o m�xima nesse tema. Continue assim!\n\n");
        }
        if (nota[2] == 30)
        {
            printf("Parab�ns! Sua pontua��o foi alta nesse tema. Continue assim!\n\n");
        }
        if (nota[2] == 20)
        {
            printf("Voc� atingiu uma ponuta��o mediana nesse tema. Estude e pratique um pouco mais.\n\n");
        }
        if (nota[2] <= 10)
        {
            printf("Voc� atingiu uma pontua��o muito baixa nesse tema. � preciso refor�ar mais esse conte�do.\n\n");
        }
    }

    system("pause");
    printf("\nObrigado por utilizar o Desenrola. Volte sempre.\n");

    return 0;
}
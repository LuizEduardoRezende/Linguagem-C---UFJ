#ifndef logica_h
#define logica_h
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include <ctype.h>

void interface()
{
    setlocale(LC_ALL, "Portuguese");
    printf("AVISO IMPORTANTE :Utilize o prompt em tela cheia para obter a experi�ncia correta.\nCom o prompt em tela cheia aperte qualquer tecla para prosseguir.\n");
    system("pause");
    system("cls");

    printf("#   ########    #######   ##        ##             ##              ##   ###   ###      ##   ########      ########\n");
    printf("#   ##     ##   #######   ###      ###              ##            ##    ###   ####     ##   ##      ##   ##      ##\n");
    printf("#   ##     ##   ##        ###      ###               ##          ##     ###   ## ##    ##   ##      ##   ##      ##\n");
    printf("#   #########   #######   ## ##  ## ##     ######     ##        ##      ###   ##  ##   ##   ##      ##   ##      ##\n");
    printf("#   #########   #######   ##   ##   ##     ######      ##      ##       ###   ##   ##  ##   ##      ##   ##      ##\n");
    printf("#   ##     ##   ##        ##        ##                  ##    ##        ###   ##    ## ##   ##      ##   ##      ##\n");
    printf("#   ##     ##   #######   ##        ##                   ##  ##         ###   ##     ####   ##      ##   ##      ##\n");
    printf("#   ########    #######   ##        ##                     ##           ###   ##      ###   ########      ########\n");
    printf("\n");
    printf("                                           ###             ########\n");
    printf("                                          ## ##           ##      ##\n");
    printf("                                         ##   ##          ##      ##\n");
    printf("                                        ##     ##         ##      ##\n");
    printf("                                       ###########        ##      ##\n");
    printf("                                      ##         ##       ##      ##\n");
    printf("                                     ##           ##      ##      ##\n");
    printf("                                    ##             ##      ########\n");
    printf("\n");
    printf("#                                                                                                                                     \n");
    printf("#   ########     #######   #######   #######   ###      ##   ########      ########    ##              ###\n");
    printf("#   ##      ##   #######   #######   #######   ####     ##   ##      ##   ##      ##   ##             ## ##\n");
    printf("#   ##      ##   ##        ##        ##        ## ##    ##   ##      ##   ##      ##   ##            ##   ##\n");
    printf("#   ##      ##   #######   #######   #######   ##  ##   ##   ##########   ##      ##   ##           ##     ##\n");
    printf("#   ##      ##   #######   #######   #######   ##   ##  ##   ########     ##      ##   ##          ###########\n");
    printf("#   ##      ##   ##             ##   ##        ##    ## ##   ##      ##   ##      ##   ##         ##         ##\n");
    printf("#   ##      ##   #######   #######   #######   ##     ####   ##      ##   ##      ##   ######    ##           ##\n");
    printf("#   ########     #######   #######   #######   ##      ###   ##      ##    ########    ######   ##             ##\n");
    printf("\n");

    printf("Nesta plataforma voc� poder� testar seus conhecimentos em L�gica Computacional por meio de question�rios sobre diferentes temas.\n");
    printf("� importante ressaltar que o conte�do de L�gica Computacional apresentado no Desenrola � baseado nas produ��es do autor Jo�o Nunes de Souza.\n");
    printf("Funcionar� da seguinte forma: A cada resposta certa voc� receber� 10 pontos por�m, caso acerte respostas em sequ�ncia, seu streak aumentar�.\n");
    printf("A cada acerto seu streak aumenta em 1 e a quest�o sempre valer� : (10 x streak).\n");
    system("pause");
    system("cls");
}

int validaCPF(char cpf[])
{
    int i, j, digito1 = 0, digito2 = 0;
    if (strlen(cpf) != 11) // se o cpf tiver tamanho diferente de 11 ele � invalido
        return 0;
    else if ((strcmp(cpf, "00000000000") == 0) || (strcmp(cpf, "11111111111") == 0) || (strcmp(cpf, "22222222222") == 0) ||
             (strcmp(cpf, "33333333333") == 0) || (strcmp(cpf, "44444444444") == 0) || (strcmp(cpf, "55555555555") == 0) ||
             (strcmp(cpf, "66666666666") == 0) || (strcmp(cpf, "77777777777") == 0) || (strcmp(cpf, "88888888888") == 0) ||
             (strcmp(cpf, "99999999999") == 0))
        return 0; // se o CPF tiver todos os n�meros iguais ele � inv�lido.
    else
    {
        // digito 1---------------------------------------------------
        for (i = 0, j = 10; i < strlen(cpf) - 2; i++, j--) /// multiplica os n�meros de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i] - 48) * j;
        digito1 %= 11;
        if (digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if ((cpf[9] - 48) != digito1)
            return 0; /// se o digito 1 n�o for o mesmo que o da valida��o o CPF � inv�lido
        else
            /// digito 2--------------------------------------------------
        {
            for (i = 0, j = 11; i < strlen(cpf) - 1; i++, j--) /// multiplica os n�meros de 11 a 2 e soma os resultados dentro de digito2
                digito2 += (cpf[i] - 48) * j;
            digito2 %= 11;
            if (digito2 < 2)
                digito2 = 0;
            else
                digito2 = 11 - digito2;
            if ((cpf[10] - 48) != digito2)
                return 0; /// se o digito 2 n�o for o mesmo que o da valida��o CPF � inv�lido
        }
    }
    return 1;
}

int verifica_string(char string[])
{
    int i;
    for (i = 0; i < strlen(string); i++)
    {
        if (!isdigit(string[i]))
        {
            return 0;
        }
    }
    return 1;
}

int calc_nota(int streak) // funcao recursiva
{
    if (streak == 0)
        return 0;
    else
        return 10 + calc_nota(streak - 1);
}

void dados_usuario(tipoaluno *usuario)
{
    setlocale(LC_ALL, "Portuguese");
    printf("Primeiramente vamos organizar seus dados pessoais.\n\n");
    printf("Digite o nome do aluno: ");
    fgets(usuario->nome, 40, stdin);
    fflush(stdin);
    usuario->nome[strcspn(usuario->nome, "\n")] = '\0'; // remove o caractere de nova linha

    printf("Digite a idade do aluno: ");
    scanf("%d", &usuario->idade);
    getchar(); // consome o caractere de nova linha ap�s a leitura do inteiro
    fflush(stdin);

    printf("\nInforme seu CPF: ");
    do
    {
        scanf("%[^\n]s", &usuario->CPF);
        fflush(stdin);
        if (validaCPF(usuario->CPF) == 0)
        {
            printf("\nPor favor, insira um CPF v�lido:\n");
        }
        else
        {
            printf("\nCPF aceito!\n");
        }
    }
    while (validaCPF(usuario->CPF) == 0);
    system("pause");
    system("cls");
}

void cont_tema1()
{
    setlocale(LC_ALL, "Portuguese");
    printf("A l�gica proposicional � a forma mais simples de l�gica. Nela os fatos do mundo real s�o representados por senten�as sem argumentos,chamadas de proposi��es.\n");
    printf("Essas proposi��es devem ser representadas por letras mai�sculas das quais normalmente s�o utilizadas P,Q,R e S.\n\n");

    printf("O alfabeto da L�gica Proposicional � constitu�do por 4 s�mbolos:\n");
    printf("S�mbolos de pontua��o (; );s�mbolos de verdade: true, false;s�mbolos proposicionais(P; Q; R; S; P1; Q1; R1; S1; P2; Q2; ...);Conectivos proposicionais( ^, <->, v, �,->).\n\n");

    printf("Ao relacionar senten�as, deve-se usar conectivos para que a nova proposi��o formada por tais senten�as seja representada na l�gica proposicional.\n\n");

    printf("Existem 4 conectivos na l�gicas proposicional: o de disjun��o(v), conjun��o(^), implica��o(->) e o de biimplica��o(<->).\n\n");

    printf("Podemos ent�o representar uma proposi��o 'Hoje est� nublado' ou 'Hoje est� seco' como P v Q.\n\n");

    printf("As senten��o NUNCA devem ser terminadas com s�mbolos n�o objetivos,como o de interroga��o.\n");
    printf("Al�m de proposi��es,senten�as podem tamb�m ser representadas por s�mbolos verdade(true,false),os quais s�o f�rmulas.\n");

    printf("Toda f�rmula possui um comprimento.Os s�mbolos de verdade, s�mbolos proposicionais e conectivos proposicionais possuem +1 de comprimento.\n");
    printf("Os s�mbolos de pontua��o n�o mudam o comprimento de uma f�rmula.\n");

    printf("Ao validar f�rmulas de duas proposi��es ligadas por conectivos, � necess�rio atribuir � tais proposi��es s�mbolos verdade(true ou false) para verificar se a interpreta��o resulta em true ou false.\n");

    printf("Caso TODAS as interpreta��es da f�rmula resultarem em uma verdade,ela � definida por tautologia.\n");
    printf("Se todas as interpreta��es resultarem em falsidade, a f�rmula � denominada contradit�ria.\n");

    printf("Caso haja ao menos uma interpreta��o true da f�rmula, ela � denominada satisfat�vel. Caso haja ao menos uma interpreta��o true e uma false, a f�rmula � denominada contingente.\n");

    printf("Uma proposi��o implica semanticamente em outra somente se a interpreta��o da biimplica��o entre elas for tautol�gica.\n");
    printf("A denota��o para implica��o sem�ntica � |= .\n\n");

    printf("A interpreta��o para duas proposi��es ligas por disju��o possui 4 possibilidaes: 3 resultam em true e 1 em false.\n");
    printf("Caso apenas uma proposi��o delas for verdade,a intepreta��o da f�rmula � verdade.\n\n");

    printf("A interpreta��o para duas proposi��es ligadas por conjun��o possi 4 possibilidades: 3 resultam em false e 1 em true.\n");
    printf("A interpreta��o da f�rmula ser� false se apenas uma proposi��o for dada como false, o resultado ser� true se as duas proposi��es foram true.\n\n");

    printf("A interpreta��o para duas proposi��es ligadas por implica��o possi 4 possibilidades: 3 resultam em true e 1 em false.\n");
    printf("A interpreta��o da f�rmula ser� false somente se a proposi��o que est� implicando for true e a sua consequente for false.\n");
    printf("A interpreta��o para duas proposi��es ligadas por biimplica��o possi 4 possibilidades: 2 resultam em true e 2 em false.\n");
    printf("A interpreta��o da f�rmula ser� false somente se o valor verdade true ou false serem diferentes para ambas as proposi��es.\n\n");

    printf("Fim do conte�do.");
    system("pause");
    system("cls");
}

void cont_tema2()
{
    setlocale(LC_ALL, "Portuguese");
    printf("Os predicados na l�gica de predicados , diferente da l�gica proposicional, leva em considera��o os termos(vari�veis e fun��es) para representar e assim validar uma senten�a.\n");
    printf("Uma vez que uma vari�vel ou fun��o tiver aridade nula,ou seja,for zero-�ria ,pode-se chamar esse termo de constante.\n");
    printf("Se um predicado tiver aridade nula, ou seja,zero-�rio( que n�o possui termo algum) ele pode ser chamado de proposi��o.\n");
    printf("S�o �tomos apenas os s�mbolos verdade, predicados e proposi��es.\n");
    printf("Termos n�o s�o considerados f�rmula e ,como toda f�rmula � �tomo, termos n�o s�o �tomos.\n\n");

    printf("Existem 6 tipos de s�mbolos na l�gica de predicados sendo eles:\n");
    printf("S�mbolos de pontua��o:( ), s�mbolos de verdade: (false), s�mbolos para vari�veis: x,y,z,w,x1...,s�mbolos para fun��es: f,g,h,f1..., s�mbolos para predicados: p,q,r,p1..., s�mbolos para conectivos: �, v, A(de cabe�a para baixo),3.\n");
    printf("Nesse tipo de l�gica, existem 2 novos tipos de conectivos que s�o levados em conta al�m dos que existem na l�gica proposicional: para todo e o existencial(existe ao menos um).\n");

    printf("Na sente�a 'Todos os pol�ticos s�o desonestos' � poss�vel escrev�-la na l�gica de predicados  como: para todo(A de cabe�a par baixo)x (p(x)->�q(x)) .\n");
    printf("p= � pol�tico     q= � honesto  .\n\n");

    printf("Fim do conte�do.");
    system("pause");
    system("cls");
}

void cont_tema3()
{
    setlocale(LC_ALL, "Portuguese");
    printf("Os m�todos de vali��o da l�gica proposicional servem para determinar se uma f�rmula � de fato tautol�gica(completamente verdadeira) ou n�o.\n");
    printf("Existem tr�s tipos de m�todos o da tabela verdade, da �rvore sem�ntica e o da nega��o(redu��o ao absurdo).\n\n");

    printf("O m�todo da tabela verdade verifica cada possibilidade da seten�a ser verdadeira ou falsa atribuindo �s proposi��es principais(subf�rmulas at�micas) s�mbolos de verdade ou falsidade para que ent�o verifique se ela � de fato tautol�gica.\n");
    printf("A quantidade de linhas de uma tabela-verdade � igual a 2 eleveado a N, pois as subf�rmulas at�micas s� possuem 2 tipos de resultados: true ou false.\n");

    printf("O m�todo da nega��o ele parte de uma seten�a falsa para que se determine se toda a f�rmula � tautol�gica ou n�o.\n");
    printf("Caso seja poss�vel achar falsidade na seten�a sem entrar em contradi��es, como o absurdo(duas interpreta��es diferentes para a mesma subf�rmula at�mica),a seten�a n�o ser� uma tautologia.");

    printf("O m�todo da �rvore sem�ntica parte do mesmo princ�pio da tabela verdade,apenas se diferencia na abordagem da valida��o.As interpreta��es s�o representadas como folhas ou n�s.\n");
    printf("Enquanto o m�todo da tabela-verdade parte das subf�rmulas at�micas, o da �rvore sem�ntica parte das poss�veis interpreta��es para assim atribuir valor verdade para as proposi��es.\n\n");

    printf("Fim do conte�do.");
    system("pause");
    system("cls");
}

int tema1(int flag_tema1, int *nota, int acertos[][9])
{
    int streak = 0; // sequ�ncia de acertos
    char res1_1[5] = " ", res1_2[5] = " ", res1_3[5] = " ", res1_4[5] = " ", res1_5[5] = " ";
    char res1_6[5] = " ", res1_7[5] = " ", res1_8[5] = " ", res1_9[5] = " "; // respostas para cada pergunta

    if (flag_tema1 == 1)
    {
        printf("Este tema j� foi respondido. Por favor escolha outro tema ou encerre os question�rios.\n\n");
        return 1;
    }
    else
    {
        system("cls");
        printf("A seguir ser�o apresentados os exerc�cios de L�gica proposicional:\n\n");

        while ((strcmp(res1_1, "1") != 0) && (strcmp(res1_1, "2") != 0))
        {
            printf("Exerc�cio 1.1: As proposi��es da L�gica proposicional podem ser representados pelas letras min�sculas p,q,r,s,p1... VERDADEIRO ou FALSO ?\n");
            printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
            fgets(res1_1, 3, stdin);
            res1_1[strcspn(res1_1, "\n")] = '\0'; // remove o caractere de nova linha
            fflush(stdin);
            if ((strcmp(res1_1, "1") != 0) && (strcmp(res1_1, "2") != 0))
                printf("Resposta inv�lida. Por favor escolha uma op��o v�lida para sua resposta.\n\n");
        }

        if (strcmp(res1_1, "1") == 0)
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
            nota[0] += calc_nota(streak);
        }

        while ((strcmp(res1_2, "1") != 0) && (strcmp(res1_2, "2") != 0))
        {
            printf("Exerc�cio 1.2: Uma proposi��o da L�gica proposicional n�o pode ser encerrada com ponto de interroga��o. VERDADEIRO ou FALSO ?\n");
            printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
            fgets(res1_2, 3, stdin);
            res1_2[strcspn(res1_2, "\n")] = '\0'; // remove o caractere de nova linha
            fflush(stdin);
            if ((strcmp(res1_2, "1") != 0) && (strcmp(res1_2, "2") != 0))
                printf("Resposta inv�lida. Por favor escolha uma op��o v�lida para sua resposta.\n\n");
        }

        if (strcmp(res1_2, "1") == 0)
        {
            printf("Resposta Correta. Uma proposi��o em forma de senten�a n�o pode terminar com ponto de interroga��o, uma vez que ela deve ter um valor l�gico TRUE ou FALSE.\n\n");
            acertos[0][1] = 1;
            streak++;
            nota[0] += calc_nota(streak);
        }
        else
        {
            printf("Resposta Incorreta. Uma proposi��o em forma de senten�a n�o pode terminar com ponto de interroga��o, uma vez que ela deve ter um valor l�gico TRUE ou FALSE.\n\n");
            acertos[0][1] = 0;
            streak = 0;
        }

        do
        {
            printf("Exerc�cio 1.3: No total quantos tipos de s�mbolos existem na L�gica proposicional.\n");
            fgets(res1_3, 3, stdin);
            res1_3[strcspn(res1_3, "\n")] = '\0'; // remove o caractere de nova linha
            fflush(stdin);
            if (verifica_string(res1_3) == 0)
                printf("Resposta Inv�lida. Por favor digite 0 ou um valor positivo.\n");

        }
        while (verifica_string(res1_3) == 0);

        if (strcmp(res1_3, "4") == 0)
        {
            printf("Resposta Correta. Existem 4 tipos de s�mbolos sendo eles : s�mbolos de pontua��o (), s�mbolos de verdade( T, F ), s�mbolos proposicionais( P, Q, R, S...), conectivos proposicionais(~, v, ^, ->, <->). \n\n");
            acertos[0][2] = 1;
            streak++;
            nota[0] += calc_nota(streak);
        }
        else
        {
            printf("Resposta Incorreta. Existem 4 tipos de s�mbolos sendo eles : s�mbolos de pontua��o (), s�mbolos de verdade( T, F ), s�mbolos proposicionais( P, Q, R, S...), conectivos proposicionais(~, v, ^, ->, <->). \n\n");
            acertos[0][2] = 0;
            streak = 0;
        }

        while ((strcmp(res1_4, "1") != 0) && (strcmp(res1_4, "2") != 0))
        {
            printf("Exerc�cio 1.4: Todo s�mbolo de verdade � uma f�rmula. VERDADEIRO ou FALSO ?\n");
            printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
            fgets(res1_4, 3, stdin);
            res1_4[strcspn(res1_4, "\n")] = '\0'; // remove o caractere de nova linha
            fflush(stdin);
            if ((strcmp(res1_4, "1") != 0) && (strcmp(res1_4, "2") != 0))
                printf("Resposta inv�lida. Por favor escolha uma op��o v�lida para sua resposta.\n\n");
        }

        if (strcmp(res1_4, "1") == 0)
        {
            printf("Resposta Correta. Todo s�mbolo de verdade � uma f�rmula e todo s�mbolo proposicional � uma f�rmula.\n\n");
            acertos[0][3] = 1;
            streak++;
            nota[0] += calc_nota(streak);
        }
        else
        {
            printf("Resposta Incorreta. Todo s�mbolo de verdade � uma f�rmula e todo s�mbolo proposicional � uma f�rmula.\n\n");
            acertos[0][3] = 0;
            streak = 0;
        }

        while ((strcmp(res1_5, "1") != 0) && (strcmp(res1_5, "2") != 0))
        {
            printf("Exerc�cio 1.5: O comprimento de uma f�rmula funciona da seguinte maneira: s�mbolo de verdade = +1 comprimento, s�mbolo proposicional = +1 comprimento, conectivo proposicional = +1 comprimento, s�mbolos de pontua��o = +1 comprimento.\n");
            printf("VERDADEIRO ou FALSO ?\n");
            printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
            fgets(res1_5, 3, stdin);
            res1_5[strcspn(res1_5, "\n")] = '\0'; // remove o caractere de nova linha
            fflush(stdin);
            if ((strcmp(res1_5, "1") != 0) && (strcmp(res1_5, "2") != 0))
                printf("Resposta inv�lida. Por favor escolha uma op��o v�lida para sua resposta.\n\n");
        }

        if (strcmp(res1_5, "1") == 0)
        {
            printf("Resposta Incorreta. Os s�mbolos de verdade, s�mbolos proposicionais e conectivos proposicionais possuem +1 de comprimento, por�m os s�mbolos de pontua��o n�o mudam o comprimento de uma f�rmula.\n\n");
            acertos[0][4] = 0;
            streak = 0;
        }
        else
        {
            printf("Resposta Correta. Os s�mbolos de verdade, s�mbolos proposicionais e conectivos proposicionais possuem +1 de comprimento, por�m os s�mbolos de pontua��o n�o mudam o comprimento de uma f�rmula.\n\n");
            acertos[0][4] = 1;
            nota[0] += calc_nota(streak);
        }

        do
        {
            printf("Exerc�cio 1.6: Em uma f�rmula com duas proposi��es distintas e um conectivo implica as ligando, quantas possibilidades existem para a interpreta��o dessa f�rmula ser FALSA ?\n");
            fgets(res1_6, 3, stdin);
            res1_6[strcspn(res1_5, "\n")] = '\0'; // remove o caractere de nova linha
            fflush(stdin);
            if (verifica_string(res1_6) == 0)
                printf("Resposta inv�lida. Por favor digite um valor positivo ou zero.\n\n");

        }
        while (verifica_string(res1_6) == 0);

        if (strcmp(res1_6, "1") == 0)
        {
            printf("Resposta Correta. A �nica poss�bilidade para a f�rmula ser falsa � a primeira proposi��o sendo VERDADEIRA e a segunda proposi��o sendo FALSA.\n");
            printf("Exemplo: H = (P -> Q), para H ser FALSO P deve ser VERDADEIRO e Q deve ser FALSO.\n\n");
            acertos[0][5] = 1;
            streak++;
            nota[0] += calc_nota(streak);
        }
        else
        {
            printf("Resposta Incorreta. A �nica poss�bilidade para a f�rmula ser falsa � a primeira proposi��o sendo VERDADEIRA e a segunda proposi��o sendo FALSA.\n");
            printf("Exemplo: H = (P -> Q), para H ser FALSO P deve ser VERDADEIRO e Q deve ser FALSO.\n\n");
            acertos[0][5] = 0;
            streak = 0;
        }

        while ((strcmp(res1_7, "1") != 0) && (strcmp(res1_7, "2") != 0))
        {
            printf("Exerc�cio 1.7: Uma f�rmula H � tautologia se existe pelo menos uma interpreta��o VERDADEIRA para ela. VERDADEIRO ou FALSO ?\n");
            printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
            fgets(res1_7, 3, stdin);
            res1_7[strcspn(res1_7, "\n")] = '\0'; // remove o caractere de nova linha
            fflush(stdin);
            if ((strcmp(res1_7, "1") != 0) && (strcmp(res1_7, "2") != 0))
                printf("Resposta inv�lida. Por favor escolha uma op��o v�lida para sua resposta.\n\n");
        }

        if (strcmp(res1_7, "1") == 0)
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
            nota[0] += calc_nota(streak);
        }

        while ((strcmp(res1_8, "1") != 0) && (strcmp(res1_8, "2") != 0))
        {
            printf("Exerc�cio 1.8: Considerando as f�rmulas H = (P v Q), G = P, � correto dizer que H |= P . VERDADEIRO ou FALSO ?\n");
            printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
            fgets(res1_8, 3, stdin);
            res1_8[strcspn(res1_8, "\n")] = '\0'; // remove o caractere de nova linha
            fflush(stdin);
            if ((strcmp(res1_8, "1") != 0) && (strcmp(res1_8, "2") != 0))
                printf("Resposta inv�lida. Por favor escolha uma op��o v�lida para sua resposta.\n\n");
        }

        if (strcmp(res1_8, "1") == 0)
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
            nota[0] += calc_nota(streak);
        }

        while ((strcmp(res1_9, "1") != 0) && (strcmp(res1_9, "2") != 0))
        {
            printf("Exerc�cio 1.9: Uma f�rmula H n�o � satisfat�vel se, e somente se, H for contradit�ria. VERDADEIRO ou FALSO ?\n");
            printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
            fgets(res1_9, 3, stdin);
            res1_9[strcspn(res1_9, "\n")] = '\0'; // remove o caractere de nova linha
            fflush(stdin);
            if ((strcmp(res1_9, "1") != 0) && (strcmp(res1_9, "2") != 0))
                printf("Resposta inv�lida. Por favor escolha uma op��o v�lida para sua resposta.\n\n");
        }

        if (strcmp(res1_9, "1") == 0)
        {
            printf("Resposta Correta. Uma f�rmula n�o satisfat�vel s� possui interpreta��es FALSAS, logo ela tamb�m � uma f�rmula contradit�ria.\n\n");
            acertos[0][8] = 1;
            streak++;
            nota[0] += calc_nota(streak);
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
        return 0;
    }
}

void tema2(int flag_tema2, int *nota, int acertos[][9])
{
    int resposta_2[6] = {0, 0, 0, 0, 0, 0};
    int streak = 0;

    if (flag_tema2 == 0)
    {
        system("cls");
        printf("A seguir ser�o apresentados os exerc�cios sobre l�gica de predicados:\n\n");

        while (resposta_2[0] <= 0)
        {
            printf("Exercicio 2.1: Na logica de predicados existem quantos tipos de simbolos?\n");
            scanf("%d", &resposta_2[0]);
            fflush(stdin);
            if (resposta_2[0] <= 0)
            {
                printf("Resposta invalida. Por favor digite um numero maior que zero.\n\n");
            }
        }

        if (resposta_2[0] == 6)
        {
            printf("Resposta Correta. Existem 6 tipos sendo eles: simbolos de pontuacao:( ), simbolos de verdade: (false), simbolos para variaveis: x,y,z,w,x1..., \nsimbolos para funcoes: f,g,h,f1..., simbolos para predicados: p,q,r,p1..., simbolos para conectivos: �, ?, ?, ?.\n\n");
            acertos[1][0] = 1;
            streak++;
            nota[1] += calc_nota(streak);
        }
        else
        {
            printf("Resposta Incorreta. Existem 6 tipos sendo eles: simbolos de pontuacao:( ), simbolos de verdade: (false), simbolos para variaveis: x,y,z,w,x1..., \nsimbolos para funcoes: f,g,h,f1..., simbolos para predicados: p,q,r,p1..., simbolos para conectivos: �, ?, ?, ?.\n\n");
            acertos[1][0] = 0;
            streak = 0;
        }

        while (resposta_2[1] != 1 && resposta_2[1] != 2)
        {
            printf("Exercicio 2.2: Um predicado de argumento zero(K = 0), ou seja, aridade nula, e considerado uma proposi��o. VERDADEIRO ou FALSO ?\n");
            printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
            scanf("%d", &resposta_2[1]);
            fflush(stdin);
            if (resposta_2[1] != 1 && resposta_2[1] != 2)
            {
                printf("Resposta invalida. Por favor escolha uma opcao valida para sua resposta.\n\n");
            }
        }

        if (resposta_2[1] == 1)
        {
            printf("Resposta Correta. Todo predicado de argumento zero e uma proposicao.\n\n");
            acertos[1][1] = 1;
            streak++;
            nota[1] += calc_nota(streak);
        }
        else
        {
            printf("Resposta Incorreta. Todo predicado de argumento zero e uma proposicao.\n\n");
            acertos[1][1] = 0;
            streak = 0;
        }

        printf("Exerc�cio 2.3: Uma fun��o de argumento zero (K = 0), ou seja, aridade nula, continua sendo considerada uma fun��o. VERDADEIRO ou FALSO?\n");
        printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
        scanf("%d", &resposta_2[2]);
        fflush(stdin);
        if (resposta_2[2] != 1 && resposta_2[2] != 2)
        {
            printf("Resposta inv�lida. Por favor escolha uma op��o v�lida para sua resposta.\n\n");
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
            nota[1] += calc_nota(streak);
        }
        while (resposta_2[3] != 1 && resposta_2[3] != 2)
        {
            printf("Exerc�cio 2.4: Vari�veis, constantes e fun��es s�o consideradas �tomos. VERDADEIRO ou FALSO?\n");
            printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
            scanf("%d", &resposta_2[3]);
            fflush(stdin);
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
            nota[1] += calc_nota(streak);
        }

        while (resposta_2[4] != 1 && resposta_2[4] != 2)
        {
            printf("Exerc�cio 2.5: Todo �tomo � f�rmula. VERDADEIRO ou FALSO ?\n");
            printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
            scanf("%d", &resposta_2[4]);
            fflush(stdin);
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
            nota[1] += calc_nota(streak);
        }
        else
        {
            printf("Resposta Incorreta. Todo �tomo(s�mbolo verdade, predicado ou proposi��o) � uma f�rmula.\n\n");
            acertos[1][4] = 0;
            streak = 0;
        }

        while (resposta_2[5] != 1 && resposta_2[5] != 2)
        {
            printf("Exerc�cio 2.6: Considerando a senten�a a seguir: Nenhum le�o � manso. \nEla pode ser escrita na l�gica de predicados da seguinte maneira: Ax ( p(x) -> �q(x) )      Sendo p= � le�o, q= � manso\n");
            printf("VERDADEIRO ou FALSO ?\n");
            printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
            scanf("%d", &resposta_2[5]);
            fflush(stdin);
            if (resposta_2[5] != 1 && resposta_2[5] != 2)
            {
                printf("Resposta inv�lida. Por favor escolha uma op��o v�lida para sua resposta.\n\n");
            }
        }

        if (resposta_2[5] == 1)
        {
            printf("Resposta Correta. A senten�a foi transcrita para l�gica de predicados perfeitamente.\n\n");
            acertos[1][5] = 1;
            streak++;
            nota[1] += calc_nota(streak);
        }
        else
        {
            printf("Resposta Incorreta. A senten�a foi transcrita para l�gica de predicados perfeitamente.\n\n");
            acertos[1][5] = 1;
            streak++;
            nota[1] += calc_nota(streak);
        }
        printf("Question�rio do tema 1 encerrado.\n");
        system("pause");
        system("cls");
    }
    else
    {
        printf("Este tema j� foi respondido. Por favor escolha outro tema ou encerre os question�rios.\n\n");
    }
}

int tema3(int flag_tema3, int *nota, int acertos[][9])
{
    int streak = 0;                                         // sequ�ncia de acertos
    char res3_1[5] = " ", res3_2[5] = " ", res3_3[5] = " "; // respostas para cada pergunta

    if (flag_tema3 == 1)
    {
        printf("Este tema j� foi respondido. Por favor escolha outro tema ou encerre os question�rios.\n\n");
        return 1;
    }
    else
    {
        system("cls");
        printf("A seguir ser�o apresentados os exerc�cios sobre m�todos de valida��o da l�gica proposicional:\n\n");

        while ((strcmp(res3_1, "1") != 0) && (strcmp(res3_1, "2") != 0))
        {
            printf("Exerc�cio 3.1: No m�todo de valida��o da tabela-verdade a quantidade de linhas � igual a 3 elevado a N, sendo N o n�mero de subf�rmulas at�micas. VERDADEIRO ou FALSO ?\n");
            printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
            fgets(res3_1, 3, stdin);
            res3_1[strcspn(res3_1, "\n")] = '\0'; // remove o caractere de nova linha
            fflush(stdin);
            if ((strcmp(res3_1, "1") != 0) && (strcmp(res3_1, "2") != 0))
            {
                printf("Resposta inv�lida. Por favor escolha uma op��o v�lida para sua resposta.\n\n");
            }
        }

        if (strcmp(res3_1, "1") == 0)
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
            nota[2] += calc_nota(streak);
        }

        while ((strcmp(res3_2, "1") != 0) && (strcmp(res3_2, "2") != 0))
        {
            printf("Exerc�cio 3.2: Caso algu�m utilize o m�todo da nega��o em uma f�rmula e na primeira possibilidade encontre um absurdo, ela poder� afirmar que aquela f�rmula � uma tautologia. VERDADEIRO ou FALSO ?\n");
            printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
            fgets(res3_2, 3, stdin);
            res3_2[strcspn(res3_2, "\n")] = '\0'; // remove o caractere de nova linha
            fflush(stdin);
            if ((strcmp(res3_2, "1") != 0) && (strcmp(res3_2, "2") != 0))
            {
                printf("Resposta inv�lida. Por favor escolha uma op��o v�lida para sua resposta.\n\n");
            }
        }

        if (strcmp(res3_2, "1") == 0)
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
            nota[2] += calc_nota(streak);
        }

        while ((strcmp(res3_3, "1") != 0) && (strcmp(res3_3, "2") != 0))
        {
            printf("Exerc�cio 3.3: Se as folhas de uma �rvore sem�ntica estiverem todas rotuladas com F, ent�o a f�rmula que est� sendo analisada � contradit�ria. VERDADEIRO ou FALSO ?\n");
            printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
            fgets(res3_3, 3, stdin);
            res3_3[strcspn(res3_3, "\n")] = '\0'; // remove o caractere de nova linha
            fflush(stdin);
            if ((strcmp(res3_3, "1") != 0) && (strcmp(res3_3, "2") != 0))
            {
                printf("Resposta inv�lida. Por favor escolha uma op��o v�lida para sua resposta.\n\n");
            }
        }

        if (strcmp(res3_3, "1") == 0)
        {
            printf("Resposta Correta. Quando todas folhas da �rvore sem�ntica estiverem rotuladas com F todas as interpreta��es para aquela f�rmula s�o FALSAS, o que configura esta f�rmula como contradit�ria.\n\n");
            acertos[2][2] = 1;
            streak++;
            nota[2] += calc_nota(streak);
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
        return 0;
    }
}

void matrizAcerto(int acertos[3][9])
{
    int i, j = 0, tema = 0;
    for (i = 0; i < 3; i++)
    {
        printf("\n");
        printf("Tema %d  ", tema + 1);
        tema++;
        for (j = 0; j < 9; j++)
        {
            if (acertos[i][j] == 2)
            {
                printf(" \t");
            }
            if (acertos[i][j] == 1)
            {
                printf("Quest�o %d.%d: C\t", i + 1, j + 1);
            }
            if (acertos[i][j] == 0)
            {
                printf("Quest�o %d.%d: E\t", i + 1, j + 1);
            }
        }
    }
}

#endif

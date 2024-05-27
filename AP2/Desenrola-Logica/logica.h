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
    printf("AVISO IMPORTANTE :Utilize o prompt em tela cheia para obter a experiência correta.\nCom o prompt em tela cheia aperte qualquer tecla para prosseguir.\n");
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

    printf("Nesta plataforma você poderá testar seus conhecimentos em Lógica Computacional por meio de questionários sobre diferentes temas.\n");
    printf("É importante ressaltar que o conteúdo de Lógica Computacional apresentado no Desenrola é baseado nas produções do autor João Nunes de Souza.\n");
    printf("Funcionará da seguinte forma: A cada resposta certa você receberá 10 pontos porém, caso acerte respostas em sequência, seu streak aumentará.\n");
    printf("A cada acerto seu streak aumenta em 1 e a questão sempre valerá : (10 x streak).\n");
    system("pause");
    system("cls");
}

int validaCPF(char cpf[])
{
    int i, j, digito1 = 0, digito2 = 0;
    if (strlen(cpf) != 11) // se o cpf tiver tamanho diferente de 11 ele é invalido
        return 0;
    else if ((strcmp(cpf, "00000000000") == 0) || (strcmp(cpf, "11111111111") == 0) || (strcmp(cpf, "22222222222") == 0) ||
             (strcmp(cpf, "33333333333") == 0) || (strcmp(cpf, "44444444444") == 0) || (strcmp(cpf, "55555555555") == 0) ||
             (strcmp(cpf, "66666666666") == 0) || (strcmp(cpf, "77777777777") == 0) || (strcmp(cpf, "88888888888") == 0) ||
             (strcmp(cpf, "99999999999") == 0))
        return 0; // se o CPF tiver todos os números iguais ele é inválido.
    else
    {
        // digito 1---------------------------------------------------
        for (i = 0, j = 10; i < strlen(cpf) - 2; i++, j--) /// multiplica os números de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i] - 48) * j;
        digito1 %= 11;
        if (digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if ((cpf[9] - 48) != digito1)
            return 0; /// se o digito 1 não for o mesmo que o da validação o CPF é inválido
        else
            /// digito 2--------------------------------------------------
        {
            for (i = 0, j = 11; i < strlen(cpf) - 1; i++, j--) /// multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                digito2 += (cpf[i] - 48) * j;
            digito2 %= 11;
            if (digito2 < 2)
                digito2 = 0;
            else
                digito2 = 11 - digito2;
            if ((cpf[10] - 48) != digito2)
                return 0; /// se o digito 2 não for o mesmo que o da validação CPF é inválido
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
    getchar(); // consome o caractere de nova linha após a leitura do inteiro
    fflush(stdin);

    printf("\nInforme seu CPF: ");
    do
    {
        scanf("%[^\n]s", &usuario->CPF);
        fflush(stdin);
        if (validaCPF(usuario->CPF) == 0)
        {
            printf("\nPor favor, insira um CPF válido:\n");
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
    printf("A lógica proposicional é a forma mais simples de lógica. Nela os fatos do mundo real são representados por sentenças sem argumentos,chamadas de proposições.\n");
    printf("Essas proposições devem ser representadas por letras maiúsculas das quais normalmente são utilizadas P,Q,R e S.\n\n");

    printf("O alfabeto da Lógica Proposicional é constituído por 4 símbolos:\n");
    printf("Símbolos de pontuação (; );símbolos de verdade: true, false;símbolos proposicionais(P; Q; R; S; P1; Q1; R1; S1; P2; Q2; ...);Conectivos proposicionais( ^, <->, v, ¬,->).\n\n");

    printf("Ao relacionar sentenças, deve-se usar conectivos para que a nova proposição formada por tais sentenças seja representada na lógica proposicional.\n\n");

    printf("Existem 4 conectivos na lógicas proposicional: o de disjunção(v), conjunção(^), implicação(->) e o de biimplicação(<->).\n\n");

    printf("Podemos então representar uma proposição 'Hoje está nublado' ou 'Hoje está seco' como P v Q.\n\n");

    printf("As sentenção NUNCA devem ser terminadas com símbolos não objetivos,como o de interrogação.\n");
    printf("Além de proposições,sentenças podem também ser representadas por símbolos verdade(true,false),os quais são fórmulas.\n");

    printf("Toda fórmula possui um comprimento.Os símbolos de verdade, símbolos proposicionais e conectivos proposicionais possuem +1 de comprimento.\n");
    printf("Os símbolos de pontuação não mudam o comprimento de uma fórmula.\n");

    printf("Ao validar fórmulas de duas proposições ligadas por conectivos, é necessário atribuir à tais proposições símbolos verdade(true ou false) para verificar se a interpretação resulta em true ou false.\n");

    printf("Caso TODAS as interpretações da fórmula resultarem em uma verdade,ela é definida por tautologia.\n");
    printf("Se todas as interpretações resultarem em falsidade, a fórmula é denominada contraditória.\n");

    printf("Caso haja ao menos uma interpretação true da fórmula, ela é denominada satisfatível. Caso haja ao menos uma interpretação true e uma false, a fórmula é denominada contingente.\n");

    printf("Uma proposição implica semanticamente em outra somente se a interpretação da biimplicação entre elas for tautológica.\n");
    printf("A denotação para implicação semântica é |= .\n\n");

    printf("A interpretação para duas proposições ligas por disjução possui 4 possibilidaes: 3 resultam em true e 1 em false.\n");
    printf("Caso apenas uma proposição delas for verdade,a intepretação da fórmula é verdade.\n\n");

    printf("A interpretação para duas proposições ligadas por conjunção possi 4 possibilidades: 3 resultam em false e 1 em true.\n");
    printf("A interpretação da fórmula será false se apenas uma proposição for dada como false, o resultado será true se as duas proposições foram true.\n\n");

    printf("A interpretação para duas proposições ligadas por implicação possi 4 possibilidades: 3 resultam em true e 1 em false.\n");
    printf("A interpretação da fórmula será false somente se a proposição que está implicando for true e a sua consequente for false.\n");
    printf("A interpretação para duas proposições ligadas por biimplicação possi 4 possibilidades: 2 resultam em true e 2 em false.\n");
    printf("A interpretação da fórmula será false somente se o valor verdade true ou false serem diferentes para ambas as proposições.\n\n");

    printf("Fim do conteúdo.");
    system("pause");
    system("cls");
}

void cont_tema2()
{
    setlocale(LC_ALL, "Portuguese");
    printf("Os predicados na lógica de predicados , diferente da lógica proposicional, leva em consideração os termos(variáveis e funções) para representar e assim validar uma sentença.\n");
    printf("Uma vez que uma variável ou função tiver aridade nula,ou seja,for zero-ária ,pode-se chamar esse termo de constante.\n");
    printf("Se um predicado tiver aridade nula, ou seja,zero-ário( que não possui termo algum) ele pode ser chamado de proposição.\n");
    printf("São átomos apenas os símbolos verdade, predicados e proposições.\n");
    printf("Termos não são considerados fórmula e ,como toda fórmula é átomo, termos não são átomos.\n\n");

    printf("Existem 6 tipos de símbolos na lógica de predicados sendo eles:\n");
    printf("Símbolos de pontuação:( ), símbolos de verdade: (false), símbolos para variáveis: x,y,z,w,x1...,símbolos para funções: f,g,h,f1..., símbolos para predicados: p,q,r,p1..., símbolos para conectivos: ¬, v, A(de cabeça para baixo),3.\n");
    printf("Nesse tipo de lógica, existem 2 novos tipos de conectivos que são levados em conta além dos que existem na lógica proposicional: para todo e o existencial(existe ao menos um).\n");

    printf("Na senteça 'Todos os políticos são desonestos' é possível escrevê-la na lógica de predicados  como: para todo(A de cabeça par baixo)x (p(x)->¬q(x)) .\n");
    printf("p= é político     q= é honesto  .\n\n");

    printf("Fim do conteúdo.");
    system("pause");
    system("cls");
}

void cont_tema3()
{
    setlocale(LC_ALL, "Portuguese");
    printf("Os métodos de valição da lógica proposicional servem para determinar se uma fórmula é de fato tautológica(completamente verdadeira) ou não.\n");
    printf("Existem três tipos de métodos o da tabela verdade, da árvore semêntica e o da negação(redução ao absurdo).\n\n");

    printf("O método da tabela verdade verifica cada possibilidade da setença ser verdadeira ou falsa atribuindo às proposições principais(subfórmulas atômicas) símbolos de verdade ou falsidade para que então verifique se ela é de fato tautológica.\n");
    printf("A quantidade de linhas de uma tabela-verdade é igual a 2 eleveado a N, pois as subfórmulas atômicas só possuem 2 tipos de resultados: true ou false.\n");

    printf("O método da negação ele parte de uma setença falsa para que se determine se toda a fórmula é tautológica ou não.\n");
    printf("Caso seja possível achar falsidade na setença sem entrar em contradições, como o absurdo(duas interpretações diferentes para a mesma subfórmula atômica),a setença não será uma tautologia.");

    printf("O método da árvore semântica parte do mesmo princípio da tabela verdade,apenas se diferencia na abordagem da validação.As interpretações são representadas como folhas ou nós.\n");
    printf("Enquanto o método da tabela-verdade parte das subfórmulas atômicas, o da árvore semântica parte das possíveis interpretações para assim atribuir valor verdade para as proposições.\n\n");

    printf("Fim do conteúdo.");
    system("pause");
    system("cls");
}

int tema1(int flag_tema1, int *nota, int acertos[][9])
{
    int streak = 0; // sequência de acertos
    char res1_1[5] = " ", res1_2[5] = " ", res1_3[5] = " ", res1_4[5] = " ", res1_5[5] = " ";
    char res1_6[5] = " ", res1_7[5] = " ", res1_8[5] = " ", res1_9[5] = " "; // respostas para cada pergunta

    if (flag_tema1 == 1)
    {
        printf("Este tema já foi respondido. Por favor escolha outro tema ou encerre os questionários.\n\n");
        return 1;
    }
    else
    {
        system("cls");
        printf("A seguir serão apresentados os exercícios de Lógica proposicional:\n\n");

        while ((strcmp(res1_1, "1") != 0) && (strcmp(res1_1, "2") != 0))
        {
            printf("Exercício 1.1: As proposições da Lógica proposicional podem ser representados pelas letras minúsculas p,q,r,s,p1... VERDADEIRO ou FALSO ?\n");
            printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
            fgets(res1_1, 3, stdin);
            res1_1[strcspn(res1_1, "\n")] = '\0'; // remove o caractere de nova linha
            fflush(stdin);
            if ((strcmp(res1_1, "1") != 0) && (strcmp(res1_1, "2") != 0))
                printf("Resposta inválida. Por favor escolha uma opção válida para sua resposta.\n\n");
        }

        if (strcmp(res1_1, "1") == 0)
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
            nota[0] += calc_nota(streak);
        }

        while ((strcmp(res1_2, "1") != 0) && (strcmp(res1_2, "2") != 0))
        {
            printf("Exercício 1.2: Uma proposição da Lógica proposicional não pode ser encerrada com ponto de interrogação. VERDADEIRO ou FALSO ?\n");
            printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
            fgets(res1_2, 3, stdin);
            res1_2[strcspn(res1_2, "\n")] = '\0'; // remove o caractere de nova linha
            fflush(stdin);
            if ((strcmp(res1_2, "1") != 0) && (strcmp(res1_2, "2") != 0))
                printf("Resposta inválida. Por favor escolha uma opção válida para sua resposta.\n\n");
        }

        if (strcmp(res1_2, "1") == 0)
        {
            printf("Resposta Correta. Uma proposição em forma de sentença não pode terminar com ponto de interrogação, uma vez que ela deve ter um valor lógico TRUE ou FALSE.\n\n");
            acertos[0][1] = 1;
            streak++;
            nota[0] += calc_nota(streak);
        }
        else
        {
            printf("Resposta Incorreta. Uma proposição em forma de sentença não pode terminar com ponto de interrogação, uma vez que ela deve ter um valor lógico TRUE ou FALSE.\n\n");
            acertos[0][1] = 0;
            streak = 0;
        }

        do
        {
            printf("Exercício 1.3: No total quantos tipos de símbolos existem na Lógica proposicional.\n");
            fgets(res1_3, 3, stdin);
            res1_3[strcspn(res1_3, "\n")] = '\0'; // remove o caractere de nova linha
            fflush(stdin);
            if (verifica_string(res1_3) == 0)
                printf("Resposta Inválida. Por favor digite 0 ou um valor positivo.\n");

        }
        while (verifica_string(res1_3) == 0);

        if (strcmp(res1_3, "4") == 0)
        {
            printf("Resposta Correta. Existem 4 tipos de símbolos sendo eles : símbolos de pontuação (), símbolos de verdade( T, F ), símbolos proposicionais( P, Q, R, S...), conectivos proposicionais(~, v, ^, ->, <->). \n\n");
            acertos[0][2] = 1;
            streak++;
            nota[0] += calc_nota(streak);
        }
        else
        {
            printf("Resposta Incorreta. Existem 4 tipos de símbolos sendo eles : símbolos de pontuação (), símbolos de verdade( T, F ), símbolos proposicionais( P, Q, R, S...), conectivos proposicionais(~, v, ^, ->, <->). \n\n");
            acertos[0][2] = 0;
            streak = 0;
        }

        while ((strcmp(res1_4, "1") != 0) && (strcmp(res1_4, "2") != 0))
        {
            printf("Exercício 1.4: Todo símbolo de verdade é uma fórmula. VERDADEIRO ou FALSO ?\n");
            printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
            fgets(res1_4, 3, stdin);
            res1_4[strcspn(res1_4, "\n")] = '\0'; // remove o caractere de nova linha
            fflush(stdin);
            if ((strcmp(res1_4, "1") != 0) && (strcmp(res1_4, "2") != 0))
                printf("Resposta inválida. Por favor escolha uma opção válida para sua resposta.\n\n");
        }

        if (strcmp(res1_4, "1") == 0)
        {
            printf("Resposta Correta. Todo símbolo de verdade é uma fórmula e todo símbolo proposicional é uma fórmula.\n\n");
            acertos[0][3] = 1;
            streak++;
            nota[0] += calc_nota(streak);
        }
        else
        {
            printf("Resposta Incorreta. Todo símbolo de verdade é uma fórmula e todo símbolo proposicional é uma fórmula.\n\n");
            acertos[0][3] = 0;
            streak = 0;
        }

        while ((strcmp(res1_5, "1") != 0) && (strcmp(res1_5, "2") != 0))
        {
            printf("Exercício 1.5: O comprimento de uma fórmula funciona da seguinte maneira: símbolo de verdade = +1 comprimento, símbolo proposicional = +1 comprimento, conectivo proposicional = +1 comprimento, símbolos de pontuação = +1 comprimento.\n");
            printf("VERDADEIRO ou FALSO ?\n");
            printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
            fgets(res1_5, 3, stdin);
            res1_5[strcspn(res1_5, "\n")] = '\0'; // remove o caractere de nova linha
            fflush(stdin);
            if ((strcmp(res1_5, "1") != 0) && (strcmp(res1_5, "2") != 0))
                printf("Resposta inválida. Por favor escolha uma opção válida para sua resposta.\n\n");
        }

        if (strcmp(res1_5, "1") == 0)
        {
            printf("Resposta Incorreta. Os símbolos de verdade, símbolos proposicionais e conectivos proposicionais possuem +1 de comprimento, porém os símbolos de pontuação não mudam o comprimento de uma fórmula.\n\n");
            acertos[0][4] = 0;
            streak = 0;
        }
        else
        {
            printf("Resposta Correta. Os símbolos de verdade, símbolos proposicionais e conectivos proposicionais possuem +1 de comprimento, porém os símbolos de pontuação não mudam o comprimento de uma fórmula.\n\n");
            acertos[0][4] = 1;
            nota[0] += calc_nota(streak);
        }

        do
        {
            printf("Exercício 1.6: Em uma fórmula com duas proposições distintas e um conectivo implica as ligando, quantas possibilidades existem para a interpretação dessa fórmula ser FALSA ?\n");
            fgets(res1_6, 3, stdin);
            res1_6[strcspn(res1_5, "\n")] = '\0'; // remove o caractere de nova linha
            fflush(stdin);
            if (verifica_string(res1_6) == 0)
                printf("Resposta inválida. Por favor digite um valor positivo ou zero.\n\n");

        }
        while (verifica_string(res1_6) == 0);

        if (strcmp(res1_6, "1") == 0)
        {
            printf("Resposta Correta. A única possíbilidade para a fórmula ser falsa é a primeira proposição sendo VERDADEIRA e a segunda proposição sendo FALSA.\n");
            printf("Exemplo: H = (P -> Q), para H ser FALSO P deve ser VERDADEIRO e Q deve ser FALSO.\n\n");
            acertos[0][5] = 1;
            streak++;
            nota[0] += calc_nota(streak);
        }
        else
        {
            printf("Resposta Incorreta. A única possíbilidade para a fórmula ser falsa é a primeira proposição sendo VERDADEIRA e a segunda proposição sendo FALSA.\n");
            printf("Exemplo: H = (P -> Q), para H ser FALSO P deve ser VERDADEIRO e Q deve ser FALSO.\n\n");
            acertos[0][5] = 0;
            streak = 0;
        }

        while ((strcmp(res1_7, "1") != 0) && (strcmp(res1_7, "2") != 0))
        {
            printf("Exercício 1.7: Uma fórmula H é tautologia se existe pelo menos uma interpretação VERDADEIRA para ela. VERDADEIRO ou FALSO ?\n");
            printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
            fgets(res1_7, 3, stdin);
            res1_7[strcspn(res1_7, "\n")] = '\0'; // remove o caractere de nova linha
            fflush(stdin);
            if ((strcmp(res1_7, "1") != 0) && (strcmp(res1_7, "2") != 0))
                printf("Resposta inválida. Por favor escolha uma opção válida para sua resposta.\n\n");
        }

        if (strcmp(res1_7, "1") == 0)
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
            nota[0] += calc_nota(streak);
        }

        while ((strcmp(res1_8, "1") != 0) && (strcmp(res1_8, "2") != 0))
        {
            printf("Exercício 1.8: Considerando as fórmulas H = (P v Q), G = P, é correto dizer que H |= P . VERDADEIRO ou FALSO ?\n");
            printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
            fgets(res1_8, 3, stdin);
            res1_8[strcspn(res1_8, "\n")] = '\0'; // remove o caractere de nova linha
            fflush(stdin);
            if ((strcmp(res1_8, "1") != 0) && (strcmp(res1_8, "2") != 0))
                printf("Resposta inválida. Por favor escolha uma opção válida para sua resposta.\n\n");
        }

        if (strcmp(res1_8, "1") == 0)
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
            nota[0] += calc_nota(streak);
        }

        while ((strcmp(res1_9, "1") != 0) && (strcmp(res1_9, "2") != 0))
        {
            printf("Exercício 1.9: Uma fórmula H não é satisfatível se, e somente se, H for contraditória. VERDADEIRO ou FALSO ?\n");
            printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
            fgets(res1_9, 3, stdin);
            res1_9[strcspn(res1_9, "\n")] = '\0'; // remove o caractere de nova linha
            fflush(stdin);
            if ((strcmp(res1_9, "1") != 0) && (strcmp(res1_9, "2") != 0))
                printf("Resposta inválida. Por favor escolha uma opção válida para sua resposta.\n\n");
        }

        if (strcmp(res1_9, "1") == 0)
        {
            printf("Resposta Correta. Uma fórmula não satisfatível só possui interpretações FALSAS, logo ela também é uma fórmula contraditória.\n\n");
            acertos[0][8] = 1;
            streak++;
            nota[0] += calc_nota(streak);
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
        printf("A seguir serão apresentados os exercícios sobre lógica de predicados:\n\n");

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
            printf("Resposta Correta. Existem 6 tipos sendo eles: simbolos de pontuacao:( ), simbolos de verdade: (false), simbolos para variaveis: x,y,z,w,x1..., \nsimbolos para funcoes: f,g,h,f1..., simbolos para predicados: p,q,r,p1..., simbolos para conectivos: ¬, ?, ?, ?.\n\n");
            acertos[1][0] = 1;
            streak++;
            nota[1] += calc_nota(streak);
        }
        else
        {
            printf("Resposta Incorreta. Existem 6 tipos sendo eles: simbolos de pontuacao:( ), simbolos de verdade: (false), simbolos para variaveis: x,y,z,w,x1..., \nsimbolos para funcoes: f,g,h,f1..., simbolos para predicados: p,q,r,p1..., simbolos para conectivos: ¬, ?, ?, ?.\n\n");
            acertos[1][0] = 0;
            streak = 0;
        }

        while (resposta_2[1] != 1 && resposta_2[1] != 2)
        {
            printf("Exercicio 2.2: Um predicado de argumento zero(K = 0), ou seja, aridade nula, e considerado uma proposição. VERDADEIRO ou FALSO ?\n");
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

        printf("Exercício 2.3: Uma função de argumento zero (K = 0), ou seja, aridade nula, continua sendo considerada uma função. VERDADEIRO ou FALSO?\n");
        printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
        scanf("%d", &resposta_2[2]);
        fflush(stdin);
        if (resposta_2[2] != 1 && resposta_2[2] != 2)
        {
            printf("Resposta inválida. Por favor escolha uma opção válida para sua resposta.\n\n");
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
            nota[1] += calc_nota(streak);
        }
        while (resposta_2[3] != 1 && resposta_2[3] != 2)
        {
            printf("Exercício 2.4: Variáveis, constantes e funções são consideradas átomos. VERDADEIRO ou FALSO?\n");
            printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
            scanf("%d", &resposta_2[3]);
            fflush(stdin);
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
            nota[1] += calc_nota(streak);
        }

        while (resposta_2[4] != 1 && resposta_2[4] != 2)
        {
            printf("Exercício 2.5: Todo átomo é fórmula. VERDADEIRO ou FALSO ?\n");
            printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
            scanf("%d", &resposta_2[4]);
            fflush(stdin);
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
            nota[1] += calc_nota(streak);
        }
        else
        {
            printf("Resposta Incorreta. Todo átomo(símbolo verdade, predicado ou proposição) é uma fórmula.\n\n");
            acertos[1][4] = 0;
            streak = 0;
        }

        while (resposta_2[5] != 1 && resposta_2[5] != 2)
        {
            printf("Exercício 2.6: Considerando a sentença a seguir: Nenhum leão é manso. \nEla pode ser escrita na lógica de predicados da seguinte maneira: Ax ( p(x) -> ¬q(x) )      Sendo p= é leão, q= é manso\n");
            printf("VERDADEIRO ou FALSO ?\n");
            printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
            scanf("%d", &resposta_2[5]);
            fflush(stdin);
            if (resposta_2[5] != 1 && resposta_2[5] != 2)
            {
                printf("Resposta inválida. Por favor escolha uma opção válida para sua resposta.\n\n");
            }
        }

        if (resposta_2[5] == 1)
        {
            printf("Resposta Correta. A sentença foi transcrita para lógica de predicados perfeitamente.\n\n");
            acertos[1][5] = 1;
            streak++;
            nota[1] += calc_nota(streak);
        }
        else
        {
            printf("Resposta Incorreta. A sentença foi transcrita para lógica de predicados perfeitamente.\n\n");
            acertos[1][5] = 1;
            streak++;
            nota[1] += calc_nota(streak);
        }
        printf("Questionário do tema 1 encerrado.\n");
        system("pause");
        system("cls");
    }
    else
    {
        printf("Este tema já foi respondido. Por favor escolha outro tema ou encerre os questionários.\n\n");
    }
}

int tema3(int flag_tema3, int *nota, int acertos[][9])
{
    int streak = 0;                                         // sequência de acertos
    char res3_1[5] = " ", res3_2[5] = " ", res3_3[5] = " "; // respostas para cada pergunta

    if (flag_tema3 == 1)
    {
        printf("Este tema já foi respondido. Por favor escolha outro tema ou encerre os questionários.\n\n");
        return 1;
    }
    else
    {
        system("cls");
        printf("A seguir serão apresentados os exercícios sobre métodos de validação da lógica proposicional:\n\n");

        while ((strcmp(res3_1, "1") != 0) && (strcmp(res3_1, "2") != 0))
        {
            printf("Exercício 3.1: No método de validação da tabela-verdade a quantidade de linhas é igual a 3 elevado a N, sendo N o número de subfórmulas atômicas. VERDADEIRO ou FALSO ?\n");
            printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
            fgets(res3_1, 3, stdin);
            res3_1[strcspn(res3_1, "\n")] = '\0'; // remove o caractere de nova linha
            fflush(stdin);
            if ((strcmp(res3_1, "1") != 0) && (strcmp(res3_1, "2") != 0))
            {
                printf("Resposta inválida. Por favor escolha uma opção válida para sua resposta.\n\n");
            }
        }

        if (strcmp(res3_1, "1") == 0)
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
            nota[2] += calc_nota(streak);
        }

        while ((strcmp(res3_2, "1") != 0) && (strcmp(res3_2, "2") != 0))
        {
            printf("Exercício 3.2: Caso alguém utilize o método da negação em uma fórmula e na primeira possibilidade encontre um absurdo, ela poderá afirmar que aquela fórmula é uma tautologia. VERDADEIRO ou FALSO ?\n");
            printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
            fgets(res3_2, 3, stdin);
            res3_2[strcspn(res3_2, "\n")] = '\0'; // remove o caractere de nova linha
            fflush(stdin);
            if ((strcmp(res3_2, "1") != 0) && (strcmp(res3_2, "2") != 0))
            {
                printf("Resposta inválida. Por favor escolha uma opção válida para sua resposta.\n\n");
            }
        }

        if (strcmp(res3_2, "1") == 0)
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
            nota[2] += calc_nota(streak);
        }

        while ((strcmp(res3_3, "1") != 0) && (strcmp(res3_3, "2") != 0))
        {
            printf("Exercício 3.3: Se as folhas de uma árvore semântica estiverem todas rotuladas com F, então a fórmula que está sendo analisada é contraditória. VERDADEIRO ou FALSO ?\n");
            printf("Digite 1 para VERDADEIRO ou 2 para FALSO.\n");
            fgets(res3_3, 3, stdin);
            res3_3[strcspn(res3_3, "\n")] = '\0'; // remove o caractere de nova linha
            fflush(stdin);
            if ((strcmp(res3_3, "1") != 0) && (strcmp(res3_3, "2") != 0))
            {
                printf("Resposta inválida. Por favor escolha uma opção válida para sua resposta.\n\n");
            }
        }

        if (strcmp(res3_3, "1") == 0)
        {
            printf("Resposta Correta. Quando todas folhas da árvore semântica estiverem rotuladas com F todas as interpretações para aquela fórmula são FALSAS, o que configura esta fórmula como contraditória.\n\n");
            acertos[2][2] = 1;
            streak++;
            nota[2] += calc_nota(streak);
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
                printf("Questão %d.%d: C\t", i + 1, j + 1);
            }
            if (acertos[i][j] == 0)
            {
                printf("Questão %d.%d: E\t", i + 1, j + 1);
            }
        }
    }
}

#endif

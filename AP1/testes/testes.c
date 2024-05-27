#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int menu,menu2,menu3,menu4,menu5,menu6,menu7,i,respostac[5],resposta,k,cont,ncont,y;
    respostac[0]=-9;
    respostac[1]=-1;
    respostac[2]=7;
    respostac[3]=4;
    respostac[4]=5;
    char correcao[5][150]={"A resposta da questão é a própria constante","Apenas substitua o valor de x no limite","Semelhante a última questão, apenas substitua o valor de x no limite e realize o cálculo","Você precisa usar técnicas de fataroção de polinômios:(a^2+b^2)*(a^2-b^2)=(a^2-b^2)","Para esta questão você deve usar a divisão de polinômios, dica:se um número (a) é raiz de um polinômio, esse polinômio é divisível por x-a"};
    char questoes[10][25]={"lim -9=","x->6","lim 2x-5=","x->2","lim (3x^2+2)/x=","x->2", "lim (x^2-4)/(x-2)=","x->2","lim (x^2-x-6)/(x-3)=","x->3"};
    k=0;
    cont=0;
    ncont=2;
    
    do{
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
    printf("                                               _______________\n");
    printf("                                              |1-Para Iniciar |\n");
    printf("                                              |_______________|\n");
     printf("                                              |0-Para Encerrar|\n");
    printf("                                              |_______________|\n");
    scanf("%d",&menu);
    switch(menu){
        case 1:
         do{
            system("clear"); 
    printf("#   ########     #######   #######   #######   ###      ##   ########      ########    ##              ###\n");
    printf("#   ##      ##   #######   #######   #######   ####     ##   ##      ##   ##      ##   ##             ## ##\n");
    printf("#   ##      ##   ##        ##        ##        ## ##    ##   ##      ##   ##      ##   ##            ##   ##\n");
    printf("#   ##      ##   #######   #######   #######   ##  ##   ##   ##########   ##      ##   ##           ##     ##\n");
    printf("#   ##      ##   #######   #######   #######   ##   ##  ##   ########     ##      ##   ##          ###########\n");
    printf("#   ##      ##   ##             ##   ##        ##    ## ##   ##      ##   ##      ##   ##         ##         ##\n");
    printf("#   ##      ##   #######   #######   #######   ##     ####   ##      ##   ##      ##   ######    ##           ##\n");
    printf("#   ########     #######   #######   #######   ##      ###   ##      ##    ########    ######   ##             ##\n");
    printf("                                               ___________________ \n");
    printf("                                              |1-Para Pré cálculo |\n");
    printf("                                              |___________________|\n");
    printf("                                               ___________________ \n");
    printf("                                              |2-Para cálculo     |\n");
    printf("                                              |___________________|\n");
     printf("                                               ___________________ \n");
    printf("                                              |3-Para Geometria   |\n");
    printf("                                              |     Analitica     |\n");
    printf("                                              |___________________|\n");
      printf("                                               ___________________ \n");
    printf("                                              |0-Para Voltar      |\n");
    printf("                                              |___________________|\n");
             scanf("%d",&menu2);
              switch(menu2){
                do{
                    case 1:
                     system("clear");
                     printf("Nada aqui por enquanto\n");
                     scanf("%d",&menu3);
                      break;
                    case 2:
                     do{
                        system("clear");
            printf("#   ########     #######   #######   #######   ###      ##   ########      ########    ##              ###\n");
            printf("#   ##      ##   #######   #######   #######   ####     ##   ##      ##   ##      ##   ##             ## ##\n");
            printf("#   ##      ##   ##        ##        ##        ## ##    ##   ##      ##   ##      ##   ##            ##   ##\n");
            printf("#   ##      ##   #######   #######   #######   ##  ##   ##   ##########   ##      ##   ##           ##     ##\n");
            printf("#   ##      ##   #######   #######   #######   ##   ##  ##   ########     ##      ##   ##          ###########\n");
            printf("#   ##      ##   ##             ##   ##        ##    ## ##   ##      ##   ##      ##   ##         ##         ##\n");
            printf("#   ##      ##   #######   #######   #######   ##     ####   ##      ##   ##      ##   ######    ##           ##\n");
            printf("#   ########     #######   #######   #######   ##      ###   ##      ##    ########    ######   ##             ##\n");
                     printf("                                               ___________________ \n");
                     printf("                                              |1-Para Calculo 1   |\n");
                     printf("                                              |___________________|\n");
                     printf("                                               ___________________ \n");
                     printf("                                              |2-Para Calculo 2   |\n");
                     printf("                                              |___________________|\n");
                     printf("                                               ___________________ \n");
                     printf("                                              |3-Para Calculo 3   |\n");
                     printf("                                              |___________________|\n");
                     printf("                                               ___________________ \n");
                     printf("                                              |4-Para Calculo 4   |\n");
                     printf("                                              |___________________|\n");
                     printf("                                               ___________________ \n");
                     printf("                                              |0-Para Voltar      |\n");
                     printf("                                              |___________________|\n");
                     scanf("%d",&menu4);
                      switch(menu4){
                         do{
                          system("clear");
                            case 1:
                            do{
                            system("clear");
                            printf("          #   ########    #######   #      #  #########  ########  #      #  ###       ########\n");
                            printf("          #   ##         #       #  ##     #  #########  ########  #      #  #  #     #        #\n");
                            printf("          #   ##         #       #  # #    #     ###     ##        #      #  #   #    #        #\n");
                            printf("          #   ##         #       #  #  #   #     ###     ########  #      #  #    #   #        #\n");
                            printf("          #   ##         #       #  #   #  #     ###     ########  #      #  #     #  #        #\n");
                            printf("          #   ##         #       #  #    # #     ###     ##        #      #  #     #  #        #\n");
                            printf("          #   ##         #       #  #     ##     ###     ########  #      #  #     #  #        #\n");
                            printf("          #   ########    #######   #      #     ###     ########  ########  #######   ########\n");
                            printf("                                             ________________________ \n");
                            printf("                                            |1-Limites Indeterminados|\n");
                            printf("                                            |________________________|\n");
                            printf("                                             ________________________ \n");
                            printf("                                            |2-Limites no infinito   |\n");
                            printf("                                            |________________________|\n");
                            printf("                                             ________________________ \n");
                            printf("                                            |3-Limites Laterais      |\n");
                            printf("                                            |________________________|\n");
                            printf("                                             ________________________ \n");
                            printf("                                            |4-Limites infinitos     |\n");
                            printf("                                            |________________________|\n");
                            printf("                                             ________________________ \n");
                            printf("                                            |5-Continuidade          |\n");
                            printf("                                            |________________________|\n");
                            printf("                                             ________________________ \n");
                            printf("                                            |6-Mudanca de Variavel   |\n");
                            printf("                                            |________________________|\n");
                            printf("                                             ________________________ \n");
                            printf("                                            |7-Limite Fundamental    |\n");
                            printf("                                            |________________________|\n");
                            printf("                                             ________________________ \n");
                            printf("                                            |8-Teorema do Confronto  |\n");
                            printf("                                            |________________________|\n");
                            printf("                                             ________________________ \n");
                            printf("                                            |0-Para Voltar           |\n");
                            printf("                                            |________________________|\n");
                      scanf("%d",&menu6);
                       switch(menu6){
                           case 1:
                            while(k<5){
                            system("clear");
                            printf("Questão Número %d:\n",k+1);
                            for (i = cont; i<ncont; i++){
                            printf ("%s\n", questoes[i]);}
                            scanf("%d",&resposta);
                            if(resposta==respostac[k]){
                                printf("Parabéns! Você acertou!\n");
                                k++;
                                cont = cont + 2;
                                ncont = ncont + 2;
                            }else{
                                printf("Você errou, deseja ver a correcao?\n");
                                printf("1 para sim ou 2 para ir para a próxima questao\n");
                                 scanf("%d",&resposta);
                                  if(resposta==1){
                                    for (i = 0; i < 1; i ++){
                                    printf ("%s\n", correcao[k]);
                                    printf("Pronto para ir para a próxima questao?\n");
                                    scanf("%d",&y);
                                    k++;
                                    cont = cont + 2;
                                    ncont = ncont + 2;
                                    } 
                                  }else{
                                    k++;
                                    cont = cont + 2;
                                    ncont = ncont + 2;
                                  }
                             }
                            }
                            scanf("%d",&menu7);
                             break;
                           case 2:
                            system("clear");
                            printf("Nada aqui por enquanto\n");
                            scanf("%d",&menu7);
                             break;
                           case 3:
                            system("clear");
                            printf("Nada aqui por enquanto\n");
                            scanf("%d",&menu7);
                             break;
                           case 4:
                            system("clear");
                            printf("Nada aqui por enquanto\n");
                            scanf("%d",&menu7);
                             break;
                           case 5:
                            system("clear");
                            printf("Nada aqui por enquanto\n");
                            scanf("%d",&menu7);
                             break;
                           case 6:
                            system("clear");
                            printf("Nada aqui por enquanto\n");
                            scanf("%d",&menu7);
                             break;
                           case 7:
                            system("clear");
                            printf("Nada aqui por enquanto\n");
                            scanf("%d",&menu7);
                             break;
                           case 8:
                            system("clear");
                            printf("Nada aqui por enquanto\n");
                            scanf("%d",&menu7);
                             break;
                           case 0:
                             break;
                           
                       }
                            }while(menu6!=0);
                              break;
                            case 2:
                             system("clear");
                             printf("Nada aqui por enquanto\n");
                             scanf("%d",&menu5);
                              break;
                            case 3:
                             system("clear");
                             printf("Nada aqui por enquanto\n");
                             scanf("%d",&menu5);
                              break;
                            case 4:
                             system("clear");
                             printf("Nada aqui por enquanto\n");
                             scanf("%d",&menu5);
                              break;
                            case 0:
                              break;
                        }while(menu5!=0);
                       }
                      }while(menu4!=0);
                      break;
                    case 3:
                     system("clear");
                     printf("Nada aqui por enquanto\n");
                     scanf("%d",&menu3);
                      break;
                    case 0:
                     break;
                }while(menu3!=0);  
              }
         }while(menu2!=0);
         system("clear");
         break;
        case 0:
        printf("Até a próxima!");
         break;
       }
    }while(menu!=0);
 return 0;
}

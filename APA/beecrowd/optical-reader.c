#include <stdio.h>
#include <string.h>


int main() {
    //black <= 127
    //white > 127
    //mais de um x ou nenhum x (desconsida questão)

    int t = 1; // número de t estradas (questões)
    int letter[5];

    do{
        scanf("%d", &t);
        for(int i = 0; i < t; i++){
            scanf("%d %d %d %d %d", &letter[0], &letter[1], &letter[2], &letter[3], &letter[4]);

            int marked = -1; // nenhuma letra marcada
            int flag_marked = 0; //nenhuma letra marcada

            for(int j = 0; j < 5; j++){
                if(letter[j] <= 127){ // questão marcada
                    marked = j;
                    flag_marked++;
                }
            }

            if(flag_marked != 1)
                printf("*\n"); //questão anulada, mais de uma letra marcada
            else
            {
                switch (marked)
                {
                case -1:
                    printf("*\n"); //questão anulada, nenhuma letra marcada
                    break;
                case 0:
                    printf("A\n");
                    break;
                case 1:
                    printf("B\n");
                    break;
                case 2:
                    printf("C\n");
                    break;
                case 3:
                    printf("D\n");
                    break;
                case 4:
                    printf("E\n");
                    break;
                default:
                    printf("?\n");
                    break;
                }
            }

        }
    }while(t != 0);

    return 0;
}

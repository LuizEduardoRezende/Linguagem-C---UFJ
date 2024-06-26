#include <stdio.h>
#include <math.h>

int main() {
    //Mary always choose Head = 0
    //John always choose Tail = 1
    int t; //quantidade t de entradas (jogos)

    while(t != 0){
        scanf("%d", &t); 
        if(t == 0)
            break;

        int coin = -1;
        int mary_w = 0;
        int john_w = 0;

        for(int i = 0; i <  t; i++){
            scanf("%d", &coin); 
            if(coin == 0)
                mary_w++;
            else
                john_w++;
        }

        printf("Mary won %d times and John won %d times\n", mary_w, john_w);

    };

    return 0;
}

#include <stdio.h>
#include <math.h>

int main() {
    int t; //quantidade t de entradas
    scanf("%d", &t); 

    //Dabriel Pomekon -> 0
    //Guarte Pokemon -> 1

    int b; //bonus value
    int Ai[2]; //attack 
    int Di[2]; //defense
    int Li[2]; //level of the pokemon master
    float value[2]; //total pontuation of the pokemon

    for(int i = 0; i < t; i++){
        scanf("%d", &b);
        scanf("%d %d %d", &Ai[0], &Di[0], &Li[0]);
        scanf("%d %d %d", &Ai[1], &Di[1], &Li[1]);

        value[0] = (Ai[0] + Di[0]) / 2;
        value[1] = (Ai[1] + Di[1]) / 2;

        if(Li[0] % 2 == 0) // se o level for par recebe o bônus
            value[0] += b;

        if(Li[1] % 2 == 0) // se o level for par recebe o bônus
            value[1] += b;

        if(value[0] > value[1])
            printf("Dabriel\n");
        else{
            if(value[0] == value[1])
                printf("Empate\n");
            else
                printf("Guarte\n");
        }
        
    }

    return 0;
}

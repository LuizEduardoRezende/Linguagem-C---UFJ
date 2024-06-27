#include <stdio.h>
#include <string.h>
#define T 3

int main(){

    /*For each shot, KiloMan can either (stand still) or (jump)
    stand still:
        shot <= 2  ---- hit
        shot > 2   ---- miss
    jump:
        shot > 2   ---- hit
        shot < 2   ---- miss

    input:
        N -- test cases
        S -- number of shots
        1 2 3 4 5 6 7 6 1 3 -- heights of the shots
        JSJJJSSS -- action of the KiloMan
    output:
        number of times he got hit
    */

    int n;
    int n_shots;

    scanf("%d", &n); // test cases
    while (n--)
    {
        //number of shots
        scanf("%d", &n_shots); 

        //array of shots
        int shots[n_shots]; 
        fgets(shots, sizeof(shots), stdin);
        shots[strcspn(shots, "\n")] = '\0';

        //actions
        int actions[n_shots];
        scanf("%s", actions);

        int hits;

    }

    return 0;
}

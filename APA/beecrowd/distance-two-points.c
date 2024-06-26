#include <stdio.h>
#include <math.h>

int main() {
    float p1[2];
    float p2[2];

    for(int i = 0; i < 2; i++){
        scanf("%f", &p1[i]);
    }

    for(int i = 0; i < 2; i++){
        scanf("%f", &p2[i]);
    }

    float distance = sqrt( pow((p2[0] - p1[0]),2) + pow((p2[1] - p1[1]),2));
    printf("%.4f\n", distance);

    return 0;
}

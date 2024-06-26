#include <stdio.h>

int main() {
    long long int R, G, B;
    scanf("%llx", &R);
    scanf("%llx", &G);
    scanf("%llx", &B);

    long long int red_labels = 1;
    long long int green_stickers = (R / G) * (R / G); 
    long long int blue_stickers_per_green = (G / B) * (G / B);

    long long int total_labels = red_labels + green_stickers + (blue_stickers_per_green * green_stickers);
    printf("%llx\n", total_labels);

    return 0;
}

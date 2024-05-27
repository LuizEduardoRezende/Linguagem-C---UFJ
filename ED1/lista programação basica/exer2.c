#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>


int main(){
    int n = 0, i = 0;

    printf("Digite o numero n para saber os n primeiros numeros impares.\n");
    scanf("%d", &n);
    fflush(stdin);

    for( i = 0; i <= n; i++){
        if( (i%2) != 0)
            printf("%d\n", i);
    }
    

    return 0;
}

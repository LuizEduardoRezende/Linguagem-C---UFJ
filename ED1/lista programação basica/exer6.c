#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>


int main(){
    char seq[50];
    char seq_inversa[50];
    int j = 0;

    printf("Digite uma sequenia de numeros:\n");
    scanf("%[^\n]s", seq);
    fflush(stdin);

    for(int i = strlen(seq) - 1; i >= 0; i--)
    {
        seq_inversa[j] = seq[i];
        j++;
    }

    printf("Sequencia inversa: %s", seq_inversa);
    
    return 0;
}

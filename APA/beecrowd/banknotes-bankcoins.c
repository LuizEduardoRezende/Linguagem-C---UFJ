#include <stdio.h>
#define TAM_N 6
#define TAM_M 6

int main() {
    int notas_val[TAM_N] = {100, 50, 20, 10, 5, 2}; //notas disponiveis
    float moedas_val[TAM_M] = {1.00, 0.50, 0.25, 0.10, 0.05, 0.01}; //moedas disponiveis:

    int notas_quant[TAM_N] = {0, 0, 0, 0, 0, 0};
    int moedas_quant[TAM_M] = {0, 0, 0, 0, 0, 0};

    float saque;
    scanf("%f", &saque); 

    //calculando notas
    for(int i = 0; i < TAM_N; i++){
        //enquanto o saque for maior que a nota atual, vai usando 1 nota dessa
        while(saque >= notas_val[i]){
            notas_quant[i]++;
            saque -= notas_val[i];
        }
    }

    //calculando moedas
    for(int i = 0; i < TAM_M; i++){
        //enquanto o saque for maior que a moeda atual, vai usando 1 moeda dessa
        while(saque >= moedas_val[i]){
            moedas_quant[i]++;
            saque -= moedas_val[i];
        }        
    }

    //printando notas
    printf("NOTAS:\n");
    for(int i = 0; i < TAM_N; i++){
        printf("%d nota(s) de R$ %d.00\n", notas_quant[i], notas_val[i]);
    }

    //printando moedas
    printf("MOEDAS:\n");
    for(int i = 0; i < TAM_M; i++){
        printf("%d moedas(s) de R$ %.2f\n", notas_quant[i], moedas_val[i]);
    }

    return 0;
}

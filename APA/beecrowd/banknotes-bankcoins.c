#include <stdio.h>
#define TAM_N 6
#define TAM_M 6

int main() {
    //notas disponiveis: 100, 50, 20, 10, 5, 2
    //moedas disponiveis: 1, 50, 25, 10, 5, 1

    int notas_val[TAM_N] = {10000, 5000, 2000, 1000, 500, 200}; //notas disponiveis em centavos
    int moedas_val[TAM_M] = {100, 50, 25, 10, 5, 1}; //moedas disponiveis em centavos

    int notas_quant[TAM_N] = {0, 0, 0, 0, 0, 0};
    int moedas_quant[TAM_M] = {0, 0, 0, 0, 0, 0};

    float saque;
    scanf("%f", &saque); 
    int saque_centavos = (int)(saque * 100 + 0.5); // Converte para centavos e arredonda

    //calculando notas
    for(int i = 0; i < TAM_N; i++){
        //enquanto o saque for maior que a nota atual, vai usando 1 nota dessa
        while(saque_centavos >= notas_val[i]){
            notas_quant[i]++;
            saque_centavos -= notas_val[i];
        }
    }

    //calculando moedas
    for(int i = 0; i < TAM_M; i++){
        //enquanto o saque for maior que a moeda atual, vai usando 1 moeda dessa
        while(saque_centavos >= moedas_val[i]){
            moedas_quant[i]++;
            saque_centavos -= moedas_val[i];
        }        
    }

    //printando notas
    printf("NOTAS:\n");
    for(int i = 0; i < TAM_N; i++){
        printf("%d nota(s) de R$ %d.00\n", notas_quant[i], notas_val[i] / 100);
    }

    //printando moedas
    printf("MOEDAS:\n");
    for (int i = 0; i < TAM_M; i++) {
        printf("%d moeda(s) de R$ %.2f\n", moedas_quant[i], moedas_val[i] / 100.0);
    }

    return 0;
}

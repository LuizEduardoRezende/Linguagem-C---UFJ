#include <stdio.h>
#include <stdlib.h>

int main(){
int exer;
printf("Digite o exercicio desejado, de 5 a 8.\n");
scanf("%d",& exer);
    while (exer!=0){
        switch (exer){
        case 5: printf("Exercicio 5.\n");   break;
        case 6: printf("Exercicio 6.\n");   break;
        case 7: printf("Exercicio 7.\n");   break;
        case 8: printf("Exercicio 8.\n");   break;
        default: printf("Exercicio inexistente.\n");   break;
        }
    printf("Digite 0 caso queira encerrar o menu.\n");
    scanf("%d",& exer);
    }
printf("Menu encerrado.\n");

system ("pause");
return 0;
}
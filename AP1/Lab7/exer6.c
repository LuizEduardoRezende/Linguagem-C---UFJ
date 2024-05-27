#include <stdio.h>
#include <stdlib.h>

int main(){
int num, number, fat=1;
printf("Digite um numero para calcular o fatorial.\n");
scanf("%d",& num);
number=num;

    while (num>0){
        fat=fat*(num);
        num--;
    }

printf("O fatorial %d! e: %d\n",number,fat);

system ("pause");
return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(){
   double raio, area;
   printf("Digite um raio para calcular a area do circulo.\n");
   scanf("%lf",& raio);
   area = raio*raio*3.14159;
   
   printf("A=%.4lf\n",area);

system("pause");
return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int anterior = 0, atual = 1, proximo = 1, quant, contador = 1;
    printf("Digite uma quantidade inteira e positiva para receber os primeiros numeros da sequencia de Fibonacci.\n");
    scanf("%d", &quant);
    printf("%d ", atual);

    do
    {
        proximo = atual + anterior;
        anterior = atual;
        atual = proximo;

        printf("%d ", atual);
        contador++;
    } while (contador < quant);
    printf("\n");

    system("pause");
    return 0;
}
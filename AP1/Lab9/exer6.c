#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float x = 0, somatoria = 0;
    int i = 1, n_termos = 0, soma = 0, anterior = 0, proximo = 1;

    for(x=0; x<=0;)         // loop até o usuário digitar valores corretos
    {
        for(n_termos == 0; n_termos<=0;)
        {
            printf("Digite o numero de termos da sequencia.\n");
            scanf("%d", &n_termos);
        }
        printf("Digite um numero positivo X.\n");
        scanf("%f",&x);
    }
    
    for(i = 1; i <=n_termos; i++)
    {
        soma = proximo + anterior;
        anterior = proximo;
        proximo = soma;

        if(i % 2 == 0) // se i for par
        {
            somatoria = somatoria + (pow(x,i+1)/anterior);
        }
        else          // se i for impar
        {
            somatoria = somatoria - (pow(x,i+1)/anterior);
        }

        printf("%d\n", anterior);
    }

    printf("Somatoria = %f\n",somatoria);

    system("pause");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cod = 0, i = 1, j = 0, n_veiculos = 0, n_acidentes = 0, soma_acidentes = 0, media_acidentes = 0, soma_todosveiculos = 0, media_veiculos = 0;
    int menor_n_acidentes = 2e+9, maior_n_acidentes = 0, cod_maior_n_acidentes = 0, cod_menor_n_acidentes = 0;

    for(i = 1; i <= 5; i++)
    {
        printf("\nDigite o codigo da cidade.\n");
        scanf("%d",&cod);
        printf("Digite o numero de veiculos de passeio.\n");
        scanf("%d", &n_veiculos);
        printf("Digite o numero de acidentes.\n");
        scanf("%d", &n_acidentes);

        soma_todosveiculos = soma_todosveiculos + n_veiculos;

        if(n_veiculos < 2000)
        {
            soma_acidentes = soma_acidentes + n_acidentes;
            j++;
        }

        if(n_acidentes < menor_n_acidentes)
        {
            menor_n_acidentes = n_acidentes;
            cod_menor_n_acidentes = cod;
        }

        if(n_acidentes > maior_n_acidentes)
        {
            maior_n_acidentes = n_acidentes;
            cod_maior_n_acidentes = cod;
        }
    }

    media_veiculos = soma_todosveiculos / 5;
    media_acidentes = soma_acidentes / j;


    printf("Maior numero de acidentes: %d Cidade: %d\n", maior_n_acidentes, cod_maior_n_acidentes);
    printf("Menor numero de acidentes: %d Cidade: %d\n\n", menor_n_acidentes, cod_menor_n_acidentes);

    printf("Media do numero de veiculos em todas cidades: %d\n", media_veiculos);
    printf("Media dos acidentes nas cidades com menos de 2000 veiculos: %d\n", media_acidentes);


    system("pause");
    return 0;
}
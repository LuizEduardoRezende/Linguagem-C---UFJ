#include <stdio.h>
#include <stdlib.h>
//aluno: Luiz Eduardo Rezende Moraes

typedef struct NOH{
    int valor;
    struct NOH* proximo;
}*tipo_lista;

tipo_lista criarNOH(int valor){

    tipo_lista novoNOH = (tipo_lista)malloc(sizeof(tipo_lista));

    if(novoNOH == NULL){
        printf("\nErro ao alocar memória.\n");
        return NULL;
    }
    else{
        novoNOH ->valor = valor;
        novoNOH ->proximo = NULL;
        return novoNOH;
    }
}

tipo_lista inserirInico(int valor, tipo_lista inicio){ 

    tipo_lista novoNOH = criarNOH(valor);

    if (inicio == NULL)
    {
        return novoNOH;
    }
    else{
        novoNOH->proximo = inicio;

        return novoNOH;
    }   
}

tipo_lista inserirFinal(int valor, tipo_lista lista){ 

    tipo_lista novoNOH = criarNOH(valor);

    if (lista == NULL)
    {
        return novoNOH;
    }
    else{
    
        tipo_lista listaAuxiliar = lista;

        while(listaAuxiliar->proximo != NULL){

            listaAuxiliar = listaAuxiliar->proximo;
        }

        listaAuxiliar->proximo = novoNOH;
    
        return lista;
    }
    
}

void exibir(tipo_lista lista){
    printf("\n---- LISTA ----\n");

    if(lista == NULL){
        printf("Vazia");
    }
    else{

        tipo_lista listaAuxiliar = lista;

        while(listaAuxiliar != NULL){

            printf("[%d] ",listaAuxiliar->valor);

            listaAuxiliar = listaAuxiliar->proximo;
        }
    }

}

int main() {

    tipo_lista lista = NULL;

    lista = inserirInico(1,lista);
    lista = inserirInico(3,lista);
    lista = inserirInico(6,lista);
    lista = inserirFinal(10,lista);
    lista = inserirFinal(11,lista);
    exibir(lista);




    return 0;
}
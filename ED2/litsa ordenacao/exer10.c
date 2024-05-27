#include <stdio.h>
#include <math.h>

void validaArrumado(int vetor[], float tam){
    int escolhido,flag=0;
    escolhido = ceil(tam/2);
    
    for(int i=0;i<escolhido;i++){
        if(vetor[i]>escolhido){
            flag++;
        }
    }
    
    for(int i=escolhido+1;i<tam;i++){
        if(vetor[i]<escolhido){
            flag++;
        }
    }
    
    if(flag>0){
        printf("Não esta arrumado!");
    }else{
        printf("Está arrumado!");
    }
}

int main(){
    int vetor[7] = {1,5,2,3,32,12,43};
    
    validaArrumado(vetor,6);
    
    return 0; 
}
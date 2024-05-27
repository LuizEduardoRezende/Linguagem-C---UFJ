#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
 
/*Rotina que ser� executada*/
void * routine(void *arg);
 
int main (int argc, char *argv[])
{
 pthread_t thread_id;
 void * thread_res;
 int rstatus;
 char frase[50];

 sprintf(frase, "%s", "Minha primeira thread!");
 
 /*tenta iniciar o thread, indicando a fun��o 'routine' e passando como argumento a string "Minha primeira Thread!"*/
 rstatus = pthread_create (&thread_id, NULL, routine, (void *)frase);
 
 /*verificar se ocorreu algum erro na chamada de pthread_create*/
 if(rstatus != 0)
 {
 printf ("Main> Erro ao criar o thread.\n");
 exit(EXIT_FAILURE);
 }
 
 printf ("Main> Thread criado com sucesso!\n");
 
 /*aguarda finaliza��o do thread identificado por thread_id. O retorno � passado pelo ponteiro thread_res*/
 rstatus = pthread_join (thread_id, &thread_res);
 
 /*verificar se ocorreu algum erro na chamada de pthread_join*/
 if(rstatus != 0)
 {
 printf ("Main> Erro ao aguardar finaliza��o do thread.\n");
 exit(EXIT_FAILURE);
 }
 
 /*exibe o valor de retorno da fun��o 'routine'*/
 printf ("Main> Thread finalizado! Retorno = %s\n", (char *)thread_res);
 
 return 0;
}
 
void * routine(void *arg)
{
 /*exibe o argumento recebido*/
 printf("routine> Argumento passado: %s\n", (char *)arg);
 sprintf((char *)arg, "%s", "My first thread!");
 
 /*finaliza a fun��o retornando o argumento que foi recebido*/
 pthread_exit(arg);
}

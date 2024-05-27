#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
/* o tamanho (em bytes) do objeto de memória compartilhada */
const int SIZE = 4096;
/* nome do objeto de memória compartilhada */
const char *name = "areacomum";
/* strings gravadas na memória compartilhada */
const char *message0 = "Hello";
const char *message1 = "World!";
/* descritor de arquivo da memória compartilhada */
int shm_fd;
/* ponteiro para o objeto de memória compartilhada */
void *ptr;
/* cria o objeto de memória compartilhada */
shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
/* configura o tamanho do objeto de memória compartilhada */
ftruncate(shm_fd, SIZE);
/* mapeia o objeto de memória compartilhada para a memória */
ptr = (char *) mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
/* escreve na memória compartilhada */
sprintf(ptr,"%s",message0);
ptr += strlen(message0);
sprintf(ptr,"%s",message1);
ptr += strlen(message1);
return 0;
}


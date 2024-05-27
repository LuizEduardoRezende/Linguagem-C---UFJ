#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    struct horario
    {
        float hora, minuto, segundo;
    } h;
    typedef struct horario tipohorario;

    struct data
    {
        int dia, mes, ano;
        char mes_escrito[15];
    } d;
    typedef struct data tipodata;


    struct agenda
    {
        tipodata data;
        tipohorario horario;
        struct horario;
        char texto[50];
    }a;

    a.texto[50] ='a';
    a.horario.hora = 5;









    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char user[10] = "", senha[10] = "";
    int i = 0;
    int flag_u = 0, flag_s = 0;

    printf("Digite seu usuário:  ");
    fflush(stdin);
    scanf("%[^\n]s", user);

    printf("Digite sua senha:  ");
    fflush(stdin);
    scanf("%[^\n]s", senha);

    if (strcmp(user,"admin") == 0)
    {
        printf("Nome de usuário correto.\n");
    }

    if (strcmp(senha,"a1b2C3") == 0)
    {
        printf("Senha de usuário correta.\n");
    }

    return 0;
}
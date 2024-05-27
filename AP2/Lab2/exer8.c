#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char user_C[10] = "admin", senha_C[10] = "a1b2C3";
    char user[10] = "", senha[10] = "";
    int i = 0;
    int flag_u = 0, flag_s = 0;

    printf("Digite seu usuário: ");
    scanf("%[^\n]s", user);
    fflush(stdin);

    printf("Digite sua senha: ");
    scanf("%[^\n]s", senha);
    fflush(stdin);

    for (i = 0; i <= 9; i++)
    {
        if (user[i] == user_C[i])
        {
            flag_u++;
        }
    }

    for (i = 0; i <= 9; i++)
    {
        if (senha[i] == senha_C[i])
        {
            flag_s++;
        }
    }

    if (flag_u == 10)
    {
        printf("Nome de usuário correto.\n");
    }

    if (flag_s == 10)
    {
        printf("Senha de usuário correta.\n");
    }

    return 0;
}
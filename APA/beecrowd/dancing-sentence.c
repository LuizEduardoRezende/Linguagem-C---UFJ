#include <stdio.h>
#include <string.h>

int main()
{
    char ch[100];

    int pos = 0; // primeira pos = 0
    // posicao par -> upper
    // posicao impar -> lower

    while (gets(ch) != NULL)
    {
        pos = 0;
        int tamanho = strlen(ch);
        for (int i = 0; i < tamanho; i++)
        {
            if (ch[i] != ' ')                               // Ignorar espaços
            { 
                if ((pos % 2) == 0)                         // posicao par
                {                                                 
                    if (ch[i] >= 'a' && ch[i] <= 'z')       // Letra em minúscula
                        ch[i] -= 32;                        // Converter para maiúscula
                }
                else                                        // posicao impar
                {                                                 
                    if (ch[i] >= 'A' && ch[i] <= 'Z')       // Letra em maiúscula
                        ch[i] += 32;                        // Converter para minúscula
                }
                pos++;
            }
        }
        ch[tamanho] = '\0';
        printf("%s\n", ch);
    }

    return 0;
}

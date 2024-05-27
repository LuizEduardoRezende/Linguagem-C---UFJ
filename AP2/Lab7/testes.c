#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    int V[3] = {10, 20, 30};
    int *ptr;
    ptr = V; // ptr = &V[0];
    printf("%d\t%d\t%d", *ptr, *ptr + 1, *(ptr + 2));

    return 0;
}
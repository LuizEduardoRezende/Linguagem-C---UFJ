#include <stdio.h>
#include <string.h>
#include <locale.h>

int main () {

	char string[50], string2[50], string3[100] = "";

	setlocale (LC_ALL,"");

	printf ("Digite duas strings .\n\nString: ");
	fflush(stdin);
	scanf ("%[^\n]s]", string);
	printf ("String: ");
	fflush(stdin);
	scanf ("%[^\n]s]", string2);
	strcat(string, string2);
	strcpy(string3, string);
	printf ("String concatenada: %s", string3);

	return 0;

}

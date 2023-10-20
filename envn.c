#include "main.h"
/**
 * env - function that print enronment veriables
 * Return: void
 */
int env(void)
{
	int x;
	char nl = '\n';

	for  (x = 0; environ[x] != NULL ; x++)
	{
		write(1, environ[x], _strlen(environ[x]));
	}
	write(1, &nl, 1);
	return (0);
}

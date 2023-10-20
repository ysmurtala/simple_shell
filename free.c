#include "main.h"
/**
 * freeall - function that free every thing
 * @args: pointer that points to a pointer
 * Return: Always 0
 */
int freeall(char **args)
{
	int x;

	if (args == NULL)
	{
		return (0);
	}
	for (x = 0 ; args[x] ; x++)
	{
		if (args[x] != NULL)
		{
			free(args[x]);
		}
	}
	if (args != NULL)
	{
		free(args);
	}
	return (0);
}

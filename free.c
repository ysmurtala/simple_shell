#include "main.h"
/**
 * freeall - function that free every thing
 * @args: pointer that points to a pointer
 */
void freeall(char **args)
{
	int x;

	if (args == NULL)
	{
		return;
	}
	for (x = 0; args[x]; x++)
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
}

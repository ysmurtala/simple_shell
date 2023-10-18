#include "main.h"
/**
 * main - Entry point
 * _child - function call
 * @args: fuction parameter
 * Return: Always 0
 */
void _child(char **args);
int main(void)
{
	int i = 0;
	char *content = NULL;
	size_t size = 0;
	size_t reads = 0;
	char *token = NULL;
	int intractive  = 1;
	char **args;


	while (1)
	{
		intractive = isatty(STDIN_FILENO);
		args = malloc(100 * sizeof(char *));
		if (intractive != 0)
		{
			write(1, "$ ", 2);
			i = 0;
			reads = getline(&content, &size, stdin);
			token = strtok(content, " \n\t\r");
			while (token != NULL)
			{
				args[i] = malloc(sizeof(char) * (_strlen(token) + 1));
				_strcpy(args[i], token);
				i++;
				token = strtok(NULL, " \n\t\r");
			}
			if (i == 0)
			{
				free(args);
				continue;
			}
			args[i] = NULL;
			if (_strcmp(args[0], "exit") == 0)
			{
				freeall(args);
				break;
			}
			if (_strcmp(args[0], "env") == 0)
			{

				env();
				freeall(args);
				continue;
			}
			if (intractive == 0)
				break;

			_child(args);
			if (reads > 1)
			{
				if (args[0] != NULL)
				{
					freeall(args);
				}
			}

		}
	}
	if (content != NULL)
		free(content);

	return (0);
}

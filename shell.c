#include "main.h"
/**
 * main - Entry point
 * _child - function call
 * @args: fuction parameter
 * Return: Always 0
 */
char **init_arg(char *str);
int _child(char **args);
int main(void)
{
	int check;
	char *content = NULL;
	size_t size = 0;
	ssize_t reads;
	int intractive  = 0;
	char **args;


	while (1)
	{
		intractive = isatty(STDIN_FILENO);
		if (intractive != 0)
		{
			write(1, "$ ", 2);
		}
		reads = getline(&content, &size, stdin);
		if (reads == -1)
		{
			break;
		}
		args = init_arg(content);
		if (args == NULL)
		{
			freeall(args);
			continue;
		}
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

		check = _child(args);

		if (intractive == 0)
			break;
		if (check == 0)
			continue;
		if (reads > 1)
		{
			if (args[0] != NULL)
			{
				freeall(args);
			}
		}
		continue;
	}
	if (content != NULL)
		free(content);

	return (0);
}
/**
 * init_arg - function that work non interactive
 * @str: pointer to the string
 * Return: args
 */
char **init_arg(char *str)
{
	int i;
	char *token;
	char **args;

	args = malloc(100 * sizeof(char *));
	i = 0;
	token = strtok(str, " \n\t\r");
	if (token == NULL)
		return (NULL);
	while (token != NULL)
	{
		args[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		_strcpy(args[i], token);
		i++;
		token = strtok(NULL, " \n\t\r");
	}
	args[i] = NULL;
	return (args);
}

#include"main.h"
/**
 * _child - function that create process
 * @args: arguments
 * Return: an integer value
 */
int _child(char **args)
{
	struct stat buffer;
	pid_t pid;

	if (stat(args[0], &buffer) == 0)
	{
		pid = fork();
		if (pid == -1)
		{
			freeall(args);
			perror("./hsh");
			return (0);
		}
		if (pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("./hsh");
				exit(1);
			}
		}
		else
		{
			wait(NULL);
			freeall(args);
			return (0);
		}
	}
	return (handle_pathcmd(args));
}

/**
 * handle_pathcmd - function that handle path command
 * @input: array of pointers
 * Return: an integer value
 */
int handle_pathcmd(char **input)
{
	struct stat buff;
	pid_t pid;
	char *path = malloc(sizeof(char) *
			(_strlen(input[0]) + _strlen("/bin/") + 1));
	_strcpy(path, "/bin/");
	path = _strcat(path, input[0]);


	if (stat(path, &buff) != -1)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("./hsh");
			freeall(input);
			return (0);
		}
		if (pid == 0)
		{
			if (execve(path, input, NULL) == -1)
			{
				perror("./hsh");
				freeall(input);
				exit(1);
			}
		}
		else
		{
			wait(NULL);
			free(path);
			freeall(input);
			return (0);
		}
	}
	perror("./hsh");
	return (1);
}

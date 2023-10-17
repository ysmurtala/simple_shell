#include"main.h"
/**
 * _child - function that create process
 * @args: arguments
 */
void _child(char **args)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execve(args[0], args, environ);
		perror("failure");
		exit(2);
	}
	else if (pid < 0)
	{
		perror("failure");
	}
	else
	{
		wait(&status);
	}
}

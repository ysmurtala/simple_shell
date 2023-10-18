#include"main.h"
/**
 * _child - function that create process
 * @args: arguments
 */
void _child(char **args)
{
	struct stat buffer;
	int status;
	pid_t pid;

	if (stat(args[0], &buffer) == 0)
	{

	pid = fork();
	if (pid == 0)
	{
		execve(args[0], args, environ);
		perror("failed");
		exit(1);
	}
	else if (pid < 0)
	{
		perror("failed");
	}
	else
	{
		wait(&status);
	}
	}
	perror("./hsh");
}

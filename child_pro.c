#include"main.h"
char *_strcat(char *src, char *dest);
char *_getpath(char *input);
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
	char *path;

	path = _getpath(input[0]);
	if (path == NULL)
	{
		perror("./hsh");
		return (1);
	}


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
/**
 * _getpath - function that get path
 * @input: pointer
 * Return: character
 */
char *_getpath(char *input)
{
	char *path;
	char *token;
	char *PATH;
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		path = strdup(environ[i]);
		token = strtok(path, "=:");
		if (strcmp(token, "PATH") == 0)
		{
			for (; token != NULL;)
			{
				if (strcmp(token, "/bin") == 0)
				{
					PATH = _strcat(token, "/");
					PATH = _strcat(PATH, input);
					return (PATH);

				}
				token = strtok(NULL, "=:");
				continue;
			}
			return (NULL);
		}
		free(path);
		continue;
	}
	return (0);
}

/**
 * *_strcat - function that concatinate a string
 * @dest: function parameter
 * @src: function parameter
 * Return: dest
 */
char *_strcat(char *src, char *dest)
{
	int i, j;
	char *new_str;

	new_str = malloc(sizeof(char) * (strlen(src) + strlen(dest) + 1));
	for (i = 0, j = 0;; i++, j++)
	{
		if (src[j] == '\0')
		{
			j = 0;
			new_str[i] = dest[j];
			i++;
			j++;
			for (; dest[j] != '\0'; i++, j++)
			{
				new_str[i] = dest[j];
			}
			new_str[i] = '\0';
			break;
		}
		new_str[i] = src[j];
	}
	return (new_str);
}

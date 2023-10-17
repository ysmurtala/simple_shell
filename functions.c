#include "main.h"
/**
 * _strlen - function that return the length of string
 * @s: string
 * Return: count
 */
int _strlen(char *s)
{
	int x;
	int count = 0;

	for (x = 0 ; s[x] != '\0' ; x++)
		count++;
	return (count);
}
/**
 * *_strcpy - function that copies string pointer including null byte
 * @dest: parametr of the function
 * @src: parameter of the function
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int x;

	for (x = 0 ; src[x] != '\0' ; x++)
		dest[x] = src[x];
	dest[x] = '\0';
	return (dest);
}
/**
 * _strcmp - function that copies a strings
 *
 * @s1: string 1
 * @s2: string 2
 * Return: Always 0
 */
int _strcmp(char *s1, char *s2)
{
	int x;

	for (x = 0 ; s1[x] != '\0' || s2[x] != '\0' ; x++)
	{
		if (s1[x] != s2[x])
		{
			if (s1[x] < s2[x])
				return (s1[x] - s2[x]);
			else if (s2[x] < s1[x])
				return (s1[x] - s2[x]);
		}
	}
	return (0);
}

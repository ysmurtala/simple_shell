#ifndef MAIN_H
#define MAIN_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/stat.h>
char *_strcat(char *dest, char *src);
int handle_pathcmd(char **input);
int sum(void);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _child(char **args);
int freeall(char **args);
int env(void);
extern char **environ;
#endif

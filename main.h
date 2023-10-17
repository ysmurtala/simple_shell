#ifndef MAIN_H
#define MAIN_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int sum(void);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
void _child(char **args);
void freeall(char **args);
void env(void);
extern char **environ;
#endif

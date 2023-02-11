#ifndef MAIN_H
#define MAIN_H

/* define custom macros */
#define MAX_INPUT 4096

/* define needed extern variables */
extern char **environ;

/* include needed standard libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>

/**
 * struct path - replace entered command with path to program for that command
 *
 * @command: command to execute
 * @path: path to the executable program
 */

typedef struct path
{
	char *command;
	char *path;
} put_path;


/* declare function prototypes */
int command_path(char **command);
char **breaker(char *command, int word_count, char **env); // added a new third argument to breaker to to get access to the declared **environ in main.c
char *input_parser(char *input, int *word_count __attribute__((unused)));
void print_env(char **env); /*add new function prototype*/
#endif

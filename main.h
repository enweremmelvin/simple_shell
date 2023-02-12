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
void print_env(char **env);
int check_command(char *command);
int command_path(char **command);
void free_arg(char **arg, int word_count);
int exit_shell(char *command, char *exit_code);
char **breaker(char *command, int word_count, char **env);
int check_input_mode(char **arg, char *fcommand, int word_count);
char *input_parser(char *input, int *word_count __attribute__((unused)));

#endif

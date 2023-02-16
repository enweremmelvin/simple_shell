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

/**
 * struct custom_commands - check if command is recognized
 *
 * @command: command to check for
 * @handle_function: function to handle given command
 */
typedef struct custom_commands
{
	char *command;
	void (*handle_function)(char **arg);
} btn_cmd;


/* declare function prototypes */
int check_command(char *command);
int command_path(char **command);
void call_execve(char **arg, int i);
void free_arg(char **arg, int word_count);
int check_separator(char **arg, int word_count);
char **breaker(char *command, int word_count, char **env);
int builtin_command(char **arg, char **env, int word_count);
int check_input_mode(char **arg, char *fcommand, int word_count);
ssize_t _getline(char **buffer_add, size_t *length, int fd_read);
char *input_parser(char *input, int *word_count __attribute__((unused)));

/* builtin command handlers */
void do_setenv(char **arg);
void print_env(char **env);
void exit_shell(char **arg);
void do_unsetenv(char **arg);
void change_dir(char **arg);

#endif

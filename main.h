#ifndef MAIN_H
#define MAIN_H

/* define custom macros */
#define MAX_INPUT 4096

/* include needed standard libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>

/* declare function prototypes */
char **breaker(char *command, int word_count);
char *input_parser(char *input, int *word_count __attribute__((unused)));

#endif

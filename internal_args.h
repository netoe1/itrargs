#ifndef INTERNAL_ARGS_H
#define INTERNAL_ARGS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 256

typedef struct __line
{
    char **string;
    int height;
} Line;
void internal_args_init(Line *ptr);
void internal_args_push(Line *ptr, char *name);
void internal_args_pop(Line *ptr);
void internal_args_show(Line *ptr);
void internal_args_init(Line *ptr);
#endif

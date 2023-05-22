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

void push(Line *ptr, char *name);
void pop(Line *ptr);
void show(Line *ptr);
#endif

#ifndef ITRARGS_H
#define ITRARGS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 256

typedef struct __line
{
    char **string;
    int height;
} Line;
void ITRARGS_init(Line *ptr);
void ITRARGS_push(Line *ptr, char *name);
void ITRARGS_pop(Line *ptr);
void ITRARGS_show(Line *ptr);
void ITRARGS_end(Line *ptr);
void ITRARGS_tokens(Line *ptr, char line[]);
#endif

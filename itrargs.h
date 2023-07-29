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
} ITRARGS_Line;
void ITRARGS_init(ITRARGS_Line *ptr);
void ITRARGS_push(ITRARGS_Line *ptr, char *name);
void ITRARGS_pop(ITRARGS_Line *ptr);
void ITRARGS_show(ITRARGS_Line *ptr);
void ITRARGS_end(ITRARGS_Line *ptr);
void ITRARGS_tokens(ITRARGS_Line *ptr, char line[]);
#endif

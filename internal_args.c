#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itrargs.h"

#define BUF_SIZE 256

void ITRARGS_init(Line *ptr)
{
    ptr->height = 0;
}
void ITRARGS_push(Line *ptr, char *name)
{

    if (ptr->height == 0)
    {
        puts("INTERNAL: push for the first time!(1/3)");
        ptr->string = (char **)malloc(sizeof(char) * ++ptr->height);
        ptr->string[ptr->height - 1] = (char *)malloc(sizeof(char) * BUF_SIZE);
    }
    else
    {
        puts("INTERNAL: push more than once!(2/3)");
        ptr->string = (char **)realloc(ptr->string, sizeof(char) * ++ptr->height);
        ptr->string[ptr->height - 1] = (char *)realloc(ptr->string[ptr->height - 1], sizeof(char) * BUF_SIZE);
    }
    strncpy(ptr->string[ptr->height - 1], name, strlen(name));
    strncat(ptr->string[ptr->height - 1], "\0", sizeof(ptr->string[ptr->height - 1]));
    puts("INTERNAL: string added!(3/3)");
};

void ITRARGS_pop(Line *ptr)
{
    if (ptr->height > 0)
    {
        free(ptr->string[ptr->height]);
        ptr->height--;
        return;
    }

    puts("Cannot delete stack!");
}

void ITRARGS_show(Line *ptr)
{
    for (int i = 0; i < ptr->height; i++)
    {
        printf("String %d:%s\n", i + 1, ptr->string[i]);
    }
}

void ITRARGS_end(Line *ptr)
{
    free(ptr->string);
}

void ITRARGS_tokens(Line *ptr, char line[])
{
    char *buf = NULL;

    buf = strtok(line, " ");
    ITRARGS_push(ptr, buf);
    ITRARGS_show(ptr);

    while (buf != NULL)
    {
        buf = strtok(NULL, " ");
        if (buf != NULL)
        {
            ITRARGS_push(ptr, buf);
        }
    }

    // ITRARGS_show(&arguments);
}

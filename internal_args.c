#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "internal_args.h"

#define BUF_SIZE 256

void push(Line *ptr, char *name)
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

void pop(Line *ptr)
{
    if (ptr->height > 0)
    {
        free(ptr->string[ptr->height]);
        ptr->height--;
        return;
    }

    puts("Cannot delete stack!");
}

void show(Line *ptr)
{
    for (int i = 0; i < ptr->height; i++)
    {
        printf("String %d:%s\n", i + 1, ptr->string[i]);
    }
}

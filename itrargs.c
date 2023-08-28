#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itrargs.h"

#define BUF_SIZE 256

void ITRARGS_init(ITRARGS_Line *ptr)
{

    if (ptr != NULL)
    {
        ptr->height = 0;
        return;
    }
    puts("ERROR: You must add a valid pointer!");

    return;
}
static void ITRARGS_push(ITRARGS_Line *ptr, char *name)
{

    if (ptr != NULL && name != NULL)
    {

        if (ptr->height == 0)
        {
            // puts("INTERNAL: push for the first time!(1/3)");
            ptr->string = (char **)malloc(sizeof(char) * ++ptr->height);
            ptr->string[ptr->height - 1] = (char *)malloc(sizeof(char) * BUF_SIZE);
        }
        else
        {
            // puts("INTERNAL: push more than once!(2/3)");
            ptr->string = (char **)realloc(ptr->string, sizeof(char) * ++ptr->height);
            ptr->string[ptr->height - 1] = (char *)realloc(ptr->string[ptr->height - 1], sizeof(char) * BUF_SIZE);
        }
        strncpy(ptr->string[ptr->height - 1], name, strlen(name));
        ptr->string[strlen(name) + 1] = '\0';
        // puts("INTERNAL: string added!(3/3)");
    }
};
static void ITRARGS_pop(ITRARGS_Line *ptr)
{
    if (ptr != NULL)
    {
        if (ptr->height > 0)
        {
            free(ptr->string[ptr->height]);
            ptr->height--;
            return;
        }
    }

    puts("Cannot delete stack!");
}
void ITRARGS_show(ITRARGS_Line *ptr)
{
    if (ptr != NULL)
    {

        for (int i = 0; i < ptr->height; i++)
        {
            printf("String %d:%s\n", i + 1, ptr->string[i]);
        }
    }
}
void ITRARGS_free(ITRARGS_Line *ptr)
{
    if (ptr != NULL)
    {
        free(ptr->string);
    }
}
void ITRARGS_tokens(ITRARGS_Line *ptr, char *line)
{
    char buffer[512];
    strncpy(buffer, line, sizeof(buffer) - 1);
    buffer[sizeof(buffer)] = '\0';
    if (ptr != NULL)
    {
        char *buf = NULL;
        if (strstr(line, " ") != NULL)
        {
            buf = strtok(buffer, " ");
            ITRARGS_push(ptr, buf);
            // ITRARGS_show(ptr);

            while (buf != NULL)
            {
                buf = strtok(NULL, " ");
                if (buf != NULL)
                {
                    ITRARGS_push(ptr, buf);
                }
            }
        }
        else
        {
            puts("The string hasn't a empty space!");
        }
    }
    // ITRARGS_show(&arguments);
}

void ITRARGS_tokens_w_pivot(ITRARGS_Line *ptr, char *line, char *pivot)
{
    char buffer[512];
    strncpy(buffer, line, sizeof(buffer) - 1);
    buffer[sizeof(buffer)] = '\0';
    if (ptr != NULL)
    {
        char *buf = NULL;
        if (pivot != NULL && strstr(line, pivot) != NULL)
        {

            buf = strtok(buffer, pivot);
            ITRARGS_push(ptr, buf);
            // ITRARGS_show(ptr);

            while (buf != NULL)
            {
                buf = strtok(NULL, pivot);
                if (buf != NULL)
                {
                    ITRARGS_push(ptr, buf);
                }
            }
        }
        else
        {
            puts("You have to set a pivot to use!");
        }
    }
    // ITRARGS_show(&arguments);
}

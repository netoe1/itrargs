# itrargs.h (old internal-args.h)

This is a library to facilitate operations with arguments in C.

<p>  To use, *<strong>include the library header in your project</strong>*.
  I recommend using the makefile to avoid errors and improve the readability of the directories, <strong>however, if you want, 
  copy and paste the .c code directly into the header</strong>. This is directly down to your preference.
</p>

```c
#include "itrargs.h"
```

</br>

<p>
  Here's a snippet of the library's header code.
</p>

```c
void ITRARGS_init(Line *ptr); // Init the structure.
void ITRARGS_show(Line *ptr); // Show the all arg in one line.
void ITRARGS_end(Line *ptr); /*It closes\ ends the library structure, it must always be used at the end of the algorithm or function use, to avoid memory leaks!*/
void ITRARGS_tokens(Line *ptr, char line[]); /*Separates an entire line into tokens, which you can access via array indexes.*/
```

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itrargs.h"

int main(void)
{
    // Initialize the pointer to stack.
    Line lineArgs;
    ITRARGS_init(&lineArgs);

    // This function will take tokens of the string's content
    ITRARGS_tokens(&lineArgs, "Hello world!");

    puts(lineArgs.string[0]); // Prints "Hello"
    puts(lineArgs.string[1]); // Prints "World!"

    // Remember to close the pointer, to avoid memory leaks!
    ITRARGS_end(&lineArgs);
}
```

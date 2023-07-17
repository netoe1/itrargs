PATH_TO_OBJ = ./
FILENAME_C= itrargs.c

all:
	gcc -c $(FILENAME_C) -o itrargs.o -I $(PATH_TO_OBJ)

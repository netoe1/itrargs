PATH_TO_OBJ = ./
FILENAME_C= internal_args.c
all:
	gcc -c i $(FILENAME_C) -o internal_args.o -I $(PATH_TO_OBJ)
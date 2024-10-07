# Makefile to AVL TREE TAD

OBJS	= main.o avl.o principal.o
SOURCE	= main.c avl.c principal.c
HEADER	= avl.h principal.h
OUT	= myavl
CC	 = gcc
FLAGS	 = -g -c -Wall -Wextra -Werror
LFLAGS	 = -lm

all: myavl

myavl: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

valgrind: myavl
	valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=high --track-origins=yes --vgdb=yes ./myavl

clean:
	rm -f *.o *.gch $(OUT)

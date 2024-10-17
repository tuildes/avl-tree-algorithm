# Makefile to AVL Tree

OBJS	= avl.o main.o
SOURCE	= avl.c main.c
HEADER	= avl.h
OUT	= myavl
CC	 = gcc
FLAGS	 = -g -c -Wall -Wextra -Werror -Wshadow
LFLAGS	 = -lm

all: myavl

myavl: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

avl.o: avl.c
	$(CC) $(FLAGS) avl.c -o avl.o

main.o: main.c
	$(CC) $(FLAGS) main.c -o main.o

clean:
	rm -f $(OBJS) $(OUT)
# Makefile to AVL Tree

OBJS	= src/avl.o src/main.o
SOURCE	= src/avl.c src/main.c
HEADER	= src/avl.h
OUT	= myavl
CC	 = gcc
FLAGS	 = -g -c -Wall -Wextra -Werror -Wshadow
LFLAGS	 = -lm

all: myavl

myavl: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

src/avl.o: src/avl.c
	$(CC) $(FLAGS) src/avl.c -o src/avl.o

src/main.o: src/main.c
	$(CC) $(FLAGS) src/main.c -o src/main.o

clean:
	rm -f $(OBJS) $(OUT)

valgrind: myavl
	valgrind ./myavl

valgrind_leakcheck: myavl
	valgrind --leak-check=full ./myavl

valgrind_extreme: myavl
	valgrind -s --leak-check=full --show-leak-kinds=all --leak-resolution=high --track-origins=yes --vgdb=yes ./myavl < input/teste0.in
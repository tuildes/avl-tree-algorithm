OBJS	= main.o avl.o
SOURCE	= main.c avl.c
HEADER	= avl.h
OUT	= myavl
CC	 = gcc
FLAGS	 = -g -c -Wall -Wextra -Werror
LFLAGS	 = -lm

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

program.o: program.c
	$(CC) $(FLAGS) $(OBJS) 

clean:
	rm -f *.o *.gch $(OUT)

OBJS = wasd.o
CC = gcc
CFLAGS = -Wall -Wextra -pedantic-errors --std=c89 -c
LFLAGS = -lncurses

control: $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o control

wasd.o: wasd.c
	$(CC) $(CFLAGS) wasd.c

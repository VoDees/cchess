CC=gcc
CFLAGS=-std=c99 -Wall -Werror -Wextra

all: chess.c
	$(CC) $(CFLAGS) chess.c -o chess
clear:
	-rm chess chess.o

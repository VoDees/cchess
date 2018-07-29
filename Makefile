CC=gcc
CFLAGS=-std=c99 -Wall -Werror -Wextra

all: cchess.h cchess_console.c cchess_logic.c cchess.c
	$(CC) $(CFLAGS) cchess_console.c cchess_logic.c cchess.c -o cchess
clear:
	-rm cchess cchess.o

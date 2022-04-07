CC = gcc
CFLAGS = -Wall -Wextra -std=c11

default: program

# (3.) Making the main-program (executable)
program: main.o Functions.o
	$(CC) $(CFLAGS) -o program main.o Functions.o -lm

# (2.) Making main.o from main.c
main.o: main.c Functions.h
	$(CC) $(CFLAGS) -c main.c

# (1.) Making Functions.o from Functions.c
Functions.o: Functions.c Functions.h
	$(CC) $(CFLAGS) -c Functions.c

# ~~ #

clean:
	$(DEL) program *.o *~
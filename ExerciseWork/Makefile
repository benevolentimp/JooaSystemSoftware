CC = gcc
CFLAGS = -Wall -Wextra -std=c11

default: program.exe

# Making the main-program (executable)
program.exe: main.o wndProcedure.o
	$(CC) $(CFLAGS) -o program main.o wndProcedure.o

# Making main.o from main.c
main.o: main.c wndProcedure.h
	$(CC) $(CFLAGS) -c main.c

# Making wndProcedure-object from wndProcedure.c
wndProcedure.o: wndProcedure.c wndProcedure.h
	$(CC) $(CFLAGS) -c wndProcedure.c

# ~¤~ #

clean:
	$(DEL) program.exe *.o *~
# Title			: Makefile
# Author		: Jooa Jaakkola (@benevolentimp)
# Description	: Makefile for compiling this directory.

CC = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0` -lm

all: Program

# Make main executable, from Main.o
Program: Main.o Setup.o Calc.o
	$(CC) $(CFLAGS) -o Program Main.o Setup.o Calc.o $(LIBS)

# Make Main.o, from Main.c
Main.o: Main.c Setup.h Calc.h
	$(CC) $(CFLAGS) -c Main.c $(LIBS)

# ... Make other files the same way; target -> object-file, pre-req ->  their implementation and headers
Setup.o: Setup.c Setup.h Calc.h
	$(CC) $(CFLAGS) -c Setup.c $(LIBS)
	
Calc.o: Calc.c Calc.h
	$(CC) $(CFLAGS) -c Calc.c $(LIBS)
	

# Remove all object-files and executables
clean:
	$(RM) Program *.o *~

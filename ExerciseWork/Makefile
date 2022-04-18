# Title		: Makefile
# Author	: Jooa Jaakkola (@benevolentimp)
# Description	: 
# -¤-
# format:
# target: prerequisites
# 	action
PROGRAM = MainGtkApp

CC = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0`

$(PROGRAM): $(PROGRAM).c
	$(CC) $(CFLAGS) -o $(PROGRAM) $(PROGRAM).c $(LIBS)

ActivateWindow: ActivateWindow.c ActivateWindow.h

clean:
	rm $(PROGRAM)

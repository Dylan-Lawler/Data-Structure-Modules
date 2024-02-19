# Makefile for 'set' module
#
# CS50, Spring 2022

PROG = settest
OBJS = settest.o set.o ../lib/memory.o 
LIBS =

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I../lib
CC = gcc
MAKE = make

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

settest.o: set.h ../lib/readlinep.h
set.o: set.h

.PHONY: test clean valgrind

test: $(PROG)
	./$(PROG)

clean:
	rm -rf *.dSYM  # MacOS debugger info
	rm -f *~ *.o
	rm -f $(PROG)

valgrind: $(PROG)
	valgrind ./$(PROG)
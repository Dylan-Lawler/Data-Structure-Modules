# Makefile for 'counters' module
#
# CS50, Spring 2022

PROG = counterstest
OBJS = counterstest.o counters.o ../lib/memory.o 
LIBS =

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I../lib
CC = gcc
MAKE = make

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

counterstest.o: counters.h ../lib/readlinep.h
counters.o: counters.h

.PHONY: test clean valgrind

test: $(PROG)
	./$(PROG)

clean:
	rm -rf *.dSYM  # MacOS debugger info
	rm -f *~ *.o
	rm -f $(PROG)

valgrind: $(PROG)
	valgrind ./$(PROG)
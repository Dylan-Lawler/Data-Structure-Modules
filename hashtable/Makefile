# Makefile for 'hashtable' module
#
# CS50, Spring 2022

PROG = hashtabletest
OBJS = hashtabletest.o hashtable.o ../lib/memory.o  ../set/set.o jhash.o

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I../lib -I../set
CC = gcc
MAKE = make

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

hashtabletest.o: hashtable.h 
hashtable.o: hashtable.h ../set/set.h

.PHONY: test clean valgrind

test: $(PROG)
	./$(PROG)

clean:
	rm -rf *.dSYM  # MacOS debugger info
	rm -f *~ *.o
	rm -f $(PROG)

valgrind: $(PROG)
	valgrind ./$(PROG)
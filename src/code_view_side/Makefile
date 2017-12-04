.PHONY:clean info
CC = gcc
CFLAGS = -g -Wall
INCLUDE = -I../../inc/code_r -I../../inc/code_v
LIBRARY = -L../../lib/code_r -L../../lib/code_v
LIBS = -lcoder -lcodev -lncurses
OUTPUT = code_view_test

code_view_test:code_view_test.o
	$(CC) $(CFLAGS) -o $(OUTPUT) code_view_test.o $(LIBRARY) $(LIBS)
code_view_test.o:code_view_test.c
	$(CC) $(CFLAGS) -c $(INCLUDE) code_view_test.c -o code_view_test.o
clean:
	sudo rm *.o $(OUTPUT)
info:
	nm code_view_test

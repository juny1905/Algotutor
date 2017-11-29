.PHONY:clean info
CC = gcc
CFLAGS = -g -Wall
INCLUDE = ../../inc/code_r
LIBRARY = ../../lib/code_r
OUTPUT = code_r_test

code_r_test:code_r_test.o ../../lib/code_r/libcoder.a
	$(CC) $(CFLAGS) -o $(OUTPUT) code_r_test.o -L$(LIBRARY) -lcoder
code_r_test.o:code_r_test.c
	$(CC) $(CFLAGS) -c -I$(INCLUDE) code_r_test.c -o code_r_test.o
clean:
	sudo rm *.o $(OUTPUT)
info:
	nm code_r_test

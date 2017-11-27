.PHONY:clean info
CC = gcc
CFLAGS = -g -Wall
INCLUDE = ../inc/code_v
LIBRARY = ../lib/code_v
OUTPUT = code_v_test

code_v_test:code_v_test.o ../lib/code_v/libcodev.a
	$(CC) $(CFLAGS) -o $(OUTPUT) code_v_test.o -L$(LIBRARY) -lcodev
code_v_test.o:code_v_test.c
	$(CC) $(CFLAGS) -c -I$(INCLUDE) code_v_test.c -o code_v_test.o
clean:
	sudo rm *.o $(OUTPUT)
info:
	nm code_v_test

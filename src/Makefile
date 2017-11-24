.PHONY:clean info
CC = gcc
CFLAGS = -g -Wall
INCLUDE = ../inc/code_v
LIBRARY = ../lib/code_v
OUTPUT = code_v_test

code_v_test:code_v_test.o
	$(CC) $(CFLAGS) -o $(OUTPUT) -L$(LIBRARY) -lcodev code_v_test.o
code_v_test.o:code_v_test.c
	$(CC) $(CFLAGS) -c -I$(INCLUDE) code_v_test.c -o code_v_test.o
clean:
	sudo rm *.o $(OUTPUT)
info:
	nm code_v_test

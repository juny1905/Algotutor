CC = gcc
CFLAGS = -g -Wall
OBJ = ./cursor.o ./console.o
LIB_FILES = libui.so.1
LIB_DIR = ../lib/ui

.PHONY: clean

../algotutor : ./main.c 
	$(CC) -o $@ $< -I../inc/ui/ -L$(LIB_DIR) -lui -lncurses

#$(LIB_DIR)/$(LIB_FILES) : 

clean :
	/bin/rm -f *.o
	/bin/rm -f *.so
	/bin/rm -f *.so.1
	/bin/rm -f *.so.1.0

CC = gcc
CFLAGS = -g -Wall
OBJ = ./cursor.o ./console.o
LIB_FILES = libui.so.1 libcodev.so.1 libcoder.so.1
LIB_DIR = -L../lib/ui -L../lib/code_r -L../lib/code_v
.PHONY: clean

../algotutor : ./main.c 
	$(CC) -o $@ $< -I../inc/ui/ -I../inc/code_v/ -I../inc/code_r $(LIB_DIR) -lui -lncurses -lpthread -lcodev -lcoder

#$(LIB_DIR)/$(LIB_FILES) : 

clean :
	/bin/rm -f *.o
	/bin/rm -f *.so
	/bin/rm -f *.so.1
	/bin/rm -f *.so.1.0

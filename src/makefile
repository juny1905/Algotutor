CC = gcc
CFLAGS = -g -Wall
OBJ = ./cursor.o ./console.o
LIB_FILES = libui.so.1 libcodev.so.1 libcoder.so.1
INC_DIR = -I../inc/ui/ -I../inc/simul_v/ -I../inc/code_v/ -I../inc/code_r 
LIB_DIR = -L../lib/ui -L../lib/simul_v -L../lib/code_r -L../lib/code_v 
.PHONY: clean

../algotutor : ./main.c 
	$(CC) $(CFLAGS) -o $@ $< $(INC_DIR) $(LIB_DIR) -lui -lsim -lcodev -lcoder -lncurses -lpthread 

#$(LIB_DIR)/$(LIB_FILES) : 

clean :
	/bin/rm -f *.o
	/bin/rm -f *.so
	/bin/rm -f *.so.1
	/bin/rm -f *.so.1.0

CC = gcc
CFLAGS = -g -Wall -fPIC -c
OBJ = ./viewcode.o 
LIB_DIR = ../../lib
LUI_DIR = ../../lib/code_v
INC_DIR = -I../../inc/code_v -I../../inc/ui

.PHONY: clean

./libcodev.so.1 : $(OBJ)
	ld -shared -soname=libcodev.so.1 ./*.o -o $(LUI_DIR)/libcodev.so.1.0 -lc
	ln -s $(LUI_DIR)/libcodev.so.1.0 $(LUI_DIR)/libcodev.so
	ln -s $(LUI_DIR)/libcodev.so.1.0 $(LUI_DIR)/libcodev.so.1
	cp $(LUI_DIR)/libcodev.so.1 $(LIB_DIR)/libcodev.so.1

%.o:%.c
	$(CC) $(CFLAGS) -o $@ $< $(INC_DIR)

clean :
	/bin/rm -f ./*.o
	/bin/rm -f $(LUI_DIR)/*.so
	/bin/rm -f $(LUI_DIR)/*.so.1
	/bin/rm -f $(LUI_DIR)/*.so.1.0

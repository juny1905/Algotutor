CC = gcc
CFLAGS = -g -Wall -fPIC -c
OBJ = ./readcode.o 
LIB_DIR = ../../lib
LUI_DIR = ../../lib/code_r
INC_DIR = ../../inc/code_r

.PHONY: clean

./libcoder.so.1 : $(OBJ)
	ld -shared -soname=libcoder.so.1 ./*.o -o $(LUI_DIR)/libcoder.so.1.0 -lc
	ln -s $(LUI_DIR)/libcoder.so.1.0 $(LUI_DIR)/libcoder.so
	ln -s $(LUI_DIR)/libcoder.so.1.0 $(LUI_DIR)/libcoder.so.1
	cp $(LUI_DIR)/libcoder.so.1 $(LIB_DIR)/libcoder.so.1

%.o:%.c
	$(CC) $(CFLAGS) -o $@ $< -I$(INC_DIR)

clean :
	/bin/rm -f ./*.o
	/bin/rm -f $(LUI_DIR)/*.so
	/bin/rm -f $(LUI_DIR)/*.so.1
	/bin/rm -f $(LUI_DIR)/*.so.1.0

CC = gcc
CFLAGS = -g -Wall -fPIC -c
OBJ = ./cursor.o ./console.o
LIB_DIR = ../../lib
LUI_DIR = ../../lib/ui

.PHONY: clean

./libui.so.1 : $(OBJ)
	ld -shared -soname=libui.so.1 ./*.o -o $(LUI_DIR)/libui.so.1.0 -lc
	ln -s $(LUI_DIR)/libui.so.1.0 $(LUI_DIR)/libui.so
	ln -s $(LUI_DIR)/libui.so.1.0 $(LUI_DIR)/libui.so.1
	cp $(LUI_DIR)/libui.so.1 $(LIB_DIR)/libui.so.1

console.o : console.c
	$(CC) $(CFLAGS) $< -I../../inc/ui/

cursor.o : cursor.c
	$(CC) $(CFLAGS) $<

clean :
	/bin/rm -f $(LUI_DIR)/*.o
	/bin/rm -f $(LUI_DIR)/*.so
	/bin/rm -f $(LUI_DIR)/*.so.1
	/bin/rm -f $(LUI_DIR)/*.so.1.0

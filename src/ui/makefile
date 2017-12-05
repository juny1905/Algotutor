CC = gcc
CFLAGS = -g -Wall -fPIC -c
OBJ = ./cursor.o ./loaddir.o ./uimain.o ./uisub.o ./keyhandler.o 
LIB_DIR = ../../lib
LUI_DIR = ../../lib/ui
INC_DIR = ../../inc/ui

.PHONY: clean

./libui.so.1 : $(OBJ)
	ld -shared -soname=libui.so.1 ./*.o -o $(LUI_DIR)/libui.so.1.0 -lc
	ln -s $(LUI_DIR)/libui.so.1.0 $(LUI_DIR)/libui.so
	ln -s $(LUI_DIR)/libui.so.1.0 $(LUI_DIR)/libui.so.1
	cp $(LUI_DIR)/libui.so.1 $(LIB_DIR)/libui.so.1

#loaddir.o : loaddir.c
#	$(CC) $(CFLAGS) $< -I../../inc/ui/

#cursor.o : cursor.c
#	$(CC) $(CFLAGS) $< -I../../inc/ui/

%.o:%.c
	$(CC) $(CFLAGS) -o $@ $< -I$(INC_DIR)

clean :
	/bin/rm -f ./*.o
	/bin/rm -f $(LUI_DIR)/*.so
	/bin/rm -f $(LUI_DIR)/*.so.1
	/bin/rm -f $(LUI_DIR)/*.so.1.0

CC = gcc
CFLAGS = -g -Wall -fPIC -c

./lib_ui.so.1 : ./cursor
	ld -shared -soname=libui.so.1 ./*.o -o libui.so.1.0 -lc
	ln -s libui.so.1.0 libui.so
	ln -s libui.so.1.0 libui.so.1

./cursor : ./cursor.c
	$(CC) $(CFLAGS) $<

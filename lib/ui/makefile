CC = gcc
CFLAGS = -g -Wall -fPIC -c

.PHONY: clean

./libui.so.1 : ./cursor
	ld -shared -soname=libui.so.1 ./*.o -o libui.so.1.0 -lc
	ln -s libui.so.1.0 libui.so
	ln -s libui.so.1.0 libui.so.1
	cp ./libui.so.1 ../libui.so.1

./cursor : ./cursor.c
	$(CC) $(CFLAGS) $<

clean :
	/bin/rm -f *.o
	/bin/rm -f *.so
	/bin/rm -f *.so.1
	/bin/rm -f *.so.1.0

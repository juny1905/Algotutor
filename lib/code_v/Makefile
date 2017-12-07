.PHONY:clean info
CC = gcc
CFLAGS = -g -Wall
OBJFILES = viewcode.o
INCLUDE = -I../../inc/code_v -I../../inc/ui
SHARED = libcodev.so.1.0 
OUTPUT = libcodev.so libcodev.so.1
$(OUTPUT): $(SHARED)
	ln -s $(SHARED) libcodev.so
	ln -s $(SHARED) libcodev.so.1
	cp libcodev.so.1 ../libcodev.so.1
$(SHARED): $(OBJFILES)
	$(CC) -fPIC -shared -Wl,-soname=libcodev.so.1 *.o -o libcodev.so.1.0 -lc
%.o: %.c
	$(CC) $(CFLAGS) -fPIC -c $(INCLUDE) -c $< -o $@ -lcoder -lncurses -lui
clean:
	sudo rm *.o $(OUTPUT) $(SHARED) ../libcodev.so.1
info:
	nm libcodev.so.1.0

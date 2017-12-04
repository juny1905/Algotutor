.PHONY:clean info
CC = gcc
CFLAGS = -g -Wall
OBJFILES = readcode.o
INCLUDE = ../../inc/code_r
SHARED = libcoder.so.1.0 
OUTPUT = libcoder.so libcoder.so.1
$(OUTPUT): $(SHARED)
	ln -s $(SHARED) libcoder.so
	ln -s $(SHARED) libcoder.so.1
	cp libcoder.so.1 ../libcoder.so.1
$(SHARED): $(OBJFILES)
	$(CC) -fPIC -shared -Wl,-soname=libcoder.so.1 *.o -o libcoder.so.1.0 -lc
%.o: %.c
	$(CC) $(CFLAGS) -fPIC -c -I$(INCLUDE) -c $< -o $@
clean:
	sudo rm *.o $(OUTPUT) $(SHARED) ../libcoder.so.1
info:

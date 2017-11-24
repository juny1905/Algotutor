.PHONY:clean info
CC = gcc
CFLAGS = -g -Wall
OBJFILES = readcode.o
INCLUDE = ../../inc/code_v
OUTPUT = libcodev.a

$(OUTPUT): $(OBJFILES)
	ar rv $(OUTPUT) $(OBJFILES)
%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@
clean:
	sudo rm *.o $(OUTPUT)
info:
	nm libcodev.a

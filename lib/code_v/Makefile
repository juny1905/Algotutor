.PHONY : clean info
CC = gcc
CFLAGS = -g -Wall
OBJFILES = viewcode.o
INCLUDE = -I../../inc/code_r -I../../inc/code_v
LIB = -L../../lib/code_r
LIBS = -lcoder -lncurses
 
OUTPUT = libcodev.a

$(OUTPUT) : $(OBJFILES)
	ar rv $(OUTPUT) $(OBJFILES)
%.o:%.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@
clean:
	sudo rm *.o $(OUTPUT)
info:
	nm libcodev.a

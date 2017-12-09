CC = gcc
CFLAGS = -g -Wall -fPIC -c
OBJ = ./printf_v.o ./simulmain.o
LIB_DIR = ../../lib
LSIM_DIR = ../../lib/simul_v
INC_DIR = ../../inc/simul_v

.PHONY: clean

./libui.so.1 : $(OBJ)
	ld -shared -soname=libsim.so.1 ./*.o -o $(LSIM_DIR)/libsim.so.1.0 -lc
	ln -s $(LSIM_DIR)/libsim.so.1.0 $(LSIM_DIR)/libsim.so
	ln -s $(LSIM_DIR)/libsim.so.1.0 $(LSIM_DIR)/libsim.so.1
	cp $(LSIM_DIR)/libsim.so.1 $(LIB_DIR)/libsim.so.1

#loaddir.o : loaddir.c
#	$(CC) $(CFLAGS) $< -I../../inc/ui/

#cursor.o : cursor.c
#	$(CC) $(CFLAGS) $< -I../../inc/ui/

%.o:%.c
	$(CC) $(CFLAGS) -o $@ $< -I$(INC_DIR)

clean :
	/bin/rm -f ./*.o
	/bin/rm -f $(LSIM_DIR)/*.so
	/bin/rm -f $(LSIM_DIR)/*.so.1
	/bin/rm -f $(LSIM_DIR)/*.so.1.0

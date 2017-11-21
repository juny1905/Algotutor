#! /bin/bash

# setting Library Directory
# need sudo command!
echo $(pwd)/lib/ > /etc/ld.so.conf.d/algotutor.conf
LD_LIBRARY_PATH=$(pwd)/lib/:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH

# call make

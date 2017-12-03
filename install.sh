#! /bin/bash

echo "You need the SU permission for installation."
echo "Are you typed the << su ./install.sh >> ?"
echo "[Y/N]"
read answer

if [ $answer == "y" ]
then
	echo "install starting..."
elif [ $answer == "Y" ]
then
	echo "install starting..."
else
	echo "please restart the install.sh"
	exit 0
fi

# setting Library Directory
# need sudo command!
echo "[set] library directory"

echo $(pwd)/lib/ > /etc/ld.so.conf.d/algotutor.conf
ldconfig

# set the Environment variable 
# Not used
:<<'END'
LD_LIBRARY_PATH="$(pwd)/lib/:"$LD_LIBRARY_PATH
export LD_LIBRARY_PATH

LD_LIBRARY_PATH=$(dirname $0)/lib/:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH
echo $LD_LIBRARY_PATH
END

echo "[complete] library directory"

# installing required packages
echo "[install] ncurses-dev package"

apt-get --assume-yes install ncurses-dev >> /dev/null

echo "[complete] ncurses-dev package"

# call make



exit 0

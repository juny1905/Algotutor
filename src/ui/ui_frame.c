#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "my_ui.h"

#define NOMERGED 1
#define MERGED 0

void checkConsoleSize(int *_row, int *_col)
{
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	*_row = w.ws_row;
	*_col = w.ws_col;
	return;
}

void printHorizonLine(int _start_row, int _start_col, int rowMAX, int colMAX, int _option)
{
	setCursorPos(_start_row, _start_col);
	
	for(int i=0; i<colMAX; i++)
	{
		if(i == 0 || i == (colMAX-1) || ((i == (colMAX/2)) && _option ))
			printf("+");
		else
			printf("-");
	}

	return;
}

void printVerticalLine(int _start_row, int _end_row, int rowMAX, int colMAX, int _option)
{
	
	for(int i=_start_row; i<=_end_row; i++)
	{
		setCursorPrint(i,0,"|");
		
		if(_option)
			setCursorPrint(i,colMAX/2,"|");
		setCursorPrint(i,colMAX-1,"|");
	}

	return;
}

int main(int argc, char *argv[])
{
	int rowMAX, colMAX;

	checkConsoleSize(&rowMAX, &colMAX);

	system("clear");

	// first Line
	printHorizonLine(0,0,rowMAX,colMAX,NOMERGED);
	printVerticalLine(1,rowMAX-6,rowMAX,colMAX,NOMERGED);
	printHorizonLine(rowMAX-5,0,rowMAX,colMAX,NOMERGED);
	printVerticalLine(rowMAX-4,rowMAX-1,rowMAX,colMAX,MERGED);
	// last Line
	printHorizonLine(rowMAX,0,rowMAX,colMAX,MERGED);

	while(1)
	{
		setCursorPos(0,0);	
	}

	return 0;
}

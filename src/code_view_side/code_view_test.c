#include "readcode.h"
#include "viewcode.h"

int main(void)
{
	LINE *TEST = (LINE *)malloc(sizeof(LINE));
	TEST = ReadFile("../../doc/Chap1-printf/printf.txt");
	printPara(10,10,30,5,TEST);
	// displayText(TEST);	
	return 0;	
}

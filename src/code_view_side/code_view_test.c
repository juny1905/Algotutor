#include "readcode.h"
#include "viewcode.h"

int main(void)
{
	LINE *TEST = (LINE *)malloc(sizeof(LINE));
	TEST = ReadFile("../../doc/test.txt");
	printPara(10,10,10,10,TEST);
	return 0;	
}

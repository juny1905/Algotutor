#include "readcode.h"

int main(void)
{
	LINE *TEST = (LINE *)malloc(sizeof(LINE));
	TEST = ReadFile("../../doc/test.txt");
	displayText(TEST);

	return 0;	
}

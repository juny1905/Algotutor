#include <stdlib.h>

//set window size = (24, 80)
//success init function return 0 value
//failure init function return -1 value
int init(void)
{
	system("resize -s 24 80 >> /dev/null");
	return 0;
}

/*
int main(void)
{
	init();

	return 0;
}
*/

#include "readcode.h"

int main(int argc, char *argv[])
{
	LINE *TEST = (LINE *)malloc(sizeof(LINE));
	if(argc != 2)
	{
			fprintf(stderr,"Invalid Argument !\n");
			return 0;
	}
	TEST = ReadFile(argv[1]);
	displayText(TEST);

	return 0;	
}

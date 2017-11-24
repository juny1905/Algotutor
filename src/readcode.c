#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SZ_BUF 1024

typedef struct _LINE{
	struct _LINE *NEXT;
	char *text;
	short type;
}LINE;
short isComment(char *line_buf)
{
		if(strncmp(line_buf,"//@",3) == 0)
				return 1;
		else
				return 0;
}
void addToText(char *feed, short type, LINE **HEAD)
{
	LINE *NEW = (LINE *)malloc(sizeof(LINE));
	NEW->text = (char *)malloc(sizeof(feed)+1);
	strcpy(NEW->text, feed);
	NEW->NEXT = 0; NEW->type = type;
	if((*HEAD) == 0)
	{
		(*HEAD) = NEW;
	}
	else
	{
		LINE *CUR = (*HEAD);
		while(CUR->NEXT != 0)
		{
			CUR = CUR->NEXT;
		}
		CUR->NEXT = NEW;
	}
}
void displayText(LINE *HEAD) // For testing.
{
	LINE *CUR = HEAD;
	while(CUR != 0)
	{
		if(CUR->type == 1)
		{
				printf("\x1B[31m");
		}
		else
		{
				printf("\x1B[0m");
		}
		printf("Line : %sType : %d\n",CUR->text,CUR->type);
		CUR = CUR->NEXT;
	}		
}
LINE *ReadFile(char *filename)
{
	LINE *para = 0;
	FILE *infile;
	char line_buf[SZ_BUF];

	infile = fopen(filename,"r");

	if(!infile)
	{
		perror("Algotutor :");
		return NULL;
	}	
	
	// How do I read the text line by line ?

	while(fgets(line_buf,sizeof(line_buf), infile))
	{
		addToText(line_buf,isComment(line_buf),&para);
	}
	
	return para;
}

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

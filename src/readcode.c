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

void addToText(char *feed, short type, LINE **HEAD)
{
	LINE *NEW = (LINE *)malloc(sizeof(LINE));
	NEW->NEXT = 0; NEW->text = feed;
	NEW->type = type;
	if(*HEAD == 0)
	{
		*HEAD = NEW;
		printf("Head Add | Type = %d\n",type);
		return;
	}
	else
	{
		LINE *CUR = *HEAD;
		while(CUR->NEXT != 0)
		{
			CUR = CUR->NEXT;
		}
		CUR->NEXT = NEW;
		printf("Node Add | Type = %d\n",type);
		return;
	}
}

void displayText(LINE **HEAD) // For testing.
{
	LINE *CUR = *HEAD;
	while(CUR != 0)
	{
		printf("Line : %s | Type : %d\n",CUR->text,CUR->type);
		CUR = CUR->NEXT;
	}		
}
LINE *ReadFile(char *filename)
{
	LINE *para = 0;

	FILE *infile;
	int line_n, i;
	char line_buf[SZ_BUF];
	short type = 0; // default is 0 (Description)

	infile = fopen(filename,"r");

	if(!infile)
	{
		perror("Algotutor :");
		return NULL;
	}	
	
	// How do I read the text line by line ?
	line_n =0 ;
	
	while(fgets(line_buf,sizeof(line_buf), infile))
	{
		++line_n;	
		if(strncmp(line_buf,"\\@",3) == 0) type = 1;
		else type = 0;

		addToText(line_buf,type,&para);
		
	}
	return para;
}
int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		perror("Invalid Arguments !");
		return 0;
	}
	
	LINE *Paragraph = ReadFile(argv[1]);

	displayText(&Paragraph);
		
	return 0;
	
}

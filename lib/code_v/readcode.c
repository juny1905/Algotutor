#include "readcode.h"


int i=0; // for line numbering
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
	if(NEW->type == SRC_LINE) // If the type of line is source
	{
		i++;
	}
	NEW->line_index = i;
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
		if(CUR->type == COM_LINE)
		{
				printf("\x1B[31m"); // Set the line color Red
		}
		else
		{
				printf("\x1B[0m");
		}
		printf("%d : %s",CUR->line_index,CUR->text);
		CUR = CUR->NEXT;
	}		
}
LINE *ReadFile(char *filename)
{
	LINE *para = 0;
	FILE *infile;
	char line_buf[SZ_BUF];
	char file_location[] = "../doc/";

	infile = fopen(strcat(file_location,filename),"r");
	if(!infile)
	{
		perror("File");
		return NULL;
	}	
	
	// How do I read the text line by line ?

	while(fgets(line_buf,sizeof(line_buf), infile))
	{
		addToText(line_buf,isComment(line_buf),&para);
	}
	
	return para;
}

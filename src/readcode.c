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

void addToText(char *feed, short type, LINE *HEAD)
{
	LINE *NEW = (LINE *)malloc(sizeof(LINE));
	NEW->NEXT = 0; NEW->text = feed;
	NEW->type = type;
	if(HEAD == 0)
	{
		HEAD = NEW;
	}
	else
	{
		LINE *CUR = HEAD;
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
		printf("%s | %d",CUR->text,CUR->type);
		CUR = CUR->NEXT;
	}		
}
char buf[SZ_BUF];
LINE *ReadFile(char *filename)
{
	LINE *para = 0;

	int fd,nb;
	short type = 0; // default is 0 (Description)

	fd = open(filename,O_RDONLY);

	if(fd == -1)
	{
		perror("Algotutor :");
		return NULL;
	}	
	
	while(nb = read(fd, buf, SZ_BUF))
	{
		if(buf[nb] == '\n') // If the 'new line' detected...
		{
			int i;
			if(strncmp(buf,"\\@",3) == 0) type = 1;
			else type = 0;
			addToText(buf,type,para);
		}
	}

	close(fd);

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

	displayText(Paragraph);
		
	return 0;
	
}

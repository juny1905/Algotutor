#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define SZ_BUF 1024

typedef struct *LINE
{
	LINE* NEXT;
	char *text;
	short type;
}LINE;

// Test for inline reading and stack
LINE* HEAD = 0;

void addToText(char *feed, short type)
{
	LINE *NEW = (LINE *)malloc(sizeof(LINE));
	NEW->NEXT = 0; NEW->text = feed;
	NEW->type = type;
	if(HEAD -> NEXT = 0)
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
void displayText(void) // For testing.
{
	LINE *CUR = HEAD;
	while(CUR->NEXT != 0)
	{
		printf("%s | %d",CUR->text,CUR->type);
		CUR = CUR->NEXT;
	}		
}
char buf[SZ_BUF];
char *ReadFile(char *filename)
{
	int fd;
	fd = open(filename,O_RDONLY);

	if(fd == -1)
	{
		perror("Algotutor :");
		return NULL;
	}	
	
	while(nb = read(fd, buf, SZ_BUF));

	close(fd);

	return buf;
}
void *SeprateFile(char *text)
{
	int i;
	for(i=0;text[i]!=0;i++)
	{
		if(text[i]=='\' && text[i+1]=='n')
		{
			
		}
	}
}
int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		perror("Invalid Arguments !");
		return 0;
	}
	
	char *text = ReadFile(argv[1]);
	write(0, text, SZ_BUF);
	return 0;
	
}

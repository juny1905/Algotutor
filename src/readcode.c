#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


#include <stdio.h>
#define SZ_BUF 1024

// Test for inline reading
char buf[SZ_BUF];
char *inlineRead(char *filename)
{
	int fd;
	fd = open(filename,O_RDONLY);

	if(fd == -1)
	{
		perror("Algotutor :");
		return NULL;
	}	
	
	while(read(fd, buf, SZ_BUF));

	close(fd);

	return buf;
}
int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		perror("Invalid Arguments !");
		return 0;
	}
	
	char *text = inlineRead(argv[1]);
	write(0, text, SZ_BUF);
	return 0;
	
}

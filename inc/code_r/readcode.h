#ifndef CODE_VIEW_H
#define CODE_VIEW_H

#define SZ_BUF 1024

#define COM_LINE 1
#define SRC_LINE 0

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _LINE{
	struct _LINE *NEXT;
	char *text;
	short type;
	int line_index;
}LINE;

short isComment(char *line_buf);
void addToText(char *feed, LINE **HEAD);
void displayText(LINE *HEAD);
LINE *ReadFile(char *filename);
char *deleteComment(char *line_buf);
#endif // CODE_VIEW_H

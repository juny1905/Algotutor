#include "viewcode.h"
#include "ncurses.h"
void printComm(int _y, int _x, int line,  LINE *para)
{
	LINE *CUR = para;
	while(CUR != 0)
	{
		if(CUR->line_index == line && CUR->type == COM_LINE)
		{
			mvaddstr(_y,_x,CUR->text);
		}
		CUR = CUR->NEXT;
	}
}
void currentLine(int _y, int _x, int line)
{
	char *info = (char *)malloc(sizeof(info)*30);
	sprintf(info,"Current Line : %d",line);
	mvaddstr(_y,_x,info);
}
void printPara(int _y, int _x, int _y_limit, int _x_limit, int line, LINE *para)
{
	LINE *CUR = para;
	int i,j;
	
	// How can I highlight the specific 'line' ?
	for(i=0;i<_y_limit;i++)
	{
		if(CUR->type == COM_LINE) CUR = CUR->NEXT;
		for(j=0;j<_x_limit;j++)
		{
			if(CUR->text[j] == '\0') break;
			mvaddch(_y + i,_x + j,CUR->text[j]); // From the library 'cursors'
		}
		if(CUR->NEXT == NULL)
		{
			break;
		}
		CUR = CUR->NEXT;
	}
}
void printScrolled(int _y, int _x, int _y_limit, int _x_limit, LINE *para)
{
	LINE *CUR = para;
	if(_x_limit < strlen(CUR->text))
	{
		int i,j,k,Scr_Amount;
		Scr_Amount = strlen(CUR->text) - _x_limit + 3 ;
		for(j=0; j<Scr_Amount; j++)
		{
			for(k=0; k<_x_limit; i++)
			{
				mvaddch(_y,_x + k,' ');
			}
			for(i=0; i<_x_limit; i++)
			{
				mvaddch(_y , _x + j,CUR->text[j]);	
				// Requires the timer.
			}
		}		
	}
}


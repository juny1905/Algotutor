#include "viewcode.h"
#include "uisub.h"
#include "ncurses.h"

void currentLine(int _y, int _x,int _y_limit, int _x_limit, int line)
{
	//initscr();
	//start_color();
	init_pair(1,COLOR_WHITE,COLOR_BLACK);
	attron(COLOR_PAIR(1));
	char *info = (char *)malloc(sizeof(info)*50);
	sprintf(info,"< Current Line : %d [%d,%d] >",line,_y_limit,_x_limit);
	mvaddstr(_y,_x,info);
	attroff(COLOR_PAIR(7));
	//refresh();
}
void printPara(int _y, int _x, int _y_limit, int _x_limit, int line, LINE *para)
{
	LINE *CUR = para;
	int i,j;

	// How can I highlight the specific 'line' ?
	for(i=0;i<_y_limit;i++)
	{
		if(CUR->type == COM_LINE)
			CUR = CUR->NEXT;

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


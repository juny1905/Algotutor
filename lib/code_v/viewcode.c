#include "readcode.h"
#include "ncurses.h"
void printPara(int _y, int _x, int _x_limit, int _y_limit, LINE *para);
void printScrolled(int _y, int _x, int _x_limit, int _y_limit, LINE *para);

void printPara(int _y, int _x, int _x_limit, int _y_limit, LINE *para)
{
	LINE *CUR = para;
	int i,j;	
	for(i=0;i<_y_limit;i++)
	{
		for(j=0;j<_x_limit;j++)
		{
			mvaddch(_y,_x + j,CUR->text[j]); // From the library 'cursors'
			if(CUR->text[sizeof(CUR->text)-1] == '\0');
					CUR = CUR->NEXT;
		}
	}
}
void printScrolled(int _y, int _x, int _x_limit, int _y_limit, LINE *para)
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

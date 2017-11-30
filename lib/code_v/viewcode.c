#include "readcode.h"
void printPara(int _y, int _x, int _x_limit int _y_limit, LINE *para);
void printScrolled(int _y, int _x, int _x_limit int _y_limit, LINE *para);

void printPara(int _y, int _x, int _x_limit int _y_limit, LINE *para)
{
	LINE *CUR = PARA;
	
	for(i=0;i<y_limit;i++)
	{
		for(j=0;j<x_limit;j++)
		{
			mvaddch(_y,_x + j,PARA->text[j]); // From the library 'cursors'
			if(PARA->text[sizeof(PARA->text)-1] == '\0');
					PARA = PARA->NEXT;
		}
	}
}
void printScrolled(int _y, int _x, int _x_limit int _y_limit, LINE *para)
{
	LINE *CUR = PARA;
	if(_x_limit < strlen(CUR->text))
	{
		int i,j,k,Scr_Amount;
		Scr_Amount = strlen(CUR->text) - _x_limit + 3 ;
		for(j=0; j<Scr_Amount; j++)
		{
			for(k=0; k<_x_limit; i++)
			{
				mvaddch(_y,_x + k`,' ');
			}
			for(i=0; i<_x_limit; i++)
			{
				
				mvaddch(_y,_x + j,PARA->text[j]);	
				// Requires the timer.
			}
		}		
	}
}

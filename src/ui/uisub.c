#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <curses.h>
#include <stddef.h>
#include <wchar.h>
#include <sys/types.h>
#include <dirent.h>

#include "uisub.h"

#define BUFSIZE 255;

void init_ui(void)
{
	initscr();
	start_color();
	raw();
	keypad(stdscr, TRUE);
	curs_set(0);
	noecho();
	return;
}

void clearWorkspace(int _maxRow, int _maxCol, int _option)
{
	if( _option == CODE_VIEW_PART )
	{
		for(int i=1; i<(_maxRow-5); i++)
		{
			for(int j=1; j<(_maxCol/2); j++)
			{
				mvaddch(i,j,' ');
			}
		}
	}
	else if( _option == SIMUL_VIEW_PART )
	{
		for(int i=1; i<(_maxRow-5); i++)
		{
			for(int j=(_maxCol/2+1); j<(_maxCol-1); j++)
			{
				mvaddch(i,j,' ');
			}
		}
	}
	else if( _option == COMMENT_PART )
	{
		for(int i=(_maxRow-4); i<(_maxRow-1); i++)
		{
			for(int j=1; i<(_maxCol-1); j++)
			{
				mvaddch(i,j,' ');
			}
		}
	}
	
	return;
}

void printFrame(int _maxRow, int _maxCol)
{
	//int half_maxRow = _maxRow/2;
	int half_maxCol = _maxCol/2;
	int midRow = _maxRow-5;

	for(int i=0; i<_maxRow; i++)
	{
		for(int j=0; j<_maxCol; j++)
		{
			if( ((i == 0) || (i == midRow)) && \
			(j != half_maxCol) && (j < (_maxCol-1)) && (j > 0) )
			{
				mvaddch(i,j,'-'|A_BOLD);
			}
			else if( ((i == 0) || (i == midRow)) )
			{
				mvaddch(i,j,'+'|A_BOLD);
			}
			else if( (i > 0) && (i < midRow) && \
			((j==0) || (j==half_maxCol) || (j==(_maxCol-1))))
			{
				mvaddch(i,j,'|'|A_BOLD);
			}
			else if( ((i>(midRow-1)) && (i<(_maxRow-1))) && \
			((j==0) || (j==(_maxCol-1))))
			{
				mvaddch(i,j,'|'|A_BOLD);
			}
			else if( (i == (_maxRow-1)) && \
			((j==0) || (j==(_maxCol-1))))
			{
				mvaddch(i,j,'+'|A_BOLD);
			}
			else if( (i == (_maxRow-1)) )
			{
				mvaddch(i,j,'-'|A_BOLD);
			}
		}
	}
}

void mvaddstr_att(int _y, int _x, const char *_str, int _att)
{
	int i=0;

	while(TRUE)
	{
		if(*(_str+i) == 0)
		{
			break;
		}
		mvaddch(_y, _x+i, *(_str+i) | _att);
		i++;
	}

	return;
}

void showMenu(int _maxRow, int _maxCol, int _menuCur, int _categoryNum, struct category *_cat_head)
{
	struct category *cur = _cat_head;
	
	clearWorkspace(_maxRow,_maxCol,CODE_VIEW_PART);
	
	mvaddch(4+(_menuCur*2), 3, '>');

	{
			int j = 0;

			while(TRUE)
			{
				if(cur->bottom == NULL)
				{
					if(cur->cat_name != NULL)
					{
						mvaddstr(4+(j*2), 4, (char *)cur->cat_name);
					}
					break;
				}

				if(j == 0)
				{
					mvaddstr_att(4+(j*2), 4, \
					(char *)cur->cat_name, A_BOLD);
					//mvaddch(4+(j*2), 25, (char)(cur->action + '1'));
				}
				else
				{
					mvaddstr(4+(j*2), 4, (char *)cur->cat_name);
					//mvaddch(4+(j*2), 25, (char)(cur->action + '1'));
				}

				cur = cur->bottom;
				j++;
			}
	}
	return;
}

int countCategory(struct category *cur)
{
	int result = 0;
	
	while(TRUE)
	{
		if(cur->bottom == NULL)
		{
			if(cur->cat_name != NULL)
			{
				result++;
			}
			break;
		}
		cur = cur->bottom;
		result++;
	}

	return result;
}



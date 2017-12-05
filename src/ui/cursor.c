#include <ncurses.h>
#include <curses.h>

#include "cursor.h"

void cursor_up(int *_menuCur, int *_maxMenu)
{
	mvaddch(4+((*_menuCur)*2), 3, ' ');
	if(((*_menuCur) - 1) < 0)
	{
		(*_menuCur) = (*_maxMenu) - 1;
	}
	else
	{
		(*_menuCur)--;
	}
	mvaddch(4+((*_menuCur)*2), 3, '>');
	return;
}

void cursor_down(int *_menuCur, int *_maxMenu)
{
	mvaddch(4+((*_menuCur)*2), 3, ' ');	
	(*_menuCur) = ((*_menuCur) + 1)%(*_maxMenu);	
	mvaddch(4+((*_menuCur)*2), 3, '>');
	return;
}

int cursor_select(int *_menuCur, struct category **cur)
{
	struct category *prev = (*cur);
	int result = IDLE;

	for(int i=0; i<(*_menuCur); i++)
	{
		//mvaddstr(30+i*2,30,(*cur)->cat_name);
		if( (*cur)->bottom != NULL )
		{
			(*cur) = (*cur)->bottom;
		}
	}

	if( (*cur)->action == IDLE)
	{
		(*cur) = prev;
		result = IDLE;
	}
	else if( (*cur)->action == STRT || (*cur)->action == DIRS )
	{	
		result = (*cur)->action;
		//mvaddstr(20,30,(*cur)->bottom->cat_name);
		if( (*cur)->next != NULL )
		{
			(*cur) = (*cur)->next;
		}
		//mvaddstr(10,30,(*cur)->bottom->cat_name);
	}

	return result;
}

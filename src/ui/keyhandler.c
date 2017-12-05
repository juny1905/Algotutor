#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <curses.h>
#include <stddef.h>
#include <wchar.h>
#include <sys/types.h>

#include "cursor.h"

void keyHandler(int *_state, struct category *_cat_head)
{
	wchar_t key;
	int menuCur = 0;
	int maxMenu = 5;

	while((key = getch()) != 27)
	{
		switch(key)
		{

			case KEY_UP:
			{	
				/* less than EVENT */
				if((*_state) < 3)
				{
					cursor_up(&menuCur, &maxMenu);
				}

				/* doing EVENT */
				if((*_state) == 4)
				{
					// page scrolling?
				}

				break;
			}
			case KEY_DOWN:	
			{
				/* less than EVENT */
				if((*_state) < 3)
				{
					cursor_down(&menuCur, &maxMenu);
				}

				/* doing EVENT */
				if((*_state) == 4)
				{
					// page scrolling?
				}

				break;
			}
			case KEY_LEFT:
			{
				break;
			}
			case KEY_RIGHT:
			{
				break;
			}
			case '\n':
			{
				/* IDLE */
				if((*_state) == 0)
				{
					// do nothing..?
				}
				/* selected START and Directory */
				else if((*_state) == 1 ||\
					(*_state) == 2)
				{
					cursor_select(&menuCur, &_cat_head);	
				}
				/* selected Event */
				else if((*_state) == 3)
				{
					// do something..?
				}
				/* selected EXIT */
				else if((*_state) == -2)
				{
					// exit program
				}
			}

		}

	}

	return;
}

/*
int main(void)
{
	int state = 0;

	initscr();
	start_color();
	raw();
	keypad(stdscr, TRUE);
	noecho();

	keyHandler(&state,&cat_head);

	return 0;	
}
*/

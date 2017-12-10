#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <curses.h>
#include <stddef.h>
#include <wchar.h>
#include <sys/types.h>

#include "uisub.h"
#include "cursor.h"
#include "mykey.h"

void keyHandler(int *_menuCur, int *_maxMenu, int *_state, int *_keyFlag, struct category **_cat_head)
{
	wchar_t key;
	//int menuCur = 0;
	//int maxMenu = 5;

	struct category *cur = (*_cat_head);
	(*_maxMenu) = countCategory(cur);

	while((key = getch()) != 27)
	{
		switch(key)
		{

			case KEY_UP:
			{	
				/* less than EVENT */
				if((*_state) < EVENT)
				{
					cursor_up(_menuCur, _maxMenu);
					(*_keyFlag) = KEY_FLAG_UP;
				}

				/* doing EVENT */
				if((*_state) == EVENT)
				{
					// page scrolling?
				}

				break;
			}
			case KEY_DOWN:	
			{
				/* less than EVENT */
				if((*_state) < EVENT)
				{
					cursor_down(_menuCur, _maxMenu);
					(*_keyFlag) = KEY_FLAG_DOWN;
				}

				/* doing EVENT */
				if((*_state) == EVENT)
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
				/* selected START and Directory */
				if((*_state) == IDLE ||\
				   (*_state) == STRT ||\
				   (*_state) == DIRS)
				{
					//printf("before change : %d\n",(*_state));
					(*_state)\
					= cursor_select(_menuCur, _cat_head);
					(*_keyFlag) = KEY_FLAG_ENTER;
					
					// test code
					//printf("after change : %d\n",(*_state));
				}
				/* selected Event */
				else if((*_state) == EVENT)
				{
					// do something..?
					(*_keyFlag) = KEY_FLAG_ENTER;
				}
				/* selected EXIT */
				else if((*_state) == EXIT)
				{
					// exit program
					(*_state) = EXIT;
					return;
				}
				break;
			}

		}

	}

	(*_state) = EXIT;

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
